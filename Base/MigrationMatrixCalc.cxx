#ifndef __BASE_MIGRATIONMATRIXCALC_CXX__
#define __BASE_MIGRATIONMATRIXCALC_CXX__

#include "MigrationMatrixCalc.h"

namespace Base{


   void MigrationMatrixCalc::SetOutputFileName(std::string name)
   {
      if(_f_out.is_open()){
         _f_out.close();
      }
      _f_out.open(_folder+name, std::ios::out | std::ios::trunc);

   }
   void MigrationMatrixCalc::SetOutFir(std::string dir)
   {
      std::string out_folder_base = std::getenv("MYSW_OUTDIR");
      _outdir = out_folder_base + dir;
      auto now = std::time(nullptr);
      char buf[sizeof("YYYY-MM-DD_HH-MM-SS")];
      std::string timestamp = std::string(buf,buf + std::strftime(buf,sizeof(buf),"%F_%H-%M-%S",std::gmtime(&now)));

      _folder = _outdir + "_" + timestamp + "/";

      system(("mkdir " + _folder).c_str());


   }
   void MigrationMatrixCalc::SetTrueRecoHistogram(TH2D *h)
   {
      _h_true_reco_mom = h;
   }


   void MigrationMatrixCalc::SetNBins(int n_var1_bins, int n_var2_bins)
   {
      _n = n_var1_bins;
      _m = n_var2_bins;
   }
 
   TMatrix MigrationMatrixCalc::CalculateMigrationMatrix()
   {
      //n x m matrix
      //n= number of rows
      //m= number of columns
      //
      //TMatrix S;
      _S.Clear();
      _S.ResizeTo(_n+1, _m+1); // over flow bin added

      for(int j=0; j<_m+2; j++) {
         int true_idx = j-1;
         if(j==0 ) true_idx = _m;
         if(j== _m+1) true_idx = _m;
         
         std::vector<double> p_v;
         p_v.resize(_n+1);
         double sum = 0;
         for (int i = 0; i < _n + 2; i++) {      // Reco bin        
            p_v.at(i) = _h_true_reco_mom->GetBinContent(j, i);
            sum += p_v.at(i);
         } ///end of loop over i the reco bin
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         double tot_prob = 0;
         for (int i = 1; i < _n + 1; i++) {
            if (sum == 0 || std::isnan(sum))
               p_v.at(i) = 0;
            else
            p_v.at(i) /= sum;
            //LOG_DEBUG() << "\t\tProbability at " << i << " is " << p_v.at(i) << std::endl;
            tot_prob += p_v.at(i);

            _S[i - 1][true_idx] += p_v.at(i);
         }
         //Add over/under flow
         _S[_n][true_idx] = p_v.at(0) / sum + p_v.at(_n + 1) / sum;
      }// true bin

      if(_verbose) _S.Print();
      return _S;


   } //end of the function calculate migration matrix
   void MigrationMatrixCalc::PlotMatrix(){

   }
   void MigrationMatrixCalc::PrintSmearingMatrixLatex()
   {
    if (!_f_out.is_open()) {
      std::cout << "File not opened." << std::endl;
      return;
    }

    _f_out << "Last entry is the overflow bin." << std::endl;
    _f_out << "\\begin{equation}" << std::endl;
    _f_out << "S_{ij} =" << std::endl;
    _f_out << "\\begin{bmatrix}" << std::endl;

    for (int i = 0; i < _n + 1; i++) {
      for (int j = 0; j < _m + 1; j++) {

        _f_out << std::setprecision(3) << _S[i][j] << "  &  ";

      }

      _f_out << " \\\\" << std::endl;
    }

    _f_out << "\\end{bmatrix}" << std::endl;
    _f_out << "\\end{equation}" << std::endl << std::endl;

  }
 



}//end of base namespace



#endif
