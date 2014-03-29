/*
  Copyright (C) 2009 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

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

#include <fstream>

using namespace std;

int K,N;
ifstream in("input.txt");
ofstream out("output.txt");

void calcola(int j)
{
    if (j==10)
	{
		out << (j-2)/2 << " " << j-1 << endl;
		return;
	}
    out << (j-2)/2 << " " << j-1 << endl;
    out << j-3 << " " << (j-2)/2 << endl;
	calcola(j-2);
}

int main()
{
	in >> N;
	K = 2*N-3;
	out << K << " " << N << endl;
	calcola(2*N+2);
	out << 6 << " " << 4 << endl;
	out << 2 << " " << 6 << endl;
	out << 5 << " " << 2 << endl;
	out << 2*N+1 << " " << 5 << endl;
	return 0;
}
