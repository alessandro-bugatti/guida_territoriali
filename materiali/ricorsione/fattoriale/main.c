/*
  Copyright (C) 2010 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

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
 *  \brief Funzione ricorsiva per il calcolo del fattoriale
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  22/02/2010
 *  \date  Ultima modifica 22/02/2010
 */

#include <stdio.h>

//ricorsivo
int fattoriale_r(int n)
{
    if (n == 0) return 1;
    return n * fattoriale_r(n-1);
}
//non ricorsivo
int fattoriale(int n)
{
	int f = 1, i;
	for (i = 1; i <= n; i++)
		f *= i;
	return f;
}

int main()
{
    int i;
    printf("Inserisci il valore di cui vuoi sapere il fattoriale: ");
    scanf("%d",&i);
    printf("Il fattoriale di %d è %d %d\n",i,fattoriale_r(i), fattoriale(i));
    return 0;
}

