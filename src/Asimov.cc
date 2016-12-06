#ifndef ASIMOV_CC
#define ASIMOV_CC

#include "Asimov.hh"

Asimov::Asimov( TTree *tree  ):
	AvNLLtot( mReader, "AvNLLtot" ),
	Index( mReader, "Index" )
{
	mReader.SetTree(tree);
	mNevents = mReader.GetEntries( kTRUE );
}

Asimov::~Asimov()
{
}

//=================================================================
//// GetEntry
//=================================================================
Int_t Asimov::GetEntry( Long64_t entry )
{
	return mReader.SetEntry( entry );
}

#endif
