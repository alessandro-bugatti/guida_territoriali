//footing - territoriali 2015
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

struct tratto{
	int arriva;
	int lunghezza;
	tratto(int a, int b):arriva(a),lunghezza(b){}
};

struct casa{
	int numero;
	int visita;
	list <tratto> collegate;
	casa():visita(-1){}
};

casa casette[1001];
int N, M;
int vie[1001][1001];


int percorso_minimo = 1000000000;


void percorri(int partenza, int tragitto)
{
	list<tratto>::iterator i;
	for (i = casette[partenza].collegate.begin();
		i != casette[partenza].collegate.end(); ++i)
		{
			
			if (vie[partenza][i->arriva] == 0 && i->lunghezza < percorso_minimo  )
			{
				//cout << partenza << " " << i->arriva << " v: " << casette[i->arriva].visita << " t: " << tragitto << endl;
				vie[partenza][i->arriva] = vie[i->arriva][partenza] = 1;	
				if (casette[i->arriva].visita == -1)
				{
					casette[i->arriva].visita = tragitto + i->lunghezza;
					percorri(i->arriva,tragitto + i->lunghezza);
				}
				else
				{
					if (tragitto + i->lunghezza - casette[i->arriva].visita < percorso_minimo)
						percorso_minimo = tragitto + i->lunghezza - casette[i->arriva].visita;
					vie[i->arriva][partenza] = 1;
					//cout << "M: " << percorso_minimo << endl;
				}
			}
			vie[partenza][i->arriva] = 0;	
		}
		casette[partenza].visita = -1;
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
		//cout << u << " " << v << " " << w << endl;
		casette[u].collegate.push_back(tratto(v,w));
		casette[v].collegate.push_back(tratto(u,w));
	}
	/*for (int i = 1; i <= N; i++)
	{
		cout << i << "->";
		list<tratto>::iterator li;
	for (li = casette[i].collegate.begin();
		li != casette[i].collegate.end(); ++li)
			cout << li->arriva << "," << li->lunghezza << " - ";
		cout << endl;
	}*/
	casette[1].visita = 0;
	percorri(1,0);
	out << percorso_minimo << endl;
	return 0;
}
