/*
 *      Problema depura - selezioni territoriali 2009
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
#include <set>
#include <list>

using namespace std;
int K,R;

list <int> sostanze[2001];
set <int> inAcqua;

bool scorriRegole(int i)
{
    if (inAcqua.find(i) != inAcqua.end()) return true;
    bool flag = true;
    for (list<int>::iterator j=sostanze[i].begin(); j !=sostanze[i].end(); j++)
    {
        if (sostanze[*j].empty() && inAcqua.find(*j) == inAcqua.end())
            return false;
        bool verificata = scorriRegole(*j);
        flag *= verificata;
    }
    if (flag)
        inAcqua.insert(i);
    return flag;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> K >> R;
	for (int i=0; i<K; i++)
	{
	    int temp;
		in >> temp;
		inAcqua.insert(temp);
	}
	for (int i=0; i<R; i++)
	{
	    int A,n;
		in >> A >> n;
		list <int> temp;
		for (int j=0; j<n; j++)
        {
            int t;
            in >> t;
            temp.push_back(t);
        }
        sostanze[A] = temp;
	}
    if (scorriRegole(1))
        out << inAcqua.size() - K << endl;
    else
        out << "-1" << endl;
	return 0;
}
