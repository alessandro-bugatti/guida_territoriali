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
 *  \brief Esempio di ordinamento di un vettore di interi in C
 *  utilizzando la funzione di libreria qsort
 *  \author Alessandro Bugatti
 *
 *  \version 0.2
 *  \date  Creazione  19/03/2009
 *  \date  Ultima modifica 19/03/2009
 *
 */

#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b)
{
    int primo = *(int *)a;
    int secondo = *(int *)b;
    if (primo > secondo) return 1;
    if (primo < secondo) return -1;
    return 0;
}

int vettore[10];

int main()
{
    //inserisco dieci numeri casuali
    for (int i=0; i<10; i++)
        vettore[i] = rand()%100;
    printf("Prima dell'ordinamento\n");
    for (int i=0; i<10; i++)
        printf("%d\n",vettore[i]);
    qsort(vettore,10,sizeof(int),cmp);
    printf("Dopo l'ordinamento\n");
    for (int i=0; i<10; i++)
        printf("%d\n",vettore[i]);
    return 0;
}
