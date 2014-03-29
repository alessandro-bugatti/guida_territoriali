/*
 *      Problema brambillia - selezioni territoriali 2006
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
int abitanti[100];
int costi[100];
int spostamenti[100][100];
int orario[100];
int antiorario[100];
	
void stampaDebug(int riga)
{
	cout << "Orario" << endl;
	for (int i=0; i < N; i++)
		cout << orario[i] << " "; 
	cout << endl;
	cout << "Antiorario" << endl;
	for (int i=0; i < N; i++)
		cout << antiorario[i] << " "; 
	cout << endl;
	cout << "Costi" << endl;
	for (int i=0; i < N; i++)
		cout << spostamenti[riga][i] << " "; 
	cout << endl;
}	

int costoSpostamento(int i)
{
	int costo = 0;
	for (int j = 0; j < N; j++)
		costo += spostamenti[i][j]*abitanti[j];
	return costo;
}
	
int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i=0; i < N; i++)
		in >> costi[i];
	for (int i=0; i < N; i++)
		in >> abitanti[i];
	//Per ogni città
	for (int i=0; i < N; i++)
	{
		//Calcolo dei costi per arrivare alla città i-esima
		//spostandosi in senso orario
		orario[i] = 0;
		for (int j = 1; j < N; j++)
			orario[(j+i)%N] = orario[((j+i)-1)%N] + costi[(j+i-1)%N];
		//Calcolo dei costi per arrivare alla città i-esima
		//spostandosi in senso antiorario
		antiorario[i] = 0;
		for (int j = 1; j < N; j++)
			antiorario[(j+i)%N] = antiorario[((j+i)-1)%N] + costi[(N - j + i)%N];
		//Calcolo il senso chemi permette il costo minimo
		//e lo inserisco nella matrice dei costi
		for (int j = 1; j < N; j++)
			if (orario[(j+i)%N] < antiorario[(N-j+i)%N])
				spostamenti[i][(j+i)%N] = orario[(j+i)%N];
			else
				spostamenti[i][(j+i)%N] = antiorario[(N-j+i)%N];
		//stampaDebug(i);
	} 
	//Calcolo il costo per ogni città e trovo il minimo
	int minimo = costoSpostamento(0);
	int citta = 0;
	for (int j = 1; j < N; j++)
		if (costoSpostamento(j) < minimo)
		{
			minimo = costoSpostamento(j);
			citta = j;
		}
	out << citta + 1 << endl;
	return 0;
}
