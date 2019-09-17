/**
 * \file MigrationMatrixCalc.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class MigrationMatrixCalc
 *
 * @author jiangl
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_MIGRATIONMATRIXCALC_H__
#define __BASE_MIGRATIONMATRIXCALC_H__

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <map>
#include <time.h>

#include <TSystem.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TRandom1.h>
#include <TSystem.h>
#include <TBrowser.h>
#include <TApplication.h>
#include <TChain.h>
#include "TThread.h"
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"
#include "TGraph.h"
#include <TString.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TMath.h>
#include "Math/SMatrix.h"
#include "TMatrix.h"
#include "TLine.h"
#include "TGaxis.h"
#include "TMatrix.h"

#include "Types.h"
//#include "LoggerFeature.h"


namespace Base {

  /**
     \class MigrationMatrixCalc
     User defined class MigrationMatrixCalc ... these comments are used to generate
     doxygen documentation!
  */
  class MigrationMatrixCalc{
    
  public:
    
    /// Default constructor
    MigrationMatrixCalc(){}
    
    /// Default destructor
    ~MigrationMatrixCalc(){}
		
    ///
    TMatrix CalculateMigrationMatrix();

    void SetTrueRecoHistogram(TH2D *h);

    void SetNBins(int n_var1_bins, int n_var2_bins);

    void SetOutputFileName(std::string name);

    void SetOutFir(std::string dir);

    void PrintSmearingMatrixLatex();

    void PlotMatrix();
  private:

    std::string _name= "[MigrationMatrix2D]";
    int _n, _m;
    TH2D *_h_true_reco_mom;
    TMatrix _S; //The smearing matrix
    std::ofstream _f_out; // the output file
    std::string _outdir = "";
    std::string _folder = "MigrationMatrix2DPlots/";
    bool _verbose = false;

    
  };
}

#endif
/** @} */ // end of doxygen group 

