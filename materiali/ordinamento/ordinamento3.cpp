/*
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief Esempio di ordinamento di un vettore di strutture in C
 *  utilizzando la funzione di libreria qsort
 *  \author Alessandro Bugatti
 *
 *  \version 0.2
 *  \date  Creazione  19/03/2009
 *  \date  Ultima modifica 19/03/2009
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct persona{
    int peso;
    int altezza;
};

//Ordina per peso, in caso di pesi uguali ordina per altezza
bool cmp(const persona& a,const persona& b)
{
    if (a.peso >= b.peso) return false;
    if (a.peso < b.peso) return true;
    if (a.altezza >= b.altezza) return false;
    if (a.altezza < b.altezza) return true;
    return true;
}

vector <persona> vettore;

int main()
{
    //inserisco dieci pesi e altezze casuali, i pesi sono
    //uguali a due a due per mostrare il funzionamento
    //della funzione di comparazione
    for (int i=0; i<10; i+=2)
    {
        persona tmp;
        tmp.peso = rand()%60+40;
        tmp.altezza = rand()%50+140;
        vettore.push_back(tmp);
        tmp.altezza = rand()%50+140;
        vettore.push_back(tmp);
    }
    cout << "Prima dell'ordinamento" << endl;
    for (int i=0; i<10; i++)
        cout << vettore.at(i).peso << " " << vettore.at(i).altezza << endl;
    sort(vettore.begin(),vettore.end(),cmp);
    cout << "Dopo l'ordinamento" << endl;
    for (int i=0; i<10; i++)
        cout << vettore.at(i).peso << " " << vettore.at(i).altezza << endl;
    return 0;
}
