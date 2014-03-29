#include <fstream>
#include <iostream>

using namespace std;

//#define DEBUG

#define MAXN 128
#define MAXS 400

struct tMission
{ int d, s; }
Missions[MAXN];

int Best[MAXN][MAXS];


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
		for (int j=0; j<=Missions[i].s; j++)
			Best[i][j] = Best[i-1][j];

		for (int j=Missions[i].d; j<=Missions[i].s; j++)
			Best[i][j] = max(Best[i][j], Best[i-1][j-Missions[i].d] + 1);
	}
	#ifdef DEBUG
    for (int i=0; i<=n; i++){
    cout << i << "-> ";
		for (int j=0; j<=Missions[n].s; j++)
      cout << Best[i][j] << " ";
    cout << endl;
    
  }
    #endif
	fout << Best[n][Missions[n].s] << endl;
}
