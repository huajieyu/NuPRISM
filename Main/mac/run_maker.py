import sys, os

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

maker = Main.Maker()


maker.SetInputFile("/pnfs/genie/persistent/users/jiangl/GENIE_sample/gntp.1000.gst.286.root");

maker.SetOutputFile("/genie/app/users/jiangl/NuPRISM_output/output_test.root");

maker.SetNeutrinoFlavor(0);  # the options are 0(numu), 1(anumu), 2(nue, 3(anue)

maker.SetInteractionType(0); # the options are 0 (QE), 1 (RES), 2 (DIS) 3 (MEC)

#maker.SetExperimentName("PerfectReconstruction_neutronsDetected");
#maker.SetExperimentName("PerfectReconstruction_neutronsUndetected");
#maker.SetExperimentName("OurSetup_neutronsDetected");
#maker.SetExperimentName("OurSetup_neutronsUndetected");
maker.SetExperimentName("DUNE_FastMC");





maker.PrintConfig()

maker.MakeFile()
