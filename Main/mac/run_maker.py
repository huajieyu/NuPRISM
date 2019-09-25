import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()


calc_syst_list = ["PerfectReconstruction_neutronsDetected"]
#calc_syst_list = ["PerfectReconstruction_neutronsUndetected"]
#calc_syst_list = ["OurSetup_neutronsDetected"]
#calc_syst_list = ["OurSetup_neutronsUndetected"]
#calc_syst_list = ["DUNE_FastMC"]

for systname in calc_syst_list:
	maker.SetInputFile("/pnfs/genie/persistent/users/jiangl/GENIE_sample/gntp.1000.gst.286.root");

	maker.SetOutputFile("/genie/app/users/jiangl/NuPRISM_output/output_"+systname+".root");

	maker.SetNeutrinoFlavor(1);  # the options are 1(numu), 2(anumu), 3(nue, 4(anue)  

	maker.SetInteractionType(4); # the options are 1 (QE), 2 (RES), 3 (DIS) 4 (MEC) 5(COH)0(ALL);

	maker.SetExperimentName(systname);

	maker.SetFSIOn(True);



	maker.PrintConfig()

	maker.MakeFile()
