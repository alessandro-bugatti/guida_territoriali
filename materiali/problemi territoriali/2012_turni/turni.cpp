/*
 *      Problema turni - selezioni territoriali 2012
 *      
 *      Copyright 2012 Alessandro Bugatti <alessandro.bugatti@istruzione.it>
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
#include <algorithm>

using namespace std;

class Turno
{ 
	public:
	int inizio, fine; 
	bool operator< (const Turno& t) const
	{
		return inizio < t.inizio;
	}
};

Turno turni[50];
int K,N;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> K >> N;
	for (int i=0; i<N; i++)
		in >> turni[i].inizio >> turni[i].fine;
    sort(turni, turni + N);
	int fine = -1;
	int i = 0;
	int quanti = 0;
	while (fine < K-1)
	{
		int max = turni[i].fine;
		while (turni[i].inizio - 1 <= fine)
		{
			if (turni[i].fine > max)
				max = turni[i].fine;
			i++;
		}
		fine = max;
		quanti++;
	}
	out << quanti << endl;
	return 0;
            
}
