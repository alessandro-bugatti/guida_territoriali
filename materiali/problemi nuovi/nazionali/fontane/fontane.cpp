/*
  Name: fontane.cpp
  Copyright: GPL
  Author: Alessandro Bugatti
  Date: 01.04.2013 16:40:22
  Description: Soluzione con ricerca binaria
  nazionali 2012
*/

#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct fontana{
	int x, y;
};

struct tratto{
	bool orizzontale;
	int coordinata;
	int inizio, fine;
	tratto(){}
	tratto(bool dir, int c, int i, int f):orizzontale(dir),
	coordinata(c), inizio(i), fine(f){}
	bool compreso(int v)
	{
		if (inizio < fine)
		{
			if (v >= inizio && v <= fine)
				return true;
		}
		else
		{
			if (v <= inizio && v >= fine)
				return true;
		}
		return false;
	}
};

int N, M;

fontana fontane_x[100000], fontane_y[100000];
tratto tratti[100000];



bool cmp_x(const fontana& a, const fontana& b)
{
	//return a.x < b.x;
	if ( a.x < b.x) return true;
	if ( a.x > b.x) return false;
	return a.y < b.y;
}

bool cmp_y(const fontana& a, const fontana& b)
{
	//return a.y < b.y;
	if ( a.y < b.y) return true;
	if ( a.y > b.y) return false;
	return a.x < b.x;
}

bool search_x(const fontana& a, const fontana& b)
{
	return a.x < b.x;
}

bool search_y(const fontana& a, const fontana& b)
{
	return a.y < b.y;
}

int main()
{
	fstream in,out;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    in >> N >> M;
    int x,y, xprec, yprec;
    in >> xprec >> yprec;
	for (int i = 0; i < N; i++)
	{
		in >> x >> y;
		if (xprec == x)
			tratti[i] = tratto(false,x,yprec,y);
		else
			tratti[i] = tratto(true,y,xprec,x);
		xprec = x;
		yprec = y;
	}
	for (int i = 0; i < M; i++)
	{
		in >> x >> y;
		fontane_x[i].x = fontane_y[i].x = x;
		fontane_x[i].y = fontane_y[i].y = y;
	}
	sort(fontane_x, fontane_x + M, cmp_x);
	sort(fontane_y, fontane_y + M, cmp_y);
	for (int i = 0; i < M; i++)
	{
		//cout << fontane_x[i].x << " " << fontane_x[i].y << endl;
	}
	int max_tratta = 0, tratta = 0;
	for (int i = 0; i < N; i++)
	{
		if (tratti[i].orizzontale)
		{
			fontana cercata; 
			cercata.y = tratti[i].coordinata;
			fontana* low = lower_bound(fontane_y, fontane_y + M, 
				cercata, search_y);
			fontana* upper = upper_bound(fontane_y, fontane_y + M, 
				cercata, search_y);
			if (low == upper) //non c'è una fontana
			{
				tratta += abs(tratti[i].inizio - tratti[i].fine);
				//cout << i  << " - No fontana" << endl;
			}
			else
			{
				if (tratti[i].inizio < tratti[i].fine)
				{
					int prec = tratti[i].inizio;
					bool flag_fontana = false;
					for (fontana *p= low; p < upper; p++)
					{
						if (tratti[i].compreso(p->x))
						{
							flag_fontana = true;
							tratta += p->x - prec;
							if (tratta > max_tratta)
								max_tratta = tratta;
							//cout << p->x << " " << prec << " " << tratta << endl;
							//cout << tratta << endl;
							tratta = 0;
							prec = p->x;
						}
					}
					if (flag_fontana)
						tratta = tratti[i].fine - prec;
					else
						tratta+= tratti[i].fine - prec;
				}
				else
				{
					int prec = tratti[i].inizio;
					bool flag_fontana = false;
					for (fontana *p= upper - 1; p >= low ; p--)
					{
						if (tratti[i].compreso(p->x))
						{
							flag_fontana = true;
							tratta += prec - p->x;
							if (tratta > max_tratta)
								max_tratta = tratta;
							//cout << tratta << endl;
							tratta = 0;
							prec = p->x;
						}
					}
					if (flag_fontana)
						tratta = prec - tratti[i].fine;
					else
						tratta += prec - tratti[i].fine;
				}
			}
		}
		else
		{
			fontana cercata; 
			cercata.x = tratti[i].coordinata;
			fontana* low = lower_bound(fontane_x, fontane_x + M, 
				cercata, search_x);
			fontana* upper = upper_bound(fontane_x, fontane_x + M, 
				cercata, search_x);
			if (low == upper) //non c'è una fontana
			{
				tratta += abs(tratti[i].inizio - tratti[i].fine);
				//cout << i  << " - No fontana" << endl;
			}
			else
			{
				if (tratti[i].inizio < tratti[i].fine)
				{
					bool flag_fontana = false;
					int prec = tratti[i].inizio;
					for (fontana *p= low; p < upper; p++)
					{
						if (tratti[i].compreso(p->y))
						{	
							flag_fontana = true;
							tratta += p->y - prec;
							if (tratta > max_tratta)
								max_tratta = tratta;
							//cout << p->y << " " << prec << " " << tratta << endl;
							tratta = 0;
							prec = p->y;
						}
					}
					if (flag_fontana)
						tratta = tratti[i].fine - prec;
					else
						tratta += tratti[i].fine - prec;
				}
				else
				{
					bool flag_fontana = false;
					int prec = tratti[i].inizio;
					for (fontana *p= upper - 1; p >= low ; p--)
					{
						if (tratti[i].compreso(p->y))
						{
							flag_fontana = true;
							tratta += prec - p->y;
							if (tratta > max_tratta)
								max_tratta = tratta;
							//cout << p->y << " " << prec << " " << tratta << endl;
							tratta = 0;
							prec = p->y;
						}
					}
					if (flag_fontana)
						tratta = prec - tratti[i].fine;
					else
						tratta += prec - tratti[i].fine;
				}
			}
		}
		
	}
	if (tratta > max_tratta)
		max_tratta = tratta;
	if (max_tratta > 100)
		out << max_tratta - 100 << endl ;
	else
		out << "0" << endl;
	
	return 0;
}
