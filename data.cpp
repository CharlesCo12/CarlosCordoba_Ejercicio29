#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void onda(int nmax, int tiempo, string filename);
const float L=1;
const float C=1/2;
const float tmax=6;
const float pi=4*atan(1);

int main(){
    onda(101,601,"datos.dat");
    return 0;
}

void onda(int nmax, int tiempo, string filename){  
  double dx=1/100;
  double dt=1/100;  
  ofstream outfile;
  outfile.open(filename);
  float T[nmax][3]={0};
    
  for(int i=0;i<nmax;i++){
      T[i][0]=sin(pi*i/100);
      T[i][2]=T[i][0];
  } 
  for(int j=0;j<nmax;j++)
  {
      outfile << T[j][0] << " ";
      if(j==nmax-1){outfile<<endl;}
  }
  for(int j=1;j<nmax-1;j++)
  {
      T[j][1]=T[j][0]+(0.5*0.25)*(T[j+1][0]+T[j-1][0]-2*T[j][0]);
  }
  for(int j=0;j<nmax;j++)
  {
      outfile << T[j][1] << " ";
      if(j==nmax-1){outfile<<endl;}
  }
  for(int j=0;j<nmax;j++)
  {
      outfile << T[j][2] << " ";
      if(j==nmax-1){outfile<<endl;}
  }
  for(int k=3;k<tiempo;k++)
  {
      for(int i=0;i<nmax;i++)
      {
          T[i][0]=T[i][1];
          T[i][1]=T[i][2];
          T[i][2]=0;
      }
      for(int j=1;j<nmax-1;j++)
      {
          T[j][2]=2*T[j][1]-T[j][0]+(0.25)*(T[j+1][1]+T[j-1][1]-2*T[j][1]);
      }
      for(int j=0;j<nmax;j++)
      {
          outfile << T[j][2] << " ";
          if(j==nmax-1){outfile<<endl;}
      }
  }      
  outfile.close();
}