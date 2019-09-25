#ifndef __MAIN_SIMPLIFIED_GEN_CXX__
#define __MAIN_SIMPLIFIED_GEN_CXX__

#include "Simplified_Gen.h"

#include <TArray2D.h>
#include <TArray3D.h>
using namespace std;
using namespace Base;

void Main::Simplified_Gen::SetInputFile(std::string in)
{
  filen = in;
}
void Main::Simplified_Gen::SetOutputFile(std::string in)
{
  fileoutn = in;
}
void Main::Simplified_Gen::PrintConfig()
{
  //LOG_INFO()<<"____Main::Simplified_Gen::PrintConfig"<<std::endl;

}
void Main::Simplified_Gen::DrawProgressBar(double progress, double barWidth){
  std::cout<<"[";
  int pos = barWidth * progress;
  for (int i=0; i< barWidth; i++){
     if(i<pos) std::cout<<"=";
     else if(i == pos) std::cout << ">";
     else std::cout<<" ";
  }
  std::cout << "] " << int(progress * 100.0) << " %\r";
  std::cout.flush();
}

void Main::Simplified_Gen::MakeFile(){


  TFile *file_out = new TFile(fileoutn.c_str(), "RECREATE");
  if ( file_out -> IsOpen() ){
    //LOG_NORMAL()>>" File Opened Successfully. "<<std::endl;
    std::cout <<" File Opened Successfully. "<<std::endl;
  } else {
    //LOG_CRITICAL() <<"File not Opened (maybe not found. File:"<<fileoutn<<std::endl;
    std::cout <<"File not Opened (maybe not found. File:"<<fileoutn<<std::endl;
    exit(0);
  }


  for(int i=0; i<calOptions; i++){
          h_Enu_reso[i]=new TH1D(Form("h_Enu_reso_%d", i), Form("h_Enu_reso_%d", i), 60, -0.1, 0.3);
          h_Enu_reso[i]->GetXaxis()->SetTitle("Fractional Resolution of E_{#mu}");
          h_Enu_reso[i]->GetYaxis()->SetTitle("Nevents");
  }
 
  


  std::string pattern = filen;
  
  TChain *chain_nuprism;
  chain_nuprism = new TChain ("gst");
  chain_nuprism->Add(pattern.c_str());
  int evts = chain_nuprism -> GetEntries();
  int barWidth = 70;
  std::cout<<"[Simplified_Gen]<<<<<Number of events used is: "<<evts<<std::endl;

  GENIEEventHisto *t=new GENIEEventHisto(chain_nuprism);

  _event_histo_1d = new DUNENDEventHisto1D();
  _event_histo_1d->InitializeBootstraps();

    
    int finalParticleNumber(0);
    double trueNuEnergy(0.0), leptonEnergy(0.0);
    double recNuEnergy_cal[calOptions];

    int eventCnt_cal[calOptions];

    


    for ( int kCnt(0); kCnt < calOptions; ++kCnt )
    {
        eventCnt_cal[kCnt] = 0;

        recNuEnergy_cal[kCnt] = 0.0;
    }

    double neutronEnergy(0.0);

    int eventCnt(0);

    ///loop over all entries in the GENIE trees
    //for (int iCnt = 49992; iCnt < 49993; iCnt++)
    for (int iCnt = 0; iCnt < chain_nuprism->GetEntries(); ++iCnt)
    {
        chain_nuprism->GetEntry(iCnt);
        //TArray3D<double>& CalMatrix(0, 0, 0);
        //if(iCnt != 49892) continue;

        // selection interaction type here
        if(interactionType == 1 && t->qel !=1) {continue;}
        if(interactionType == 2 && t->res !=1) {continue;}
        if(interactionType == 3 && t->dis !=1) {continue;}
        if(interactionType == 4 && t->mec !=1) {continue;}
        if(interactionType == 5 && t->coh !=1) {continue;}



        double nuEnergy = t->Ev;
        const int nx = round( (nuEnergy - eMin)/eStep); 

    
        finalParticleNumber = t->nf;
        trueNuEnergy  = t->Ev;
        leptonEnergy = t->El;


 
        if (finalParticleNumber < 0)
            continue;

        for (int jCnt(0); jCnt < calOptions; ++jCnt) {
            recNuEnergy_cal[jCnt] = leptonEnergy;
        }

    	double calorimetricContribution[calOptions];

    	for ( int kCnt(0); kCnt < calOptions; ++kCnt ) {
        	calorimetricContribution[kCnt] = 0.0;
        }
        ///till the whole event is read, it is not clear if we are going to keep it,
        ///so the calorimetric contribution cannot be immediately added to calculate the reconstructed energy

        


        int  heavyBaryon_app = 0; 


        for (int finalPartCnt=0; finalPartCnt < finalParticleNumber; ++finalPartCnt)
        {  //std::cout<<"<<<<<<<<<<<<<<<<<PDG code is "<<t->pdgf[finalPartCnt] <<std::endl;

           ///calculate invariant mass here
	    double invariantMass = sqrt( t->Ef[finalPartCnt]*t->Ef[finalPartCnt] - 
					t->pxf[finalPartCnt]*t->pxf[finalPartCnt] - 
					t->pyf[finalPartCnt]*t->pyf[finalPartCnt] - 
					t->pzf[finalPartCnt]*t->pzf[finalPartCnt] );
        
            ///make sure that there are no nuclear remnants here!!!
            
            ///protons
            if ( t->pdgf[finalPartCnt] == 2212 )
            {   //std::cout<<"[Simplified_Gen] << Oooooooooops find a proton ! "<<"Energy is "<<t->Ef[finalPartCnt]<<"  pMass= "<<pMass<<std::endl;
                for ( int kCnt(0); kCnt < calOptions; ++kCnt ) {
        		calorimetricContribution[kCnt] += t->Ef[finalPartCnt] - pMass; 
        		//calorimetricContribution[kCnt] += t->Ef[finalPartCnt] - invariantMass; 
                }

            }
            //std::cout<<"test::::calorimetricContribution is "<<calorimetricContribution[0]<<std::endl;
            ///antiprotons
            ///if you have an antiproton, one of the protons was produced and not knocked out
            ///so it should be treated differently above
            ///here we correct its treatment adding its mass here
            ///a produced pair contributes 2 total energies, for the proton we already added the kinetic energy above,
            ///so for antiproton we add the total energy, plus the proton mass
            else if ( t->pdgf[finalPartCnt] == -2212 )
            {   //std::cout<<"[Simplified_Gen] << Oooooooooops find an anti-proton ! "<<std::endl; 
                for ( int kCnt(0); kCnt < calOptions; ++kCnt ) {
                        calorimetricContribution[kCnt] += t->Ef[finalPartCnt] + pMass;
        		//calorimetricContribution[kCnt] += t->Ef[finalPartCnt] + invariantMass; 
		}
            }

            else if ( t->pdgf[finalPartCnt] == 2112 )
            {    std::cout<<"[Simplified_Gen] << Oooooooooops find a neutron ! "<<std::endl; 
                for ( int kCnt(0); kCnt < calOptions; ++kCnt ) {
                    calorimetricContribution[kCnt] += (minNeutronEfficiency + kCnt*stepNeutronEfficiency)*(t->Ef[finalPartCnt] - nMass);
                    //calorimetricContribution[kCnt] += (minNeutronEfficiency + kCnt*stepNeutronEfficiency)*(t->Ef[finalPartCnt] - invariantMass);
                }
                neutronEnergy += t->Ef[finalPartCnt] - nMass;
                
            }

            ///antineutrons, same story as for protons
            else if ( t->pdgf[finalPartCnt] == -2112 )
            {    std::cout<<"[Simplified_Gen] << Oooooooooops find an anti-neutron ! "<<std::endl;  
                for ( int kCnt(0); kCnt < calOptions; ++kCnt ){
                    calorimetricContribution[kCnt] += (minNeutronEfficiency + kCnt*stepNeutronEfficiency)*(t->Ef[finalPartCnt] + nMass);
                    //calorimetricContribution[kCnt] += (minNeutronEfficiency + kCnt*stepNeutronEfficiency)*(t->Ef[finalPartCnt] + invariantMass);
                }
                neutronEnergy += t->Ef[finalPartCnt] + nMass;
            }


            ///heavy baryon
            else if ( abs(t->pdgf[finalPartCnt]) == 3122 || abs(t->pdgf[finalPartCnt]) == 3222 
                   || abs(t->pdgf[finalPartCnt]) == 3212 || abs(t->pdgf[finalPartCnt]) == 3112 
	           || abs(t->pdgf[finalPartCnt]) == 3224 || abs(t->pdgf[finalPartCnt]) == 3214 
                   || abs(t->pdgf[finalPartCnt]) == 3114 || abs(t->pdgf[finalPartCnt]) == 3322 
                   || abs(t->pdgf[finalPartCnt]) == 3312 || abs(t->pdgf[finalPartCnt]) == 3324 
                   || abs(t->pdgf[finalPartCnt]) == 3314 || abs(t->pdgf[finalPartCnt]) == 3334 
                   || abs(t->pdgf[finalPartCnt]) == 4122 || abs(t->pdgf[finalPartCnt]) == 4222
                   || abs(t->pdgf[finalPartCnt]) == 4212 || abs(t->pdgf[finalPartCnt]) == 4112
                   || abs(t->pdgf[finalPartCnt]) > 10e5
                   )
            {
                std::cout<<"Heavy baryon found. Should not be here!"<<std::endl;
                heavyBaryon_app ++;
                continue;
            }

            ///for pions, photons etc. add the total energy
            else {
                for ( int kCnt(0); kCnt < calOptions; ++kCnt ){
                    calorimetricContribution[kCnt] += t->Ef[finalPartCnt];
                }
            } 

        }
        if(heavyBaryon_app > 0) {continue;}

        for (int mCnt(0); mCnt < calOptions; ++mCnt) {
                    recNuEnergy_cal[mCnt] += calorimetricContribution[mCnt];
                    

                    if(mCnt== calOptions -1 && -(recNuEnergy_cal[mCnt] - trueNuEnergy) > 0.5) {continue;}
                     _event_histo_1d->h_true_calc_Enu[mCnt]->Fill(trueNuEnergy, recNuEnergy_cal[mCnt]);
                     h_Enu_reso[mCnt]->Fill((trueNuEnergy - recNuEnergy_cal[mCnt])/trueNuEnergy);
        }



        ++eventCnt;








    } //end of loop over all the entris





  file_out->cd();
  file_out->WriteObject(_event_histo_1d, "DUNENDEventHisto1D");


  file_out->Write();
  file_out->Close();













}  //end of member function MakeFile















#endif
