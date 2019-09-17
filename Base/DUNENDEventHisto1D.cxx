#ifndef __BASE_DUNENDEVENTHISTO1D_CXX__
#define __BASE_DUNENDEVENTHISTO1D_CXX__

#include "DUNENDEventHisto1D.h"

namespace Base {

   void DUNENDEventHisto1D::InitializeBootstraps()
   {
      h_Enu = new TH1D("h_Enu", "h_Enu", 100, 0.0, 10.0);
      h_Evis = new TH1D("h_Evis", "h_Evis", 100, 0.0, 10.0);
      h_Enu_CCQE = new TH1D("h_Enu_CCQE", "h_Enu_CCQE", 100, 0.0, 10.0);
      h_Enu_CCRES = new TH1D("h_Enu_CCRES", "h_Enu_CCRES", 100, 0.0, 10.0);
      h_Enu_CCDIS = new TH1D("h_Enu_CCDIS", "h_Enu_CCDIS", 100, 0.0, 10.0);
      h_Enu_CCMEC = new TH1D("h_Enu_CCMEC", "h_Enu_CCMEC", 100, 0.0, 10.0);

      for(int i=0; i<calOptions; i++){
          h_true_calc_Enu[i]=new TH2D(Form("h_true_calc_Enu_%d", i), Form("h_true_calc_Enu_%d", i), 78, 0.2, 8.0, 78, 0.2,8.0);
          h_true_calc_Enu[i]->GetYaxis()->SetTitle("Calculated E_{#nu}[GeV]");
          h_true_calc_Enu[i]->GetXaxis()->SetTitle("True E_{#nu}[GeV]");
      }
      h_muon_reso = new TH1D("h_muon_reso", "h_muon_reso", 50, -0.3, 0.3);
      h_proton_reso = new TH1D("h_proton_reso", "h_proton_reso", 50, -0.5, 0.5);
      h_neutron_reso = new TH1D("h_neutron_reso", "h_neutron_reso", 50, -0.3, 0.3);
      h_pionC_reso = new TH1D("h_pionC_reso", "h_pionC_reso", 50, -0.3, 0.3);
      h_pionZero_reso = new TH1D("h_pionZero_reso", "h_pionZero_reso", 50, -0.3, 0.3);
      h_kaonC_reso = new TH1D("h_kaonC_reso", "h_kaonC_reso", 50, -0.3, 0.3);
      h_kaonZero_reso = new TH1D("h_kaonZero_reso", "h_kaonZero_reso", 50, -0.3, 0.3);
  

   }
}





#endif
