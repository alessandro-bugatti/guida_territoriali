/*
 *      Problema torero - selezioni territoriali 2007
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
#include <vector>			

using namespace std;

class indumento{
	public:
	bool indossabile;
	vector<int> lista;
	indumento():indossabile(true){}
};

int N,M,Q, non = 0;
indumento indumenti[100000];
	
void propaga(int n)
{
	if (indumenti[n].indossabile == false) return;
	non++;
	indumenti[n].indossabile = false;
	for (int j = 0; j < indumenti[n].lista.size(); j++)
		propaga(indumenti[n].lista[j]);
	
}

void stampaDebug()
{
	
	for (int i = 0; i < N; i++)
	{
		cout << i+1 << " " << indumenti[i+1].indossabile << " -> " ;
		for (int j = 0; j < indumenti[i+1].lista.size(); j++)
			cout << indumenti[i+1].lista[j] << " ";
		cout << endl;
	}
}	
	
int main(int argc, char** argv)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> M >> Q;
	//Leggo le regole di precedenza e le metto nel vettore
	for (int i=0; i < M; i++)
	{
		int r,s;
		in >> r >> s;
		indumenti[r].lista.push_back(s);
	}
	
	//stampaDebug();
	propaga(Q);
	//stampaDebug();
	out << N-non << endl;
	return 0;
}
