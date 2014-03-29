/*
 *      Problema poldo - selezioni territoriali 2004
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

using namespace std;

int soluzioni[100];
int panini[100];

int main(int argc, char *argv[])
{
  fstream in,out;
  int numeroPanini,max;
  in.open("input.txt",ios::in);
  out.open("output.txt",ios::out);
  in >> numeroPanini;    
  for (int i=0;i<numeroPanini;i++) 
        in >> panini[i];
  for (int i=numeroPanini-1;i>=0;i--) 
  {
    max=0;
    for (int j=numeroPanini-1;j>i;j--)
    {
        if (panini[i] > panini[j] && soluzioni[j]>max)
            max=soluzioni[j];
    }
    soluzioni[i] = max + 1;
  }  
  max=soluzioni[0];
  for (int i=1; i< numeroPanini;i++)
    if (soluzioni[i] > max) 
		max = soluzioni[i];
  out << max;
}
