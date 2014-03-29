/*
 *      Problema essenza - selezioni territoriali 2009
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

using namespace std;

int K,N;
int vettore[1000];

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> K >> N;
	for (int i=0; i<N; i++)
		in >> vettore[i];
	int max=0;
	for (int i=0; i<N; i++)
		for (int j=0; j<=K; j++)
			if (i+j<N && vettore[i+j] - vettore[i] > max)
				max = vettore[i+j] - vettore[i];
	out << max << endl;
	return 0;
}
