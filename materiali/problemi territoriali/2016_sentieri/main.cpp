//sentieri - territoriali 2016
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <limits>

using namespace std;

struct sentiero{
	int arriva;
	int lunghezza;
	sentiero(int a, int b):arriva(a),lunghezza(b){}
};

struct incrocio{
	int distanza;
	list <sentiero> collegate;
	incrocio():distanza(numeric_limits<int>::max()){}
};

incrocio incroci[101];
set <int> stabili;
int N, A, B;
int percorso_minimo;

	
int dijkstra(int begin, int end, int n_incroci)
{
	//Metto a zero la distanza del nodo di partenza e 
	//lo inserisco nell'insieme dei nodi stabili
	incroci[begin].distanza = 0;
	stabili.insert(begin);
	incrocio incrocio_corrente = incroci[begin];
	int ultimo_inserito = begin;
	while (ultimo_inserito != end)
	{
	    //Aggiorno tutti i nodi confinanti con l'ultimo stabile
		auto i = incrocio_corrente.collegate.begin();
		for(;i!=incrocio_corrente.collegate.end();++i)
		{
			int incrocio_da_aggiornare = i->arriva;
			//Se l'aggiornamento conviene viene aggiornato il nodo
			if (incroci[incrocio_da_aggiornare].distanza > incroci[ultimo_inserito].distanza + i->lunghezza)
					incroci[incrocio_da_aggiornare].distanza = incroci[ultimo_inserito].distanza + i->lunghezza;
				
		}
		//Inserisco il nodo con distanza minore nell'insieme dei nodi stabili
		int min = std::numeric_limits<int>::max();
		for (int i = 1; i <= n_incroci; i++)
		{			
			//Se il nodo non è stabile e la sua distanza è minore di quella attualmente minima...
			if (stabili.find(i) == stabili.end() && incroci[i].distanza < min)
			{
				min = incroci[i].distanza;
				ultimo_inserito = i;
			}
		}
		incrocio_corrente = incroci[ultimo_inserito];
		stabili.insert(ultimo_inserito);
	}
	return incroci[end].distanza;
}


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> A >> B;
	//Sentieri normali
	for (int i = 0; i < A; i++)
	{
		int u,v;
		in >> u >> v;
		incroci[u].collegate.push_back(sentiero(v,0));
		incroci[v].collegate.push_back(sentiero(u,0));
	}
	//Sentieri bollenti
	for (int i = 0; i < B; i++)
	{
		int u,v;
		in >> u >> v;
		incroci[u].collegate.push_back(sentiero(v,1));
		incroci[v].collegate.push_back(sentiero(u,1));
	}
	out << dijkstra(1, N, N) << endl;
	return 0;
}
