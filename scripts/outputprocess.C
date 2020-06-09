void outputprocess(void)
{
 TFile f("output.root", "read");
  f.cd("Energydeposition");

 double theta = 0;
 double phi = 0;
 double x = 0;
 double y = 0;
 double z = 0;
 int event = 0;
 int previousevent = 0;
 double thetaphi = 0;
 
 TH2D *results = new TH2D("results","Scatter plot of event number vs. angular ratio",100,0,100,100,-5,5);
 
 fTree->SetBranchAddress("detectorx", &x);
 fTree->SetBranchAddress("detectory", &y);
 fTree->SetBranchAddress("detectorz", &z);
 fTree->SetBranchAddress("event", &event);
 int why = 0;
 for(int i = 0, N = fTree->GetEntries(); i < N; ++i)
   {
     
     fTree->GetEntry(i);
 
     	 if(x<.0001)
	   {
	     cout << event << "   " << why << "   " << x  << "   " << y  << "   " << z <<   endl;
	     why++;
	   }
	   
     //	   {
	     
	     theta = atan(y/x)*180/TMath::Pi();
	     phi =  atan(sqrt(pow(x,2)+pow(y,2))/z)*180/TMath::Pi();
	     thetaphi = theta/phi;
	     results->Fill(event,theta/phi);
	     // cout << theta/phi << endl;
	    
	     //	   }//if x>.0001
	 
   }//for int i
 results->SetDirectory(gROOT);
 results->Draw("surf");
 
}
