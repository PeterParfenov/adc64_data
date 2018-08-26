#ifndef adc64_data_h
#define adc64_data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <iostream>
#include <map>

namespace adc64_info
{
const Int_t Nchannels = 10;
const Int_t kNoBins = 100;
const Double_t kHistoWeight = 1.;
} // namespace adc64_info

using namespace adc64_info;

class adc64_data
{
public:
  adc64_data(TTree *tree, TString _outFileName);
  virtual ~adc64_data();
  virtual Int_t GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void Loop();
  virtual void Init(TTree *tree);
  virtual void Show(Long64_t entry = -1);
  virtual void WriteHist();

private:
  TTree *fChain;  //!pointer to the analyzed TTree or TChain
  Int_t fCurrent; //!current Tree number in a TChain

  // Fixed size dimensions of array or collections stored in the TTree if any.

  // Declaration of leaf types

  Int_t channel_integral_in_gate[Nchannels];
  Float_t channel_mean_in_gate[Nchannels];
  Float_t channel_mean_out_gate[Nchannels];
  Float_t channel_RMS_in_gate[Nchannels];
  Float_t channel_RMS_out_gate[Nchannels];
  Float_t channel_zero_level[Nchannels];
  Float_t channel_zero_level_RMS[Nchannels];
  Float_t channel_time_cross[Nchannels];
  Float_t channel_time_half[Nchannels];
  Short_t channel_MAX_in_gate[Nchannels];
  Short_t channel_MIN_in_gate[Nchannels];
  Short_t channel_MAX_out_gate[Nchannels];
  Short_t channel_MIN_out_gate[Nchannels];
  UShort_t channel_time_max_in_gate[Nchannels];
  UShort_t channel_time_min_in_gate[Nchannels];
  ULong64_t channel_iEvt[Nchannels];

  Int_t channel_0_integral_in_gate;
  Float_t channel_0_mean_in_gate;
  Float_t channel_0_mean_out_gate;
  Float_t channel_0_RMS_in_gate;
  Float_t channel_0_RMS_out_gate;
  Float_t channel_0_zero_level;
  Float_t channel_0_zero_level_RMS;
  Float_t channel_0_time_cross;
  Float_t channel_0_time_half;
  Short_t channel_0_MAX_in_gate;
  Short_t channel_0_MIN_in_gate;
  Short_t channel_0_MAX_out_gate;
  Short_t channel_0_MIN_out_gate;
  UShort_t channel_0_time_max_in_gate;
  UShort_t channel_0_time_min_in_gate;
  ULong64_t channel_0_iEvt;
  Int_t channel_1_integral_in_gate;
  Float_t channel_1_mean_in_gate;
  Float_t channel_1_mean_out_gate;
  Float_t channel_1_RMS_in_gate;
  Float_t channel_1_RMS_out_gate;
  Float_t channel_1_zero_level;
  Float_t channel_1_zero_level_RMS;
  Float_t channel_1_time_cross;
  Float_t channel_1_time_half;
  Short_t channel_1_MAX_in_gate;
  Short_t channel_1_MIN_in_gate;
  Short_t channel_1_MAX_out_gate;
  Short_t channel_1_MIN_out_gate;
  UShort_t channel_1_time_max_in_gate;
  UShort_t channel_1_time_min_in_gate;
  ULong64_t channel_1_iEvt;
  Int_t channel_2_integral_in_gate;
  Float_t channel_2_mean_in_gate;
  Float_t channel_2_mean_out_gate;
  Float_t channel_2_RMS_in_gate;
  Float_t channel_2_RMS_out_gate;
  Float_t channel_2_zero_level;
  Float_t channel_2_zero_level_RMS;
  Float_t channel_2_time_cross;
  Float_t channel_2_time_half;
  Short_t channel_2_MAX_in_gate;
  Short_t channel_2_MIN_in_gate;
  Short_t channel_2_MAX_out_gate;
  Short_t channel_2_MIN_out_gate;
  UShort_t channel_2_time_max_in_gate;
  UShort_t channel_2_time_min_in_gate;
  ULong64_t channel_2_iEvt;
  Int_t channel_3_integral_in_gate;
  Float_t channel_3_mean_in_gate;
  Float_t channel_3_mean_out_gate;
  Float_t channel_3_RMS_in_gate;
  Float_t channel_3_RMS_out_gate;
  Float_t channel_3_zero_level;
  Float_t channel_3_zero_level_RMS;
  Float_t channel_3_time_cross;
  Float_t channel_3_time_half;
  Short_t channel_3_MAX_in_gate;
  Short_t channel_3_MIN_in_gate;
  Short_t channel_3_MAX_out_gate;
  Short_t channel_3_MIN_out_gate;
  UShort_t channel_3_time_max_in_gate;
  UShort_t channel_3_time_min_in_gate;
  ULong64_t channel_3_iEvt;
  Int_t channel_4_integral_in_gate;
  Float_t channel_4_mean_in_gate;
  Float_t channel_4_mean_out_gate;
  Float_t channel_4_RMS_in_gate;
  Float_t channel_4_RMS_out_gate;
  Float_t channel_4_zero_level;
  Float_t channel_4_zero_level_RMS;
  Float_t channel_4_time_cross;
  Float_t channel_4_time_half;
  Short_t channel_4_MAX_in_gate;
  Short_t channel_4_MIN_in_gate;
  Short_t channel_4_MAX_out_gate;
  Short_t channel_4_MIN_out_gate;
  UShort_t channel_4_time_max_in_gate;
  UShort_t channel_4_time_min_in_gate;
  ULong64_t channel_4_iEvt;
  Int_t channel_5_integral_in_gate;
  Float_t channel_5_mean_in_gate;
  Float_t channel_5_mean_out_gate;
  Float_t channel_5_RMS_in_gate;
  Float_t channel_5_RMS_out_gate;
  Float_t channel_5_zero_level;
  Float_t channel_5_zero_level_RMS;
  Float_t channel_5_time_cross;
  Float_t channel_5_time_half;
  Short_t channel_5_MAX_in_gate;
  Short_t channel_5_MIN_in_gate;
  Short_t channel_5_MAX_out_gate;
  Short_t channel_5_MIN_out_gate;
  UShort_t channel_5_time_max_in_gate;
  UShort_t channel_5_time_min_in_gate;
  ULong64_t channel_5_iEvt;
  Int_t channel_6_integral_in_gate;
  Float_t channel_6_mean_in_gate;
  Float_t channel_6_mean_out_gate;
  Float_t channel_6_RMS_in_gate;
  Float_t channel_6_RMS_out_gate;
  Float_t channel_6_zero_level;
  Float_t channel_6_zero_level_RMS;
  Float_t channel_6_time_cross;
  Float_t channel_6_time_half;
  Short_t channel_6_MAX_in_gate;
  Short_t channel_6_MIN_in_gate;
  Short_t channel_6_MAX_out_gate;
  Short_t channel_6_MIN_out_gate;
  UShort_t channel_6_time_max_in_gate;
  UShort_t channel_6_time_min_in_gate;
  ULong64_t channel_6_iEvt;
  Int_t channel_7_integral_in_gate;
  Float_t channel_7_mean_in_gate;
  Float_t channel_7_mean_out_gate;
  Float_t channel_7_RMS_in_gate;
  Float_t channel_7_RMS_out_gate;
  Float_t channel_7_zero_level;
  Float_t channel_7_zero_level_RMS;
  Float_t channel_7_time_cross;
  Float_t channel_7_time_half;
  Short_t channel_7_MAX_in_gate;
  Short_t channel_7_MIN_in_gate;
  Short_t channel_7_MAX_out_gate;
  Short_t channel_7_MIN_out_gate;
  UShort_t channel_7_time_max_in_gate;
  UShort_t channel_7_time_min_in_gate;
  ULong64_t channel_7_iEvt;
  Int_t channel_8_integral_in_gate;
  Float_t channel_8_mean_in_gate;
  Float_t channel_8_mean_out_gate;
  Float_t channel_8_RMS_in_gate;
  Float_t channel_8_RMS_out_gate;
  Float_t channel_8_zero_level;
  Float_t channel_8_zero_level_RMS;
  Float_t channel_8_time_cross;
  Float_t channel_8_time_half;
  Short_t channel_8_MAX_in_gate;
  Short_t channel_8_MIN_in_gate;
  Short_t channel_8_MAX_out_gate;
  Short_t channel_8_MIN_out_gate;
  UShort_t channel_8_time_max_in_gate;
  UShort_t channel_8_time_min_in_gate;
  ULong64_t channel_8_iEvt;
  Int_t channel_9_integral_in_gate;
  Float_t channel_9_mean_in_gate;
  Float_t channel_9_mean_out_gate;
  Float_t channel_9_RMS_in_gate;
  Float_t channel_9_RMS_out_gate;
  Float_t channel_9_zero_level;
  Float_t channel_9_zero_level_RMS;
  Float_t channel_9_time_cross;
  Float_t channel_9_time_half;
  Short_t channel_9_MAX_in_gate;
  Short_t channel_9_MIN_in_gate;
  Short_t channel_9_MAX_out_gate;
  Short_t channel_9_MIN_out_gate;
  UShort_t channel_9_time_max_in_gate;
  UShort_t channel_9_time_min_in_gate;
  ULong64_t channel_9_iEvt;
  Int_t channel_10_integral_in_gate;
  Float_t channel_10_mean_in_gate;
  Float_t channel_10_mean_out_gate;
  Float_t channel_10_RMS_in_gate;
  Float_t channel_10_RMS_out_gate;
  Float_t channel_10_zero_level;
  Float_t channel_10_zero_level_RMS;
  Float_t channel_10_time_cross;
  Float_t channel_10_time_half;
  Short_t channel_10_MAX_in_gate;
  Short_t channel_10_MIN_in_gate;
  Short_t channel_10_MAX_out_gate;
  Short_t channel_10_MIN_out_gate;
  UShort_t channel_10_time_max_in_gate;
  UShort_t channel_10_time_min_in_gate;
  ULong64_t channel_10_iEvt;
  Int_t channel_11_integral_in_gate;
  Float_t channel_11_mean_in_gate;
  Float_t channel_11_mean_out_gate;
  Float_t channel_11_RMS_in_gate;
  Float_t channel_11_RMS_out_gate;
  Float_t channel_11_zero_level;
  Float_t channel_11_zero_level_RMS;
  Float_t channel_11_time_cross;
  Float_t channel_11_time_half;
  Short_t channel_11_MAX_in_gate;
  Short_t channel_11_MIN_in_gate;
  Short_t channel_11_MAX_out_gate;
  Short_t channel_11_MIN_out_gate;
  UShort_t channel_11_time_max_in_gate;
  UShort_t channel_11_time_min_in_gate;
  ULong64_t channel_11_iEvt;
  Long64_t log_data_1_timestamp;
  Float_t log_data_1_Common_HV;
  Float_t log_data_1_MPPC_HV[10];
  Int_t log_data_1_temp;
  Int_t log_data_1_LED_HV;
  Int_t log_data_1_PinDiode;
  Long64_t log_data_2_timestamp;
  Float_t log_data_2_Common_HV;
  Float_t log_data_2_MPPC_HV[10];
  Int_t log_data_2_temp;
  Int_t log_data_2_LED_HV;
  Int_t log_data_2_PinDiode;

  std::map<TString, TH1D *> th1Data;
  std::map<TString, TH1D *> th1CutData;
  TFile *outFile;

  // List of branches
  TBranch *b_channel_0;  //!
  TBranch *b_channel_1;  //!
  TBranch *b_channel_2;  //!
  TBranch *b_channel_3;  //!
  TBranch *b_channel_4;  //!
  TBranch *b_channel_5;  //!
  TBranch *b_channel_6;  //!
  TBranch *b_channel_7;  //!
  TBranch *b_channel_8;  //!
  TBranch *b_channel_9;  //!
  TBranch *b_channel_10; //!
  TBranch *b_channel_11; //!
  TBranch *b_log_data_1; //!
  TBranch *b_log_data_2; //!

  virtual Int_t Cut(Long64_t entry, Int_t _iChannel);
  virtual Bool_t Notify();
  virtual void InitHist();
  virtual void adcGetEntry(Int_t entry);
  ClassDef(adc64_data, 0);
};

#endif

#ifdef adc64_data_cxx
adc64_data::adc64_data(TTree *tree, TString _outFileName) : fChain(0)
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0)
  {
    TFile *f = (TFile *)gROOT->GetListOfFiles()->FindObject("../mpd_run_trigCode_3699.root");
    if (!f || !f->IsOpen())
    {
      f = new TFile("../mpd_run_trigCode_3699.root");
    }
    f->GetObject("adc64_data", tree);
  }
  if (_outFileName.Sizeof() != 1)
  {
    outFile = new TFile(_outFileName.Data(), "recreate");
  }
  else
  {
    std::cerr << "adc64_data::adc64_data: no name for output file." << std::endl;
  }
  Init(tree);
}

adc64_data::~adc64_data()
{
  if (!fChain)
    return;
  delete fChain->GetCurrentFile();
  for (auto it = th1Data.begin(); it != th1Data.end(); it++)
  {
    delete it->second;
  }
  th1Data.clear();
  for (auto it = th1CutData.begin(); it != th1CutData.end(); it++)
  {
    delete it->second;
  }
  th1CutData.clear();
  if (outFile->IsOpen())
  {
    outFile->Close();
  }
}

Int_t adc64_data::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain)
    return 0;
  return fChain->GetEntry(entry);
}
Long64_t adc64_data::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain)
    return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0)
    return centry;
  if (fChain->GetTreeNumber() != fCurrent)
  {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void adc64_data::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree)
    return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);
  th1Data.clear();

  fChain->SetBranchAddress("channel_0", &channel_0_integral_in_gate, &b_channel_0);
  fChain->SetBranchAddress("channel_1", &channel_1_integral_in_gate, &b_channel_1);
  fChain->SetBranchAddress("channel_2", &channel_2_integral_in_gate, &b_channel_2);
  fChain->SetBranchAddress("channel_3", &channel_3_integral_in_gate, &b_channel_3);
  fChain->SetBranchAddress("channel_4", &channel_4_integral_in_gate, &b_channel_4);
  fChain->SetBranchAddress("channel_5", &channel_5_integral_in_gate, &b_channel_5);
  fChain->SetBranchAddress("channel_6", &channel_6_integral_in_gate, &b_channel_6);
  fChain->SetBranchAddress("channel_7", &channel_7_integral_in_gate, &b_channel_7);
  fChain->SetBranchAddress("channel_8", &channel_8_integral_in_gate, &b_channel_8);
  fChain->SetBranchAddress("channel_9", &channel_9_integral_in_gate, &b_channel_9);
  fChain->SetBranchAddress("channel_10", &channel_10_integral_in_gate, &b_channel_10);
  fChain->SetBranchAddress("channel_11", &channel_11_integral_in_gate, &b_channel_11);
  fChain->SetBranchAddress("log_data_1", &log_data_1_timestamp, &b_log_data_1);
  fChain->SetBranchAddress("log_data_2", &log_data_2_timestamp, &b_log_data_2);
  InitHist();
  Notify();
}

Bool_t adc64_data::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void adc64_data::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain)
    return;
  fChain->Show(entry);
}
Int_t adc64_data::Cut(Long64_t entry, Int_t _iChannel)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.

  if (channel_time_max_in_gate[_iChannel] > 47 && channel_time_max_in_gate[_iChannel] < 54)
    return 1;
  else
    return -1;
}
ClassImp(adc64_data);
#endif // #ifdef adc64_data_cxx
