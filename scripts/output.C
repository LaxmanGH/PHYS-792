void output()
{
  std::string gps="/gps/hist/point";
  TFile *f=new TFile("neutron_spectrum_from_alpha_N_in_borated_hdpe.root");//includes TH1F;
  TH1F *h=(TH1F*)f->Get("h1");
  ofstream fout("output.txt");
  for(int i=1;i<=h->GetNbinsX();i++) { 
    for(int j=1;j<=h->GetNbinsY();j++) {
      int x=h->GetXaxis()->GetBinLowEdge(i)+h->GetBinWidth(i);
      double x1=h->GetBinContent(i,j);
      fout.fixed;
     
 fout<<gps<<" "<<x<<" "<<x1<<endl;
       

//fout<<h->GetXaxis()->GetBinLowEdge(i)<<" "<<h->GetBinContent(i,j).precision(1)<<endl;
 }
  }
  fout.close();
}
