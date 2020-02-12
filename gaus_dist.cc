#include<iostream>
#include<TRandom3.h>
using namespace std;

TH1F *h=new TH1F("h","the gaussian distribution",100,0,100);
void gaus_dist(){
  for (int i=0;i<1000;i++){
    double y= gRandom->Gaus(50,10);
  h->Fill(y);
  }
  h->Fit("gaus");
  h->Draw();
  }

