/*
 *      Problema quasipal - selezioni territoriali 2010
 *      
 *      Copyright 2011 Alessandro Bugatti <alessandro.bugatti@istruzione.it>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

/*! \file
 *  \brief Soluzione del problema quasipal delle territoriali 2010
 *  \author Alessandro Bugatti
 *	
 *  \version 0.1
 *  \date  Creazione  18/04/2010
 *  \date  Ultima modifica 18/04/2010
 *	\attention Per risolvere il problema io ho fatto così:come prima cosa
 *  ho scelto di risolverlo a forza bruta (perchè altri modi non ne ho visti)
 *	provando tutte le possibili permutazioni delle righe e vedendo quale generava
 *  un rettangolo quasipalindromo. Il problema può così essere risolto dividendolo in due.<br>
 *	Primo bisogna generare tutte le permutazioni degli indici delle righe, e questo si pò fare 
 *  ricorsivamente.<br>
 *	Secondo per ogni permutazione generata si verifica se da origine a un rettangolo quasi 
 *  palindromo, nel qual caso lo si stampa e si termina il programma.
 *	
 */

#include <cstdio>
#include <cstdlib>

int M;//numero di righe
int N;//numero di cifre per riga
int cifre[8];//Vettore delle cifre
int presente[8]; //Vettore che indica se la cifra i+1 esima è presente (1) o no (0)
char rettangolo[8][8]; //Rettangolo da verificare
FILE *in,*out;

//Funziona che usa il vettore cifre che contiene gli indici delle righe in tutte le possibili
//permutazioni per "scambiare" le righe e verificare la quasi palindromia
bool verifica_rettangolo()
{
	int i,j;
	//Controllo per ogni colonna
	for (i=0;i<N;i++)
		//Controllo sulla i-esima colonna
		for (j=0;j<M/2;j++)
		{
			//Se le cifre in posizione "speculare" non sono uguali e nessuna delle due è uno zero ritorna falso
			//Inoltre devo stare attento che come indice di riga devo usare quello ottenuta dalla permutazione
			int is = cifre[j];
			int id = cifre[M-j-1];
			if ((rettangolo[is][i] != rettangolo[id][i]) && (rettangolo[is][i] != '0' && rettangolo[id][i]!='0'))	
				return false;
		}
	return true;
}

void stampa()
{	
	int i,j;
	for (i=0;i<M;i++)
	{
		int riga = cifre[i];
		for (j=0;j<N;j++)
			fprintf(out,"%c",rettangolo[riga][j]);
		fprintf(out,"\n");
	}
}
//Calcola tutte le permutazioni possibili delle prime N cifre intere a partire da uno
void calcola_permutazioni(int inizio, int fine)
{
	int i;
	if (inizio >= fine)
	{
		if (verifica_rettangolo())
		{
			stampa();
			exit(0);
		}
		return;
	}
	for (i = 0; i < fine; i++)
	{
		if (presente[i])
		{
			cifre[inizio] = i; //Inserisce la cifra scelta nel vettore delle permutazioni
			presente[i] = 0; //Serve a indicare che quella cifra non è più presente in modo che non 
							//compaia nelle successive permutazioni della parte rimanente di vettore
			calcola_permutazioni(inizio+1,fine);//si richiama ricorsivamente sulla parte rimanente di vettore
			presente[i]=1; //reinscerisce la cifra tolta per poterla usare in altre permutazioni
		}
	}
}

int main()
{
	int i,j;
	in = fopen("input.txt","r");
	out = fopen("output.txt","w");
	fscanf(in,"%d %d",&M,&N);
	for (i=0;i<M;i++)
	{
		char temp[10];
		fscanf(in,"%s",temp);
		for (j=0;j<N;j++)
			rettangolo[i][j] = temp[j];//Trasformo il carattere letto in un intero
	}
    for (i = 0; i < M; i++)
    {
		presente[i]=1;
		cifre[i]=i;
	}
	calcola_permutazioni(0,M);
    return 0;
}

