//EKO Coci marzo 2012
//Soluzione con ricerca binaria dell'altezza
//Tutti corretti, il più pesante in 0.45 s
//Occhio ai long long int, nella forza bruta non si nota
//perchè si ferma ai casi piccoli

#include <iostream>

using namespace std;

int N, M;
int alberi[1000000];

long long int legno_tagliato(int altezza)
{
	long long int legno = 0;
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
	int inizio = 0, fine = max-1, medio;
	long long int legno;
	while (inizio < fine)
	{
		medio = (inizio + fine)/2;
		legno = legno_tagliato(medio);
		if ( legno == M)
		{
			cout << medio << endl;
			return 0;
		}
		if (legno > M)
			inizio = medio + 1;
		if (legno < M)
			fine = medio;
	}
	if (legno >= M)
		cout << medio << endl;
	else 
		cout << medio -1 << endl;
	return 0;
}
