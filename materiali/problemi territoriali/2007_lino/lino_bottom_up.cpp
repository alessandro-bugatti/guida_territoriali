/*
 *      Problema lino - selezioni territoriali 2007
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
#include <algorithm>

using namespace std;

int monete[100];
int soluzioni[1001];
int N,R;


int main()
{
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> R;
	for (int i=0;i<N;i++)
		in >> monete[i];	
	for (int i=0; i<=R; i++)
		soluzioni[i] = 0;
	soluzioni[0]=1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= R - monete[i]; j++)
			soluzioni[j + monete[i]] = soluzioni[j + monete[i]] + soluzioni[j];  
	out << soluzioni[R];
	return 0;
}
