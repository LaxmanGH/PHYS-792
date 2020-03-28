#include<iostream>
#include<TRandom3.h>
using namespace std;

TH1F *h=new TH1F("h","The distribution of random numbers that follow the poisson distribution fitted with the Gaussian function ",100,0,100);
TRandom3 generator(0);
void gaus_dist(){
for (int i=0;i<5000;i++){
  // generating 5000 random numbers that follow the P.D. having mean 50.0                           

double  x=generator.PoissonD(50.0);
  h->Fill(x);
  }
  h->Fit("gaus");
  h-> SetXTitle("Random numbers from the P.D. distn having mean 50");
  h->SetYTitle("Counts");
  h->Draw();
  }

