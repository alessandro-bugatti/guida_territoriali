/*
  Name: fermata.cpp
  Copyright: GPL
  Author: Alessandro Bugatti
  Date: 01.04.2013 23:18:32
  Description: semplice automa a stati
  nazionali 2012
*/

#include <fstream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N, S, C;

struct cambio{
	int nuovo_stato;
	int spostamento;
};

struct stato{
	int stato_corrente;
	int posizione;
};

int nastro[1000000];
map <int, cambio> regole;
set <int> cicli, soluzioni, lavoro;

int main()
{
	fstream in,out;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    in >> N >> S >> C;
    for (int i= 0; i < S*C; i++)
    {
		int a,b;
		cambio c;
		in >> a;
		in >> b;
		in >> c.nuovo_stato;
		in >> c.spostamento;
		regole[a*10000 + b] = c;
	}
	for (int i= 0; i < N; i++)
		in >> nastro[i];
	stato macchina;
	queue <int> stati_soluzione;
	stati_soluzione.push(0);
	for (int i = 1; i < N; i++)
	{
		macchina.stato_corrente = 0;
		macchina.posizione = i;
		//cout << macchina.stato_corrente << " " << macchina.posizione << endl;
		int indice;
		cambio c;
		bool risolve = false;
		while (macchina.posizione != 0)
		{
			if (lavoro.find(macchina.stato_corrente*10000+macchina.posizione) != lavoro.end())
			{
				cicli.insert(lavoro.begin(),lavoro.end());
				break;
			}
			if (cicli.find(macchina.stato_corrente*10000+macchina.posizione) != cicli.end())
				break;
			if (soluzioni.find(macchina.stato_corrente*10000+macchina.posizione) != soluzioni.end())
			{
				risolve = true;
				break;
			}
			//cout << macchina.stato_corrente << " " << macchina.posizione << endl;
			lavoro.insert(macchina.stato_corrente*10000+macchina.posizione);
			indice = macchina.stato_corrente*10000+nastro[macchina.posizione];
			c = regole[indice];
			macchina.posizione += c.spostamento;
			macchina.stato_corrente = c.nuovo_stato;
		}
		if (macchina.posizione == 0 || risolve)
		{
			stati_soluzione.push(i);
			soluzioni.insert(lavoro.begin(), lavoro.end());
		}
		lavoro.clear();
	}
	out << stati_soluzione.size() << endl;
	while (!stati_soluzione.empty())
	{
		out << stati_soluzione.front() << endl;
		stati_soluzione.pop();
	}
	return 0;
}
