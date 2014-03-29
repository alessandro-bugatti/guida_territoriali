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
 *  \brief Esempio di ordinamento di un vettore di interi in C++
 *  utilizzando la funzione di libreria sort
 *  \author Alessandro Bugatti
 *
 *  \version 0.2
 *  \date  Creazione  19/03/2009
 *  \date  Ultima modifica 19/03/2009
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int vettore[10];

int main()
{
    //inserisco dieci numeri casuali
    for (int i=0; i<10; i++)
        vettore[i]=rand()%100;
    cout << "Prima dell'ordinamento" << endl;
    for (int i=0; i<10; i++)
        cout << vettore[i] << endl;
    sort(vettore,vettore + 10);
    cout << "Dopo l'ordinamento" << endl;
    for (int i=0; i<10; i++)
        cout << vettore[i] << endl;
    return 0;
}
