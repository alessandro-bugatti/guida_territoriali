/*
 *      Problema gardaland - selezioni territoriali 2013
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

using namespace std;

int nazioni[100];
int N,L;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> L;
	for (int i = 0; i < N; i++)
		in >> nazioni[i];
	for (int i = 0; i < L; i++)
	{
		int n,r;
		in >> n >> r;
		nazioni[n] -= r;
	}
	int assenti = 0;
	for (int i = 0; i < N; i++)
		if (nazioni[i] != 0)
			assenti++;	
	out << assenti << endl;
	if (assenti)
		for (int i = 0; i < N; i++)
				if (nazioni[i] != 0)
					out << i << " " << nazioni[i] << endl;
	return 0;
}
