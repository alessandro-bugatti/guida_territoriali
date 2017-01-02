//footing - territoriali 2015
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <limits>

using namespace std;

struct tratto{
	int arriva;
	int lunghezza;
	tratto(int a, int b):arriva(a),lunghezza(b){}
};

struct casa{
	int distanza;
	list <tratto> collegate;
	casa():distanza(numeric_limits<int>::max()){}
};

casa casette[1001];
set <int> stabili;
int N, M;
int tratti[10000][3];
int percorso_minimo;

void inizializza_djikstra()
{
	for (int i = 0; i <= N; i++)
		casette[i].distanza = std::numeric_limits<int>::max();
	stabili.clear();
}
	
int djikstra(int begin, int end, int n_case, int interno)
{
	//Metto a zero la distanza del nodo di partenza e 
	//lo inserisco nell'insieme dei nodi stabili
	casette[begin].distanza = interno;
	stabili.insert(begin);
	casa casa_corrente = casette[begin];
	int ultimo_inserito = begin;
	while (ultimo_inserito != end)
	{
	    //Aggiorno tutti i nodi confinanti con l'ultimo stabile
		list <tratto>::iterator i = casa_corrente.collegate.begin();
		for(;i!=casa_corrente.collegate.end();++i)
		{
			//Escludo il tratto diretto da begin a end
			if ((ultimo_inserito != begin || i->arriva != end))
			{
				int casa_da_aggiornare = i->arriva;
				//Se l'aggiornamento conviene viene aggiornato il nodo
				if (casette[casa_da_aggiornare].distanza > casette[ultimo_inserito].distanza + i->lunghezza)
					casette[casa_da_aggiornare].distanza = casette[ultimo_inserito].distanza + i->lunghezza;
				
			}
		}
		//Inserisco il nodo con distanza minore nell'insieme dei nodi stabili
		int min = std::numeric_limits<int>::max();
		for (int i = 1; i <= n_case; i++)
		{			
			//Se il nodo non è stabile e la sua distanza è minore di quella attualmente minima...
			if (stabili.find(i) == stabili.end() && casette[i].distanza < min)
			{
				min = casette[i].distanza;
				ultimo_inserito = i;
			}
		}
		casa_corrente = casette[ultimo_inserito];
		if (min >= percorso_minimo ) return std::numeric_limits<int>::max();
		stabili.insert(ultimo_inserito);
	}
	
	return casette[end].distanza;
}


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u,v,w;
		in >> u >> v >> w;
		casette[u].collegate.push_back(tratto(v,w));
		casette[v].collegate.push_back(tratto(u,w));
		tratti[i][0] = u;
		tratti[i][1] = v;
		tratti[i][2] = w;
	}
	percorso_minimo = numeric_limits<int>::max();
	for (int i = 0; i < M; i++)
	{
		inizializza_djikstra();
		int temp = djikstra(tratti[i][0],tratti[i][1],N,tratti[i][2]);
		//cout << tratti[i][0] << " " << tratti[i][1] << " " << tratti[i][2] << " " << temp << endl; 
		if (temp < percorso_minimo)
			percorso_minimo = temp;
	}
	out << percorso_minimo << endl;
	return 0;
}
