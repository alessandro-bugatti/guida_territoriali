/*
 *      Problema sostituzioni gara ABC Bergamo 2013
 * 		Soluzione ricorsiva con memoizzazione
 *      
 *      Copyright 2013 Alessandro Bugatti <alex@susie>
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

#define INT_MAX 1000000000
int a[10];
int N, M;
int tab[10000][11];

int costo(int m, int e)
{
	if (m == M && e == N)
		return 0;
	if (e == N)
		return INT_MAX;
	int min = INT_MAX;
	int i = -a[e];
	for(;m + (a[e] + i)*(a[e] + i) <= M;i++)
	{
		int ci;
		if (tab[m][e] != -1)
			ci = tab[m][e];
		else
			ci = costo(m + (a[e] + i)*(a[e] + i), e + 1) + i*i;
		if ( ci < min)
			min = ci;
	}
	tab[m][e] = min;
	return min;
}

int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> M;
	for (int i = 0; i < N; i++)
		in >> a[i];
	for (int i = 0 ; i <10000;i ++)
		for (int j = 0 ; j <11;j ++)
			tab[i][j] = -1;
	int c = costo (0,0) ;
	if (c == INT_MAX) 
		out << -1 << endl;
	else
		out << c << endl;
	return 0;
}
