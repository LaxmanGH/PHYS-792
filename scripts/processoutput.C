#include<typeinfo>
  
int processoutput(void)
{
  //variable declaration next 50 or so lines

  
  TFile f("output.root", "read");

  //analysis variables
  double theta = 0;
  double phi = 0;
  double thetaphi = 0;

  //variables assigned to tree branches
  double PID = 0;
  double energy = 0;
  double time = 0;
  double x = 0;
  double y = 0;
  double z = 0;
  double eventnumber = 0;
  double stepnumber = 0;
  double tracknumber = 0;
  double detectornumber = 0;
  string variablenames[10] = {"PID","energy","time","x","y","z","eventnumber","stepnumber","tracknumber","detectornumber"}

  //histograms
  TH2D *results = new TH2D("results","Scatter plot of event number vs. angular ratio",100,0,100,100,-5,5);
  TH1D *modular1dhisto;
  TH2D *modular2dhisto;
  TH3D *modular3dhisto;

  //variables affected by user input
  string variable1;
  char variable1draw[100];
  string variable2;
  char variable2draw[100];
  string variable3;
  char variable3draw[100];
  double highest1 = -10000000;
  double highest2 = -10000000;
  double highest3 = -10000000;
  double lowest1 = 10000000;
  double lowest2 = 10000000;
  double lowest3 = 10000000;
  int dimensions = 0;
  
  //assign branches
  fTree->SetBranchAddress("PID", &PID);
  fTree->SetBranchAddress("energy", &energy);
  fTree->SetBranchAddress("time", &time);
  fTree->SetBranchAddress("x", &x);
  fTree->SetBranchAddress("y", &y);
  fTree->SetBranchAddress("z", &z);
  fTree->SetBranchAddress("eventnumber", &eventnumber);
  fTree->SetBranchAddress("stepnumber", &stepnumber);
  fTree->SetBranchAddress("tracknumber", &tracknumber);
  fTree->SetBranchAddress("detectornumber", &detectornumber);

  //user interface stuff next 30 or so lines
  
  cout << endl << endl << "This program allows you to enter the variables from the TTree that you want plotted." << endl;

  
  cout << "Enter 1 for a 1 dimensional plot, 2 for a 2 dimensional plot, or 3 for a 3 dimensional plot." << endl;

  cin >> dimensions;
  if(dimensions!=1 &&dimensions!=2 && dimensions!=3)
    {
      cout <<"Invalid entry for dimensions. Seriously, dude? There were like, 3 choices. How did you mess this up?" << endl;
      return 0;
    }

  
  cout << endl <<  "Commands are spelling and case sensitive." << endl << "Available variables are:" << endl;

  for(int i = 0; i < 10; i++) {cout << variablenames[i] << endl;}

  cout << "Please note, that since PID may have a few entries with  value around 10 million, these have been cut out to make the other values visible on the histogram." << endl;
  
  cout << endl << "Enter variable to go on x axis" << endl;
  cin >> variable1draw;
  variable1 = variable1draw;
  
  if(dimensions>1)
    {
      cout << "Enter variable to go on y axis" << endl;
      cin >> variable2draw;
      variable2 = variable2draw;
    }

  if(dimensions>2)
    {
      cout << "Enter variable to go on z axis" << endl;
      cin >> variable3draw;
      variable3 = variable3draw;
    }


   
  

  //loop analysis goes in the following for loop
  
  for(int i = 0, N = fTree->GetEntries(); i < N; ++i)
    {

      fTree->GetEntry(i);
      
      theta = atan(y/x)*180/TMath::Pi();
      phi =  atan(sqrt(pow(x,2)+pow(y,2))/z)*180/TMath::Pi();
      thetaphi = theta/phi;
      results->Fill(eventnumber,theta/phi);

      if(variable1 == "PID")
	{
	  if(highest1<PID && PID < 100){highest1=PID;}
	  if(lowest1>PID){lowest1=PID;}
	}
      
      else if(variable1 == "energy")
	{
	  if(highest1<energy){highest1=energy;}
	  if(lowest1>energy){lowest1=energy;}
	}
      else if(variable1 == "time")
	{
	  if(highest1<time){highest1=time;}
	  if(lowest1>time){lowest1=time;}
	}
      else if(variable1 == "x")
	{
	  if(highest1<x){highest1=x;}
	  if(lowest1>x){lowest1=x;}
	}
      else if(variable1 == "y")
	{
	  if(highest1<y){highest1=y;}
	  if(lowest1>y){lowest1=y;}
	}
      else if(variable1 == "z")
	{
	  if(highest1<z){highest1=z;}
	  if(lowest1>z){lowest1=z;}
	}
      else if(variable1 == "eventnumber")
	{
	  if(highest1<eventnumber){highest1=eventnumber;}
	  if(lowest1>eventnumber){lowest1=eventnumber;}
	}
      else if(variable1 == "stepnumber")
	{
	  if(highest1<stepnumber){highest1=stepnumber;}
	  if(lowest1>stepnumber){lowest1=stepnumber;}
	}
      else if(variable1 == "tracknumber")
	{
	  if(highest1<tracknumber){highest1=tracknumber;}
	  if(lowest1>tracknumber){lowest1=tracknumber;}
	}
      else if(variable1 == "detectornumber")
	{
	  if(highest1<detectornumber){highest1=detectornumber;}
	  if(lowest1>detectornumber){lowest1=detectornumber;}
	}
      else
	{
	  cout << "You fool. You utter and detestable fool. You nincompoop. You MADE this program, you wrote it from SCRATCH, you make it PRINT THE DAMN INSTRUCTIONS EVERY TIME YOU RUN IT, AND YOU S T I L L  M E S S E D  U P. How hard is it to input the variable names correctly? Seriously dude. Go take a typing course or something." << endl;
	  return 0;
	}

      
      if(dimensions>1)
	{
	  if(variable2 == "PID")
	    {
	      if(highest2<PID && PID<100 ){highest2=PID;}
	      if(lowest2>PID){lowest2=PID;}
	    }
      
	  else if(variable2 == "energy")
	    {
	      if(highest2<energy){highest2=energy;}
	      if(lowest2>energy){lowest2=energy;}
	    }
	  else if(variable2 == "time")
	    {
	      if(highest2<time){highest2=time;}
	      if(lowest2>time){lowest2=time;}
	    }
	  else if(variable2 == "x")
	    {
	      if(highest2<x){highest2=x;}
	      if(lowest2>x){lowest2=x;}
	    }
	  else if(variable2 == "y")
	    {
	      if(highest2<y){highest2=y;}
	      if(lowest2>y){lowest2=y;}
	    }
	  else if(variable2 == "z")
	    {
	      if(highest2<z){highest2=z;}
	      if(lowest2>z){lowest2=z;}
	    }
	  else if(variable2 == "eventnumber")
	    {
	      if(highest2<eventnumber){highest2=eventnumber;}
	      if(lowest2>eventnumber){lowest2=eventnumber;}
	    }
	  else if(variable2 == "stepnumber")
	    {
	      if(highest2<stepnumber){highest2=stepnumber;}
	      if(lowest2>stepnumber){lowest2=stepnumber;}
	    }
	  else if(variable2 == "tracknumber")
	    {
	      if(highest2<tracknumber){highest2=tracknumber;}
	      if(lowest2>tracknumber){lowest2=tracknumber;}
	    }
	  else if(variable2 == "detectornumber")
	    {
	      if(highest2<detectornumber){highest2=detectornumber;}
	      if(lowest2>detectornumber){lowest2=detectornumber;}
	    }
	  else
	    {
	      cout << "You fool. You utter and detestable fool. You nincompoop. You MADE this program, you wrote it from SCRATCH, you make it PRINT THE DAMN INSTRUCTIONS EVERY TIME YOU RUN IT, AND YOU S T I L L  M E S S E D  U P. How hard is it to input the variable names correctly? Seriously dude. Go take a typing course or something." << endl;
	      return 0;
	    }
	}//if(dimensions

           
      if(dimensions>2)
	{
	  if(variable3 == "PID")
	    {
	      if(highest3<PID && PID<100){highest3=PID;}
	      if(lowest3>PID){lowest3=PID;}
	    }
      
	  else if(variable3 == "energy")
	    {
	      if(highest3<energy){highest3=energy;}
	      if(lowest3>energy){lowest3=energy;}
	    }
	  else if(variable3 == "time")
	    {
	      if(highest3<time){highest3=time;}
	      if(lowest3>time){lowest3=time;}
	    }
	  else if(variable3 == "x")
	    {
	      if(highest3<x){highest3=x;}
	      if(lowest3>x){lowest3=x;}
	    }
	  else if(variable3 == "y")
	    {
	      if(highest3<y){highest3=y;}
	      if(lowest3>y){lowest3=y;}
	    }
	  else if(variable3 == "z")
	    {
	      if(highest3<z){highest3=z;}
	      if(lowest3>z){lowest3=z;}
	    }
	  else if(variable3 == "eventnumber")
	    {
	      if(highest3<eventnumber){highest3=eventnumber;}
	      if(lowest3>eventnumber){lowest3=eventnumber;}
	    }
	  else if(variable3 == "stepnumber")
	    {
	      if(highest3<stepnumber){highest3=stepnumber;}
	      if(lowest3>stepnumber){lowest3=stepnumber;}
	    }
	  else if(variable3 == "tracknumber")
	    {
	      if(highest3<tracknumber){highest3=tracknumber;}
	      if(lowest3>tracknumber){lowest3=tracknumber;}
	    }
	  else if(variable3 == "detectornumber")
	    {
	      if(highest3<detectornumber){highest3=detectornumber;}
	      if(lowest3>detectornumber){lowest3=detectornumber;}
	    }
	  else
	    {
	      cout << "You fool. You utter and detestable fool. You nincompoop. You MADE this program, you wrote it from SCRATCH, you make it PRINT THE DAMN INSTRUCTIONS EVERY TIME YOU RUN IT, AND YOU S T I L L  M E S S E D  U P. How hard is it to input the variable names correctly? Seriously dude. Go take a typing course or something." << endl;
	      return 0;
	    }
	}//if(dimensions
 
      i++;
      
    }//for(int i = 0...
  
  results->SetDirectory(gROOT);
  results->GetXaxis()->SetTitle("Event Number");
  results->GetYaxis()->SetTitle("Theta/Phi");
  //results->Draw("surf");


 
 
  //modular2dhisto = new TH2D("modular2dhisto",Form("Plot of %s vs %s", variable1draw, variable2draw), highest1, lowest1, highest1, highest2, lowest2, highest2);

  int adjustedbinsize1 = highest1-lowest1;
  int adjustedbinsize2 = highest2-lowest2;
  int adjustedbinsize3 = highest3-lowest3;

  //to make sure parameters with a wide range don't make a million bins and trash the server's RAM
  if(adjustedbinsize1>10000){adjustedbinsize1=10000;}
  if(adjustedbinsize2>10000){adjustedbinsize2=10000;}
  if(adjustedbinsize3>10000){adjustedbinsize3=10000;}

  if(dimensions==3)
    {
      cout << "Please be aware that 3D histograms may take a while to draw." << endl;
      if(adjustedbinsize1>500){adjustedbinsize1=500;}
      if(adjustedbinsize2>500){adjustedbinsize2=500;}
      if(adjustedbinsize3>500){adjustedbinsize3=500;}
    }

  if(dimensions==1)
    {
      modular1dhisto = new TH1D("modular1dhisto","Help me pls", adjustedbinsize1*1.05, lowest1, highest1*1.05);
 
      fTree->Draw(Form("%s>>modular1dhisto",variable1draw));
      modular1dhisto->SetDirectory(gROOT);
      modular1dhisto->SetTitle(Form("%s histogram;%s;Count",variable1draw,variable1draw));
      gStyle->SetOptStat("erm");
      modular1dhisto->Draw();
    }

  else if(dimensions==2)
    {
      modular2dhisto = new TH2D("modular2dhisto","Help me pls", adjustedbinsize1*1.05, lowest1, highest1*1.05, adjustedbinsize2*1.05, lowest2, highest2*1.05);
 
      fTree->Draw(Form("%s:%s>>modular2dhisto",variable2draw,variable1draw));
      modular2dhisto->SetDirectory(gROOT);
      modular2dhisto->SetTitle(Form("%s vs. %s;%s;%s",variable1draw,variable2draw,variable1draw,variable2draw));
      gStyle->SetOptStat("erm");
      modular2dhisto->Draw();
    }

  else
    {
      modular3dhisto = new TH3D("modular3dhisto","Help me pls", adjustedbinsize1*1.05, lowest1, highest1*1.05, adjustedbinsize2*1.05, lowest2, highest2*1.05, adjustedbinsize3*1.05, lowest3, highest3*1.05);
 
      fTree->Draw(Form("%s:%s:%s>>modular3dhisto",variable3draw,variable2draw,variable1draw));
      modular3dhisto->SetDirectory(gROOT);
      modular3dhisto->SetTitle(Form("%s, %s, and %s;%s;%s;%s",variable1draw,variable2draw,variable3draw,variable1draw,variable2draw,variable3draw));
      gStyle->SetOptStat("erm");
      modular3dhisto->Draw();
    }

  return 1;
  
}
