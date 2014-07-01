/*
 *      Problema domino - selezioni territoriali 2011
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

using namespace std;

int N;

struct tessera{
	int s,d;
};

tessera t[10];
tessera r[10];
bool usata[10];
tessera permutazione[10];
int lunghezza = 0;

void stampa_permutazione(int pos)
{
	for (int i = 0; i<pos;i++)
		cout << permutazione[i].s << "-" << permutazione[i].d << " ";
	cout << endl;
}

void trova_permutazione(int pos)
{
	if (pos > lunghezza)	
		lunghezza = pos;
	for (int i = 0; i < N; i++)
	{
		if (pos == 0 || (permutazione[pos-1].d == t[i].s && usata[i] == false))
		{
			permutazione[pos] = t[i];
			stampa_permutazione(pos+1);
			usata[i] = true;
			trova_permutazione(pos + 1);
			usata[i] = false;
		}
		if (pos == 0 || (permutazione[pos-1].d == r[i].s && usata[i] == false))
		{
			permutazione[pos] = r[i];
			stampa_permutazione(pos+1);
			usata[i] = true;
			trova_permutazione(pos + 1);
			usata[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for(int i = 0; i < N; i++)
	{
		in >> t[i].s >> t[i].d;
		r[i].s = t[i].d;
		r[i].d = t[i].s;
	}
	for(int i = 0; i < N; i++)
		usata[i] = false;
	trova_permutazione(0);
	out << lunghezza;
	return 0;
}
