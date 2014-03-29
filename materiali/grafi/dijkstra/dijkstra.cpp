/*
 *      Algoritmo di Dijkstra con nodi indicati da interi
 * 		Implementazione che segue per quanto possibile quanto spiegato nelle
 * 		dispense, perseguendo la chiarezza e non l'efficienza o la sinteticità
 *
 *      Copyright 2012 Alessandro Bugatti <alessandro.bugatti@istruzione.it>
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

#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <limits>

using namespace std;

/**
 * \brief Rappresenta un arco orientato pesato
 */
struct Arco_orientato{
	int peso; ///<Peso dell'arco
	int nodo_destinazione; ///Indice del nodo verso cui è diretto
	Arco_orientato(int a, int b):nodo_destinazione(a), peso(b){};
};

//Rappresenta un nodo del grafo
struct Nodo{
	int precedente; ///<Indice del nodo da cui si arriva per ricostruire il percorso
	list <Arco_orientato> archi; ///<Archi in uscita dal grafo
	int distanza;
	/**
	 * \brief Costruttore che inizializza la distanza a "infinito", in pratica
	 * al massimo valore intero
	 */
	Nodo():precedente(-1),distanza(std::numeric_limits<int>::max()){};
};

Nodo nodi[100]; ///<Descrizione del grafo pesato e orientato
set <int> stabili;
int N,M;

int djikstra(int begin, int end, int n_nodi)
{
	//Metto a zero la distanza del nodo di partenza e 
	//lo inserisco nell'insieme dei nodi stabili
	nodi[begin].distanza = 0;
	stabili.insert(begin);
	Nodo nodo_corrente = nodi[begin];
	int ultimo_inserito = begin;
	//Qui viene fatto il controllo per verificare tutti i nodi, altrimenti si poteva anche fare
	//ultimo_inserito != end per evitare di controllare cose "inutili"
	while (stabili.size() != n_nodi)
	{
	    //Aggiorno tutti i nodi confinanti con l'ultimo stabile
		list <Arco_orientato>::iterator i = nodo_corrente.archi.begin();
		for(;i!=nodo_corrente.archi.end();++i)
		{
			int nodo_da_aggiornare = i->nodo_destinazione;
			//Se l'aggiornamento conviene viene aggiornato il nodo
			if (nodi[nodo_da_aggiornare].distanza > nodi[ultimo_inserito].distanza + i->peso)
			{
				nodi[nodo_da_aggiornare].distanza = nodi[ultimo_inserito].distanza + i->peso;
				nodi[nodo_da_aggiornare].precedente = ultimo_inserito;
			}
		}
		//Inserisco il nodo con distanza minore nell'insieme dei nodi stabili
		int min = std::numeric_limits<int>::max();
		for (int i = 1; i <= n_nodi; i++)
		{			
			//Se il nodo non è stabile e la sua distanza è minore di quella attualmente minima...
			if (stabili.find(i) == stabili.end() && nodi[i].distanza < min)
			{
				min = nodi[i].distanza;
				ultimo_inserito = i;
			}
		}
		nodo_corrente = nodi[ultimo_inserito];
		stabili.insert(ultimo_inserito);
	}
	return nodi[end].distanza;
}

void stampa_percorso(int begin, int end)
{
	if (begin == end) return;
	stampa_percorso(begin,nodi[end].precedente);
	cout << (char)(end + 'A' - 1) << " ";
}

int main(int argc, char *argv[])
{
    fstream in("input.txt",ios::in);
    in >> N >> M;
    for (int i=0; i<M; i++)
    {
        int a,b,c;
        in >> a >> b >> c;
		Arco_orientato temp(b,c);
        nodi[a].archi.push_back(temp);
    }
	//Come nodo finale potevo mettere quello che volevo per come è fatta la funzione
	djikstra(1,N,N);
	for (int i = 1; i<=N; i++)
	{
		cout << "La distanza minima tra A e " << (char)(i +'A' -1)<< " vale " << nodi[i].distanza << " con percorso ";
		stampa_percorso(1,i);
		cout << endl;
	}
	return 0;
}

/*Esempio di input (grafo della dispensa)
8 17
1 2 3
1 3 11
2 3 7
2 4 4
2 5 12
3 4 6
3 5 2
4 3 2
4 5 5
4 6 3
4 8 15
5 7 5
5 8 8
6 8 12
7 5 4
7 6 3
7 8 7
Output del programma
La distanza minima tra A e A vale 0 con percorso 
La distanza minima tra A e B vale 3 con percorso B 
La distanza minima tra A e C vale 9 con percorso B D C 
La distanza minima tra A e D vale 7 con percorso B D 
La distanza minima tra A e E vale 11 con percorso B D C E 
La distanza minima tra A e F vale 10 con percorso B D F 
La distanza minima tra A e G vale 16 con percorso B D C E G 
La distanza minima tra A e H vale 19 con percorso B D C E H 
* /
