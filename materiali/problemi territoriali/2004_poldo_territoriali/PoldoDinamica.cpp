#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class nodo
{
    public:
    int peso; //peso nel nodo
    int numPanini; //numero di panini mangiati
    nodo():peso(0),numPanini(0){}
};

nodo lista[100];
int panini[100];

int main(int argc, char *argv[])
{
  fstream in,out;
  int numeroPanini,max;
  int conta=0;
  in.open("input.txt",ios::in);
  out.open("output.txt",ios::out);
  in >> numeroPanini;    
  for (int i=0;i<numeroPanini;i++) 
    {
        in >> panini[i];
        lista[i].peso=panini[i];
    }
  for (int i=numeroPanini-1;i>=0;i--) 
  {
    max=0;
    for (int j=numeroPanini-1;j>i;j--)
    {
        if (lista[i].peso > panini[j] && lista[j].numPanini>max)
            max=lista[j].numPanini;
    }
    lista[i].numPanini=max+1;
  }  
  max=lista[0].numPanini;
  for (int i=1; i< numeroPanini;i++)
    if (lista[i].numPanini>max) max=lista[i].numPanini;
  
  out << max;
  in.close();
  out.close();
}
