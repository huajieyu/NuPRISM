#ifndef __MAIN_MAKER_CXX__
#define __MAIN_MAKER_CXX__

#include "Maker.h"
#include <TArray2D.h>
#include <TArray3D.h>
using namespace std;
using namespace Base;

void Main::Maker::SetInputFile(std::string in)
{
  filen = in;
}
void Main::Maker::SetOutputFile(std::string in)
{
  fileoutn = in;
}
void Main::Maker::PrintConfig()
{
  //LOG_INFO()<<"____Main::Maker::PrintConfig"<<std::endl;

}
void Main::Maker::DrawProgressBar(double progress, double barWidth){
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


void Main::Maker::MakeFile()
{
  clock_t begin = clock();
  system("mkdir -p output/");
  //========================================================================
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine("gErrorIgnoreLevel = 2001;"); //1001 INFO, 2001:WARNING, 3001:ERROR

  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  TH1D* histo_Enu;
  TH1D* histo_Enu_CCQE;
  TH1D* histo_Enu_CCRES;
  TH1D* histo_Enu_CCDIS;
  TH1D* histo_Enu_CCMEC;
  TH1D* histo_Evis;
  TH1D* histo_Evis_noFSI;

  TH1D* histo_Fermi_mom;

  //initialize histograms of Enu and Evis
  histo_Enu = new TH1D("histo_Enu", "histo_Enu", 100, 0.0, 10.0);
  histo_Evis = new TH1D("histo_Evis", "histo_Evis", 100, 0.0, 10.0);
  histo_Enu_CCQE = new TH1D("histo_Enu_CCQE", "histo_Enu_CCQE", 100, 0.0, 10.0);
  histo_Enu_CCRES = new TH1D("histo_Enu_CCRES", "histo_Enu_CCRES", 100, 0.0, 10.0);
  histo_Enu_CCDIS = new TH1D("histo_Enu_CCDIS", "histo_Enu_CCDIS", 100, 0.0, 10.0);
  histo_Enu_CCMEC = new TH1D("histo_Enu_CCMEC", "histo_Enu_CCMEC", 100, 0.0, 10.0);
  histo_Evis_noFSI = new TH1D("histo_Evis_noFSI", "histo_Evis_noFSI", 100, 0.0, 10.0);
  
  histo_Fermi_mom = new TH1D("histo_Fermi_mom", "histo_Fermi_mom", 100, 0.0, 0.8);


  TFile *file_out = new TFile(fileoutn.c_str(), "RECREATE");
  if ( file_out -> IsOpen() ){
    //LOG_NORMAL()>>" File Opened Successfully. "<<std::endl;
    std::cout <<" File Opened Successfully. "<<std::endl;
  } else {
    //LOG_CRITICAL() <<"File not Opened (maybe not found. File:"<<fileoutn<<std::endl;
    std::cout <<"File not Opened (maybe not found. File:"<<fileoutn<<std::endl;
    exit(0);
  }
  std::string pattern = filen;
  
  TChain *chain_nuprism;
  chain_nuprism = new TChain ("gst");
  chain_nuprism->Add(pattern.c_str());
  int evts = chain_nuprism -> GetEntries();
  int barWidth = 70;
  std::cout<<"Number of events used is: "<<evts<<std::endl;

  GENIEEventHisto *t=new GENIEEventHisto(chain_nuprism);

  _event_histo_1d = new DUNENDEventHisto1D();
  _event_histo_1d->InitializeBootstraps();



  //neutrinoFlavor, interactionType, experiment


  const EventType event(allEvents);

  //set the minimum value, maxmum value and bin steps of the migration matrix
  const double eMin = 0.2*GeV;
  const double eMax = 8.0*GeV;
   
  const double eStep = 50.0 * MeV;

  const int eRes ( static_cast<int> ( (eMax - eMin)/eStep) + 1 ); //total number of bins
  
  const int calOptions = 5;
  //declare the 2D array, and 3D matrix with the calOptions
  //5 calOptions with different fraction of neutron detected
  TArray2D <double>KinMatrix(eRes, eRes, 0.0);
  TArray3D <double>CalMatrix(calOptions, eRes, eRes, 0.0);


  //eRes =  KinMatrix.get_x();
  //calOptions =  CalMatrix.get_x() ;
  
  int finalParticleNumber = 0.0;
  double trueNuEnergy = 0.0;
  double leptonEnergy = 0.0;
  double leptonMomentum_x(0.0), leptonMomentum_y(0.0), leptonMomentum_z(0.0);
  //recoil nucleus kinetic energy and calculated kinetic energy
  double recNuEnergy_kin(0.0);
  double recNuEnergy_cal[calOptions];

  int eventCnt = 0;
  int eventCnt_kin = 0;
  int eventCnt_cal[calOptions];

  double missingEnergy[calOptions];
  //initialize the number of events of each caloptions 
  for ( int kCnt(0); kCnt < calOptions; ++kCnt )
  {
        eventCnt_cal[kCnt] = 0;

        recNuEnergy_cal[kCnt] = 0.0;
        missingEnergy[kCnt] = 0.0;
  }


  int piZMultiplicity(0);
  int piCMultiplicity(0);
  int kaonZMultiplicity(0);
  int kaonCMultiplicity(0);
  int neutronMultiplicity(0);
  int protonMultiplicity(0);

  int missingPiZMultiplicity(0);
  int missingPiCMultiplicity(0);
  int missingKaonZMultiplicity(0);
  int missingKaonCMultiplicity(0);
  int missingNeutronMultiplicity(0);
  int missingProtonMultiplicity(0);

  double missingPiZEnergy(0.0);
  double missingPiCEnergy(0.0);
  double missingKaonZEnergy(0.0);
  double missingKaonCEnergy(0.0);
  double missingNeutronEnergy(0.0);
  double missingProtonEnergy(0.0);

  double missingSigmaEnergy(0.0);
  double missingOtherPartEnergy(0.0);

  double missingTransverseMomentum(0.0);

  ///set the charged lepton's mass
  //const double leptMass(   (neutrinoFlavor == 0 or neutrinoFlavor == 1) ? muMass : eMass );
  const double leptMassSq( (neutrinoFlavor == 0 or neutrinoFlavor == 1) ? muMassSq : eMassSq );
    
  ///for neutrinos M - epsilon = m_neutron - epsilon, for antineutrinos M - epsilon = m_proton - epsilon
  ///for delta, assumed to be the same, for simplicity
  const double iNuclMassTilde(   (neutrinoFlavor == 0 or neutrinoFlavor == 2) ? nMass - NeutronBinding : pMass - ProtonBinding );
    
  ///for QE and MEC select neutron or proton mass
  const double fNuclMassSq(   (neutrinoFlavor == 0 or neutrinoFlavor == 2) ? pMassSq : nMassSq   );
    
  const double deltaConst_QE( fNuclMassSq - iNuclMassTilde*iNuclMassTilde - leptMassSq );
  const double deltaConst_res( deltaMassSq - iNuclMassTilde*iNuclMassTilde - leptMassSq );



  std::cout<<"Start Looping over all the selected events "<<std::endl;
  //loop over all the events
  //for(int iCnt= _initial_entry; iCnt<100; iCnt++){
  //for(int iCnt= 1; iCnt<2; iCnt++){
  //for(int iCnt= 33; iCnt<34; iCnt++){
  //for(int iCnt= 33; iCnt<34; iCnt++){
  //for(int iCnt= 47; iCnt<48; iCnt++){
  //for(int iCnt= 2274; iCnt<2275; iCnt++){
  for(int iCnt = _initial_entry; iCnt<evts; iCnt++){
	if (iCnt != 0) DrawProgressBar((double)iCnt/(double)evts, barWidth);
	chain_nuprism->GetEntry(iCnt);

	std::cout<<"[Main::Maker] Fill Histograms of Enu, Fermi Momentum"<<std::endl;

	histo_Enu->Fill(t->Ev);
	_event_histo_1d->h_Enu->Fill(t->Ev);
     
        
	histo_Fermi_mom->Fill(TMath::Sqrt(t->pxn*t->pxn+t->pyn*t->pyn+t->pzn*t->pzn));
	if(t->cc == 1 && t->qel == 1){
           _event_histo_1d->h_Enu_CCQE->Fill(t->Ev);
                        histo_Enu_CCQE->Fill(t->Ev);
	}
	if(t->cc == 1 && t->res == 1){
           _event_histo_1d->h_Enu_CCRES->Fill(t->Ev);
                        histo_Enu_CCRES->Fill(t->Ev);
	}
	if(t->cc == 1 && t->dis == 1){
           _event_histo_1d->h_Enu_CCDIS->Fill(t->Ev);
                        histo_Enu_CCDIS->Fill(t->Ev);
	}
	if(t->cc == 1 && t->mec == 1){
           _event_histo_1d->h_Enu_CCMEC->Fill(t->Ev);
                        histo_Enu_CCMEC->Fill(t->Ev);
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


        
	CRandomGen rnd;
 	CDetectorEffects detector;   
        //get the neutrino energy, number of different kind of particles 
	double nuEnergy= t->Ev;
        std::cout<<"[Main::Maker] The incoming neutrino's true energy is "<<nuEnergy<<std::endl;
        if(t->nfkp>0){  //print nfkp number of kaon plus
        std::cout<<"[Main::Maker] The Number of charged kaon+ is "<<t->nfkp<<"  iCnt = "<<iCnt<<std::endl; 
        }else if(t->nfkm>0){ //print nfkm number of kaon minus
        std::cout<<"[Main::Maker] The Number of charged kaon- is "<<t->nfkm<<"  iCnt = "<<iCnt<<std::endl; 
        }else if(t->nfk0>0){ //print nfko number of neutral kaons
        std::cout<<"[Main::Maker] The Number of charged kaon0 is "<<t->nfk0<<"  iCnt = "<<iCnt<<std::endl; 
        } 
        

        //Get the bin number of a certain event

	const int nx(   static_cast<int>( (nuEnergy - eMin)/eStep )   );
 	//eRes > the value in Base/DUNENDEventHist.cxx
	if ( nx > eRes )
	{
        std::cerr<<"The energy "<<nuEnergy<<" exceeds the considered maximal value!"<<std::endl;
        continue;
	}
  

	//const int intEnergy( static_cast<int>(nuEnergy/MeV) );
	//const int eng( std::abs(intEnergy - nuEnergy/MeV) < 0.5 ? intEnergy : intEnergy + 1 );
	//set the minimum and maxmum number of tracks in an event
	const int minAddTrackNumber(   (event == multiTrack) ? 1 : 0   );///minimal number of tracks, in addition to the charged lepton's one
	const int maxAddTrackNumber(   (event == oneTrack) ? 0 : 5   );///maximal number of tracks, in addition to the charged lepton's one   


	

	//get the final state particles and neutrino energy
	finalParticleNumber = t->nf;
	trueNuEnergy  = t->Ev;


     
	//get the leading lepton information
	leptonEnergy = t->El;
	leptonMomentum_x = t->pxl;
	leptonMomentum_y = t->pyl;
	leptonMomentum_z = t->pzl;


	double totalMomentum_x(0.0);
	double totalMomentum_y(0.0);
        //initialize before loop over all the particles in an event
	int missingPiZCnt(0);
	int missingPiCCnt(0);
	int missingKaonZCnt(0);
	int missingKaonCCnt(0);
	int missingNeutronCnt(0);
	int missingProtonCnt(0);

	int kaonZCnt(0);
	int kaonCCnt(0);

	double missingPiZEnContrib(0.0);
	double missingPiCEnContrib(0.0);
	double missingKaonZEnContrib(0.0);
	double missingKaonCEnContrib(0.0);
	double missingNeutronEnContrib(0.0);
	double missingProtonEnContrib(0.0);

	double missingOtherPartEnContrib(0.0);
	double missingSigmaEnContrib(0.0);     

        
	double leptonTrueMomentum( sqrt(leptonMomentum_x*leptonMomentum_x + leptonMomentum_y*leptonMomentum_y + leptonMomentum_z*leptonMomentum_z) );
        //double leptonAgularReosution
        //double leptonMeasuredMomentum 
        //try to get the lepton momentum and angular resotuion from Base::CDetectorEffects::getSigma


	TLorentzVector v4mom;
	v4mom.SetE(leptonEnergy);
	v4mom.SetPx(leptonMomentum_x);
	v4mom.SetPy(leptonMomentum_y);
	v4mom.SetPz(leptonMomentum_z);



	//CDetectorEffects::ExperimentName experiment = PerfectReconstruction_neutronsDetected;
	//CDetectorEffects::ExperimentName experiment = 0;
	//ExperimentName ii_experiment = 0;
	//Get the index of the options
	int ii_experiment = -999;
        if( i_experiment == "PerfectReconstruction_neutronsDetected") {ii_experiment = 0;}
        if( i_experiment == "PerfectReconstruction_neutronsUndetected") {ii_experiment = 1;}
        if( i_experiment == "OurSetup_neutronsDetected") {ii_experiment = 2;}
        if( i_experiment == "OurSetup_neutronsUndetected"){ii_experiment = 3;}
        if( i_experiment == "DUNE_FastMC") {ii_experiment = 4;} 


;
	double m_Res=0.0;
        double m_Eff=0.0;
	double m_Sigma=0.0;
	double m_Momentum=0.0;
        //deal with the lepton first, get the sigma and resolution
	int leptonPDG = get_leptonPDG(t->neu);
     
	detector.CDetectorEffects_getSigma(&leptonPDG, &v4mom, ii_experiment, &m_Res, &m_Eff,  &m_Sigma, &m_Momentum); 


	//get the lepton momentum and angular resolution

	//double leptonAngularResolution =  (neutrinoFlavor == 0 or neutrinoFlavor == 1) ? detector.get_angularResolution_muon()
	//                                                                                : detector.get_angularResolution_electron();

	//double leptonMeasuredMomentum =  (neutrinoFlavor == 0 or neutrinoFlavor == 1) ? detector.find_muonMeasuredMomentum(leptonTrueMomentum)                                         
	//                                                                               : detector.find_electronMeasuredMomentum(leptonTrueMomentum);
	double leptonSigma = m_Sigma;
	double leptonAngularResolution = m_Res;
	double leptonMeasuredMomentum = m_Momentum; 

	//Finally got the sigma angular resoltuion and measuredmomentum ~~~~~~~~~~~~~~~~~

	///smear the vector of the momentum and get the new three momentum of protons
	detector.find_measuredThreeMomentum_nonhadron( leptonAngularResolution, leptonMeasuredMomentum, leptonMomentum_x, leptonMomentum_y, leptonMomentum_z );
	leptonEnergy = sqrt( leptMassSq + leptonMeasuredMomentum*leptonMeasuredMomentum );
     
	totalMomentum_x += leptonMomentum_x;
	totalMomentum_y += leptonMomentum_y;
     

	bool switchMesonDetected(false);
	if(finalParticleNumber < 0){
         std::cout<<"Final Particle Number <0 "<<std::endl;
         continue;
	} 

	recNuEnergy_cal[0] = leptonEnergy; _event_histo_1d->h_muon_reso->Fill((t->El - leptonEnergy ) /t->El);
        //--------------End of Calculation of Muon ------------------------------------------ 
	int observedTrackCnt = 0; //number of observed tracks initialized before loop over all the hadrons 
	double hadronicEnergy = 0.0; //measured energy of particles other than charged lepton

	double initMom = sqrt(t->pxn*t->pxn + t->pyn*t->pyn + t->pzn*t->pzn);
	if ( initMom > maxInitMom ) //!!!!!!!!!!!!!maxInitMom is cut of the high momentum of the spectrul function
	{
              hadronicEnergy = -999.0;
              
              continue;
	}

        //deal with the hadrons 
	for (int finalPartCnt = 0; finalPartCnt < finalParticleNumber; finalPartCnt++)
	{     
		//std::cout<<"[Main::Maker]<<<<<<<<<finalPartCnt = "<<finalPartCnt<<" pdgcode is "<<t->pdgf[finalPartCnt]<<std::endl;
		if (t->pdgf[finalPartCnt] > 1E5) //get rid of other particles which are not baryon /meson/leptons
                {  continue; std::cout<<"[Main::Maker]<<<<<<<<<<<<"<<"the pdg code is over 1E5"<<std::endl;}

		double measuredEnergy = 0.0;
		double calorimetricContribution = 0.0;
		//calculate invariantMass from the four momentum 
		double invariantMass = sqrt( t->Ef[finalPartCnt]*t->Ef[finalPartCnt] - 
					t->pxf[finalPartCnt]*t->pxf[finalPartCnt] - 
					t->pyf[finalPartCnt]*t->pyf[finalPartCnt] - 
					t->pzf[finalPartCnt]*t->pzf[finalPartCnt] );
               
		if ( t->Ef[finalPartCnt] < invariantMass )// for safety, negative kinetic energy is not allowed
		{    std::cout<<"[Main::Maker] ooops, the energy is smaller than invariance mass "<<std::endl; continue;}

		//calculate protons
		//anti-protons should be treated differently, but they are unlikely to be distinguished from protons
		if (t->pdgf[finalPartCnt] == 2212 || t->pdgf[finalPartCnt] == -2212 )
		{
			//double initMom = sqrt(t->pxf[finalPartCnt]*t->pxf[finalPartCnt] + t->pyf[finalPartCnt]*t->pyf[finalPartCnt] + t->pzf[finalPartCnt]*t->pzf[finalPartCnt]);
                        //std::cout<<"[Main::Maker]<<<<<test proton candidate : initMom is "<<initMom<<" maxInitMom is "<<maxInitMom<<std::endl;
			/*if ( initMom > maxInitMom ) //!!!!!!!!!!!!!maxInitMom is cut of the high momentum of the spectrul function
			{
                             hadronicEnergy = -1.0;
                             //break;
                             continue;
			}*/
			TLorentzVector  v4mom_finalPart;
			v4mom_finalPart.SetE(t->Ef[finalPartCnt]);
			v4mom_finalPart.SetPx(t->pxf[finalPartCnt]);
			v4mom_finalPart.SetPy(t->pyf[finalPartCnt]);
			v4mom_finalPart.SetPz(t->pzf[finalPartCnt]);
			double m_Res_proton = -999.0;
                        double m_Eff_proton = -999.0;
			double m_Sigma_proton = -999.0;;
			double m_Momentum_proton = -999.0;
			int pdgcode_proton = t->pdgf[finalPartCnt];
			detector.CDetectorEffects_getSigma( &pdgcode_proton, &v4mom_finalPart, ii_experiment, &m_Res_proton, &m_Eff_proton,  &m_Sigma_proton, &m_Momentum_proton);
			std::cout<<"[Main::Maker]<<<< sigma of proton is "<<m_Sigma_proton<<std::endl;
                        std::cout<<"[Main::Maker]<<<< Eff of protons is "<<m_Eff_proton<<std::endl;
			std::cout<<"[Main::Maker]<<<< resolution of proton is "<<m_Res_proton<<std::endl;
			std::cout<<"[Main::Maker]<<<< momentum of proton is "<<m_Momentum_proton<<std::endl;
			//calculate the measured energy from kinetic energy of protons and sigma 
			measuredEnergy = detector.find_measuredEnergy_proton( t->Ef[finalPartCnt] - invariantMass , m_Eff_proton, m_Sigma_proton);
                        std::cout<<"[Main::Maker]<<<< Kinetic energy of proton is "<<t->Ef[finalPartCnt] - invariantMass<<std::endl;
			std::cout<<"[Main::Maker]<<<< Measured energy of proton is "<<measuredEnergy<<std::endl;
                        _event_histo_1d->h_proton_reso->Fill((t->Ef[finalPartCnt]-invariantMass - measuredEnergy)/(t->Ef[finalPartCnt]-invariantMass));
			calorimetricContribution = measuredEnergy;  ///kinetic energy above the threshold
                       
			if ( measuredEnergy > accuracy )
			{
                              detector.find_measuredThreeMomentum_hadron( m_Res_proton, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                              totalMomentum_x += t->pxf[finalPartCnt];
                              totalMomentum_y += t->pyf[finalPartCnt];

                              ++observedTrackCnt;
                              calorimetricContribution += ProtonBinding;

                              if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                                 break;
			}

			else
			++missingProtonCnt;
                        //why minus and plus ProtonBinding
			missingProtonEnContrib += t->Ef[finalPartCnt] - invariantMass - calorimetricContribution + ProtonBinding;                
                
		}//end of calculation for protons
            
		///neutron
		///antineutrons should be treated differently, but they are unlikely to be distringuished from neutrons
		else if ( t->pdgf[finalPartCnt] == 2112 or t->pdgf[finalPartCnt] == -2112 )
		{
			/*const double initMom(   sqrt(t->pxf[finalPartCnt]*t->pxf[finalPartCnt] + t->pyf[finalPartCnt]*t->pyf[finalPartCnt] + t->pzf[finalPartCnt]*t->pzf[finalPartCnt])   );

			if ( initMom > maxInitMom )
			{
                           hadronicEnergy = -1.0;
                           break;
			}*/
			TLorentzVector  v4mom_finalPart_neutron;
			v4mom_finalPart_neutron.SetE(t->Ef[finalPartCnt]);
			v4mom_finalPart_neutron.SetPx(t->pxf[finalPartCnt]);
			v4mom_finalPart_neutron.SetPy(t->pyf[finalPartCnt]);
			v4mom_finalPart_neutron.SetPz(t->pzf[finalPartCnt]);
			double m_Res_neutron = -999.0;
                        double m_Eff_neutron = -999.0;
			double m_Sigma_neutron = -999.0;;
			double m_Momentum_neutron = -999.0;
			int pdgcode_neutron = t->pdgf[finalPartCnt];
			detector.CDetectorEffects_getSigma( &pdgcode_neutron, &v4mom_finalPart_neutron, ii_experiment, &m_Res_neutron, &m_Eff_neutron, &m_Sigma_neutron, &m_Momentum_neutron);
			std::cout<<"[Main::Maker]<<<< sigma of neutron is "<<m_Sigma_neutron<<std::endl;
			std::cout<<"[Main::Maker]<<<< Eff of neutron is "<<m_Sigma_neutron<<std::endl;
			std::cout<<"[Main::Maker]<<<< resolution of neutron is "<<m_Res_neutron<<std::endl;
			std::cout<<"[Main::Maker]<<<< momentum of neutron is "<<m_Momentum_neutron<<std::endl;
 
			measuredEnergy = detector.find_measuredEnergy_neutron( t->Ef[finalPartCnt] - invariantMass,m_Eff_neutron,  m_Sigma_neutron );
			calorimetricContribution = measuredEnergy; ///kinetic energy above the threshold            
                        std::cout<<"[Main::Maker]<<<< kinetic energy of neutron is "<<t->Ef[finalPartCnt] - invariantMass<<std::endl;
                        std::cout<<"[Main::Maker]<<<< measured energy is neutron is "<<measuredEnergy<<std::endl;
                        _event_histo_1d->h_neutron_reso->Fill((t->Ef[finalPartCnt]-invariantMass - measuredEnergy)/(t->Ef[finalPartCnt]-invariantMass));
			if ( measuredEnergy > accuracy )
			{
                             detector.find_measuredThreeMomentum_hadron( m_Res_neutron, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );
    
                             totalMomentum_x += t->pxf[finalPartCnt];
                             totalMomentum_y += t->pyf[finalPartCnt];                  

                             ++observedTrackCnt;
                             calorimetricContribution += NeutronBinding;

                             if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                               break;
			}
			else 
			  ++missingNeutronCnt;

			missingNeutronEnContrib += t->Ef[finalPartCnt] - invariantMass - calorimetricContribution + NeutronBinding;
		} //end of calculation for neutrons 

		///heavy baryon
		///heavy antibaryons should be treated differently, but they are unlikely to be distringuished from heavy baryons
		else if ( t->pdgf[finalPartCnt] == 3122 or t->pdgf[finalPartCnt] == 3222 or t->pdgf[finalPartCnt] == 3212 or t->pdgf[finalPartCnt] == 3112 or t->pdgf[finalPartCnt] == 3224 or t->pdgf[finalPartCnt] == 3214 or t->pdgf[finalPartCnt] == 3114 or t->pdgf[finalPartCnt] == 3322 or t->pdgf[finalPartCnt] == 3312 or t->pdgf[finalPartCnt] == 3324 or t->pdgf[finalPartCnt] == 3314 or t->pdgf[finalPartCnt] == 3334 or
                      t->pdgf[finalPartCnt] ==-3122 or t->pdgf[finalPartCnt] ==-3222 or t->pdgf[finalPartCnt] ==-3212 or t->pdgf[finalPartCnt] ==-3112 or t->pdgf[finalPartCnt] ==-3224 or t->pdgf[finalPartCnt] ==-3214 or t->pdgf[finalPartCnt] ==-3114 or t->pdgf[finalPartCnt] ==-3322 or t->pdgf[finalPartCnt] ==-3312 or t->pdgf[finalPartCnt] ==-3324 or t->pdgf[finalPartCnt] ==-3314 or t->pdgf[finalPartCnt] ==-3334 )
		{

			TLorentzVector  v4mom_finalPart_heavyBaryon;
			v4mom_finalPart_heavyBaryon.SetE(t->Ef[finalPartCnt]);
			v4mom_finalPart_heavyBaryon.SetPx(t->pxf[finalPartCnt]);
			v4mom_finalPart_heavyBaryon.SetPy(t->pyf[finalPartCnt]);
			v4mom_finalPart_heavyBaryon.SetPz(t->pzf[finalPartCnt]);
			double m_Res_heavyBaryon = -999.0;
                        double m_Eff_heavyBaryon = -999.0;
			double m_Sigma_heavyBaryon = -999.0;;
			double m_Momentum_heavyBaryon = -999.0;
			int pdgcode_heavyBaryon = t->pdgf[finalPartCnt];
	
			detector.CDetectorEffects_getSigma( &pdgcode_heavyBaryon, &v4mom_finalPart_heavyBaryon, ii_experiment, &m_Res_heavyBaryon, &m_Eff_heavyBaryon, &m_Sigma_heavyBaryon, &m_Momentum_heavyBaryon);
			std::cout<<"[Main::Maker]<<<< sigma of heavyBaryon is "<<m_Sigma_heavyBaryon<<std::endl;
			std::cout<<"[Main::Maker]<<<< Eff of heavyBaryon is "<<m_Sigma_heavyBaryon<<std::endl;
			std::cout<<"[Main::Maker]<<<< resolution of heavyBaryon is "<<m_Res_heavyBaryon<<std::endl;
			std::cout<<"[Main::Maker]<<<< momentum of heavyBaryon is "<<m_Momentum_heavyBaryon<<std::endl;
 

			measuredEnergy = detector.find_measuredEnergy_heavyBaryon( t->Ef[finalPartCnt] - invariantMass, m_Eff_heavyBaryon, m_Sigma_heavyBaryon );
			calorimetricContribution = measuredEnergy;  ///"kinetic" energy
                        std::cout<<"[Main::Maker]<<<< measuredEnergy is "<<measuredEnergy<<std::endl;
			if ( measuredEnergy > accuracy )
			{
			    detector.find_measuredThreeMomentum_hadron( m_Res_heavyBaryon, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

			    totalMomentum_x += t->pxf[finalPartCnt];
                            totalMomentum_y += t->pyf[finalPartCnt];

                            observedTrackCnt += 2;
                            switchMesonDetected = true;

                            calorimetricContribution += invariantMass - pMass + ProtonBinding;

                            if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                                     break;             
			}
			else 
			{
                               ++missingPiCCnt;
	                       ++missingProtonCnt;
			}
			if ( t->pdgf[finalPartCnt] == 3222 or t->pdgf[finalPartCnt] == 3212 or t->pdgf[finalPartCnt] == 3112 )
                            missingSigmaEnContrib += t->Ef[finalPartCnt] - calorimetricContribution - pMass + ProtonBinding;
			else
			    missingOtherPartEnContrib += t->Ef[finalPartCnt] - calorimetricContribution - pMass + ProtonBinding; 
		}//end of calculation for heavy baryons 

		///charged pion
		else if ( t->pdgf[finalPartCnt] == 211 or t->pdgf[finalPartCnt] == -211 )
		{

		  TLorentzVector  v4mom_finalPart_piC;
		  v4mom_finalPart_piC.SetE(t->Ef[finalPartCnt]);
		  v4mom_finalPart_piC.SetPx(t->pxf[finalPartCnt]);
		  v4mom_finalPart_piC.SetPy(t->pyf[finalPartCnt]);
		  v4mom_finalPart_piC.SetPz(t->pzf[finalPartCnt]);
		  double m_Res_piC = -999.0;
                  double m_Eff_piC = -999.0;
		  double m_Sigma_piC = -999.0;;
		  double m_Momentum_piC = -999.0;
		  int pdgcode_piC = t->pdgf[finalPartCnt];
		  detector.CDetectorEffects_getSigma( &pdgcode_piC, &v4mom_finalPart_piC, ii_experiment, &m_Res_piC, &m_Eff_piC, &m_Sigma_piC, &m_Momentum_piC);
		  std::cout<<"[Main::Maker]<<<< sigma of piC is "<<m_Sigma_piC<<std::endl;
		  std::cout<<"[Main::Maker]<<<< Eff of piC is "<<m_Sigma_piC<<std::endl;
		  std::cout<<"[Main::Maker]<<<< resolution of piC is "<<m_Res_piC<<std::endl;
		  std::cout<<"[Main::Maker]<<<< momentum of piC is "<<m_Momentum_piC<<std::endl;
 
	

                  measuredEnergy = detector.find_measuredEnergy_piC( t->Ef[finalPartCnt] - invariantMass, m_Eff_piC,  m_Sigma_piC );
                  calorimetricContribution = measuredEnergy; ///charged pion's energy above the threshold
                  std::cout<<"[Main::Maker]<<<< kinetic energy of pionC is "<<t->Ef[finalPartCnt] - invariantMass<<std::endl;
                  std::cout<<"[Main::Maker]<<<< measured energy is pionC is "<<measuredEnergy<<std::endl;
                  _event_histo_1d->h_pionC_reso->Fill((t->Ef[finalPartCnt]-invariantMass - measuredEnergy)/(t->Ef[finalPartCnt]-invariantMass));	                  
                  if ( measuredEnergy > accuracy )
                  {
                    detector.find_measuredThreeMomentum_hadron( m_Res_piC, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                    totalMomentum_x += t->pxf[finalPartCnt];
                    totalMomentum_y += t->pyf[finalPartCnt];

                    ++observedTrackCnt;
                    calorimetricContribution += invariantMass;
                    switchMesonDetected = true;

                    if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                        break;
                  }

                  else
                    ++missingPiCCnt;

                  missingPiCEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;
		}
                ///neutral pion
                else if ( t->pdgf[finalPartCnt] == 111 or t->pdgf[finalPartCnt] == -111 )
                {

		  TLorentzVector  v4mom_finalPart_piZero;
		  v4mom_finalPart_piZero.SetE(t->Ef[finalPartCnt]);
		  v4mom_finalPart_piZero.SetPx(t->pxf[finalPartCnt]);
		  v4mom_finalPart_piZero.SetPy(t->pyf[finalPartCnt]);
		  v4mom_finalPart_piZero.SetPz(t->pzf[finalPartCnt]);
		  double m_Res_piZero = -999.0;
		  double m_Eff_piZero = -999.0;
		  double m_Sigma_piZero = -999.0;;
		  double m_Momentum_piZero = -999.0;
		  int pdgcode_piZero = t->pdgf[finalPartCnt];
		  detector.CDetectorEffects_getSigma( &pdgcode_piZero, &v4mom_finalPart_piZero, ii_experiment, &m_Res_piZero, &m_Eff_piZero,  &m_Sigma_piZero, &m_Momentum_piZero);

		  std::cout<<"[Main::Maker]<<<< sigma of piZero is "<<m_Sigma_piZero<<std::endl;
		  std::cout<<"[Main::Maker]<<<< Eff of piZero is "<<m_Sigma_piZero<<std::endl;
		  std::cout<<"[Main::Maker]<<<< resolution of piZero is "<<m_Res_piZero<<std::endl;
		  std::cout<<"[Main::Maker]<<<< momentum of piZero is "<<m_Momentum_piZero<<std::endl;
 

                   measuredEnergy = detector.find_measuredEnergy_piZero( t->Ef[finalPartCnt] - invariantMass, m_Eff_piZero, m_Sigma_piZero );///neutral pion's energy above the threshold
                   calorimetricContribution = measuredEnergy;
                   std::cout<<"[Main::Maker]<<<< kinetic energy of pionZero is "<<t->Ef[finalPartCnt] - invariantMass<<std::endl;
                   std::cout<<"[Main::Maker]<<<< measured energy is pionZero is "<<measuredEnergy<<std::endl;
	           _event_histo_1d->h_pionZero_reso->Fill((t->Ef[finalPartCnt]-invariantMass - measuredEnergy)/(t->Ef[finalPartCnt]-invariantMass));
                   if ( measuredEnergy > accuracy )
                   {
                       detector.find_measuredThreeMomentum_hadron( m_Res_piZero, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                       totalMomentum_x += t->pxf[finalPartCnt];
                       totalMomentum_y += t->pyf[finalPartCnt];

                       observedTrackCnt += 2;
                       calorimetricContribution += invariantMass;
                       switchMesonDetected = true;

                       if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                          break;
                       }

                   else
                       ++missingPiZCnt;

                   missingPiZEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;

                }

                //std::cout<<"[Main::Maker]<<<<<< calculate charge pion and neutral pions"<<std::endl;
                ///charged kaon
		else if ( t->pdgf[finalPartCnt] == 321 or t->pdgf[finalPartCnt] == -321 )
                {
                   ++kaonCCnt;

		  TLorentzVector  v4mom_finalPart_kaonC;
		  v4mom_finalPart_kaonC.SetE(t->Ef[finalPartCnt]);
		  v4mom_finalPart_kaonC.SetPx(t->pxf[finalPartCnt]);
		  v4mom_finalPart_kaonC.SetPy(t->pyf[finalPartCnt]);
		  v4mom_finalPart_kaonC.SetPz(t->pzf[finalPartCnt]);
		  double m_Res_kaonC = -999.0;
                  double m_Eff_kaonC = -999.0;
		  double m_Sigma_kaonC = -999.0;;
		  double m_Momentum_kaonC = -999.0;
		  int pdgcode_kaonC = t->pdgf[finalPartCnt];
		  detector.CDetectorEffects_getSigma( &pdgcode_kaonC, &v4mom_finalPart_kaonC, ii_experiment, &m_Res_kaonC, &m_Eff_kaonC, &m_Sigma_kaonC, &m_Momentum_kaonC);

		  std::cout<<"[Main::Maker]<<<< sigma of kaonC is "<<m_Sigma_kaonC<<std::endl;
		  std::cout<<"[Main::Maker]<<<< Eff of kaonC is "<<m_Sigma_kaonC<<std::endl;
		  std::cout<<"[Main::Maker]<<<< resolution of kaonC is "<<m_Res_kaonC<<std::endl;
		  std::cout<<"[Main::Maker]<<<< momentum of kaonC is "<<m_Momentum_kaonC<<std::endl;
 




                   measuredEnergy = detector.find_measuredEnergy_kaonC( t->Ef[finalPartCnt] - invariantMass, m_Eff_kaonC, m_Sigma_kaonC );
                   calorimetricContribution = measuredEnergy; ///charged kaon's energy above the threshold
                   std::cout<<"[Main::Maker]<<<< kinetic energy of kaonC is "<<t->Ef[finalPartCnt] - invariantMass<<std::endl;
                   std::cout<<"[Main::Maker]<<<< measured energy is kaonC is "<<measuredEnergy<<std::endl;
	           _event_histo_1d->h_kaonC_reso->Fill((t->Ef[finalPartCnt]-invariantMass - measuredEnergy)/(t->Ef[finalPartCnt]-invariantMass));
                   if ( measuredEnergy > accuracy )
                   {
                       detector.find_measuredThreeMomentum_hadron( m_Res_kaonC, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                        totalMomentum_x += t->pxf[finalPartCnt];
                        totalMomentum_y += t->pyf[finalPartCnt];

                        ++observedTrackCnt;
                        calorimetricContribution += invariantMass;
                        switchMesonDetected = true;

                        if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                           break;
                        }
    
                    else
                    {
                       missingPiCCnt += 2;
                    ++missingKaonCCnt;
                    }

                     missingKaonCEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;

		}


		///neutral kaon
		else if ( t->pdgf[finalPartCnt] == 311 or t->pdgf[finalPartCnt] == -311 or
                         t->pdgf[finalPartCnt] == 310 or t->pdgf[finalPartCnt] == -310 or
                         t->pdgf[finalPartCnt] == 130 or t->pdgf[finalPartCnt] == -130 )
		{
                     ++kaonZCnt;

		     TLorentzVector  v4mom_finalPart_kaonZero;
		     v4mom_finalPart_kaonZero.SetE(t->Ef[finalPartCnt]);
		     v4mom_finalPart_kaonZero.SetPx(t->pxf[finalPartCnt]);
		     v4mom_finalPart_kaonZero.SetPy(t->pyf[finalPartCnt]);
		     v4mom_finalPart_kaonZero.SetPz(t->pzf[finalPartCnt]);
		     double m_Res_kaonZero = -999.0;
                     double m_Eff_kaonZero = -999.0;
		     double m_Sigma_kaonZero = -999.0;;
		     double m_Momentum_kaonZero = -999.0;
		     int pdgcode_kaonZero = t->pdgf[finalPartCnt];
		     detector.CDetectorEffects_getSigma( &pdgcode_kaonZero, &v4mom_finalPart_kaonZero, ii_experiment, &m_Res_kaonZero, &m_Eff_kaonZero, &m_Sigma_kaonZero, &m_Momentum_kaonZero);

		     std::cout<<"[Main::Maker]<<<< sigma of kaonZero is "<<m_Sigma_kaonZero<<std::endl;
		     std::cout<<"[Main::Maker]<<<< Eff of kaonZero is "<<m_Sigma_kaonZero<<std::endl;
		     std::cout<<"[Main::Maker]<<<< resolution of kaonZero is "<<m_Res_kaonZero<<std::endl;
		     std::cout<<"[Main::Maker]<<<< momentum of kaonZero is "<<m_Momentum_kaonZero<<std::endl;
 


                     measuredEnergy = detector.find_measuredEnergy_kaonZero( t->Ef[finalPartCnt] - invariantMass, m_Eff_kaonZero, m_Sigma_kaonZero );///neutral kaon's energy above the threshold
                     calorimetricContribution = measuredEnergy;
                     std::cout<<"[Main::Maker]<<<< kinetic energy of kaonZero is "<<t->Ef[finalPartCnt] - invariantMass<<std::endl;
                     std::cout<<"[Main::Maker]<<<< measured energy is kaonZero is "<<measuredEnergy<<std::endl;
	             _event_histo_1d->h_kaonZero_reso->Fill((t->Ef[finalPartCnt]-invariantMass - measuredEnergy)/(t->Ef[finalPartCnt]-invariantMass));
                     if ( measuredEnergy > accuracy )
                     {
                         detector.find_measuredThreeMomentum_hadron( m_Res_kaonZero, measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                         totalMomentum_x += t->pxf[finalPartCnt];
                         totalMomentum_y += t->pyf[finalPartCnt];

                         observedTrackCnt += 2;
                         calorimetricContribution += invariantMass;
                         switchMesonDetected = true;

                        if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                          break;
                        }

                       else
                       {
                          missingPiCCnt += 2;
                          ++missingKaonZCnt;
                       }

                          missingKaonZEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;


                ///69% of K0_S's decay into pi+pi-
                ///31% of K0_S's decay into pi0pi0
                //
                 
                //
                ///41% of K0_L's decay into piC e nu (incomplete energy reconstruction)
                ///27% of K0_L's decay into piC mu nu (incomplete energy reconstruction)
		}

		///photon
		else if ( t->pdgf[finalPartCnt] == 22 )
		{




		  TLorentzVector  v4mom_finalPart_photon;
		  v4mom_finalPart_photon.SetE(t->Ef[finalPartCnt]);
		  v4mom_finalPart_photon.SetPx(t->pxf[finalPartCnt]);
		  v4mom_finalPart_photon.SetPy(t->pyf[finalPartCnt]);
		  v4mom_finalPart_photon.SetPz(t->pzf[finalPartCnt]);
		  double m_Res_photon = -999.0;
                  double m_Eff_photon = -999.0;
		  double m_Sigma_photon = -999.0;;
		  double m_Momentum_photon = -999.0;
		  int pdgcode_photon = t->pdgf[finalPartCnt];
		  detector.CDetectorEffects_getSigma( &pdgcode_photon, &v4mom_finalPart_photon, ii_experiment, &m_Res_photon, &m_Eff_photon,  &m_Sigma_photon, &m_Momentum_photon);

		  std::cout<<"[Main::Maker]<<<< sigma of photon is "<<m_Sigma_photon<<std::endl;
		  std::cout<<"[Main::Maker]<<<< Eff of photon is "<<m_Sigma_photon<<std::endl;
		  std::cout<<"[Main::Maker]<<<< resolution of photon is "<<m_Res_photon<<std::endl;
		  std::cout<<"[Main::Maker]<<<< momentum of photon is "<<m_Momentum_photon<<std::endl;
 









                  measuredEnergy = detector.find_measuredEnergy_photon( t->Ef[finalPartCnt], m_Eff_photon, m_Sigma_photon );///photon's energy above the threshold
                  calorimetricContribution = measuredEnergy;

                  if ( measuredEnergy > accuracy )
                  {
                    detector.find_measuredThreeMomentum_nonhadron( m_Res_photon, measuredEnergy, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                    totalMomentum_x += t->pxf[finalPartCnt];
                    totalMomentum_y += t->pyf[finalPartCnt];

                    ++observedTrackCnt;

                    if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                        break;
                  }

                  missingOtherPartEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;

		}

		///electron
		else if ( t->pdgf[finalPartCnt] == 11 || t->pdgf[finalPartCnt] == -11 )
		{

		  TLorentzVector  v4mom_finalPart_electron;
		  v4mom_finalPart_electron.SetE(t->Ef[finalPartCnt]);
		  v4mom_finalPart_electron.SetPx(t->pxf[finalPartCnt]);
		  v4mom_finalPart_electron.SetPy(t->pyf[finalPartCnt]);
		  v4mom_finalPart_electron.SetPz(t->pzf[finalPartCnt]);
		  double m_Res_electron = -999.0;
                  double m_Eff_electron = -999.0;
		  double m_Sigma_electron = -999.0;;
		  double m_Momentum_electron = -999.0;
		  int pdgcode_electron = t->pdgf[finalPartCnt];
		  detector.CDetectorEffects_getSigma( &pdgcode_electron, &v4mom_finalPart_electron, ii_experiment, &m_Res_electron, &m_Eff_electron,  &m_Sigma_electron, &m_Momentum_electron);

		  std::cout<<"[Main::Maker]<<<< sigma of electron is "<<m_Sigma_electron<<std::endl;
		  std::cout<<"[Main::Maker]<<<< Eff of electron is "<<m_Sigma_electron<<std::endl;
		  std::cout<<"[Main::Maker]<<<< resolution of electron is "<<m_Res_electron<<std::endl;
		  std::cout<<"[Main::Maker]<<<< momentum of electron is "<<m_Momentum_electron<<std::endl;
                 




                  ///although it is stored as 'measuredEnergy', it is the momentum
                  measuredEnergy = detector.find_electronMeasuredMomentum( sqrt( t->Ef[finalPartCnt]*t->Ef[finalPartCnt] - eMassSq ));
                  calorimetricContribution = (measuredEnergy > 0.0) ? sqrt( measuredEnergy*measuredEnergy + eMassSq ) : 0.0;///electron's energy above the threshold

                  if ( calorimetricContribution > eMass )
                  {
                    detector.find_measuredThreeMomentum_nonhadron( m_Res_electron, measuredEnergy, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                    totalMomentum_x += t->pxf[finalPartCnt];
                    totalMomentum_y += t->pyf[finalPartCnt];

                    ++observedTrackCnt;

                    if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                        break;
                  }

                  missingOtherPartEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;

		}

		///muon
		else if ( t->pdgf[finalPartCnt] == 13 or t->pdgf[finalPartCnt] == -13 )
		{
                ///although it is stored as 'measuredEnergy', it is the momentum


		  TLorentzVector  v4mom_finalPart_muon;
		  v4mom_finalPart_muon.SetE(t->Ef[finalPartCnt]);
		  v4mom_finalPart_muon.SetPx(t->pxf[finalPartCnt]);
		  v4mom_finalPart_muon.SetPy(t->pyf[finalPartCnt]);
		  v4mom_finalPart_muon.SetPz(t->pzf[finalPartCnt]);
		  double m_Res_muon = -999.0;
		  double m_Eff_muon = -999.0;
		  double m_Sigma_muon = -999.0;;
		  double m_Momentum_muon = -999.0;
		  int pdgcode_muon = t->pdgf[finalPartCnt];
		  detector.CDetectorEffects_getSigma( &pdgcode_muon, &v4mom_finalPart_muon, ii_experiment, &m_Res_muon, &m_Eff_muon, &m_Sigma_muon, &m_Momentum_muon);

		  std::cout<<"[Main::Maker]<<<< sigma of muon is "<<m_Sigma_muon<<std::endl;
		  std::cout<<"[Main::Maker]<<<< Eff of muon is "<<m_Sigma_muon<<std::endl;
		  std::cout<<"[Main::Maker]<<<< resolution of muon is "<<m_Res_muon<<std::endl;
		  std::cout<<"[Main::Maker]<<<< momentum of muon is "<<m_Momentum_muon<<std::endl;
                



                  measuredEnergy = detector.find_muonMeasuredMomentum( sqrt( t->Ef[finalPartCnt]*t->Ef[finalPartCnt] - muMassSq ));
                  calorimetricContribution = (measuredEnergy > 0.0) ? sqrt(measuredEnergy*measuredEnergy + muMassSq ) : 0.0;///muon's energy above the threshold


                  if ( calorimetricContribution > muMass )
                  {
                    detector.find_measuredThreeMomentum_nonhadron(m_Res_muon, measuredEnergy, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                    totalMomentum_x += t->pxf[finalPartCnt];
                    totalMomentum_y += t->pyf[finalPartCnt];

                    ++observedTrackCnt;

                    if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                        break;
                  }

                  missingOtherPartEnContrib += t->Ef[finalPartCnt] - calorimetricContribution;

		}

		//(anti)neutrinos in the final state
		else if ( t->pdgf[finalPartCnt] == 12 or t->pdgf[finalPartCnt] == 14 or t->pdgf[finalPartCnt] == 16 or
                      t->pdgf[finalPartCnt] ==-12 or t->pdgf[finalPartCnt] ==-14 or t->pdgf[finalPartCnt] ==-16 )
                          missingOtherPartEnContrib += t->Ef[finalPartCnt];




		else
		{
                std::cout<<"Detector effects for particle of the PDG code "<<t->pdgf[finalPartCnt]<<" handled as for a heavy baryon"<<std::endl;


		TLorentzVector  v4mom_finalPart_heavyBaryon;
		v4mom_finalPart_heavyBaryon.SetE(t->Ef[finalPartCnt]);
		v4mom_finalPart_heavyBaryon.SetPx(t->pxf[finalPartCnt]);
		v4mom_finalPart_heavyBaryon.SetPy(t->pyf[finalPartCnt]);
		v4mom_finalPart_heavyBaryon.SetPz(t->pzf[finalPartCnt]);
		double m_Res_heavyBaryon = -999.0;
		double m_Eff_heavyBaryon = -999.0;
		double m_Sigma_heavyBaryon = -999.0;;
		double m_Momentum_heavyBaryon = -999.0;
		int pdgcode_heavyBaryon = t->pdgf[finalPartCnt];
	
		detector.CDetectorEffects_getSigma( &pdgcode_heavyBaryon, &v4mom_finalPart_heavyBaryon, ii_experiment, &m_Res_heavyBaryon, &m_Eff_heavyBaryon, &m_Sigma_heavyBaryon, &m_Momentum_heavyBaryon);
		std::cout<<"[Main::Maker]<<<< sigma of other heavyBaryon is "<<m_Sigma_heavyBaryon<<std::endl;
		std::cout<<"[Main::Maker]<<<< Eff of other heavyBaryon is "<<m_Sigma_heavyBaryon<<std::endl;
		std::cout<<"[Main::Maker]<<<< resolution of other heavyBaryon is "<<m_Res_heavyBaryon<<std::endl;
		std::cout<<"[Main::Maker]<<<< momentum of other heavyBaryon is "<<m_Momentum_heavyBaryon<<std::endl;
                



                measuredEnergy = detector.find_measuredEnergy_heavyBaryon( t->Ef[finalPartCnt] - invariantMass, m_Eff_heavyBaryon, m_Sigma_heavyBaryon );
                calorimetricContribution = measuredEnergy;  ///"kinetic" energy

                if ( measuredEnergy > accuracy )
                {
                    detector.find_measuredThreeMomentum_hadron( detector.get_angularResolution_heavyBaryon(), measuredEnergy, invariantMass, t->pxf[finalPartCnt], t->pyf[finalPartCnt], t->pzf[finalPartCnt] );

                    totalMomentum_x += t->pxf[finalPartCnt];
                    totalMomentum_y += t->pyf[finalPartCnt];

                    observedTrackCnt += 2;
                    switchMesonDetected = true;
                    calorimetricContribution += ProtonBinding;

                    if ( event == oneTrack ) ///in the "charged lepton only" analysis, you can skip this event
                        break;
                }
		}

		if ( calorimetricContribution > accuracy )
                hadronicEnergy += calorimetricContribution;
                std::cout<<"[Main::Maker]<<<<<<<< pdg code of the particle is "<<t->pdgf[finalPartCnt]<<" hadronic energy is "<<hadronicEnergy<<std::endl;                



	} // End of the loop over all the final state "hadrons"

        std::cout<<"[Main::Maker]<<<<<<<<<<<<< Total Hadronic Energy is "<<hadronicEnergy<<std::endl;

	recNuEnergy_kin = switchMesonDetected ? 0.5*( 2*iNuclMassTilde*leptonEnergy + deltaConst_res )/( iNuclMassTilde - leptonEnergy + leptonMomentum_z )
                                            : 0.5*( 2*iNuclMassTilde*leptonEnergy + deltaConst_QE )/( iNuclMassTilde - leptonEnergy + leptonMomentum_z );


        /// skip the event with more than 'maxAddTrackNumber' detected particles in addition to charged lepton
        /// reconstruction efficiency is very low for events with high multiplicity

        /*std::cout<<"observeTrackCnt is "<<observedTrackCnt<<std::endl;
        if ( observedTrackCnt < minAddTrackNumber || observedTrackCnt > maxAddTrackNumber )
            continue;
        std::cout<<"[Main::Maker]<<<<<<<<<<<<< Total Hadronic Energy (Again) is "<<hadronicEnergy<<std::endl;
        */

	if ( hadronicEnergy >= 0.0 ) // for safety, total hadronic kinetic energies shouldn't be negative
	{
            recNuEnergy_cal[0] += hadronicEnergy;

            for (int kCnt(1); kCnt < calOptions; ++kCnt)
                recNuEnergy_cal[kCnt] = recNuEnergy_cal[0];

            const double transverseMomentumSq( totalMomentum_x*totalMomentum_x + totalMomentum_y*totalMomentum_y );
            const double transverseMomentum( sqrt( transverseMomentumSq ) );
            missingTransverseMomentum += transverseMomentum;

            if ( transverseMomentum > averagePT )
            {
                const double neutronOnlyEnergy(   sqrt(nMassSq + transverseMomentumSq) - nMass + NeutronBinding   );

                ///different recovery options
                recNuEnergy_cal[1] += neutronOnlyEnergy;
                recNuEnergy_cal[2] += neutronOnlyEnergy + missingPiCCnt*piCMass;
                recNuEnergy_cal[3] += (not missingPiCCnt) ? neutronOnlyEnergy : sqrt( piCMassSq + transverseMomentumSq );
                recNuEnergy_cal[4] += sqrt( piCMassSq + transverseMomentumSq );
            }

	    //std::cout<<"True neutrino energy, transverse momentum and reco neutrino energy information is"<< std::endl;
            //std::cout<<trueNuEnergy<<" "<<transverseMomentum<<" "<<totalMomentum_x<<" "<<totalMomentum_y<<" "<<recNuEnergy_cal[0]<<" "<<recNuEnergy_cal[1]<<" "<<recNuEnergy_cal[2]<<" "<<recNuEnergy_cal[3]<<" "<<recNuEnergy_cal[4]<<std::endl;

            //Fill out histograms for migration matrix and resolution of each kind of particles


            for(int m=0; m<calOptions; m++){
              _event_histo_1d->h_true_calc_Enu[m]->Fill(trueNuEnergy, recNuEnergy_cal[m]);
            }

	}

        else
            continue;
      



	for ( int kCnt(0); kCnt < calOptions; ++kCnt )
            if (   ( recNuEnergy_cal[kCnt] >= eMin ) and ( recNuEnergy_cal[kCnt] < eMax )   )
            {
                ++eventCnt_cal[kCnt];

                const int ny(   static_cast<int>( (recNuEnergy_cal[kCnt] - eMin)/eStep )   );
                CalMatrix(kCnt, nx, ny) += 1;
            }


        if (   ( recNuEnergy_kin >= eMin ) and ( recNuEnergy_kin < eMax )   )
        {
            ++eventCnt_kin;

            const int ny(   static_cast<int>( (recNuEnergy_kin - eMin)/eStep )   );
            KinMatrix(nx, ny) =+ 1;
        }

        ++eventCnt;

        for ( int kCnt(0); kCnt < calOptions; ++kCnt )
        {    missingEnergy[kCnt] += trueNuEnergy - recNuEnergy_cal[kCnt]; 

             missingPiZEnergy += missingPiZEnContrib;
             missingPiCEnergy += missingPiCEnContrib;
             missingKaonZEnergy += missingKaonZEnContrib;
             missingKaonCEnergy += missingKaonCEnContrib;
             missingNeutronEnergy += missingNeutronEnContrib;
             missingProtonEnergy += missingProtonEnContrib;

             missingSigmaEnergy += missingSigmaEnContrib;
             missingOtherPartEnergy += missingOtherPartEnContrib;

             missingPiCMultiplicity += missingPiCCnt;
             missingNeutronMultiplicity += missingNeutronCnt;
             missingProtonMultiplicity += missingProtonCnt;

             piZMultiplicity += t->nfpi0;
             piCMultiplicity += t->nfpip + t->nfpim;
             kaonZMultiplicity += kaonZCnt;
             kaonCMultiplicity += kaonCCnt;
             neutronMultiplicity += t->nfn;
             protonMultiplicity += t->nfp;

        }  



      
        

     
     
  }// loop over all the selected events



  std::ofstream kinematicInfoName (kinematicInfoName_string.c_str() );
  kinematicInfoFile<<std::showpoint<<std::fixed<<setprecision(3)<<trueNuEnergy;

  for ( int kCnt(0); kCnt < calOptions; ++kCnt )
      kinematicInfoFile<<" "<<std::setprecision(5)<<std::setw(11)<<missingEnergy[kCnt]/eventCnt;

  kinematicInfoFile<<" "<<std::setprecision(4)<<std::setw(11)<<missingTransverseMomentum/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<piZMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingPiZMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingPiZEnergy/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<piCMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingPiCMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingPiCEnergy/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<kaonZMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingKaonZMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingKaonZEnergy/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<kaonCMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingKaonCMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingKaonCEnergy/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<neutronMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingNeutronMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingNeutronEnergy/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<protonMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingProtonMultiplicity*1.0/eventCnt<<" "<<std::setw(11)<<missingProtonEnergy/eventCnt;
  kinematicInfoFile<<" "<<std::setw(11)<<missingSigmaEnergy/eventCnt<<" "<<std::setw(11)<<missingOtherPartEnergy/eventCnt<<std::endl;


  file_out->cd();
  file_out->WriteObject(_event_histo_1d, "DUNENDEventHisto1D");

  histo_Fermi_mom->Write();
  histo_Enu_CCQE->Write();
  histo_Enu_CCRES->Write();
  histo_Enu_CCDIS->Write();
  histo_Enu_CCMEC->Write();

  histo_Evis->Write();
  histo_Evis_noFSI->Write();


  file_out->Write();
  file_out->Close();



  //========================================================================
  clock_t end = clock();
  double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;

  std::cout<<"Computing time: "<<elapsed_secs<<std::endl;

  return; 

}


#endif
