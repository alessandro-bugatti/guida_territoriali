#include <fstream>
#include <list>
#include <stack>

using namespace std;

int N, A, Mg, Mb, Mt;

struct fermata{
	bool attrazione;
	list <int> collegamenti;
	fermata():attrazione(false){}
};

fermata gratuiti[1000];
fermata bus[1000];
fermata traghetti[1000];	
fermata tutti[1000];

void inserisci_collegamento(fermata *grafo,int a, int b)
{
	grafo[a].collegamenti.push_back(b);
	grafo[b].collegamenti.push_back(a);
}

int visita(fermata *grafo, int n)
{
	int contatore = 0;
	bool visitato[1000];
	stack <int> pila;
	fill(visitato, visitato + 1000,false);
	pila.push(n);
	while(!pila.empty())
	{
		int corrente = pila.top();
		pila.pop();
		if (visitato[corrente] == false)
		{
			visitato[corrente] = true;
			if (grafo[corrente].attrazione == true) contatore++;
			list <int>::iterator i;
			for (i = grafo[corrente].collegamenti.begin();
				i!=grafo[corrente].collegamenti.end();i++)
				pila.push(*i);
		}
	}
	return contatore;
}
	

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int temp,a,b;
	in >> N >> A >> Mg >> Mb >> Mt;
	for (int i = 0; i < A; i++)
	{
		in >> temp;
		gratuiti[temp].attrazione = true;
		bus[temp].attrazione = true;
		traghetti[temp].attrazione = true;
		tutti[temp].attrazione = true;
	}
	for (int i = 0; i < Mg; i++)
	{
		in >> a >> b;
		inserisci_collegamento(gratuiti,a,b);
		inserisci_collegamento(bus,a,b);
		inserisci_collegamento(traghetti,a,b);
		inserisci_collegamento(tutti,a,b);
	}
	for (int i = 0; i < Mb; i++)
	{
		in >> a >> b;
		inserisci_collegamento(bus,a,b);
		inserisci_collegamento(tutti,a,b);
	}
	for (int i = 0; i < Mt; i++)
	{
		in >> a >> b;
		inserisci_collegamento(traghetti,a,b);
		inserisci_collegamento(tutti,a,b);
	}
	out << visita(gratuiti,0) << endl;
	out << visita(bus,0) << endl;
	out << visita(traghetti,0) << endl;
	out << visita(tutti,0) << endl;
    return 0;
}
