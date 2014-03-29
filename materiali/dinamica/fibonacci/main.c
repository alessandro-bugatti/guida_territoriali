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
 *  \brief Funzione ricorsiva per il calcolo del numero di Fibonacci
 *  Per la descrizione del problema vedi http://it.wikipedia.org/wiki/Successione_di_Fibonacci
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  17/02/2010
 *  \date  Ultima modifica 17/02/2010
 */

#include <stdio.h>

int Fibonacci[100];

int fibonacci_r(int n)
{
	if (Fibonacci[n]!=-1) return Fibonacci[n];
    Fibonacci[n-1] = fibonacci_r(n-1); 
    Fibonacci[n-2] = fibonacci_r(n-2);
    return Fibonacci[n-1] + Fibonacci[n-2];
}

int fibonacci(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
	int n_1=1,n_2=0,f=1,i;
	for (i = 2; i< n; i++)
	{
		f = n_1 + n_2;
		n_1 = f;
		n_2 = n_1;
	}
	return f;
}

int main()
{
    int a,f,i;
    for (i = 0; i<100;i++)
    	Fibonacci[i] = -1;
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    printf("Fibonacci: inserisci il termine da calcolare: ");
    scanf("%d",&a);
    f = fibonacci_r(a);
    printf("F%d vale %d\n",a,f);
    return 0;
}
