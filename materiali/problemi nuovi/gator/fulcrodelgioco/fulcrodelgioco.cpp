//Fulcro del gioco Gator 2014

#include <fstream>
#include <list>
#include <stack>

using namespace std;

int M;

struct giocatore{
	list <int> passaggi;
};

giocatore giocatori[12];

bool visitato[12];

int visita(int n)
{
	int contatore = 0;
	fill(visitato, visitato + 12,false);
	visitato[n] = true; //escludo il giocatore n dal gioco
	stack <int> pila;
	pila.push(1); //parto sempre dal portiere
	while(!pila.empty())
	{
		int corrente = pila.top();
		pila.pop();
		if (visitato[corrente] == false)
		{
			visitato[corrente] = true;
			list <int>::iterator i;
			for (i = giocatori[corrente].passaggi.begin();
				i!=giocatori[corrente].passaggi.end();i++)
				pila.push(*i);
		}
	}
	for (int i = 2; i<12; i++)
		if (visitato[i] == false)
			contatore++;
	return contatore;
}
	

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		in >> a >> b;
		giocatori[a].passaggi.push_back(b);
	}
	int numero_maglia = 0, giocatori_esclusi = -1;
	for (int i = 2; i < 12; i++)
	{
		int temp = visita(i);
		if (temp > giocatori_esclusi)
		{
			giocatori_esclusi = temp;
			numero_maglia = i;
		}
	}
	out << numero_maglia << endl;
	return 0;
}
