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



#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

//#define DEBUG

struct Intervallo
{
    int inizio, fine;
};

//Ordinamento per intervallo di fine in senso crescente
bool compare_intervalli(const Intervallo &a, const Intervallo &b)
{
    if (a.fine < b.fine)
        return true;
    else
        return false;
}

int N;
Intervallo giri[1000];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for (int i=0; i<N; i++) {
        in >> giri[i].inizio >> giri[i].fine;
    }
#ifdef DEBUG
    for (int i=0; i<N; i++)
        cout << giri[i].inizio << " " << giri[i].fine  <<  endl;
#endif
    //Ordino per istante di fine
    sort(giri,giri+N,compare_intervalli);
#ifdef DEBUG
    for (int i=0; i<N; i++)
        cout << giri[i].inizio << " " << giri[i].fine  <<  endl;
#endif
    int fine_attuale = giri[0].fine;
    int caramelle = 1;
    for (int i=1; i<N; i++)
    {
        if (fine_attuale < giri[i].inizio)
        {
            fine_attuale = giri[i].fine;
            caramelle++;
        }
    }
    out << caramelle << endl ;
    return 0;
}

