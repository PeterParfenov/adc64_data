#define adc64_data_cxx
#include "adc64_data.h"

void adc64_data::InitHist()
{
  TString fName;
  for (Int_t iChannel = 0; iChannel < Nchannels; iChannel++)
  {
    fName = TString("channel_" + std::to_string(iChannel) + "_IntegralInGate");
    th1Data[TString(fName)] = new TH1D(Form("%s", fName.Data()), Form("%s", fName.Data()), kNoBins, -5e3, 30e3);
    fName = TString("Cut_channel_" + std::to_string(iChannel) + "_IntegralInGate");
    th1CutData[TString(fName)] = new TH1D(Form("%s", fName.Data()), Form("%s", fName.Data()), kNoBins, -5e3, 30e3);
  }
  std::cout << "\nadc64_data::InitHisto: Histograms are initialized." << std::endl;
  std::cout << std::endl;
  for (auto it = th1Data.begin(); it != th1Data.end(); it++)
  {
    std::cout << it->second->GetName() << std::endl;
  }
  std::cout << std::endl;
  for (auto it = th1CutData.begin(); it != th1CutData.end(); it++)
  {
    std::cout << it->second->GetName() << std::endl;
  }
}

void adc64_data::adcGetEntry(Int_t entry)
{
  fChain->GetEntry(entry);

  channel_integral_in_gate[0] = channel_0_integral_in_gate;
  channel_integral_in_gate[1] = channel_1_integral_in_gate;
  channel_integral_in_gate[2] = channel_2_integral_in_gate;
  channel_integral_in_gate[3] = channel_3_integral_in_gate;
  channel_integral_in_gate[4] = channel_4_integral_in_gate;
  channel_integral_in_gate[5] = channel_5_integral_in_gate;
  channel_integral_in_gate[6] = channel_6_integral_in_gate;
  channel_integral_in_gate[7] = channel_7_integral_in_gate;
  channel_integral_in_gate[8] = channel_8_integral_in_gate;
  channel_integral_in_gate[9] = channel_9_integral_in_gate;

  channel_time_max_in_gate[0] = channel_0_time_max_in_gate;
  channel_time_max_in_gate[1] = channel_1_time_max_in_gate;
  channel_time_max_in_gate[2] = channel_2_time_max_in_gate;
  channel_time_max_in_gate[3] = channel_3_time_max_in_gate;
  channel_time_max_in_gate[4] = channel_4_time_max_in_gate;
  channel_time_max_in_gate[5] = channel_5_time_max_in_gate;
  channel_time_max_in_gate[6] = channel_6_time_max_in_gate;
  channel_time_max_in_gate[7] = channel_7_time_max_in_gate;
  channel_time_max_in_gate[8] = channel_8_time_max_in_gate;
  channel_time_max_in_gate[9] = channel_9_time_max_in_gate;
}

void adc64_data::WriteHist()
{
  outFile->cd();
  if (outFile)
  {
    outFile->cd();
    if (outFile->IsOpen())
    {
      for (auto it = th1Data.begin(); it != th1Data.end(); it++)
      {
        it->second->Write();
      }
      for (auto it = th1CutData.begin(); it != th1CutData.end(); it++)
      {
        it->second->Write();
      }
    }
  }
}

void adc64_data::Loop()
{
  std::cout << "\nadc64_data::Loop: Proccessing." << std::endl;
  if (fChain == 0)
    return;

  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry < nentries; jentry++)
  {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;
    adcGetEntry(jentry);

    if (jentry % 1000 == 0)
      std::cout << "\tEntry " << jentry << std::endl;
    for (Int_t iChannel = 0; iChannel < Nchannels; iChannel++)
    {
      th1Data["channel_" + std::to_string(iChannel) + "_IntegralInGate"]->Fill(channel_integral_in_gate[iChannel], kHistoWeight);
      if (Cut(jentry, iChannel) == 1)
        th1CutData["Cut_channel_" + std::to_string(iChannel) + "_IntegralInGate"]->Fill(channel_integral_in_gate[iChannel], kHistoWeight);
    }
  }
}
