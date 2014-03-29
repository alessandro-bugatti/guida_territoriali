/*
 *      Problema bilancino - selezioni territoriali 2006
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
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
int M,N;
list <int> relazioni[100];
int matrice[100][100];

void esplora_nodo(int n, int p)
{
	if (relazioni[n].empty()) return;
	list <int>::iterator i;
	for ( i = relazioni[n].begin(); i!= relazioni[n].end(); ++i)
	{
		matrice[p][*i] = matrice[*i][p] = 1;
		esplora_nodo(*i,p);
	}
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	for (int i = 0; i <100 ; i++)
		matrice[i][i] = 1;
	in >> N >> M;
	for (int i = 0; i <M ; i++)
	{
		int a, b;
		in >> a >> b;
		matrice[a][b] = matrice[b][a] = 1;
		relazioni[a].push_back(b);
	}
	//Cerco altre relazioni che si possono dedurre dalle precedenti
	for (int i = 1; i <= N; ++i)
	{
		esplora_nodo(i,i);
	}
	int cont = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			if (matrice[i+1][j+1] == 0)
				cont++;
	}
	/*for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << matrice[i+1][j+1] << " ";
		cout << endl;
	}*/
	if (cont == 0)
		out << 0 << endl;
	else if (cont == 2)
		out << 1 << endl;
	else
		out << 2 << endl;
	return 0;
}
