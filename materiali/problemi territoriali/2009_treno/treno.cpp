/*
  Copyright (C) 2009 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief Soluzione del problema treno delle selezioni territoriali
 *  delle Olimpiadi di Informatica 2009. E' stata applicata la ricorsione
 *  in maniera simile al problema delle torri di Hanoi: la complessità
 *  è lineare (circa 3N) e probabilmente ci sono altri modi di risolverlo
 *  (gli esempi di test usano soluzioni differenti da questa).
 *  Nella soluzione sottostante vengono anche implementati gli spostamenti
 *  sul vettore in modo da permetterne un'eventuale stampa, anche se in realtà
 *  non sarebbero necessari.
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  05/04/2009
 *  \date  Ultima modifica 05/04/2009
 *
 */

#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int K,N;
char vettore[2003];

///Struttura che rappresenta lo spostamento i,j
struct spostamento{
    int i,j;
    spostamento (int n, int m):i(n),j(m){}
};

///Coda degli spostamenti, utile per poterli stampare nel file dopo averli calcolati
queue <spostamento> coda;

///Funzione che sposta i container
void sposta(int i, int j)
{
    vettore[j] = vettore[i];
    vettore[j+1] = vettore[i+1];
    vettore[i]='*';
    vettore[i+1]='*';
}

/**
Funzione ricorsiva che calcola gli spostamenti da fare
Usa la semplice considerazione che quando le sostanze sono più di tre (quindi
da AAAABBBB** in poi) è sempre possibile ricondursi a un caso più semplice
spostando gli AB centrali in fondo, spostando due A iniziali nel posto lasciato libero
e spostando la coppia AB all'inizio. IN questo modo si ottiene un sottoproblema
di dimensione N-1 a cui è possibile riapplicare lo stesso procedimento.
Il caso base è per N=3 che viene risolto "a mano" prendendo la soluzione dai casi di test
*/
void calcola(int i, int j)
{
    if (j-i==7){
        sposta(i -1 + 2,i -1 + 7);
        coda.push(spostamento(i -1 + 2,i -1 + 7));
        sposta(i -1 + 6,i -1 + 2);
        coda.push(spostamento(i - 1 + 6,i - 1 + 2));
        sposta(i -1 + 4,i -1 + 6);
        coda.push(spostamento(i - 1 + 4,i - 1 + 6));
        sposta(i -1 + 7,i -1 + 4);
        coda.push(spostamento(i - 1 + 7,i - 1 + 4));
        /*for (int i=1; i<=2*N+2; i++)
            cout << vettore[i];
        cout << endl;*/
        return;
    }
    int n = (j - i -1)/2 +i -1;
    sposta(n,j-1);
    coda.push(spostamento(n,j-1));
    sposta(i,n);
    coda.push(spostamento(i,n));
    sposta(j-1,i);
    coda.push(spostamento(j-1,i));
    /*for (int i=1; i<=2*N+2; i++)
		cout << vettore[i];
	cout << endl;*/
    calcola(i+2,j);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i=1; i<=N; i++)
		vettore[i]='A';
	for (int i=N+1; i<=2*N; i++)
		vettore[i]='B';
	vettore[2*N+1]= '*';
	vettore[2*N+2]= '*';
	/*for (int i=1; i<=2*N+2; i++)
		cout << vettore[i];
	cout << endl;*/
	calcola(1,2*N+2);
	out << coda.size() << " " << N << endl;
	while(!coda.empty())
	{
	    out << coda.front().i << " " << coda.front().j << endl;
	    coda.pop();
	}
    return 0;
}
