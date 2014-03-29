//EKO Coci marzo 2012
//Soluzione a forza bruta, si scrive in 5 minuti
//risolve 4 casi su 10

#include <iostream>

using namespace std;

int N, M;
int alberi[1000000];

int legno_tagliato(int altezza)
{
	int legno = 0;
	for (int i = 0; i < N; i++)
		if (alberi[i] > altezza)
			legno += alberi[i] -  altezza;
	return legno;
}


int main()
{
	int max = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> alberi[i];
		if (alberi[i] > max)
			max = alberi[i];
	}
	for (int i = max-1; i >= 0; i--)
		if (legno_tagliato(i) >= M)
		{
			cout << i << endl;
			return 0;
		}
	return 0;
}
