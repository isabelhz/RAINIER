#define readRainier_cxx
#include "readRainier.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
using namespace std;

void readRainier::Loop()
{
   if (fChain == 0) return;
   double finalE, finalJ; //last of stat transition
   const int STATGAMMA = 1;
   const int TRNGAMMA = 2;
   //add runnum to name of histogram
   //TCanvas *canvas = new TCanvas("canvas", "h2_final", 600, 400);
   TH2D *h2_final = new TH2D("h2_final", "Final Conditions;Excitation Energy (MeV); Angular Momentum (h); Counts", 500, 0, 10, 40, 0, 20);

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for(int gamma=0; gamma<gammaMult; gamma++) {
        //if(field[gamma] == STATGAMMA || field[gamma] == TRNGAMMA) {
        if(field[gamma] == 1 || field[gamma] == 2) {  //E1 transition
          //record final e and j of gamma
          finalE = eF[gamma];
          finalJ = jF[gamma];
          //cout << "filled\n";
        }
      }
      //cout << finalE << " " << finalJ << "\n";
      h2_final->Fill(finalE, finalJ);
   }
   //cout << initialE << " " << initialJ << "\n";
   //cout << h2_final->GetEntries() << "\n";
   cout << h2_final->GetMean(1) << " " << h2_final->GetMean(2) << "\n";

   finalStatE = h2_final->GetMean(1);
   finalStatJ = h2_final->GetMean(2);

   //h2_final->Draw();
}
