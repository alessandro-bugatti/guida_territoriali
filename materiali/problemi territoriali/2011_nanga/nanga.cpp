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

//Versione con le mappe, minimo uso di memoria
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int N;
map <int , int> m;
int alt = 5000;
pair<map<int,int>::iterator,bool> ret;

int main(int argc, char** argv)
{
	int temp;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	for (int i = 0; i < N; i++)
	{
		in >> temp;
		alt += temp;
		ret = m.insert(pair<int,int>(alt,1));
		if (ret.second == false)
			ret.first->second++;
	}
	map<int,int>::iterator i;
	i = m.begin();
	int max = i->first;
	int quanti = i->second;
	for (; i!=m.end();i++)
		if (i->second > quanti)
		{
			max = i->first;
			quanti = i->second;
		}
	out << max;
	return 0;
}
