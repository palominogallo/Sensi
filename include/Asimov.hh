#ifndef ASIMOV_HH
#define ASIMOV_HH

//#include <Plot1.hh>
//#include <Utils1.hh>

#include "TTreeReader.h"
#include "TTreeReaderValue.h"

class Asimov
{
	public:
		//! Default Constructor
		Asimov( TTree *tree = NULL );

		//! Destructor
		virtual ~Asimov();

	public:
		TTreeReader mReader;
		Long64_t mNevents;

		// Declaration of leaf types
		TTreeReaderValue<Double_t> AvNLLtot;
		TTreeReaderValue<Int_t> Index;
	
		Int_t GetEntry( Long64_t entry );
		inline Long64_t GetEntries(){ return mNevents; };
};

#endif
