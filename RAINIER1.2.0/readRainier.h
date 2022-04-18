//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 28 13:47:06 2022 by ROOT version 6.24/06
// from TTree tEvents/Events
// found on file: Run0001.root
//////////////////////////////////////////////////////////

#ifndef readRainier_h
#define readRainier_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class readRainier {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           gammaMult;
   Double_t        initialJ;
   Double_t        initialE;
   Double_t        deltaJ[9];   //[gammaMult]
   Double_t        deltaE[9];   //[gammaMult]
   Double_t        multiPol[9];   //[gammaMult]
   Double_t        field[9];   //[gammaMult]
   Double_t        jI[9];   //[gammaMult]
   Double_t        jF[9];   //[gammaMult]
   Double_t        eI[9];   //[gammaMult]
   Double_t        eF[9];   //[gammaMult]

   //TH2D*           h2_final;
   Double_t        finalStatE;
   Double_t        finalStatJ;

   // List of branches
   TBranch        *b_gammaMult;   //!
   TBranch        *b_initialJ;   //!
   TBranch        *b_initialE;   //!
   TBranch        *b_deltaJ;   //!
   TBranch        *b_deltaE;   //!
   TBranch        *b_multiPol;   //!
   TBranch        *b_field;   //!
   TBranch        *b_jI;   //!
   TBranch        *b_jF;   //!
   TBranch        *b_eI;   //!
   TBranch        *b_eF;   //!

   readRainier(int runnum, TTree *tree=0);
   virtual ~readRainier();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

//#ifdef readRainier_cxx
readRainier::readRainier(int runnum, TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TString name = "Run00" + to_string(runnum) + ".root";
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(name);
      if (!f || !f->IsOpen()) {
         f = new TFile(name);
      }
      f->GetObject("tEvents",tree);

   }
   Init(tree);
}

readRainier::~readRainier()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t readRainier::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t readRainier::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void readRainier::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("gammaMult", &gammaMult, &b_gammaMult);
   fChain->SetBranchAddress("initialJ", &initialJ, &b_initialJ);
   fChain->SetBranchAddress("initialE", &initialE, &b_initialE);
   fChain->SetBranchAddress("deltaJ", deltaJ, &b_deltaJ);
   fChain->SetBranchAddress("deltaE", deltaE, &b_deltaE);
   fChain->SetBranchAddress("multiPol", multiPol, &b_multiPol);
   fChain->SetBranchAddress("field", field, &b_field);
   fChain->SetBranchAddress("jI", jI, &b_jI);
   fChain->SetBranchAddress("jF", jF, &b_jF);
   fChain->SetBranchAddress("eI", eI, &b_eI);
   fChain->SetBranchAddress("eF", eF, &b_eF);
   Notify();
}

Bool_t readRainier::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void readRainier::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t readRainier::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
//#endif // #ifdef readRainier_cxx
