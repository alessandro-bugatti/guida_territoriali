/*
 *      Problema mappa - selezioni territoriali 2008
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

using namespace std;

int mappa[100][100];
int N;


void attraversa(int i, int j)
{	
	for (int r=-1; r<2; r++)
	  for (int s=-1; s<2; s++)
	  {
        if (i+r<0 || i+r>N-1 || j+s < 0 || j+s > N-1);
		else if (mappa[i+r][j+s] == 0 || mappa[i+r][j+s] > mappa[i][j] + 1 ) 
		{ 
			mappa[i+r][j+s] = mappa[i][j] + 1;
			attraversa(i+r,j+s);
		}
	  }
}
	
int main()
{
	fstream in,out;
	in.open("input.txt",ios::in);
	out.open("output.txt",ios::out);
	in >> N;
	for (int i=0;i < N;i++)
	   for (int j=0;j <N ;j++)
	   {   
		  char c; 
		  in >> c;
		   if (c=='*') mappa[i][j]=0;
			else mappa[i][j]=-1;
		}
	mappa[0][0] = 1;
	attraversa(0,0);
	out << mappa[N-1][N-1];
    return 0;
}
	
	
