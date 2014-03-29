/*
 *      Visita in profondità di un grafo con nodi indicati da interi
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

#include <iostream>
#include <fstream>
#include <list>
#include <stack>

using namespace std;

//Struttura che rappresenta una lista di adiacenza
struct lista {
    list <int> l;
};

//Vettore delle liste
list<int> liste[100];
int visitato[100];
stack <int> pila;
int N,M;

void visita_profondita(int n)
{
    pila.push(n);
    while (!pila.empty())
    {
        int corrente = pila.top();
        pila.pop();
        if (visitato[corrente] == false)
        {
            visitato[corrente] = true;
            cout << corrente << endl;
            for (list <int>::iterator i = liste[corrente].begin(); i!=liste[corrente].end();i++)
                pila.push(*i);
        }
    }
}

int main(int argc, char *argv[])
{
    fstream in("input.txt",ios::in);
    in >> N >> M;
	for (int i=0; i<N; i++)
		visitato[i] = false;
    for (int i=0; i<M; i++)
    {
        int a,b;
        in >> a >> b;
        liste[a].push_back(b);
        liste[b].push_back(a);
    }
    visita_profondita(1);
    return 0;
}
