/*
 *      Problema dello zaino - soluzione dinamica bottom-up
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
#include <cstdlib>

using namespace std;

//Struttura che rappresenta un oggetto
struct oggetto{
    int peso; 
    int valore; 
};
//Vettore degli oggetti
oggetto oggetti[100];
int soluzioni[1000];
int M,N;

int knapsack_bottom_up(int n)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= M - oggetti[i].peso ; j++)
			if (soluzioni[j] + oggetti[i].valore > soluzioni[j+oggetti[i].peso])
				soluzioni[j+oggetti[i].peso] = soluzioni[j] + oggetti[i].valore;
	//trovo il massimo in soluzioni
	int max = 0;
	for (int i = 0; i <= M; i++)
		if (soluzioni[i] > max)
			max = soluzioni[i];
	return max;
}

int main(int argc, char *argv[])
{
  int valore = 0;
  fstream in("input.txt",ios::in);
  fstream out("output.txt",ios::out);
  in >> M;
  in >> N;
  for (int i=0; i<N; i++)
    in >> oggetti[i].peso >> oggetti[i].valore;
  valore = knapsack_bottom_up(M);
  out << valore;
  return 0;
}
