/*
 *      Problema pizzini - selezioni territoriali 2008
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

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
struct Riga{
	int numero_anagrammi;
	string valore;
	Riga():numero_anagrammi(0){}
};

Riga righe[100];
string ordinate[100];

int main()
{
	fstream in, out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N;
	for (int i=0;i< N;i++)
	{
		in >> righe[i].valore;
		ordinate[i] = righe[i].valore;
		sort(ordinate[i].begin(), ordinate[i].end());
	}
	for (int i=0;i< N;i++)
		for (int j=0;j< N;j++)
			 if (ordinate[i]==ordinate[j])
				 righe[j].numero_anagrammi++;
	for (int i=0;i< N;i++)
		out << righe[i].valore.at(righe[i].numero_anagrammi-1);	
	return 0;
}
