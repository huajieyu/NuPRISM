/**
 * \file Maker.h
 *
 * \ingroup Main
 * 
 * \brief Class def header for a class Maker
 *
 * @author jiangl
 */

/** \addtogroup Main

    @{*/
#ifndef __MAIN_MAKER_H__
#define __MAIN_MAKER_H__
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <fstream>
#include <math.h>
#include <algorithm>

#include <TRandom1.h>
#include <TSystem.h>
#include <TBrowser.h>
#include <TApplication.h>
#include <TChain.h>
#include "TThread.h"
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include <TString.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TCanvas.h>
#include "TMath.h"
#include "TH2Poly.h"

//#include "include/"
//#include "include/"
//#include "include/"

#include "GENIEEventHisto.h"
#include "../Base/DUNENDEventHisto1D.h"
#include "../Base/CDetectorEffects.h"


using namespace Base;
namespace Main {

  /**
     \class Maker
     User defined class Maker ... these comments are used to generate
     doxygen documentation!
  */
  class Maker{
    
  public:
    
    /// Default constructor
    Maker(){}
    
    /// Default destructor
    ~Maker(){}

    void MakeFile();
    void SetInputFile(std::string);
    void SetOutputFile(std::string);

    void SetNeutrinoFlavor(int flavorid){
        neutrinoFlavor = flavorid;
    };
    void SetInteractionType(int interid){
        interactionType = interid;
    }
    void SetExperimentName (std::string expname){
        i_experiment = expname;    
    }

    void SetKinematicInfoFileName(std::string kinematicinfo_filename){
        kinematicInfoName_string =  kinematicinfo_filename;    
    }


    void switchFSI(bool);

    void PrintConfig();
    void DrawProgressBar(double progress, double barWidth);




  private:
    DUNENDEventHisto1D * _event_histo_1d;


    std::string filen = "";
    std::string fileoutn = "output_maker.root";
    int _initial_entry = 0; //Entry in tree to begin with    

    int neutrinoFlavor = -1;
    int interactionType = -1;
    std::string i_experiment = "";
   
    std::string kinematicInfoName_string= "kinematicInfo.txt";
    std::ofstream kinematicInfoFile;

    bool FSI_on = false;

    const double GeV = 1.0;
    const double MeV = 0.001*GeV;


    const double eMass =      0.510998928*MeV ;///electron mass
    const double muMass =   105.6583715*MeV ;///muon mass
    const double pMass =  938.272046*MeV ;///proton mass
    const double nMass =  939.565379*MeV ;///neutron mass
    const double piCMass =  139.57018*MeV ;///charged pion mass
    const double pi0Mass =  134.9766*MeV ;///neutral pion mass
    const double kaonCMass =   493.677*MeV ;///charged kaon mass
    const double kaon0Mass =   497.614*MeV ;///neutral kaon mass
    const double deltaMass =   1232*MeV ;///delta mass


    const double eMassSq =  eMass*eMass ;///electron mass squared
    const double muMassSq =  muMass*muMass ;///muon mass squared
    const double pMassSq =  pMass*pMass ;///proton mass squared
    const double nMassSq =  nMass*nMass ;///neutron mass squared
    const double piCMassSq =  piCMass*piCMass ;///charged pion mass squared
    const double pi0MassSq =  pi0Mass*pi0Mass ;///neutral pion mass squared
    const double kaonCMassSq =  kaonCMass*kaonCMass ;///charged kaon mass squared
    const double kaon0MassSq =  kaon0Mass*kaon0Mass ;///neutral kaon mass squared
    const double deltaMassSq =  deltaMass*deltaMass ;///delta mass squared




    const double accuracy =  0.001*MeV;

    const double averagePT = 0*MeV;///maximal transverse momentum allowed to be interpreted as coming from the Fermi motion
    const double maxInitMom = 265*MeV ;///cut of the high-momentum componet of the spectral function

    const double ProtonBinding = 1.0*MeV; // binding energy
    const double NeutronBinding = 13.0*MeV;// binding energy


    //const double ProtonBinding = 3.0*MeV; // binding energy
    //const double NeutronBinding = 14.0*MeV;// binding energy
    //const double ProtonBinding = 2.6*MeV; // binding energy
    //const double NeutronBinding = 15.3*MeV;// binding energy

    enum ExperimentName
    {
        PerfectReconstruction_neutronsDetected,
        PerfectReconstruction_neutronsUndetected,
        OurSetup_neutronsDetected,
        OurSetup_neutronsUndetected,
        DUNE_FastMC
    };

    int get_leptonPDG(int code){
         int leptonPDG= 0.0;
         if(code == 14)  {leptonPDG = 13;}
         if(code == -14)  {leptonPDG = -13;}
         if(code == 12)  {leptonPDG = 11;}
         if(code == -12)  {leptonPDG = -11;}
         return leptonPDG;

    }

    enum EventType
    {
         oneTrack,
         multiTrack,
         allEvents
    };

   

  };
}



#endif
/** @} */ // end of doxygen group 

