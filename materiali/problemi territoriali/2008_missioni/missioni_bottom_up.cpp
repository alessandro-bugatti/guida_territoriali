/*
 *      Problema missioni - selezioni territoriali 2008
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
#include <iostream>

using namespace std;

struct Missione
{ 
  int durata, fine; 
};

Missione missioni[101];
int soluzioni[366];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	for (int i=0; i<n; i++)
		in >> missioni[i].durata >> missioni[i].fine;
    for (int i=0; i<n; i++)
       for (int j=missioni[i].fine - missioni[i].durata; j>=0; j--)
			if (soluzioni[j] + 1 > soluzioni[j+missioni[i].durata])
                    soluzioni[j+missioni[i].durata] = soluzioni[j]+1;
    int max = soluzioni[0];
    for (int i=0; i<366; i++)  
		if (soluzioni[i] > max) max = soluzioni[i];
    out << max;
            
}
