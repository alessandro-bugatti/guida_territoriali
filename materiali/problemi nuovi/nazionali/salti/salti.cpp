//Salti nazionali 2010

#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	unsigned int D;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> D;
	int mask = 1, salti = 0;
	//Uso gli operatori bitwise
	for (int i = 0; i<31; i++)
	{
		if (D & mask)
			salti++;
		//cout << salti << " " << mask << endl;
		mask = mask << 1;
	}
	out << salti << endl;
	return 0;
 } 
