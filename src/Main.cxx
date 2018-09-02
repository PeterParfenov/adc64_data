#include <iostream>

#include "adc64_data.h"

int main(int argc, char **argv)
{
  TString inFileName, outFileName;
  if (argc < 5)
  {
    std::cerr << "./Main -i INPUTFILE -o OUTPUTFILE" << std::endl;
    return 10;
  }

  for (int i = 1; i < argc; i++)
  {
    if (std::string(argv[i]) != "-i" &&
        std::string(argv[i]) != "-o")
    {
      std::cerr << "\nMain: Unknown parameter: " << i << ": " << argv[i] << std::endl;
      return 11;
    }
    else
    {
      if (std::string(argv[i]) == "-i" && i != argc - 1)
      {
        inFileName = argv[++i];
      }
      if (std::string(argv[i]) == "-i" && i == argc - 1)
      {
        std::cerr << "\nMain: Input file name was not specified!" << std::endl;
        return 12;
      }
      if (std::string(argv[i]) == "-o" && i != argc - 1)
      {
        outFileName = argv[++i];
      }
      if (std::string(argv[i]) == "-o" && i == argc - 1)
      {
        std::cerr << "\nMain: Output file name was not specified!" << std::endl;
        return 13;
      }
    }
  }

  TTree *tree;

  // TFile *inFile = (TFile *)gROOT->GetListOfFiles()->FindObject(inFileName.Data());
  TFile *inFile = new TFile(inFileName.Data(), "read");
  // TFile *outFile = new TFile(outFileName.Data(), "recreate");
  if (!inFile || !inFile->IsOpen())
  {
    std::cerr << "\nMain: File " << inFileName.Data() << " was not found/opened." << std::endl;
    return 11;
  }
  inFile->GetObject("adc64_data", tree);

  adc64_data *adc = new adc64_data(tree, outFileName);
  adc->SetCorrelations();
  adc->InitHist();
  adc->Loop();
  adc->WriteHist();

  delete adc;

  return 0;
}
