/**
 * \file CDetectorEffects.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class CDetectorEffects
 *
 * @author jiangl
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_CDETECTOREFFECTS_H__
#define __BASE_CDETECTOREFFECTS_H__

#include "CGaussianDistrib.h"
#include "CRandomGen.h"
#include "TLorentzVector.h"
#include "TMath.h"
namespace Base {

  /**
     \class CDetectorEffects
     User defined class CDetectorEffects ... these comments are used to generate
     doxygen documentation!
  */
  class CDetectorEffects{
    
  public:
    
    /// Default constructor
    CDetectorEffects(){};
   
    /// Default destructor
    ~CDetectorEffects(){};
    
    const double GeV = 1.0;
    const double MeV = 0.001*GeV;

    const double eMass =      0.510998928*MeV ;///electron mass
    const double muMass =   105.6583715*MeV ;///muon mass
    const double pMass = 938.272046*MeV ;///proton mass
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

    enum ExperimentName
    {
        PerfectReconstruction_neutronsDetected = 0,
        PerfectReconstruction_neutronsUndetected = 1,
        OurSetup_neutronsDetected = 2,
        OurSetup_neutronsUndetected = 3,
        DUNE_FastMC = 4
    };

    typedef double (*DFindSigmaPtr);

    double Sigma_perfect(/*const*/ double, /*const*/ double, /*const*/ double){
         /*const*/ double result = 0.0;
         return result;
    }

    ///the width is calculated as sigma(E)/E = max{width/sqrt(E), minimalWidth} 
    double Sigma_typical(const double i_energy, const double i_width, const double i_minimalWidth)
    {
       const double result( i_width/sqrt(i_energy/GeV) );
       return ( result < i_minimalWidth ) ? i_minimalWidth*i_energy : result*i_energy;
    }

    ///the width is calculated as sigma(E) = max{width*sqrt(E), minimalWidth}
    double Sigma_em(const double i_energy, const double i_width, const double i_minimalWidth)
    {
       const double result( i_width*sqrt(i_energy/GeV)  );

       return ( result < i_minimalWidth ) ? i_minimalWidth : result;
    }





    void CDetectorEffects_getSigma(int *pdg_code, TLorentzVector *v4mom, int i_experiment, double *m_Res, double *m_Eff, double *m_Sigma, double *m_Momentum/*const ExperimentName i_experiment*//*, CRandomGen& io_rnd*/)
    //:m_experiment(i_experiment),
    //m_rnd(io_rnd)
    { 
        
       m_gauss = new CGaussianDistrib(m_rnd); std::cout<<"[Base::CDtectorEffects] i_experiment is "<<i_experiment<<std::endl;
       double energy = v4mom->E();  double momentum = v4mom->P(); std::cout<<"[Base::CDetectorEffects] pdg code is "<<*pdg_code<<" energy is "<<energy<<" momentum is "<<momentum<<std::endl;



       switch (i_experiment) //switch ( m_experiment )
       {
            case PerfectReconstruction_neutronsDetected:
                if(abs(*pdg_code) == 211){///charged pion
                 m_piCEnergyWidth = 0.0;///parameter driving energy resolution
                 m_piCEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_piCEnergyThreshold = 0.0;///energy threshold
                 m_piCAngularResolution = 0.0;///angular resolution
                 m_piCEfficiency = 1.0;///efficiency
                 temp_piCSigma = CDetectorEffects::Sigma_perfect(energy, m_piCEnergyWidth, m_piCEnergyMinimalWidth); 
                 m_find_piCSigma = &temp_piCSigma;
                 }
                //
                if(abs(*pdg_code) ==111) {///neutral pion
                 m_piZeroEnergyWidth = 0.0;///parameter driving energy resolution
                 m_piZeroEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_piZeroEnergyThreshold = 0.0;///energy threshold
                 m_piZeroAngularResolution = 0.0;///angular resolution
                 m_piZeroEfficiency = 1.0;///efficiency                   
                 temp_piZeroSigma = CDetectorEffects::Sigma_perfect(energy, m_piZeroEnergyWidth, m_piZeroEnergyMinimalWidth); 
                 m_find_piZeroSigma = &temp_piZeroSigma;
                }
                //
                if(abs(*pdg_code) == 22) {///photon
                 m_photonEnergyWidth = 0.0;///parameter driving energy resolution
                 m_photonEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_photonEnergyThreshold = 0.0;///energy threshold
                 m_photonAngularResolution = 0.0;///angular resolution
                 m_photonEfficiency = 1.0;///efficiency
                 temp_photonSigma = CDetectorEffects::Sigma_perfect(energy, m_photonEnergyWidth, m_photonEnergyMinimalWidth);
                 m_find_photonSigma = &temp_photonSigma;
                }
                //
                if(abs(*pdg_code)== 321) {///charged kaon
                 m_kaonCEnergyWidth = 0.0;///parameter driving energy resolution
                 m_kaonCEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_kaonCEnergyThreshold = 0.0;///energy threshold
                 m_kaonCAngularResolution = 0.0;///angular resolution
                 m_kaonCEfficiency = 1.0;///efficiency
                 temp_kaonCSigma = CDetectorEffects::Sigma_perfect(energy, m_kaonCEnergyWidth, m_kaonCEnergyMinimalWidth); 
                 m_find_kaonCSigma = &temp_kaonCSigma;
                }
                //
                if(abs(*pdg_code) == 311 ||abs(*pdg_code) == 310 || abs(*pdg_code) ==130){///neutral kaon
                 m_kaonZeroEnergyWidth = 0.0;///parameter driving energy resolution
                 m_kaonZeroEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_kaonZeroEnergyThreshold = 0.0;///energy threshold
                 m_kaonZeroAngularResolution = 0.0;///angular resolution
                 m_kaonZeroEfficiency = 1.0;///efficiency
                 temp_kaonZeroSigma = CDetectorEffects::Sigma_perfect(energy, m_kaonZeroEnergyWidth, m_kaonZeroEnergyMinimalWidth);
                 m_find_kaonZeroSigma = &temp_kaonZeroSigma;
                }
                //
                if(abs(*pdg_code) == 2212) {///proton
                 m_protonEnergyWidth = 0.0;///parameter driving energy resolution
                 m_protonEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_protonEnergyThreshold = 0.0;///energy threshold
                 m_protonAngularResolution = 0.0;///angular resolution
                 m_protonEfficiency = 1.0; ///efficiency
                 temp_protonSigma = CDetectorEffects::Sigma_perfect(energy, m_protonEnergyWidth, m_protonEnergyMinimalWidth); 
                 m_find_protonSigma = &temp_protonSigma; 
                }
                //
                if(abs(*pdg_code) == 2112){///neutron
                 m_neutronEnergyWidth = 0.0;///parameter driving energy resolution
                 m_neutronEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_neutronEnergyThreshold = 0.0;///energy threshold
                 m_neutronAngularResolution = 0.0;///angular resolution
                 m_neutronEfficiency = 1.0;///efficiency
                 temp_neutronSigma = CDetectorEffects::Sigma_perfect(energy, m_neutronEnergyWidth, m_neutronEnergyMinimalWidth);
                 m_find_neutronSigma = &temp_neutronSigma;
                }
                //
                if(abs(*pdg_code) > 2212){///heavy baryon
                 m_heavyBaryonEnergyWidth = 0.0;///parameter driving energy resolution
                 m_heavyBaryonEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_heavyBaryonEnergyThreshold = 0.0;///energy threshold
                 m_heavyBaryonAngularResolution = 0.0;///angular resolution
                 m_heavyBaryonEfficiency = 1.0;///efficiency
                 temp_heavyBaryonSigma = CDetectorEffects::Sigma_perfect(energy, m_heavyBaryonEnergyWidth, m_heavyBaryonEnergyMinimalWidth);
                 m_find_heavyBaryonSigma = &temp_heavyBaryonSigma;
                }
                //
                if(abs(*pdg_code) == 13){///muon
                 m_muonMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_muonMomentumMinimalWidth = 0.0;///parameter driving momentum resolution
                 m_muonMomentumThreshold = 0.0;  ///muon threshold
                 temp_muonSigma = CDetectorEffects::Sigma_perfect(momentum, m_muonMomentumWidth, m_muonMomentumMinimalWidth); 
                 m_find_muonSigma = &temp_muonSigma; 
                 m_muonAngularResolution = 0.0;///parameter driving angular resolution
                 m_muonEfficiency = 1.0; ///efficiency
                 temp_muonMomentum = CDetectorEffects::find_muonMeasuredMomentum_Gauss(momentum, m_muonMomentumThreshold, temp_muonSigma); 
                 m_find_muonMomentum = &temp_muonMomentum; 
                 }
                //
                if(abs(*pdg_code) == 11){///electron
                 m_electronMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumMinimalWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumThreshold = 0.0;///electron threshold
                 temp_electronSigma = CDetectorEffects::Sigma_perfect(momentum, m_electronMomentumWidth, m_electronMomentumMinimalWidth);
                 m_find_electronSigma = &temp_electronSigma;
                 m_electronAngularResolution = 0.0;///parameter driving angular resolution
                 m_electronEfficiency = 1.0;///efficiency
                 temp_electronMomentum = CDetectorEffects::find_electronMeasuredMomentum_Gauss(momentum, m_electronMomentumThreshold, temp_electronSigma);
                 m_find_electronMomentum = &temp_electronMomentum;
                }
                break;

           case PerfectReconstruction_neutronsUndetected:
                if(abs(*pdg_code ) == 211){///charged pion
                 m_piCEnergyWidth = 0.0;///parameter driving energy resolution
                 m_piCEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_piCEnergyThreshold = 0.0;///energy threshold
                 m_piCAngularResolution = 0.0;///angular resolution
                 m_piCEfficiency = 1.0;///efficiency
                 temp_piCSigma = CDetectorEffects::Sigma_perfect(energy, m_piCEnergyWidth, m_piCEnergyMinimalWidth);
                 m_find_piCSigma = &temp_piCSigma;               
                }
                //
                if(abs(*pdg_code ) == 111){///neutral pion
                 m_piZeroEnergyWidth = 0.0;///parameter driving energy resolution
                 m_piZeroEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_piZeroEnergyThreshold = 0.0;///energy threshold
                 m_piZeroAngularResolution = 0.0;///angular resolution
                 m_piZeroEfficiency = 1.0;///efficiency
                 temp_piZeroSigma = CDetectorEffects::Sigma_perfect(energy, m_piZeroEnergyWidth, m_piZeroEnergyMinimalWidth);
                 m_find_piZeroSigma = &temp_piZeroSigma;
                }
                //
                if(abs(*pdg_code) == 22){///photon
                 m_photonEnergyWidth = 0.0;///parameter driving energy resolution
                 m_photonEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_photonEnergyThreshold = 0.0;///energy threshold
                 m_photonAngularResolution = 0.0;///angular resolution
                 m_photonEfficiency = 1.0;///efficiency
                 temp_photonSigma = CDetectorEffects::Sigma_perfect(energy, m_photonEnergyWidth, m_photonEnergyMinimalWidth);
                 m_find_photonSigma = &temp_photonSigma;
                }
                //
                if(abs(*pdg_code) == 321) {///charged kaon
                 m_kaonCEnergyWidth = 0.0;///parameter driving energy resolution
                 m_kaonCEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_kaonCEnergyThreshold = 0.0;///energy threshold
                 m_kaonCAngularResolution = 0.0;///angular resolution
                 m_kaonCEfficiency = 1.0;///efficiency
                 temp_kaonCSigma = CDetectorEffects::Sigma_perfect(energy, m_kaonCEnergyWidth, m_kaonCEnergyMinimalWidth); 
                 m_find_kaonCSigma = &temp_kaonCSigma;
                }
                //
                if(abs(*pdg_code) == 311 || abs(*pdg_code) ==310 || abs(*pdg_code) ==130){///neutral kaon
                 m_kaonZeroEnergyWidth = 0.0;///parameter driving energy resolution
                 m_kaonZeroEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_kaonZeroEnergyThreshold = 0.0;///energy threshold
                 m_kaonZeroAngularResolution = 0.0;///angular resolution
                 m_kaonZeroEfficiency = 1.0;///efficiency
                 temp_kaonZeroSigma = CDetectorEffects::Sigma_perfect(energy, m_kaonZeroEnergyWidth, m_kaonZeroEnergyMinimalWidth);
                 m_find_kaonZeroSigma = &temp_kaonZeroSigma;
                }
                //
                if(abs(*pdg_code) == 2212) { ///proton
                 m_protonEnergyWidth = 0.0;///parameter driving energy resolution
                 m_protonEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_protonEnergyThreshold = 0.0;///energy threshold
                 m_protonAngularResolution = 0.0;///angular resolution
                 m_protonEfficiency = 1.0;///efficiency
                 temp_protonSigma = CDetectorEffects::Sigma_perfect(energy, m_protonEnergyWidth, m_protonEnergyMinimalWidth); 
                 m_find_protonSigma = &temp_protonSigma; 
                }
                //
                if(abs(*pdg_code) == 2112) {///neutron
                 m_neutronEnergyWidth = 0.0;///parameter driving energy resolution
                 m_neutronEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_neutronEnergyThreshold = 0.0;///energy threshold
                 m_neutronAngularResolution = 0.0;///angular resolution
                 m_neutronEfficiency = 0.0;///efficiency
                 temp_neutronSigma = CDetectorEffects::Sigma_perfect(energy, m_neutronEnergyWidth, m_neutronEnergyMinimalWidth); 
                 m_find_neutronSigma = &temp_neutronSigma;
                }
                //
                if(abs(*pdg_code) > 2212){ ///heavy baryon
                 m_heavyBaryonEnergyWidth = 0.0;///parameter driving energy resolution
                 m_heavyBaryonEnergyMinimalWidth = 0.0;///parameter driving energy resolution
                 m_heavyBaryonEnergyThreshold = 0.0;///energy threshold
                 m_heavyBaryonAngularResolution = 0.0;///angular resolution
                 m_heavyBaryonEfficiency = 1.0;///efficiency
                 temp_heavyBaryonSigma = CDetectorEffects::Sigma_perfect(energy, m_heavyBaryonEnergyWidth, m_heavyBaryonEnergyMinimalWidth); 
                 m_find_heavyBaryonSigma = &temp_heavyBaryonSigma;
                }
                //
                if(abs(*pdg_code) == 13) {///muon
                 m_muonMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_muonMomentumMinimalWidth = 0.0;///parameter driving momentum resolution
                 m_muonMomentumThreshold = 0.0;///muon threshold 
                 temp_muonSigma = CDetectorEffects::Sigma_perfect(momentum, m_muonMomentumWidth, m_muonMomentumMinimalWidth);
                 m_find_muonSigma = &temp_muonSigma;
                 m_muonAngularResolution = 0.0;///parameter driving angular resolution
                 m_muonEfficiency = 1.0;///efficiency
                 temp_muonMomentum = CDetectorEffects::find_muonMeasuredMomentum_Gauss(momentum, m_muonMomentumThreshold, temp_muonSigma);
                 m_find_muonMomentum = &temp_muonMomentum;
                }
                //
                if(abs(*pdg_code) == 11) {///electron
                 m_electronMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumMinimalWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumThreshold = 0.0;///electron threshold
                 temp_electronSigma = CDetectorEffects::Sigma_perfect(momentum, m_electronMomentumWidth, m_electronMomentumMinimalWidth);
                 m_find_electronSigma = &temp_electronSigma;
                 m_electronAngularResolution = 0.0;///parameter driving angular resolution
                 m_electronEfficiency = 1.0;///efficiency
                 temp_electronMomentum = CDetectorEffects::find_electronMeasuredMomentum_Gauss(momentum, m_electronMomentumThreshold, temp_electronSigma); 
                 m_find_electronMomentum = &temp_electronMomentum;
                }
                break;


            case OurSetup_neutronsDetected:
                if(abs(*pdg_code) == 211) {//
                 m_piCEnergyWidth = 0.5*0.29;///half of that for pions in MINERvA
                 m_piCEnergyMinimalWidth = 0.5*0.134;///half of that for pions in MINERvA
                 m_piCEnergyThreshold = 20*MeV;///MINERvA-like
                 m_piCAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_piCEfficiency = 0.80;///higher than MINERvA's best
                 temp_piCSigma = CDetectorEffects::Sigma_typical(energy, m_piCEnergyWidth, m_piCEnergyMinimalWidth);
                 m_find_piCSigma = &temp_piCSigma;
                }
                //
                if(abs(*pdg_code) == 111){ //
                 m_piZeroEnergyWidth = 0.5*0.214;///half of that for pions in MINOS
                 m_piZeroEnergyMinimalWidth = 0.5*0.04;///half of that for pions in MINOS
                 m_piZeroEnergyThreshold = 20*MeV;///MINERvA-like
                 m_piZeroAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_piZeroEfficiency = 0.60;///higher than T2K ND280's best
                 temp_piZeroSigma = CDetectorEffects::Sigma_em(energy, m_piZeroEnergyWidth, m_piZeroEnergyMinimalWidth);
                 m_find_piZeroSigma = &temp_piZeroSigma;
                }
                //
                if(abs(*pdg_code) == 22){//
                 m_photonEnergyWidth = 0.5*0.214;///half of that for pions in MINOS
                 m_photonEnergyMinimalWidth = 0.5*0.04;///half of that for pions in MINOS
                 m_photonEnergyThreshold = 20*MeV;///energy threshold
                 m_photonAngularResolution = 2.8/180.0*M_PI;///as for electrons
                 m_photonEfficiency = 0.80;///efficiency
                 temp_photonSigma = CDetectorEffects::Sigma_em(energy, m_photonEnergyWidth, m_photonEnergyMinimalWidth);
                 m_find_photonSigma = &temp_photonSigma;
                }
                //
                if(abs(*pdg_code) == 321) {//
                 m_kaonCEnergyWidth = 0.5*0.29;///half of that for pions in MINERvA
                 m_kaonCEnergyMinimalWidth = 0.5*0.134;///half of that for pions in MINERvA
                 m_kaonCEnergyThreshold = 20*MeV;///as pions in MINERvA
                 m_kaonCAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_kaonCEfficiency = 0.80;///as pions
                 temp_kaonCSigma = CDetectorEffects::Sigma_typical(energy, m_kaonCEnergyWidth, m_kaonCEnergyMinimalWidth);
                 m_find_kaonCSigma = &temp_kaonCSigma;
                }
                //
                if(abs(*pdg_code) == 311|| abs(*pdg_code) ==310 || abs(*pdg_code) ==130) {//
                 m_kaonZeroEnergyWidth = 0.5*0.29;///half of that for pionsC in MINERvA
                 m_kaonZeroEnergyMinimalWidth = 0.5*0.134;///half of that for pionsC in MINERvA
                 m_kaonZeroEnergyThreshold = 20*MeV;///as pions in MINERvA
                 m_kaonZeroAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_kaonZeroEfficiency = 0.80;///as pions
                 temp_kaonZeroSigma = CDetectorEffects::Sigma_em(energy, m_kaonZeroEnergyWidth, m_kaonZeroEnergyMinimalWidth);
                 m_find_kaonZeroSigma = &temp_kaonZeroSigma;
                }
                //
                if(abs(*pdg_code) == 2212) {//
                 m_protonEnergyWidth = 0.5*0.29;///half of that for protons in MINERvA
                 m_protonEnergyMinimalWidth = 0.5*0.134;///half of that for protons in MINERvA
                 m_protonEnergyThreshold = 40*MeV;///MINERvA-like
                 m_protonAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_protonEfficiency = 0.50;///higher than NOMAD's best
                 temp_protonSigma = CDetectorEffects::Sigma_typical(energy, m_protonEnergyWidth, m_protonEnergyMinimalWidth); 
                 m_find_protonSigma = &temp_protonSigma; 
                }  
                //
                if(abs(*pdg_code) == 2112){//
                 m_neutronEnergyWidth = 0.5*0.29;///
                 m_neutronEnergyMinimalWidth = 0.5*0.134;///
                 m_neutronEnergyThreshold = 40*MeV;///
                 m_neutronAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons                 
                 m_neutronEfficiency = 0.50;///
                 temp_neutronSigma = CDetectorEffects::Sigma_typical(energy, m_neutronEnergyWidth, m_neutronEnergyMinimalWidth);
                 m_find_neutronSigma = &temp_neutronSigma;
                }
                //
                if(abs(*pdg_code) > 2212) {//
                 m_heavyBaryonEnergyWidth = 0.5*0.29;///
                 m_heavyBaryonEnergyMinimalWidth = 0.5*0.134;///
                 m_heavyBaryonEnergyThreshold = 40*MeV + 20*MeV;///energy threshold
                 m_heavyBaryonAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_heavyBaryonEfficiency = 0.50;///efficiency
                 temp_heavyBaryonSigma = CDetectorEffects::Sigma_typical(energy, m_heavyBaryonEnergyWidth, m_heavyBaryonEnergyMinimalWidth); 
                 m_find_heavyBaryonSigma = &temp_heavyBaryonSigma;  
                }
                //
                if(abs(*pdg_code) == 13){//
                 m_muonMomentumWidth = 0.0;///as MINERvA
                 m_muonMomentumMinimalWidth = 0.02;///as in MINERvA
                 m_muonMomentumThreshold = 0.0*GeV;///perfect reconstruction 
                 temp_muonSigma = CDetectorEffects::Sigma_typical(momentum, m_muonMomentumWidth, m_muonMomentumMinimalWidth);
                 m_find_muonSigma = & temp_muonSigma;
                 m_muonAngularResolution = 0.7/180.0*M_PI;///as in MINERvA
                 m_muonEfficiency = 1.0;///perfect reconstruction
                 temp_muonMomentum = CDetectorEffects::find_muonMeasuredMomentum_Gauss(momentum, m_muonMomentumThreshold, temp_muonSigma);
                 m_find_muonMomentum = &temp_muonMomentum; 
                }
                //
                if(abs(*pdg_code) == 11) {///electron
                 m_electronMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumMinimalWidth = 0.10;///as in NovA and similar to MiniBooNE
                 m_electronMomentumThreshold = 0.0*GeV;///perfect reconstruction
                 temp_electronSigma = CDetectorEffects::Sigma_typical(momentum, m_electronMomentumWidth, m_electronMomentumMinimalWidth);
                 m_find_electronSigma = &temp_electronSigma;
                 m_electronAngularResolution = 2.8/180.0*M_PI;///as in MiniBooNE
                 m_electronEfficiency = 1.0;///perfect reconstruction
                 temp_electronMomentum = CDetectorEffects::find_electronMeasuredMomentum_Gauss(momentum, m_electronMomentumThreshold, temp_electronSigma);
                 m_find_electronMomentum = &temp_electronMomentum;
                }
                break;

            case OurSetup_neutronsUndetected:
                //
                if(abs(*pdg_code) == 211){ //
                 m_piCEnergyWidth = 0.5*0.29;///half of that for pions in MINERvA
                 m_piCEnergyMinimalWidth = 0.5*0.134;///half of that for pions in MINERvA
                 m_piCEnergyThreshold = 20*MeV;///MINERvA-like
                 m_piCAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_piCEfficiency = 0.80;///higher than MINERvA's best
                 temp_piCSigma = CDetectorEffects::Sigma_typical(energy, m_piCEnergyWidth, m_piCEnergyMinimalWidth);
                 m_find_piCSigma = &temp_piCSigma;
                }
                //
                if(abs(*pdg_code) == 111) {//
                 m_piZeroEnergyWidth = 0.5*0.214;///half of that for pions in MINOS
                 m_piZeroEnergyMinimalWidth = 0.5*0.04;///half of that for pions in MINOS
                 m_piZeroEnergyThreshold = 20*MeV;///MINERvA-like
                 m_piZeroAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_piZeroEfficiency = 0.60;///higher than T2K ND280's best
                 temp_piZeroSigma = CDetectorEffects::Sigma_em(energy, m_piZeroEnergyWidth, m_piZeroEnergyMinimalWidth);
                 m_find_piZeroSigma = &temp_piZeroSigma;
                }
                //
                if(abs(*pdg_code) ==22) {//
                 m_photonEnergyWidth = 0.5*0.214;///half of that for pions in MINOS
                 m_photonEnergyMinimalWidth = 0.5*0.04;///half of that for pions in MINOS
                 m_photonEnergyThreshold = 20*MeV;///energy threshold
                 m_photonAngularResolution = 2.8/180.0*M_PI;///2 times worse than for electrons
                 m_photonEfficiency = 0.80;///efficiency
                 temp_photonSigma = CDetectorEffects::Sigma_em(energy, m_photonEnergyWidth, m_photonEnergyMinimalWidth);
                 m_find_photonSigma = &temp_photonSigma;
                }
                //
                if(abs(*pdg_code) == 321) { //
                 m_kaonCEnergyWidth = 0.5*0.29;///half of that for pions in MINERvA
                 m_kaonCEnergyMinimalWidth = 0.5*0.134;///half of that for pions in MINERvA
                 m_kaonCEnergyThreshold = 20*MeV;///as pions in MINERvA
                 m_kaonCAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_kaonCEfficiency = 0.80;///as pions
                 temp_kaonCSigma = CDetectorEffects::Sigma_typical(energy, m_kaonCEnergyWidth, m_kaonCEnergyMinimalWidth);
                 m_find_kaonCSigma = &temp_kaonCSigma;
                }
                //
                if(abs(*pdg_code) == 311|| abs(*pdg_code) ==310 || abs(*pdg_code) ==130){ //
                 m_kaonZeroEnergyWidth = 0.5*0.29;///half of that for pionsC in MINERvA
                 m_kaonZeroEnergyMinimalWidth = 0.5*0.134;///half of that for pionsC in MINERvA
                 m_kaonZeroEnergyThreshold = 20*MeV;///as pions in MINERvA
                 m_kaonZeroAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_kaonZeroEfficiency = 0.80;///as pions
                 temp_kaonZeroSigma = CDetectorEffects::Sigma_em(energy, m_kaonZeroEnergyWidth, m_kaonZeroEnergyMinimalWidth);
                 m_find_kaonZeroSigma = &temp_kaonZeroSigma;
                }
                //
                if(abs(*pdg_code) == 2212) {//
                 m_protonEnergyWidth = 0.5*0.29;///half of that for protons in MINERvA
                 m_protonEnergyMinimalWidth = 0.5*0.134;///half of that for protons in MINERvA
                 m_protonEnergyThreshold = 40*MeV;///MINERvA-like
                 m_protonAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_protonEfficiency = 0.50;///higher than NOMAD's best
                 temp_protonSigma = CDetectorEffects::Sigma_typical(energy, m_protonEnergyWidth, m_protonEnergyMinimalWidth);
                 m_find_protonSigma = &temp_protonSigma; 
                }
                //
                if(abs(*pdg_code) == 2112) { //
                 m_neutronEnergyWidth = 0.0;///
                 m_neutronEnergyMinimalWidth = 0.0;///
                 m_neutronEnergyThreshold = 0.0;///
                 m_neutronAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_neutronEfficiency = 0.0;///
                 temp_neutronSigma = CDetectorEffects::Sigma_perfect(energy, m_neutronEnergyWidth, m_neutronEnergyMinimalWidth);
                 m_find_neutronSigma = &temp_neutronSigma; 
                }
                //
                if(abs(*pdg_code) > 2212){//
                 m_heavyBaryonEnergyWidth = 0.5*0.29;///
                 m_heavyBaryonEnergyMinimalWidth = 0.5*0.134;///
                 m_heavyBaryonEnergyThreshold = 40*MeV + 20*MeV;///energy threshold
                 m_heavyBaryonAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_heavyBaryonEfficiency = 0.50;///efficiency
                 temp_heavyBaryonSigma = CDetectorEffects::Sigma_typical(energy, m_heavyBaryonEnergyWidth, m_heavyBaryonEnergyMinimalWidth);
                 m_find_heavyBaryonSigma = &temp_heavyBaryonSigma; 
                }
                //
                if(abs(*pdg_code) ==13){ //
                 m_muonMomentumWidth = 0.0;///as MINERvA
                 m_muonMomentumMinimalWidth = 0.02;///as in MINERvA
                 m_muonMomentumThreshold = 0.0*GeV;///perfect reconstruction 
                 /*double*/ temp_muonSigma = CDetectorEffects::Sigma_typical(momentum, m_muonMomentumWidth, m_muonMomentumMinimalWidth);
                 m_find_muonSigma = &temp_muonSigma;
                 m_muonAngularResolution = 0.7/180.0*M_PI;///as in MINERvA
                 m_muonEfficiency = 1.0;///perfect reconstruction
                 temp_muonMomentum = CDetectorEffects::find_muonMeasuredMomentum_Gauss(momentum, m_muonMomentumThreshold, temp_muonSigma);
                 m_find_muonMomentum = &temp_muonMomentum;
                }
                //
                if(abs(*pdg_code) == 11){///electron
                 m_electronMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumMinimalWidth = 0.10;///as in NovA and similar to MiniBooNE
                 m_electronMomentumThreshold = 0.0*GeV;///perfect reconstruction
                 temp_electronSigma = CDetectorEffects::Sigma_typical(momentum, m_electronMomentumWidth, m_electronMomentumMinimalWidth);
                 m_find_electronSigma = &temp_electronSigma;
                 m_electronAngularResolution = 2.8/180.0*M_PI;///as in MiniBooNE
                 m_electronEfficiency = 1.0;///perfect reconstruction
                 temp_electronMomentum = CDetectorEffects::find_electronMeasuredMomentum_Gauss(momentum, m_electronMomentumThreshold, temp_electronSigma);
                 m_find_electronMomentum = &temp_electronMomentum;
                }
                break;

            case DUNE_FastMC:
                //
                if(abs(*pdg_code) == 211){//
                 m_piCEnergyWidth = 0.5*0.29;///half of that for pions in MINERvA
                 m_piCEnergyMinimalWidth = 0.5*0.134;///half of that for pions in MINERvA
                 m_piCEnergyThreshold = 20*MeV;///MINERvA-like
                 m_piCAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_piCEfficiency = 0.80;///higher than MINERvA's best
                 temp_piCSigma = CDetectorEffects::Sigma_typical(energy, m_piCEnergyWidth, m_piCEnergyMinimalWidth); 
                 m_find_piCSigma = &temp_piCSigma;
                }
                //
                if(abs(*pdg_code) == 111) {//
                 m_piZeroEnergyWidth = 0.5*0.214;///half of that for pions in MINOS
                 m_piZeroEnergyMinimalWidth = 0.5*0.04;///half of that for pions in MINOS
                 m_piZeroEnergyThreshold = 20*MeV;///MINERvA-like
                 m_piZeroAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_piZeroEfficiency = 0.60;///higher than T2K ND280's best
                 temp_piZeroSigma = CDetectorEffects::Sigma_em(energy, m_piZeroEnergyWidth, m_piZeroEnergyMinimalWidth);
                 m_find_piZeroSigma = &temp_piZeroSigma;
                }
                //
                if(abs(*pdg_code) == 22) {//
                 m_photonEnergyWidth = 0.5*0.214;///half of that for pions in MINOS
                 m_photonEnergyMinimalWidth = 0.5*0.04;///half of that for pions in MINOS
                 m_photonEnergyThreshold = 20*MeV;///energy threshold
                 m_photonAngularResolution = 2.8/180.0*M_PI;///2 times worse than for electrons
                 m_photonEfficiency = 0.80;///efficiency
                 temp_photonSigma = CDetectorEffects::Sigma_em(energy, m_photonEnergyWidth, m_photonEnergyMinimalWidth); 
                 m_find_photonSigma = &temp_photonSigma;
                }
                //
                if(abs(*pdg_code) == 321) {//
                 m_kaonCEnergyWidth = 0.5*0.29;///half of that for pions in MINERvA
                 m_kaonCEnergyMinimalWidth = 0.5*0.134;///half of that for pions in MINERvA
                 m_kaonCEnergyThreshold = 20*MeV;///as pions in MINERvA
                 m_kaonCAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_kaonCEfficiency = 0.80;///as pions
                 temp_kaonCSigma = CDetectorEffects::Sigma_typical(energy, m_kaonCEnergyWidth, m_kaonCEnergyMinimalWidth);
                 m_find_kaonCSigma = &temp_kaonCSigma;
                }
                //
                if(abs(*pdg_code) == 311|| abs(*pdg_code) ==310 || abs(*pdg_code) ==130) {//
                 m_kaonZeroEnergyWidth = 0.5*0.29;///half of that for pionsC in MINERvA
                 m_kaonZeroEnergyMinimalWidth = 0.5*0.134;///half of that for pionsC in MINERvA
                 m_kaonZeroEnergyThreshold = 20*MeV;///as pions in MINERvA
                 m_kaonZeroAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_kaonZeroEfficiency = 0.80;///as pions
                 temp_kaonZeroSigma = CDetectorEffects::Sigma_em(energy, m_kaonZeroEnergyWidth, m_kaonZeroEnergyMinimalWidth);
                 m_find_kaonZeroSigma = &temp_kaonZeroSigma;
                }
                //
                if(abs(*pdg_code) == 2212) {//
                 m_protonEnergyWidth = 0.5*0.29;///half of that for protons in MINERvA
                 m_protonEnergyMinimalWidth = 0.5*0.134;///half of that for protons in MINERvA
                 m_protonEnergyThreshold = 40*MeV;///MINERvA-like
                 m_protonAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_protonEfficiency = 0.50;///higher than NOMAD's best
                 temp_protonSigma = CDetectorEffects::Sigma_typical(energy, m_protonEnergyWidth, m_protonEnergyMinimalWidth); 
                 m_find_protonSigma = &temp_protonSigma; }
                //
                if(abs(*pdg_code) == 2112) {//
                 m_neutronEnergyWidth = 0.0;///
                 m_neutronEnergyMinimalWidth = 0.0;///
                 m_neutronEnergyThreshold = 0.0;///
                 m_neutronAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_neutronEfficiency = 0.0;///
                 temp_neutronSigma = CDetectorEffects::Sigma_perfect(energy, m_neutronEnergyWidth, m_neutronEnergyMinimalWidth); 
                 m_find_neutronSigma = &temp_neutronSigma;
                }
                //
                if(abs(*pdg_code) >2212){//
                 m_heavyBaryonEnergyWidth = 0.5*0.29;///
                 m_heavyBaryonEnergyMinimalWidth = 0.5*0.134;///
                 m_heavyBaryonEnergyThreshold = 40*MeV + 20*MeV;///energy threshold
                 m_heavyBaryonAngularResolution = 5.6/180.0*M_PI;///2 times worse than for electrons
                 m_heavyBaryonEfficiency = 0.50;///efficiency
                 temp_heavyBaryonSigma = CDetectorEffects::Sigma_typical(energy, m_heavyBaryonEnergyWidth, m_heavyBaryonEnergyMinimalWidth);
                 m_find_heavyBaryonSigma = &temp_heavyBaryonSigma;
                }
                //
                if(abs(*pdg_code) == 13){ //
                 m_muonMomentumWidth = 0.0;///as MINERvA
                 m_muonMomentumMinimalWidth = 0.02;///as in MINERvA
                 m_muonMomentumThreshold = 0.0*GeV;///perfect reconstruction
                 temp_muonSigma = CDetectorEffects::Sigma_typical(momentum, m_muonMomentumWidth, m_muonMomentumMinimalWidth);
                 m_find_muonSigma = &temp_muonSigma;
                 m_muonAngularResolution = 0.7/180.0*M_PI;///as in MINERvA
                 m_muonEfficiency = 1.0;///perfect reconstruction
                 temp_muonMomentum = CDetectorEffects::find_muonMeasuredMomentum_Gauss(momentum, m_muonMomentumThreshold, temp_muonSigma);
                 m_find_muonMomentum = &temp_muonMomentum;                             
                }
                //
                if(abs(*pdg_code) == 11) {///electron
                 m_electronMomentumWidth = 0.0;///parameter driving momentum resolution
                 m_electronMomentumMinimalWidth = 0.10;///as in NovA and similar to MiniBooNE
                 m_electronMomentumThreshold = 0.0*GeV;///perfect reconstruction
                 temp_electronSigma = CDetectorEffects::Sigma_typical(momentum, m_electronMomentumWidth, m_electronMomentumMinimalWidth);
                 m_find_electronSigma = &temp_electronSigma;
                 m_electronAngularResolution = 2.8/180.0*M_PI;///as in MiniBooNE
                 m_electronEfficiency = 1.0;///perfect reconstruction
                 temp_electronMomentum = CDetectorEffects::find_electronMeasuredMomentum_Gauss(momentum, m_electronMomentumThreshold, temp_electronSigma); 
                 m_find_electronMomentum = &temp_electronMomentum;
                }
                break;



       }// end of switch m_experiment
                
                if(*pdg_code == 13 || *pdg_code == -13) {*m_Res= m_muonAngularResolution; *m_Eff= m_muonEfficiency,  *m_Sigma= *m_find_muonSigma; *m_Momentum = *m_find_muonMomentum;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (muon) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 11) {*m_Res= m_electronAngularResolution; *m_Eff= m_electronEfficiency, *m_Sigma= *m_find_electronSigma; *m_Momentum = *m_find_electronMomentum;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (electron) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 2212) {*m_Res = m_protonAngularResolution; *m_Eff= m_protonEfficiency, *m_Sigma = *m_find_protonSigma; *m_Momentum= 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (proton) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 2112) {*m_Res = m_neutronAngularResolution; *m_Eff=m_neutronEfficiency, *m_Sigma = *m_find_neutronSigma; *m_Momentum= 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (neutron) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 211) {*m_Res= m_piCAngularResolution; *m_Eff = m_piCEfficiency, *m_Sigma= *m_find_piCSigma; *m_Momentum = 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (piC) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 111) {*m_Res = m_piZeroAngularResolution; *m_Eff = m_piZeroEfficiency, *m_Sigma = *m_find_piZeroSigma; *m_Momentum= 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (piZero) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 321) {*m_Res= m_kaonCAngularResolution; *m_Eff = m_kaonCEfficiency, *m_Sigma= *m_find_kaonCSigma; *m_Momentum = 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (kaonC) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else if(abs(*pdg_code) == 311 ||abs(*pdg_code) ==310 || abs(*pdg_code) ==130) {
                     *m_Res = m_kaonZeroAngularResolution; *m_Eff= m_kaonZeroEfficiency, *m_Sigma = *m_find_kaonZeroSigma; *m_Momentum= 0;
                     //std::cout<<"[Base::CDetectorEffects::getSigma] (kaonZero) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;
                }

                else if(abs(*pdg_code) == 22) {*m_Res = m_photonAngularResolution; *m_Eff= m_photonEfficiency,  *m_Sigma = *m_find_photonSigma; *m_Momentum= 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (photon) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                else /*if(abs(*pdg_code) == 311)*/ {*m_Res = m_heavyBaryonAngularResolution; *m_Eff= m_heavyBaryonEfficiency,  *m_Sigma = *m_find_heavyBaryonSigma; *m_Momentum= 0;
                /*std::cout<<"[Base::CDetectorEffects::getSigma] (heavyBaryon) resolution is "<<*m_Res<<" Sigma is "<<*m_Sigma<<" Momentum is "<<*m_Momentum<<std::endl;*/}

                

    }


    //~CDetectorEffects()
    //{
    //      delete m_gauss;
    //}

    
    typedef double (*DMuonMomentumPtr);//typedef double (CDetectorEffects::*DMuonMomentumPtr)(const double) const;
    typedef double (*DElectronMomentumPtr);//typedef double (CDetectorEffects::*DElectronMomentumPtr)(const double) const;


    /*inline*/ double get_angularResolution_piC() const
    {
        return m_piCAngularResolution;
    }

    /*inline*/ double get_angularResolution_piZero() const
    {
        return m_piZeroAngularResolution;
    }

    /*inline*/ double get_angularResolution_photon() const
    {
        return m_photonAngularResolution;
    }

    /*inline*/ double get_angularResolution_kaonC() const
    {
        return m_kaonCAngularResolution;
    }

    /*inline*/ double get_angularResolution_kaonZero() const
    {
        return m_kaonZeroAngularResolution;
    }

    /*inline*/ double get_angularResolution_proton() const
    {
        return m_protonAngularResolution;
    }

    /*inline*/ double get_angularResolution_neutron() const
    {
        return m_neutronAngularResolution;
    }

    /*inline*/ double get_angularResolution_heavyBaryon() const
    {
        return m_heavyBaryonAngularResolution;
    }

    /*inline*/ double get_angularResolution_muon() const
    {
        return m_muonAngularResolution;
    }

    /*inline*/ double get_angularResolution_electron() const
    {
        return m_electronAngularResolution;
    }


    /*inline*/ double find_measuredEnergy_piC(/*const*/ double energy, double mm_piCEfficiency, double temp_Sigma_piC) const
    {
        if ( energy <= m_piCEnergyThreshold )
            return 0.0;

        if ( mm_piCEfficiency < 1.0 and m_rnd > mm_piCEfficiency )
            return 0.0;
        //std::cout<<"[Base::CDetectorEffects::find_measuredEnergy_piC energy = "<<energy<<" temp_Sigma_piC "<<temp_Sigma_piC<<std::endl;
        //const double sigma(   m_find_piCSigma(energy, m_piCEnergyWidth, m_piCEnergyMinimalWidth)   );
        //const double sigma( *m_find_piCSigma);
        const double sigma = temp_Sigma_piC;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_piCEnergyThreshold )
            std::cout<<"[Base::CDetectorEffects::find_measuredEnergy_piC is "<<measuredEnergy<<std::endl;
                return measuredEnergy;
        }
    }

    
    /*inline*/ double find_measuredEnergy_piZero(/*const*/ double energy, double mm_piZeroEfficiency, double temp_Sigma_piZero) const
    {
        if ( energy <= m_piZeroEnergyThreshold )
            return 0.0;

        if ( mm_piZeroEfficiency < 1.0 and m_rnd > mm_piZeroEfficiency )
            return 0.0;

        //const double sigma(   m_find_piZeroSigma(energy, m_piZeroEnergyWidth, m_piZeroEnergyMinimalWidth)   );
        //const double sigma( *m_find_piZeroSigma);
        const double sigma = temp_Sigma_piZero;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_piZeroEnergyThreshold )
                return measuredEnergy;
        }
    }

   
    /*inline*/ double find_measuredEnergy_photon(/*const*/ double energy, double mm_photonEfficiency, double temp_photonSigma) const
    {
        if ( energy <= m_photonEnergyThreshold )
            return 0.0;

        if ( mm_photonEfficiency < 1.0 and m_rnd > mm_photonEfficiency )
            return 0.0;

        //const double sigma(   m_find_photonSigma(energy, m_photonEnergyWidth, m_photonEnergyMinimalWidth)   );
        //const double sigma (*m_find_photonSigma);
        const double sigma = temp_photonSigma;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_photonEnergyThreshold )
                return measuredEnergy;
        }
    }


    /*inline*/ double find_measuredEnergy_kaonC(/*const*/ double energy, double mm_kaonCEfficiency, double temp_kaonCSigma) const
    {
        if ( energy <= m_kaonCEnergyThreshold )
            return 0.0;

        if ( mm_kaonCEfficiency < 1.0 and m_rnd > mm_kaonCEfficiency )
            return 0.0;

        //const double sigma(   m_find_kaonCSigma(energy, m_kaonCEnergyWidth, m_kaonCEnergyMinimalWidth)   );
        //const double sigma( *m_find_kaonCSigma);
        const double sigma = temp_kaonCSigma;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_kaonCEnergyThreshold )
                return measuredEnergy;
        }
    }


    /*inline*/ double find_measuredEnergy_kaonZero(/*const*/ double energy, double mm_kaonZeroEfficiency, double temp_kaonZeroSigma) const
    {
        if ( energy <= m_kaonZeroEnergyThreshold )
            return 0.0;

        if ( mm_kaonZeroEfficiency < 1.0 and m_rnd > mm_kaonZeroEfficiency )
            return 0.0;

        //const double sigma(   m_find_kaonZeroSigma(energy, m_kaonZeroEnergyWidth, m_kaonZeroEnergyMinimalWidth)   );
        //const double sigma (*m_find_kaonZeroSigma);
        const double sigma = temp_kaonZeroSigma;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_kaonZeroEnergyThreshold )
                return measuredEnergy;
        }
    }


    /*inline*/ double find_measuredEnergy_proton(/*const*/ double energy, double mm_protonEfficiency, double temp_protonSigma) const
    {
        //std::cout<<"Base::CDetectorEffects::find_measuredEnergy_proton m_rnd = "<<m_rnd<<" energy is "<<energy<<" m_protonEfficiency"<<mm_protonEfficiency<<" sigma is "<<temp_protonSigma<<std::endl;
        if ( energy <= m_protonEnergyThreshold )
            return 0.0;
        if ( mm_protonEfficiency < 1.0 and m_rnd > mm_protonEfficiency )
            return 0.0;
 
        //const double sigma(   m_find_protonSigma(energy, m_protonEnergyWidth, m_protonEnergyMinimalWidth)   );
        const double sigma = temp_protonSigma; //const double sigma ( *m_find_protonSigma);
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_protonEnergyThreshold )
                return measuredEnergy;
        }


    }


   /*inline*/ double find_measuredEnergy_neutron(/*const*/ double energy, double mm_neutronEfficiency, double temp_neutronSigma) const
   {
        //std::cout<<"[Base::CDetectorEffects::find_measuredEnergy_neutron] m_rnd = "<<m_rnd<< "<<energy<<"<<energy<<" mm_neutronEfficiency "<<mm_neutronEfficiency<<" sigma is "<<temp_neutronSigma<<std::endl;

        if ( mm_neutronEfficiency <= 0.0 || energy <= m_neutronEnergyThreshold )
            return 0.0;
        if ( mm_neutronEfficiency < 1.0 and m_rnd > mm_neutronEfficiency )
            return 0.0;

        //const double sigma(   m_find_neutronSigma(energy, m_neutronEnergyWidth, m_neutronEnergyMinimalWidth)   );
        //const double sigma (*m_find_neutronSigma);
        const double sigma = temp_neutronSigma;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_neutronEnergyThreshold )
                return measuredEnergy;
        
        }
    }


    /*inline*/ double find_measuredEnergy_heavyBaryon(/*const*/ double energy, double mm_heavyBaryonEfficiency,  double temp_heavyBaryonSigma) const
   {
        if ( energy <= m_heavyBaryonEnergyThreshold )
            return 0.0;
        if ( mm_heavyBaryonEfficiency < 1.0 and m_rnd > mm_heavyBaryonEfficiency )
            return 0.0;

        std::cout<<"[Base::CDetectorEffects::find_measuredEnergy_heavyBaryon] energy is "<<energy<<" sigma is "<<temp_heavyBaryonSigma<<std::endl;
         //const double sigma(   m_find_heavyBaryonSigma(energy, m_heavyBaryonEnergyWidth, m_heavyBaryonEnergyMinimalWidth)   );
        //const double sigma( *m_find_heavyBaryonSigma);
        const double sigma = temp_heavyBaryonSigma;
        while (true)
        {
            const double measuredEnergy(   m_gauss->generate(energy, sigma)   );
            if ( measuredEnergy >= m_heavyBaryonEnergyThreshold )
                return measuredEnergy;
        
        }
    }


    DMuonMomentumPtr m_find_muonMomentum;
    DMuonMomentumPtr m_find_electronMomentum;


    /*inline*/ double find_muonMeasuredMomentum(/*const*/ double momentum) /*const*/
    {   
        return momentum;//return (this->*m_find_muonMomentum)(momentum);
    }
       
    /*inline*/ double find_electronMeasuredMomentum(/*const*/ double momentum) /*const*/
    {
        return momentum;//return (this->*m_find_electronMomentum)(momentum);
    }

    
    void find_measuredThreeMomentum_hadron(const double angularResolution, const double measuredEnergy, const double mass, double& kx, double& ky, double& kz) const
    {
        const double momentumSq( kx*kx + ky*ky + kz*kz  );
        const double momentum( sqrt(momentumSq)  );
        const double totalEnergy( measuredEnergy + mass );
        const double measuredMomentum( sqrt(totalEnergy*totalEnergy - mass*mass) );

        if ( measuredMomentum <= 0.0 or momentum <= 0.0  )///if measuredMomentum == 0.0, we are below the threshold
        {
            kx = 0.0;
            ky = 0.0;
            kz = 0.0;
            return;
        }

        if ( angularResolution <= 0.0 )
        {
            kx *= measuredMomentum/momentum;
            ky *= measuredMomentum/momentum;
            kz *= measuredMomentum/momentum;
            return;
        }

        const double theta( acos(kz/momentum) );
        const double deltaTheta( find_angularMisreconstruction(angularResolution) );

        const double cosMeasTheta(   cos( theta + deltaTheta )   );
        const double sinMeasTheta(   sin( theta + deltaTheta )   );

        const double phi( atan2(ky, kx) );
        const double deltaPhi( find_angularMisreconstruction(angularResolution) );

        kx = measuredMomentum*sinMeasTheta*cos(phi + deltaPhi);
        ky = measuredMomentum*sinMeasTheta*sin(phi + deltaPhi);
        kz = measuredMomentum*cosMeasTheta;
    }

    void find_measuredThreeMomentum_nonhadron(const double angularResolution, const double measuredMomentum, double& kx, double& ky, double& kz) const
    {
        const double momentum( sqrt(kx*kx + ky*ky + kz*kz)  );

        if ( measuredMomentum <= 0.0 or momentum <= 0.0  )///if measuredMomentum == 0.0, we are below the threshold
        {
            kx = 0.0;
            ky = 0.0;
            kz = 0.0;
            return;
        }

        if ( angularResolution <= 0.0 )
        {
            kx *= measuredMomentum/momentum;
            ky *= measuredMomentum/momentum;
            kz *= measuredMomentum/momentum;
            return;
        }

        const double theta( acos(kz/momentum) );
        const double deltaTheta( find_angularMisreconstruction(angularResolution) );

        const double cosMeasTheta(   cos( theta + deltaTheta )   );
        const double sinMeasTheta(   sin( theta + deltaTheta )   );

        const double phi( atan2(ky, kx) );
        const double deltaPhi( find_angularMisreconstruction(angularResolution) );

        kx = measuredMomentum*sinMeasTheta*cos(phi + deltaPhi);
        ky = measuredMomentum*sinMeasTheta*sin(phi + deltaPhi);
        kz = measuredMomentum*cosMeasTheta;
    }

 
  private:
    //const ExperimentName m_experiment= PerfectReconstruction_neutronsDetected;
    CRandomGen m_rnd;
    CGaussianDistrib* m_gauss;        
    double temp_muonSigma; 
    double temp_muonMomentum; 
    double temp_electronSigma;
    double temp_electronMomentum;
    double temp_protonSigma;
    double temp_neutronSigma;    
    double temp_piCSigma;
    double temp_piZeroSigma;
    double temp_photonSigma;
    double temp_kaonCSigma;
    double temp_kaonZeroSigma;
    double temp_heavyBaryonSigma;






    double m_piCEnergyWidth;///charged pion
    double m_piCEnergyMinimalWidth;
    double m_piCEnergyThreshold;
    double m_piCAngularResolution;
    double m_piCEfficiency;
    DFindSigmaPtr m_find_piCSigma;

    double m_piZeroEnergyWidth;///neutral pion
    double m_piZeroEnergyMinimalWidth;
    double m_piZeroEnergyThreshold;
    double m_piZeroAngularResolution;
    double m_piZeroEfficiency;
    DFindSigmaPtr m_find_piZeroSigma;

    double m_photonEnergyWidth;///photon
    double m_photonEnergyMinimalWidth;
    double m_photonEnergyThreshold;
    double m_photonAngularResolution;
    double m_photonEfficiency;
    DFindSigmaPtr m_find_photonSigma;

    double m_kaonCEnergyWidth;///charged kaon
    double m_kaonCEnergyMinimalWidth;
    double m_kaonCEnergyThreshold;
    double m_kaonCAngularResolution;
    double m_kaonCEfficiency;
    DFindSigmaPtr m_find_kaonCSigma;

    double m_kaonZeroEnergyWidth;///neutral kaon
    double m_kaonZeroEnergyMinimalWidth;
    double m_kaonZeroEnergyThreshold;
    double m_kaonZeroAngularResolution;
    double m_kaonZeroEfficiency;
    DFindSigmaPtr m_find_kaonZeroSigma;

    double m_protonEnergyWidth;///proton
    double m_protonEnergyMinimalWidth;
    double m_protonEnergyThreshold;
    double m_protonAngularResolution;
    double m_protonEfficiency;
    DFindSigmaPtr m_find_protonSigma;
 
    double m_neutronEnergyWidth;///neutron
    double m_neutronEnergyMinimalWidth;
    double m_neutronEnergyThreshold;
    double m_neutronAngularResolution;
    double m_neutronEfficiency;
    DFindSigmaPtr m_find_neutronSigma;

    double m_heavyBaryonEnergyWidth;///heavyBaryon
    double m_heavyBaryonEnergyMinimalWidth;
    double m_heavyBaryonEnergyThreshold;
    double m_heavyBaryonAngularResolution;
    double m_heavyBaryonEfficiency;
    DFindSigmaPtr m_find_heavyBaryonSigma;

    double m_muonMomentumWidth;///muon, note that the parameters regard momentum and not energy
    double m_muonMomentumMinimalWidth;
    double m_muonMomentumThreshold;
    double m_muonAngularResolution;
    double m_muonEfficiency;
    DFindSigmaPtr m_find_muonSigma;

    double m_electronMomentumWidth;///electron
    double m_electronMomentumMinimalWidth;
    double m_electronMomentumThreshold;
    double m_electronAngularResolution;
    double m_electronEfficiency;
    DFindSigmaPtr m_find_electronSigma;

    /*inline*/ double find_angularMisreconstruction(double angularResolution) const
    {
        return m_gauss->generate(0.0, angularResolution);
    }

    /*inline*/ double find_muonMeasuredMomentum_Gauss(/*const*/ double momentum, double m_muonMomentumThreshold, double temp_muonSigma) const
    {
        if ( momentum <= m_muonMomentumThreshold )
            return 0.0;
        if ( m_muonEfficiency < 1.0 and m_rnd > m_muonEfficiency )
            return 0.0;

        //const double sigma(   m_find_muonSigma(momentum, m_muonMomentumWidth, m_muonMomentumMinimalWidth)   );
        const double sigma = temp_muonSigma; //const double sigma (*m_find_muonSigma);

        double measuredMomentum; 
        while (true)
        {   
            /*const double*/ measuredMomentum = m_gauss->generate(momentum, sigma);
            if ( measuredMomentum >= m_muonMomentumThreshold )
                return measuredMomentum;
        } 
    }

    /*inline*/ double find_electronMeasuredMomentum_Gauss(/*const*/ double momentum, double m_electronMomentumThreshold, double temp_electronSigma) const
    {
        if ( momentum <= m_electronMomentumThreshold )
            return 0.0;

        if ( m_electronEfficiency < 1.0 and m_rnd > m_electronEfficiency )
            return 0.0;

        //const double sigma(   m_find_electronSigma(momentum, m_electronMomentumWidth, m_electronMomentumMinimalWidth)   );
        //const double sigma (*m_find_electronSigma);
        const double sigma = temp_electronSigma;
        while (true)
        {
            const double measuredMomentum(   m_gauss->generate(momentum, sigma)   );
            if ( measuredMomentum >= m_electronMomentumThreshold )
                return measuredMomentum;
        }
    }

  };
}

#endif
/** @} */ // end of doxygen group 

