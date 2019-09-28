/**
 * \file Simplified_Gen.h
 *
 * \ingroup Main
 * 
 * \brief Class def header for a class Simplified_Gen
 *
 * @author jiangl
 */

/** \addtogroup Main

    @{*/
#ifndef __MAIN_SIMPLIFIED_GEN_H__
#define __MAIN_SIMPLIFIED_GEN_H__
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
     \class Simplified_Gen
     User defined class Simplified_Gen ... these comments are used to generate
     doxygen documentation!
  */
  class Simplified_Gen{
    
  public:
    
    /// Default constructor
    Simplified_Gen(){}
    
    /// Default destructor
    ~Simplified_Gen(){}
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


    void SetFSIOn(bool v){
          switchon_FSI = v;

    }

    void PrintConfig();
    void DrawProgressBar(double progress, double barWidth);

  private:

    int calOptions = 11;
    double minNeutronEfficiency = 0.0;
    double stepNeutronEfficiency = 0.1;
    DUNENDEventHisto1D * _event_histo_1d;


    TH1D *h_Enu_reso[11];

    std::vector<std::string> ith_neutroneff;

    std::map<std::string, TH2D*> hmap_true_calc_temp;

    double eMin = 0.2;
    double eMax = 8.0;
    double eStep = 0.1;

    std::string filen = "";
    std::string fileoutn = "output_maker.root";
    int _initial_entry = 0; //Entry in tree to begin with    

    int neutrinoFlavor = -1;
    int interactionType = -1;
    std::string i_experiment = "";
   
    std::string kinematicInfoName_string= "kinematicInfo.txt";
    std::ofstream kinematicInfoFile;

    bool switchon_FSI = true;

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

