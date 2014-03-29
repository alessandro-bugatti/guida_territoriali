/*
 *      Problema sostituzioni gara ABC Bergamo 2013
 * 		Soluzione DP bottom-up
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
int a[11];
int N, M;
int tab[11][10001];


int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> M;
	for (int i = 1; i <= N; i++)
		in >> a[i];
	for (int i = 0 ; i <11;i ++)
		for (int j = 0 ; j <10001;j ++)
			tab[i][j] = -1;
	tab[0][0] = 0;
	int i,j,k;
	for (i = 1; i<=N; i++)
		for (j=0; j<=M; j++)
		{
			if (tab[i-1][j]!=-1)
			{
				k = -a[i];
				for (;j + (a[i] + k)*(a[i] + k) <= M;k++){
					int b = a[i]+k;
					if(tab[i-1][j] + k*k < tab[i][j + b*b)]
						|| tab[i][j + b*b] == -1)
						tab[i][j + b*b)] = tab[i-1][j] + k*k;
				}
			}
		}
	out << tab[N][M] << endl;
	return 0;
}
