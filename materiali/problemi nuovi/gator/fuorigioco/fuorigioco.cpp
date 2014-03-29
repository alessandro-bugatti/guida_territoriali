//Fuorigioco GATOR 2014

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int d, A, D;
int xi, yi, xf, yf;
float YA = 100, YD = 100;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> d >> A >> D;
	for (int i = 0; i < A; i++)
	{
		in >> xi >> yi >> xf >> yf;
		float y = (float)(yf-yi)*d/10.0 + yi;
		if (y < YA) YA = y;
	}
	for (int i = 0; i < D; i++)
	{
		in >> xi >> yi >> xf >> yf;
		float y = (float)(yf-yi)*d/10.0 + yi;
		if (y < YD) YD = y;
	}
	if (YA < YD)
		out << "F" << endl;
	else
		out << "R" << endl;
	return 0;
}

