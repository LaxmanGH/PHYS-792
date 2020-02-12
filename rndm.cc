#include<iostream>
#include <TRandom3.h>
using namespace std;
int main(){

  TRandom3 generator(0);
  for (int i=0;i<50;i++)
  cout<<generator.PoissonD(6.8)<<endl;
  return 0;
}
