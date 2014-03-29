/*
  Name: nimbusDinamica
  Copyright: 
  Author: Alessandro Bugatti
  Date: 29/02/08 10.52
  Description: Problema nimbus selezione regionale 2007
  Soluzione ricorsiva.
*/



#include <fstream>
#include <iostream>

using namespace std;

#define DEBUG

struct Intervallo
{ 
    int inizio, fine; 
};

int compare_intervalli(const void *a, const void *b)
{
  const Intervallo *da = (const Intervallo *) a;
  const Intervallo *db = (const Intervallo *) b;

  return (da->fine > db->fine) - (da->fine < db->fine);
}

int N;
Intervallo giri[1000];


int calcola (int i, int inizio)
{
    if (i == -1) return 0;
    int max1 = 0, max2 = 0;
    if (giri[i].fine < inizio)
    {
        max1 =  calcola (i-1, giri[i].inizio) + 1;
        max2 =  calcola (i-1, inizio);
    }    
    else
        max2 = calcola (i-1, inizio);
    return max(max1,max2);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i=0; i<N; i++){
		in >> giri[i].inizio >> giri[i].fine;
    }    
    #ifdef DEBUG
    for (int i=0; i<N; i++)
		cout << giri[i].inizio << " " << giri[i].fine  <<  endl;
    #endif
    //Ordino per istante di fine
    qsort(giri,N,sizeof(Intervallo),compare_intervalli);
    #ifdef DEBUG
    for (int i=0; i<N; i++)
		cout << giri[i].inizio << " " << giri[i].fine  <<  endl;
    #endif
    out << calcola(N-1,giri[N-1].fine+1); 
}
    
