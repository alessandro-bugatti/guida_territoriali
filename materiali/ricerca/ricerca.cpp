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
 *  \brief Esempio di ricerca in un vettore di interi
 *  utilizzando la funzione di libreria binary_search
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  05/09/2011
 *  \date  Ultima modifica 05/09/2011
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> vettore;

int main()
{
    int n;
    //inserisco dieci numeri casuali
    for (int i=0; i<10; i++)
        vettore.push_back(rand()%100);
    //ordino il vettore
    sort(vettore.begin(),vettore.end());
    //mostro a video gli elementi per facilitare le prove
    for (int i=0; i<10; i++)
        cout << vettore.at(i) << endl;
    cout << "Inserisci il numero da cercare (-1 per terminare): " << endl;
    cin >> n;
    while (n!= -1)
    {
        if (binary_search(vettore.begin(), vettore.end(),n))
            cout << "Trovato " << n << endl;
        else
            cout << "Non trovato" << endl;
        cout << "Inserisci il numero da cercare (-1 per terminare): " << endl;
        cin >> n;
    }
    return 0;
}
