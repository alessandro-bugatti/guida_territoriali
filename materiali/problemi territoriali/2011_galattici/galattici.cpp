/*
 *      Problema galattici - selezioni territoriali 2011
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
int M,N,K;
char parola[11];
int I,J;
char c;

struct transizione{
	int I,J;
	char c;
};

transizione t[100];

int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> M >> N >> K;
	for(int i = 0; i < K; i++)
	{
		in >> parola[i];
	}
	for(int i = 0; i < M; i++)
	{
		in >> t[i].I >> t[i].J >> t[i].c;
	}
	int stato_attuale = 1;
	for(int i = 0; i < K; i++)
	{
		int j = 0;
		while (t[j].c != parola[i] || t[j].I != stato_attuale) j++;
		stato_attuale = t[j].J;
	} 
	out << stato_attuale;
	return 0;
}
