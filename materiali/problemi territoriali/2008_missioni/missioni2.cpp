/*Soluzione di Alessandro Bugatti su sugerimento di Ramesh Rajabi 28/2/2008*/
/*Versione dinamica*/

#include <fstream>
#include <iostream>

using namespace std;

//Da commentare per eliminare gli output del debug
#define DEBUG

#define MAXN 101
#define MAXS 366

struct tMission
{ 
  int d, s; 
}
Missions[MAXN];

int Best[2][MAXS];


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;

	fin >> n;
	for (int i=1; i<=n; i++)
		fin >> Missions[i].d >> Missions[i].s;

	for (int i=1; i<=n; i++)
	{	
		for (int j=Missions[i].d; j<=Missions[i].s; j++)
			Best[1][j] = max(Best[1][j], Best[0][j-Missions[i].d] + 1);
        for (int j=0; j<=Missions[i].s; j++)
			Best[0][j] = Best[1][j];
	}
	#ifdef DEBUG
    for (int i=0; i<2; i++){
    cout << i << "-> ";
		for (int j=0; j<=Missions[n].s; j++)
      cout << Best[i][j] << " ";
    cout << endl;
    
    }
  #endif
	fout << Best[1][Missions[n].s] << endl;
}
