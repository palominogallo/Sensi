#ifndef SEPFIT_CC
#define SEPFIT_CC

#include "SepFit.hh"

SepFit::SepFit( TTree *tree  ):
	NLLtot( mReader, "NLLtot" ),
	Index( mReader, "Index" )
{
	mReader.SetTree(tree);
	mNevents = mReader.GetEntries( kTRUE );
}

SepFit::~SepFit()
{
}

//=================================================================
//// GetEntry
//=================================================================
Int_t SepFit::GetEntry( Long64_t entry )
{
	return mReader.SetEntry( entry );
}

#endif
