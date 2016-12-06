#ifndef SEPFIT_HH
#define SEPFIT_HH

//#include <Plot1.hh>
//#include <Utils1.hh>

#include "TTreeReader.h"
#include "TTreeReaderValue.h"

class SepFit
{
	public:
		//! Default Constructor
		SepFit( TTree *tree = NULL );

		//! Destructor
		virtual ~SepFit();

	public:
		TTreeReader mReader;
		Long64_t mNevents;

		// Declaration of leaf types
		TTreeReaderValue<Double_t> NLLtot;
		TTreeReaderValue<Int_t> Index;
	
		Int_t GetEntry( Long64_t entry );
		inline Long64_t GetEntries(){ return mNevents; };
};

#endif
