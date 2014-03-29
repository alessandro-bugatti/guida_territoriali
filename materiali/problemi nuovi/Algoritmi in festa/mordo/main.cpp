/*
    Autore: Alessandro Bugatti
    Descrizione: Problema dei mostri di Mordo
    Festa degli algoritmi terza edizione
    Creazione: 27.04.2012 23:29:42
*/

#include <iostream>
#include <climits>

using namespace std;


int pianeti[1000];
int quanti_pianeti;
int mostri;
int fermate;

int m[1001][500];
int p[1001][500];

int costi_fermate(int prev, int cur)
{
		int nsteps = 0;
		int i;
		for (i = 0 ; i < mostri; i++)
			if((pianeti[i] > prev) && (pianeti[i] <= cur))
				nsteps += min(pianeti[i] - prev, cur - pianeti[i]);
		return nsteps;
}

int ottimizza()
{
	int i,j,k;
	int costo;
	int ultima_fermata;
	for (i=0; i <= quanti_pianeti; i++)
	{
		m[i][0] = costi_fermate(0,INT_MAX);
		p[i][0] = -1;
	}
	for (j=1; j <= fermate; j++)
		for (i=0; i <= quanti_pianeti; i++)
		{
			m[i][j] = INT_MAX;
			for (k=0; k<=i; k++)
			{
				costo = m[k][j-1] - costi_fermate(k,INT_MAX) + costi_fermate(k,i) + costi_fermate(i,INT_MAX);
				if (costo < m[i][j])
				{
					m[i][j] = costo;
					p[i][j] = k;
				}
			}
		}
	ultima_fermata = 0;
	for (i=0; i <= quanti_pianeti; i++)
		if (m[i][fermate] < m[ultima_fermata][fermate])
			ultima_fermata = i;
	return ultima_fermata;
}

void ricostruisci_soluzione(int ultima_fermata, int fermate_da_fare)
{
	if (fermate_da_fare > 1)
		ricostruisci_soluzione(p[ultima_fermata][fermate_da_fare], fermate_da_fare - 1);
	cout << ultima_fermata << endl;
}


int main()
{
	int contatore = 0;
	cin >> quanti_pianeti >> fermate >> mostri;
	for (int i = 0; i < mostri; i++)
		cin >> pianeti[i];
    int ultima = ottimizza();
	//cout << ultima << endl;
	ricostruisci_soluzione(ultima, fermate);
	return 0;
}
