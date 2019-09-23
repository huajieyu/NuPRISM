/**
 * \file DUNENDEventHisto1D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class DUNENDEventHisto1D
 *
 * @author jiangl
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_DUNENDEVENTHISTO1D_H__
#define __BASE_DUNENDEVENTHISTO1D_H__

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

#include <TChain.h>
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include <TString.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TCanvas.h>
#include <TFile.h>
#include "TH2Poly.h"



namespace Base {

  /**
     \class DUNENDEventHisto1D
     User defined class DUNENDEventHisto1D ... these comments are used to generate
     doxygen documentation!
  */
  class DUNENDEventHisto1D{
    
  public:
    
    /// Default constructor
    DUNENDEventHisto1D(){}
    
    /// Default destructor
    ~DUNENDEventHisto1D(){}



    //Initialize the histograms here
    void InitializeBootstraps();


    TH1D *h_Evis=0;
    TH1D *h_Enu=0;
    TH1D *h_Enu_CCQE=0;
    TH1D *h_Enu_CCRES=0;
    TH1D *h_Enu_CCDIS=0; 
    TH1D *h_Enu_CCMEC=0;
    int calOptions = 11;
    TH2D *h_true_calc_Enu[11];
    TH1D *h_muon_reso;
    TH1D *h_proton_reso;
    TH1D *h_neutron_reso;
    TH1D *h_pionZero_reso;
    TH1D *h_pionC_reso;
    TH1D *h_kaonZero_reso;
    TH1D *h_kaonC_reso;


  protected:


    
  };
}

#endif
/** @} */ // end of doxygen group 

