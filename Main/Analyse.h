/**
 * \file Analyse.h
 *
 * \ingroup Main
 * 
 * \brief Class def header for a class Analyse
 *
 * @author jiangl
 */

/** \addtogroup Main

    @{*/
#ifndef __MAIN_ANALYSE_H__
#define __MAIN_ANALYSE_H__

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
#include <TH2Poly.h>
#include <TFile.h>


#include "../Base/MigrationMatrixCalc.h"

#include "../Base/DUNENDEventHisto1D.h"

using namespace Base;

namespace Main {

  /**
     \class Analyse
     User defined class Analyse ... these comments are used to generate
     doxygen documentation!
  */
  class Analyse{
    
  public:
    
    /// Default constructor
    Analyse(){}
    
    /// Default destructor
    ~Analyse(){}
  
    void SetInputFile(std::string f);
    void DoAnalyse();
  private:
    std::string mc_inputfile_name = "";
    const int calOptions = 11;
    int n_bins_temp=-999;
   
  };
}

#endif
/** @} */ // end of doxygen group 

