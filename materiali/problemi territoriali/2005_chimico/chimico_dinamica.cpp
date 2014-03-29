/*
  Name: chimico_dinamica.cpp
  Copyright: GPL
  Author: Alessandro Bugatti
  Date: 29.03.2013 16:00:31
  Description: Soluzione dinamica
  territoriali 2005
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int A; //Aminozalina
int B; //Brinofulo
int N; //numero di contenitori
int totale_bidoni;

struct bidone
{
    int posizione;
    int capacita;
    int riempito; //0 = vuoto, 1 = Aminozalina 2 = Brinofulo
};

struct soluzione{
	int quanti;
	int precedente;
};

struct nodo{
	soluzione soluzioni[2];
	bool raggiungibile;
};

bidone bidoni[100];
nodo aminozalina[10000]; //Da verificare la dimensione
nodo brinofulo[10000];


int compare_posizione(const void *a, const void *b)
{
  bidone ba = *(const bidone *) a;
  bidone bb = *(const bidone *) b;

  return (ba.posizione > bb.posizione) - (ba.posizione < bb.posizione);
}

int compare_capacita(const void *a, const void *b)
{
  bidone ba = *(const bidone *) a;
  bidone bb = *(const bidone *) b;

  return (ba.capacita > bb.capacita) - (ba.capacita < bb.capacita);
}

void stampa_debug(const nodo *a)
{
	cout << "Vettore appoggio " << endl;
	for (int i=0; i<=totale_bidoni; i++)
	{
		cout << "Indice: " << i ;
		if (!a[i].raggiungibile)
			cout << " Non raggiungibile" << endl;
		else
			cout << " S1: " << a[i].soluzioni[0].quanti << " - " 
			<< a[i].soluzioni[0].precedente << " S2: " <<
			a[i].soluzioni[1].quanti << " - " 
			<< a[i].soluzioni[1].precedente << endl;
	}
}

stack <int> crea_soluzione(const nodo *a, int inizio)
{
	stack <int> sol;
	while (a[inizio].soluzioni[0].precedente > 0)
	{
		sol.push(a[inizio].soluzioni[0].precedente);
		inizio = inizio - a[inizio].soluzioni[0].precedente;
	}
	return sol;
}
	
int cmp_aminozalina(int a, int b)
{
	return a > b;
}

int cmp_brinofulo(int a, int b)
{
	return a < b;
}


void costrusci_vettore(nodo *a, int (*cmp)(int,int))
{
	int somma_precedenti = 0;
    for (int i=0; i<N;i++)
    {
		int inizio = bidoni[i].capacita;
		int fine = bidoni[i].capacita + somma_precedenti;
        for (int j = inizio; j <= fine; j++)
			if (a[j - bidoni[i].capacita].raggiungibile)
			{
				int flag = 0;
				if (cmp(a[j - bidoni[i].capacita].soluzioni[0].quanti + 1,  
						a[j].soluzioni[0].quanti) ||  //se ottengo una soluzione migliore
					a[j].soluzioni[0].quanti == 0) //o se è la prima volta che lo esploro
						{
							//se non ho già usato il bidone
							if(a[j - bidoni[i].capacita].soluzioni[0].precedente != bidoni[i].capacita)
							{
								a[j].soluzioni[1] = a[j].soluzioni[0]; //potrebbe essere inutile
								a[j].soluzioni[0].quanti = a[j - bidoni[i].capacita].soluzioni[0].quanti + 1;
								a[j].soluzioni[0].precedente = bidoni[i].capacita;
								a[j].raggiungibile = true;
							}
							//se ho già usato il bidone, ma c'era una soluzione precedente oppure è la prima volta che lo uso
							if((a[j - bidoni[i].capacita].soluzioni[0].precedente == bidoni[i].capacita &&
								a[j - bidoni[i].capacita].soluzioni[1].quanti != 0) || flag == 0)
							{
								if(a[j - bidoni[i].capacita].soluzioni[0].precedente == bidoni[i].capacita &&
								a[j - bidoni[i].capacita].soluzioni[1].quanti != 0)
								{
									a[j].soluzioni[0].quanti = a[j - bidoni[i].capacita].soluzioni[1].quanti + 1;
									a[j].soluzioni[0].precedente = bidoni[i].capacita;
									a[j].raggiungibile = true;
								}
								else
								//Se il motivo per cui sono entrato in questo ciclo è che era la prima volta che lo usavo 
								//setto ch
								{
									a[j].soluzioni[0].quanti = a[j - bidoni[i].capacita].soluzioni[0].quanti + 1;
									a[j].soluzioni[0].precedente = bidoni[i].capacita;
									a[j].raggiungibile = true;
									flag = 1;
								}
							}
						}
			}
        somma_precedenti += bidoni[i].capacita;
    }
}

int main(int argc, char *argv[])
{
    fstream in,out;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    in >> A >> B >> N;
    for (int i=0; i<N; i++)
    {
        bidoni[i].posizione=i;
        in >> bidoni[i].capacita;
        totale_bidoni+=bidoni[i].capacita;
        bidoni[i].riempito=0;
    }
    //Ordino i bidoni in base alla capacita
    qsort(bidoni,N,sizeof(bidone),compare_capacita);
    //Inizializzo i vettori che mi servono per la dinamica
    for (int i=0; i<totale_bidoni;i++)
    {
		aminozalina[i].raggiungibile = false;
		brinofulo[i].raggiungibile = false;
	}
	aminozalina[0].raggiungibile = true;
	brinofulo[0].raggiungibile = true;
    costrusci_vettore(aminozalina,cmp_aminozalina);
    costrusci_vettore(brinofulo,cmp_brinofulo);
    //Vado a settare gli stack riempiti a partire dalle due soluzioni
    stack <int> a = crea_soluzione(aminozalina,A);
    stack <int> b = crea_soluzione(brinofulo,B);
    /*stampa_debug(aminozalina);
     while (!a.empty())
    {
		cout << a.top() << " ";
		a.pop();
	}
    stampa_debug(brinofulo);
     while (!b.empty())
    {
		cout << b.top() << " ";
		b.pop();
	}*/
	//Vado a settare il flag riempito dei bidoni usati nelle soluzioni
	int i = 0;
	while (!a.empty())
    {
		if (a.top() == bidoni[i].capacita)
		{
			bidoni[i].riempito = 1;
			a.pop();
		}
		i++;
	}
    i = 0;
	while (!b.empty())
    {
		if (b.top() == bidoni[i].capacita)
		{
			bidoni[i].riempito = 2;
			b.pop();
		}
		i++;
	}
    qsort(bidoni,N,sizeof(bidone),compare_posizione);
    //Stampo il risultato
    for (int i=0; i<N ; i++)
        if (bidoni[i].riempito == 0)
            out << "0 0" << endl;
        else if(bidoni[i].riempito == 1)
            out << bidoni[i].capacita << " 0" << endl;
        else
            out << "0 " << bidoni[i].capacita << endl;
    in.close();
    out.close();
    return EXIT_SUCCESS;
}
