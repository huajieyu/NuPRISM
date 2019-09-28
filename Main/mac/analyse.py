import sys, os, math

from ROOT import gROOT
gROOT.ProcessLine(".x " + os.environ['MYSW_DIR'] + "/Utils/rootlogon.C")

from ROOT import Main

analyser = Main.Analyse()


analyser.SetInputFile     ("/genie/app/users/jiangl/NuPRISM_output/output_simplifiedgen.root") # Tune 1 - full stat - full syst


analyser.DoAnalyse();

raw_input("Please press enter to exit.")
