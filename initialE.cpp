#include <iostream>
#include <algorithm>

void initialE() {

  TFile *file = new TFile("/Users/isabelhz/Documents/FISSION/RAINIER/RAINIER1.2.0/Run0001.root", "READ");
  if(!file->IsOpen())
    printf("File did not successfully open\n");
  TH1D *gammaSpec = (TH1D*)file->Get("hExI0GSpec_0;1");

  
}
