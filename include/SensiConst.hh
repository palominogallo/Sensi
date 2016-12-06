#ifndef ASIMOVCONST_HH
#define ASIMOVCONST_HH

#include <ROOTinclude.hh>

namespace SensiConst
{
// Oscilation Parameters
// s13		 sin2(2theta13)
// delta   delta_CP
// dm32    Delta m2 32
// s23   	 sin2(theta23)

const Int_t nParam = 6;
enum kParam { kS13, kDelta, kDm32, kS23, kDm32_bar, kS23_bar};
enum kParamih { kDm31, kDm31_bar};

const TString name[nParam] = { "s13", "delta", "dm32", "s23", "dm32_bar", "s23_bar" }; //! name
const TString latex[nParam] = { "sin^{2}(2#theta_{13})", "#delta_{CP}", "#Deltam^{2}_{32}", "sin^{2}(#theta_{23})",
																	"#Delta#bar{m}^{2}_{32}", "sin^{2}(#bar{#theta}_{23})" }; //! latex name
const TString latexih[2] = { "#Deltam^{2}_{31}", "#Delta#bar{m}^{2}_{31}" }; //! latex name

const Int_t nbins[nParam] = {  81, 51, 21, 81, 21, 81 };  //! Number of grid points for each parameter
const Double_t stValue[nParam] = {-0.005, -3.2028, 0.001975, 0.246875, 0.001765, 0.246875 }; //! First value on the grid
const Double_t ltValue[nParam] = { 0.805,  3.2028, 0.003025, 0.753125, 0.003235, 0.753125 }; //! Last value on the grid

const Int_t nbinsFC[nParam]={ 81, 51,6,5,101,51};  // FC NuMu16
const Double_t stValueFC[nParam]={-0.005, -3.2028, 0.0023-0.00005, 0.40-0.03125, 0.001765, 0.246875};   //First value on the grid
const Double_t ltValueFC[nParam]={ 0.805,  3.2028, 0.0028+0.00005, 0.65+0.03125, 0.003235, 0.753125};

const Double_t refValues[nParam] = {0.085,0.0,2.44e-3,0.511,2.44e-3,0.511};  //! Default value of oscillation parameters

const Int_t nNuFlav = 5;
const TString NuFlavName[nNuFlav] = {"nue_sig", "numu", "numubar", "nue", "nuebar"};
const TString NuFlavLatex[nNuFlav] = { "#nu_{e}", "#nu_{#mu}", "#bar{#nu}_{#mu}", "#nu_{e}", "#bar{#nu}_{e}"};

const Float_t Dm21 = 7.53*pow(10,-5);

const TString run16latex = "Run16(#nu)+Run56(#bar{#nu})";
const TString run16name  = "r16numu_r56numubar";
const TString run17latex = "Run17(#nu)+Run57(#bar{#nu})";
const TString run17name  = "r17numu_r57numubar";
const TString run17clatex = "Run17c(#nu)+Run57(#bar{#nu})";
const TString run17cname  = "r17cnumu_r57numubar";
}

#endif
