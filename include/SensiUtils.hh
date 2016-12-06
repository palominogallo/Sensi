#ifndef ASIMOVUTILS_HH
#define ASIMOVUTILS_HH

#include "Asimov.hh"
#include "SepFit.hh"
#include "FC.hh"
#include "SensiConst.hh"

using namespace SensiConst;

class SensiUtils
{
	public:
		//! Default Constructor
		SensiUtils();

		//! Default Constructor
		SensiUtils( Int_t *UsedPar );

		//! Destructor
		virtual ~SensiUtils();

	public:
		Int_t mUsedPar[nParam];
		Double_t mOscParams[nParam];
		Int_t mParams[2];
		TString mtreeName;
		Int_t mDimension;

		void ComputeOscPar( int index, bool FC=false );
		TTree  *fillFCTree( const TString &file, TH2D *h, double xval, double yval, double& critical );
		void fillAsimovHistograms( const TString &file, TH2D *h2, TMarker *m );
		void fillSepFitHistograms( const TString &file, TH2D *h2, TMarker *m );
		void fillSepChi2Histograms( const TString &file, TH2D *h2 );
		void fillSepFitHistograms( const TString &file, TH1D *h1 );
		Double_t getNLLmin( Asimov *t);
		Double_t getNLLmin( SepFit *t);
		static TObjArray *getContours( TCanvas *ctemp, TH2D *h );

		inline Int_t GetDimension(){ return mDimension; };
		inline Int_t GetParamIndex(int i){ return mParams[i]; };
		inline Double_t GetOscParam(int i){ return mOscParams[i]; };
};

#endif
