#ifndef __MAIN_ANALYSE_CXX__
#define __MAIN_ANALYSE_CXX__

#include "Analyse.h"

using namespace Base;

namespace Main{
	void Analyse::SetInputFile(std::string f){

		mc_inputfile_name = f;

	}
	void Analyse::DoAnalyse(){
	clock_t begin=clock();
	//=====================================================================
	std::string analyser_outdir = std::getenv("MYSW_OUTDIR");
	analyser_outdir += "output_data_mc/";
	std::string mkdir_command = "mkdir -p ";
	mkdir_command += analyser_outdir;
	system(mkdir_command.c_str());

	//LOG_NORMAL() << "Created output folder with name " << analyser_outdir << "." << std::endl;
  
	//gROOT->SetBatch(kTRUE);

	gROOT->ProcessLine("gErrorIgnoreLevel = 2001;"); // 1001: INFO, 2001: WARNINGS, 3001: ERRORS

	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	TFile* mc_inputfile;
	mc_inputfile  = TFile::Open(mc_inputfile_name.c_str(), "READ");
	//get all the true_reco migraton matrix
        DUNENDEventHisto1D* _event_histo_1d_mc;
	//std::map<std::string,TH1D*>* temp_map;
	std::map<std::string,TH2D*>* temp_map_2d;
	mc_inputfile->GetObject("hmap_true_calc_temp", temp_map_2d);
	std::map<std::string,TH2D*> hmap_tempmc = *temp_map_2d;
	
	for(int ind=0; ind<calOptions; ind++){
	
	 	
		ith_neutroneff.push_back(std::to_string(ind*100)+"_percent");


		int n_bins_temp = 78;

		TMatrix S_2d; S_2d.Clear(); S_2d.ResizeTo(n_bins_temp+1, n_bins_temp+1); 

		MigrationMatrixCalc migrationmatrix2d;
		migrationmatrix2d.SetOutDir("histo_temp"+std::to_string(ind));         
		migrationmatrix2d.SetNBins(n_bins_temp, n_bins_temp);
		migrationmatrix2d.SetTrueRecoHistogram(hmap_tempmc[ith_neutroneff.at(ind)]);
		//S_2d = migrationmatrix2d.CalculateMigrationMatrix();
		S_2d = migrationmatrix2d.CalculateMigrationMatrix_Globe();
		//migrationmatrix2d.PlotMatrix();
		migrationmatrix2d.SetOutputFileName("migration_matrix_2d_"+std::to_string(ind)+".tex");
		//migrationmatrix2d.PrintSmearingMatrixLatex();
		migrationmatrix2d.PrintMigrationMatrix_Globe();
			
	}

        //=======================================================================
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << std::endl << std::endl << "Computing time: " << elapsed_secs << " seconds = " << elapsed_secs/60. << " minutes." << std::endl << std::endl;
  	return;
	}//end of function doanlayse
} //end of using name space main









#endif
