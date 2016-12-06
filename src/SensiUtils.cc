#ifndef SENSIUTILS_CC
#define SENSIUTILS_CC

#include "SensiUtils.hh"
//=================================================================
// Default constructor
//=================================================================
SensiUtils::SensiUtils()
{
}

//=================================================================
// constructor
//=================================================================
SensiUtils::SensiUtils( Int_t *UsedPar )
{
	memcpy( mUsedPar, UsedPar, nParam*sizeof(Int_t) );
	int count = 0;
	for ( Int_t i = 0; i < nParam; i++ )
  {
	 	if ( mUsedPar[i] == 1 )
		{
			mParams[count] = i;
			count++;
		}
  }
	mDimension = count;
	cout << " Initializing SensiUtils with dimension = " << mDimension << endl;
}

//=================================================================
// Default destructor
//=================================================================
SensiUtils::~SensiUtils()
{
}

//=================================================================
// ComputeOscPar
//=================================================================
void SensiUtils::ComputeOscPar( int index, bool FC )
{
	Int_t NBINS[nParam];
	Double_t STVALUE[nParam], LTVALUE[nParam];
	if ( FC )
	{
		memcpy( NBINS,     nbinsFC, nParam*sizeof(Int_t) );
		memcpy( STVALUE, stValueFC, nParam*sizeof(Double_t) );
		memcpy( LTVALUE, ltValueFC, nParam*sizeof(Double_t) );
	}
	else
	{
		memcpy( NBINS,     nbins, nParam*sizeof(Int_t) );
		memcpy( STVALUE, stValue, nParam*sizeof(Double_t) );
		memcpy( LTVALUE, ltValue, nParam*sizeof(Double_t) );
	}
	Int_t CurrIndex=index;
  Int_t UsedBins=1;
	Int_t OscParBins[nParam];
  for (int i=0;i<nParam;i++)
  {
	 	if ( mUsedPar[i] == 1 ) //unused oscillation parameter, keep default values
		UsedBins*=NBINS[i];      //used oscillation parameters, contributes to the total nb of used bins
  }
  //Total nb of bins for those settings is currently UsedBins
  assert(index<UsedBins);
  for (int i=0;i<nParam;i++)
  {
		if (mUsedPar[i]!=1)continue;
		UsedBins /= NBINS[i];
		OscParBins[i]=TMath::FloorNint((double)CurrIndex/(double)UsedBins);
		mOscParams[i]=((OscParBins[i]+0.5)*(LTVALUE[i]-STVALUE[i])/NBINS[i])+STVALUE[i];
		CurrIndex=CurrIndex%UsedBins;
		if(mOscParams[i]<0 && i!=1) mOscParams[i]=0.0;
  }
}

//=================================================================
// getNLLmin
//=================================================================
Double_t SensiUtils::getNLLmin( Asimov *t)
{
  Double_t NLLmin = 1e6;
  for ( Int_t index = 0; index < t->GetEntries(); index++ )
  {
    t->GetEntry(index);
    if ( *(t->AvNLLtot) < NLLmin ) NLLmin = *(t->AvNLLtot);
  }
  return NLLmin;
}
//=================================================================
// getNLLmin
//=================================================================
Double_t SensiUtils::getNLLmin( SepFit *t)
{
  Double_t NLLmin = 1e6;
  for ( Int_t index = 0; index < t->GetEntries(); index++ )
  {
    t->GetEntry(index);
    if ( *(t->NLLtot) < NLLmin ) NLLmin = *(t->NLLtot);
  }
  return NLLmin;
}

//=================================================================
// fillFCHistogram
//=================================================================
TTree  *SensiUtils::fillFCTree( const TString &file, TH2D *h2, double xval, double yval, double& critical )
{
	Double_t NLLmin;
	Long64_t nevents;
	std::vector<Double_t> temp;

	// TChain to retrieve data
	TChain *cfc = new TChain("FitTree");
	cfc->Add(file);
 	FC *fc = new FC( cfc );
	nevents = cfc->GetEntries();

	cout << " ** events " << nevents << endl;

	double DeltaChi2;
  TTree *FCTree=new TTree("FCTree","tree");
  FCTree->Branch("DeltaChi2",&DeltaChi2,"DeltaChi2/D");

	// Loop
	for ( Int_t index = 0; index < nevents; index++)
	{
		h2->Reset();
		fc->GetEntry(index);
		Int_t n_bins = fc->N_BINS;

		// find minimum
		NLLmin=1e6;
    for (int i = 0; i < n_bins; i++ )
		{
	  	if (fc->FitRes[i] < NLLmin ) NLLmin = fc->FitRes[i];
		}

		// fill histogram
		for (int i = 0; i < n_bins; i++ )
		{
			ComputeOscPar( i );
			double z = 2*( fc->FitRes[i]-NLLmin);
			double x = mOscParams[mParams[1]];
			double y = mOscParams[mParams[0]];
			h2->Fill( x, y, z);
		}
		//Use spline to get deltachi2 of true value
		//cout << index << " " << xval << " " << yval;
		//cout << h2->FindBin(xval,yval) << " " << h2->GetBinContent( h2->FindBin(xval,yval) ) <<endl;
    DeltaChi2 = h2->GetBinContent( h2->FindBin(xval,yval) );
		temp.push_back(DeltaChi2);
    FCTree->Fill();
	}

	std::sort(temp.begin(), temp.end());
	critical = temp[9000];

	return FCTree;

}

//=================================================================
// fillAsimovHistograms
//=================================================================
void SensiUtils::fillAsimovHistograms( const TString &file, TH2D *h2, TMarker *m )
{
	Double_t NLLmin;
	Long64_t nevents;

	// TChain to retrieve data
	TChain *casimov = new TChain("SensiTree");
	casimov->Add(file);
 	Asimov *asimov = new Asimov( casimov );
	nevents = asimov->GetEntries();
	NLLmin = getNLLmin( asimov );

	cout << " ** events " << nevents << " NLLmin " << NLLmin << endl;

	// Loop
	for ( Int_t index = 0; index < nevents; index++)
	{
		asimov->GetEntry(index);
		ComputeOscPar( *asimov->Index );
		double z = 2*( *asimov->AvNLLtot-NLLmin);
		double x = mOscParams[mParams[1]];
		double y = mOscParams[mParams[0]];
		if ( z == 0 )
		{
			m->SetX(x);
			m->SetY(y);
			m->SetMarkerSize(1);
			m->SetMarkerStyle(22);
			cout << " Best fit point: " << x << " " << y << endl;
		}
		h2->Fill( x, y, z );
	}

}
//=================================================================
// fillSepFitHistograms
//=================================================================
void SensiUtils::fillSepFitHistograms( const TString &file, TH2D *h2, TMarker *m )
{
	assert( mDimension == 2 );
	Double_t NLLmin;
	Long64_t nevents;

	// TChain to retrieve data
	TChain *csepfit = new TChain("SepTree");
	csepfit->Add(file);
 	SepFit *sepfit = new SepFit( csepfit );
	nevents = sepfit->GetEntries();
	NLLmin = getNLLmin( sepfit );

	cout << " ** events " << nevents << " NLLmin " << NLLmin << endl;

	// Loop
	for ( Int_t index = 0; index < nevents; index++)
	{
		sepfit->GetEntry(index);
		ComputeOscPar( *sepfit->Index );
		double z = 2*( *sepfit->NLLtot-NLLmin);
		double x = mOscParams[mParams[1]];
		double y = mOscParams[mParams[0]];
		if ( z == 0 )
		{
			m->SetX(x);
			m->SetY(y);
			m->SetMarkerSize(1);
			m->SetMarkerStyle(22);
			cout << " Best fit point: " << x << " " << y << endl;
		}
		h2->Fill( x, y, z );
	}

}

//=================================================================
// fillSepChi2Histograms
//=================================================================
void SensiUtils::fillSepChi2Histograms( const TString &file, TH2D *h2 )
{
	assert( mDimension == 2 );
	Double_t NLLmin;
	Long64_t nevents;

	// TChain to retrieve data
	TChain *csepfit = new TChain("SepTree");
	csepfit->Add(file);
 	SepFit *sepfit = new SepFit( csepfit );
	nevents = sepfit->GetEntries();
	NLLmin = getNLLmin( sepfit );

	cout << " ** FillSepChi2, events = " << nevents << " \n ";
	// Loop
	for ( Int_t index = 0; index < nevents; index++)
	{
		sepfit->GetEntry(index);
		ComputeOscPar( *sepfit->Index );
		double z = TMath::Exp(-1*( *sepfit->NLLtot-NLLmin));
		double x = mOscParams[mParams[1]];
		double y = mOscParams[mParams[0]];
		h2->Fill( x, y, z );
	}
}

//=================================================================
// fillSepFitHistograms
//=================================================================
void SensiUtils::fillSepFitHistograms( const TString &file, TH1D *h1 )
{
	assert( mDimension == 1 );
	Double_t NLLmin;
	Long64_t nevents;

	// TChain to retrieve data
	TChain *csepfit = new TChain("SepTree");
	csepfit->Add(file);
 	SepFit *sepfit = new SepFit( csepfit );
	nevents = sepfit->GetEntries();
	NLLmin = getNLLmin( sepfit );

	cout << " ** events " << nevents << " NLLmin " << NLLmin << endl;

	// Loop
	for ( Int_t index = 0; index < nevents; index++)
	{
		sepfit->GetEntry(index);
		ComputeOscPar( *sepfit->Index );
		double y = 2*( *sepfit->NLLtot-NLLmin);
		double x = mOscParams[mParams[0]];
		h1->Fill( x, y );
	}

}


//=================================================================
// getContours
//=================================================================
TObjArray *SensiUtils::getContours( TCanvas *ctemp, TH2D *h )
{
	double contourlines[2]={2.28,4.61};
	//double contourlines[2]={2.3,4.61};
  //double contours[2]={1,2.71};
  h->SetContour(2,contourlines);
  h->Draw("CONT LIST");
	ctemp->Update();
	return (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
}

#endif
