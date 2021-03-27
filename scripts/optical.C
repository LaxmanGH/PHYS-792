void optical(void)
{
    
    //Importing a raw data from the simulation
    
    TFile *input = new TFile("allout.root","UPDATE");
    TTree *fTree;
    //taking the required informations from the raw simulation data: positions or locations, time, and energy deposition
    double energydeposition = 0;
    double x = 0;
    double y = 0;
    double z = 0;
    double time = 0;
    double detectionProbability=0;
    double totalenergydeposit;
    int nphot;
    fTree = (TTree*)input->Get("fTree");
    fTree->SetBranchAddress("x",&x);
    fTree->SetBranchAddress("y",&y);
    fTree->SetBranchAddress("z",&z);
    //fTree->SetBranchAddress("energydeposition",&energydeposition);
    //fTree->SetBranchAddress("time",&time);
    int nentries =  fTree->GetEntries();
    //creating an additional branch to fill the detection probability from Neil's optical-map file
    
    TBranch *detprob = fTree->Branch("detectionProbability",&detectionProbability,"detectionProbability/D");
    
    
    //reading Neil's optical-map file
    
        TFile* file=new TFile("./OpticalMapL200ReducedSize.root","READ");
        TH3D *dph3 = (TH3D*)file->Get("ProbMapInterior");
    
    int nbinx,nbiny,nbinz;
    /*   
	 nbinx=dph3->GetNbinsX();//120 size of X bins is 5 (ranging from -300mm to 300mm)
	 nbiny=dph3->GetNbinsY();//120 size of Y bins is 5 (ranging from -300mm to 300mm)
	 nbinz=dph3->GetNbinsZ();//340 size of Z bins is 5 (ranging from -850mm to 850mm)
	 int totalentries=dph3->GetEntries();//4896000
    */
    
    //extracting the varaible "detection probability" from the optical-map file
    
    int count=0;
    int count1=0;
    /*
      TH3D*simhist=new TH3D("simhist","X, Y, and Z distribution(for r<300mm) from the raw simulation file",120,-300.0,300.0,120,-300.0,300.0,340,-850.0,850.0);
      for(int k=0;k<nentries;k++)
      {
      
      if ((x<=300 and x>=-300) and (y<=300 and y>=-300) and (z>=-850 and z<=850))
      {
      simhist->Fill(x,y,z);
      }
      }
      //    simhist->Draw();
      */
    
    /*
      TAxis* xaxis=simhist->GetXaxis();
      TAxis* yaxis=simhist->GetYaxis();
      TAxis* zaxis=simhist->GetZaxis();
    */
    TAxis* xaxis=dph3->GetXaxis(); 
    TAxis* yaxis=dph3->GetYaxis();
    TAxis* zaxis=dph3->GetZaxis();
    int xbin=0;
    int ybin=0;
    int zbin=0;

    
    for (int i =0; i <100; i++)
      {
	
	fTree->GetEntry(i);
	if ((x<=300 and x>=-300) and (y<=300 and y>=-300) and (z>=-850 and z<=850))
	  {
	    count++;
	    xbin=xaxis->FindBin(x);
	    ybin=yaxis->FindBin(y);
	    zbin=zaxis->FindBin(z);
	    
	    // cout<<xbin<<'\t'<<ybin<<'\t'<<zbin<<endl;
	    detectionProbability = dph3->GetBinContent(xbin,ybin,zbin);
	    //	    detprob->Fill();
	  }
	else
	  {
	    count1++;
	    detectionProbability=0;
	    //	      detporb->Fill();
	    
	      cout<<"I am here"<<endl;
	  }
      }
    
    input->cd();
    //fTree->Write();
    cout<<"noz-zero probability entries are"<<count<<"\t"<<"Zero probability entries are"<<count1<<endl;	 
}

//EOF













