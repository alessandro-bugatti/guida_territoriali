/*
 *      Problema trovaparola - selezioni territoriali 2013
 *      
 *      Copyright 2013 Alessandro Bugatti <alessandro.bugatti@istruzione.it>
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

#include <fstream>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int R,C;
char matrice[101][101];
char parola[201];
stack <char> percorso;

bool naviga(int i, int j, int l)
{
	if (l == strlen(parola))
		return true;
	if (matrice[i][j] != parola[l])
		return false;
	if (naviga(i+1,j,l+1) == true)
	{
		percorso.push('B');
		return true;
	}
	if (naviga(i,j+1,l+1) == true)
	{
		percorso.push('D');
		return true;
	}
	return false;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> R >> C;
	in >> parola;
	for (int i = 0; i < R; i++)
		in >> matrice[i];
	if (naviga(0,0,0) == true)
	{
		while(!percorso.empty())
		{
			out << percorso.top();
			percorso.pop();
		}
		out << endl;
	}
	else
		out << "ASSENTE" << endl;
	return 0;
}
