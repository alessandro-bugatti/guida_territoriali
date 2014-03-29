/*
 *      Problema nanga - Selezioni territoriali 2011
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

//Versione con i vettori, massima efficienza, spreco di memoria 
//che con le assunzioni date è accettabile
#include <iostream>
#include <fstream>

using namespace std;

int N;
int alt = 100000;
int quote[200001];
int main()
{
	int temp;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i = 0; i < N; i++)
	{
		in >> temp;
		alt += temp;
		quote[alt]++;
	}
	int max = 0;
	int quanti = quote[0];
	for (int i = 0; i<200001;i++)
		if (quote[i]>quanti)
		{
			max = i;
			quanti = quote[i];
		}
	out << max - 95000;
	return 0;
}
