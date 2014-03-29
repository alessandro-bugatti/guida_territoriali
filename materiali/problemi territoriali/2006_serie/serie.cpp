/*
 *      Problema serie - selezioni territoriali 2006
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
#include <algorithm>			

using namespace std;

int N,K;
int testeDiSerie[100];
int squadre[10000];
	
//Funzione per il debugging
void stampaDebug()
{
	cout << "Squadre" << endl;
	for (int i = 0; i < K; i++)
		cout << squadre[K*N - i -1] << " ";
	cout << endl;
	cout << "Teste" << endl;
	for (int i = 0; i < K; i++)
		cout << testeDiSerie[K -i -1] << " ";
	cout << endl;
}	
	
int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> K >> N;
	int cont = 0;
	//Leggo ogni girone
	for (int i=0; i < K; i++)
	{
		//Per ogni girone metto le squadre nel vettore squadre
		//e il più forte del girone nel vettore testeDiSerie 
		int temp,testa;
		in >> temp;
		testa = temp;
		squadre[cont] = temp;
		cont++;  
		for (int j=1; j < N; j++)
		{
			in >> temp;
			if (temp > testa)
				testa = temp;
			squadre[cont] = temp;
			cont++;
		}
		testeDiSerie[i]=testa;
	}
	sort(squadre,squadre + K*N);		 
	sort(testeDiSerie,testeDiSerie + K);
	int ok = 1;
	for (int i = 0; i < K; i++)
		if(squadre[K*N - i - 1]!=testeDiSerie[K - i -1])
			ok = 0;
	//stampaDebug();
	out << ok << endl;
	return 0;
}
