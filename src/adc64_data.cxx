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
    if (isSetCorrelations)
    {
      for (Int_t jChannel = 0; jChannel < Nchannels; jChannel++)
      {
        fName = TString("channel_" + std::to_string(iChannel) + "_vs_" + std::to_string(jChannel) + "_IntegralInGate");
        th2Data[TString(fName)] = new TH2D(Form("%s", fName.Data()), Form("%s", fName.Data()), kNoBins, -1e3, 10e3, kNoBins, -1e3, 10e3);
        fName = TString("Cut_channel_" + std::to_string(iChannel) + "_vs_" + std::to_string(jChannel) + "_IntegralInGate");
        th2CutData[TString(fName)] = new TH2D(Form("%s", fName.Data()), Form("%s", fName.Data()), kNoBins, -1e3, 10e3, kNoBins, -1e3, 10e3);
      }
    }
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
  if (isSetCorrelations)
  {
    std::cout << std::endl;
    for (auto it = th2Data.begin(); it != th2Data.end(); it++)
    {
      std::cout << it->second->GetName() << std::endl;
    }
    std::cout << std::endl;
    for (auto it = th2CutData.begin(); it != th2CutData.end(); it++)
    {
      std::cout << it->second->GetName() << std::endl;
    }
  }
}

void adc64_data::adcGetEntry(Int_t entry)
{
  fChain->GetEntry(entry);
  channel_integral_in_gate.clear();
  channel_time_max_in_gate.clear();

  channel_integral_in_gate.push_back(channel_0_integral_in_gate);
  channel_integral_in_gate.push_back(channel_1_integral_in_gate);
  channel_integral_in_gate.push_back(channel_2_integral_in_gate);
  channel_integral_in_gate.push_back(channel_3_integral_in_gate);
  channel_integral_in_gate.push_back(channel_4_integral_in_gate);
  channel_integral_in_gate.push_back(channel_5_integral_in_gate);
  channel_integral_in_gate.push_back(channel_6_integral_in_gate);
  channel_integral_in_gate.push_back(channel_7_integral_in_gate);
  channel_integral_in_gate.push_back(channel_8_integral_in_gate);
  channel_integral_in_gate.push_back(channel_9_integral_in_gate);
  channel_integral_in_gate.push_back(channel_10_integral_in_gate);
  channel_integral_in_gate.push_back(channel_11_integral_in_gate);

  channel_time_max_in_gate.push_back(channel_0_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_1_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_2_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_3_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_4_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_5_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_6_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_7_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_8_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_9_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_10_time_max_in_gate);
  channel_time_max_in_gate.push_back(channel_11_time_max_in_gate);
}

void adc64_data::WriteHist()
{
  outFile->cd();
  if (outFile)
  {
    outFile->cd();
    if (outFile->IsOpen())
    {
      outFile->mkdir(kOutDirName[0].Data());
      outFile->cd(kOutDirName[0].Data());
      for (auto it = th1Data.begin(); it != th1Data.end(); it++)
      {
        it->second->Write();
      }
      outFile->mkdir(kOutDirName[1].Data());
      outFile->cd(kOutDirName[1].Data());
      for (auto it = th1CutData.begin(); it != th1CutData.end(); it++)
      {
        it->second->Write();
      }
      if (isSetCorrelations)
      {
        outFile->mkdir(kOutDirName[2].Data());
        outFile->cd(kOutDirName[2].Data());
        for (auto it = th2Data.begin(); it != th2Data.end(); it++)
        {
          it->second->Write();
        }
        outFile->mkdir(kOutDirName[3].Data());
        outFile->cd(kOutDirName[3].Data());
        for (auto it = th2CutData.begin(); it != th2CutData.end(); it++)
        {
          it->second->Write();
        }
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
      th1Data["channel_" + std::to_string(iChannel) + "_IntegralInGate"]->Fill(channel_integral_in_gate.at(iChannel), kHistoWeight);
      if (Cut(jentry, iChannel) == 1)
        th1CutData["Cut_channel_" + std::to_string(iChannel) + "_IntegralInGate"]->Fill(channel_integral_in_gate.at(iChannel), kHistoWeight);
      if (isSetCorrelations)
      {
        for (Int_t jChannel = 0; jChannel < Nchannels; jChannel++)
        {
          th2Data["channel_" + std::to_string(iChannel) + "_vs_" + std::to_string(jChannel) + "_IntegralInGate"]->Fill(channel_integral_in_gate.at(iChannel), channel_integral_in_gate.at(jChannel), kHistoWeight);
          if (Cut(jentry, iChannel) == 1 && Cut(jentry, jChannel) == 1)
            th2CutData["Cut_channel_" + std::to_string(iChannel) + "_vs_" + std::to_string(jChannel) + "_IntegralInGate"]->Fill(channel_integral_in_gate.at(iChannel), channel_integral_in_gate.at(jChannel), kHistoWeight);
        }
      }
    }
  }
}
