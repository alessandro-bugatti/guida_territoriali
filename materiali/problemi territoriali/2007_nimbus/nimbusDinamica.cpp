/*
  Name: nimbusDinamica
  Copyright: 
  Author: Alessandro Bugatti
  Date: 29/02/08 10.52
  Description: Problema nimbus selezione regionale 2007
  Soluzione con programmazione dinamica
*/



#include <fstream>
#include <iostream>

using namespace std;

#define DEBUG

struct Intervallo
{ 
    int inizio, fine, caramelle; 
};

int compare_intervalli(const void *a, const void *b)
{
  const Intervallo *da = (const Intervallo *) a;
  const Intervallo *db = (const Intervallo *) b;

  return (da->fine > db->fine) - (da->fine < db->fine);
}

int N;
Intervallo giri[1000];
int caramelle[1000];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i=0; i<N; i++){
		in >> giri[i].inizio >> giri[i].fine;
		giri[i].caramelle = 1;
    }    
    #ifdef DEBUG
    for (int i=0; i<N; i++)
		cout << giri[i].inizio << " " << giri[i].fine  << " " << giri[i].caramelle << endl;
    #endif
    //Ordino per istante di fine
    qsort(giri,N,sizeof(Intervallo),compare_intervalli);
    #ifdef DEBUG
    for (int i=0; i<N; i++)
		cout << giri[i].inizio << " " << giri[i].fine  << " " << giri[i].caramelle << endl;
    #endif
    for (int i=N-1; i>=0; i--)
    {
        for (int j = N-1 ; j>i; j--)
           if (giri[i].fine < giri[j].inizio)
           {
               giri[j].inizio = giri[i].inizio;
               giri[j].caramelle++;
           }
    }
    int massimo = giri[0].caramelle;
    for (int i=1; i< N ;i++)
        massimo = max(giri[i].caramelle,massimo);
    out << massimo; 
}
    
