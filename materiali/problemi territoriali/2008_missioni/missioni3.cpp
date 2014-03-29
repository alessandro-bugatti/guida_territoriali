/*Soluzione di Alessandro Bugatti rifatta*/
/*Versione dinamica*/

#include <fstream>
#include <iostream>

using namespace std;

//Da commentare per eliminare gli output del debug
//#define DEBUG

#define MAXN 101
#define MAXS 366

#define QUANTE 0
#define FINE 1

struct Missione
{ 
  int durata, fine; 
};
Missione Missioni[MAXN];

int Best[MAXS];

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;

	fin >> n;
	for (int i=0; i<n; i++)
		fin >> Missioni[i].durata >> Missioni[i].fine;
        
	#ifdef DEBUG
    for (int i=0; i<n; i++){
    cout << i << "-> " << Missioni[i].durata << " " << Missioni[i].fine;
    cout << endl;
    
    }
    #endif
    for (int i=0; i<n; i++)
    {
        for (int j=Missioni[i].fine - Missioni[i].durata; j>=0; j--)
        {
            if (Best[j] + 1 > Best[j+Missioni[i].durata])
                    Best[j+Missioni[i].durata] = Best[j]+1;
            
        }
    #ifdef DEBUG
        for (int i=0; i<MAXS; i++)
            cout << Best[i] << " " ;
        cout << endl;
        system("PAUSE");
        #endif
    }     
    #ifdef DEBUG
    for (int i=0; i<MAXS; i++){
    cout << i << "-> " << Best[i] << " " << Best[i];
    cout << endl;
    
    }
    #endif
    int max = Best[0];
    for (int i=0; i<MAXS; i++)  
     if (Best[i] > max) max = Best[i];
    fout << max;
            
}
