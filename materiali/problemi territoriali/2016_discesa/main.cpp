//discesa - territoriali 2016
#include <fstream>
#include <iostream>

using namespace std;

int piramide[10][10];
int A;

int discesa(int i, int j)
{
	if (i == A)
		return 0;
	int sinistra = discesa(i+1,j);
	int destra = discesa(i+1,j+1);
	if (sinistra > destra)
		return sinistra + piramide[i][j];
	return destra + piramide[i][j];
}

int discesa_dinamica()
{
	for (int i = A - 2; i >= 0; i--)
		for (int j = 0 ; j< i+1; j++)
			piramide[i][j] += piramide[i+1][j] > piramide[i+1][j+1]?piramide[i+1][j]:piramide[i+1][j+1];
	return piramide[0][0];
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> A;
	for (int i = 0; i < A; i++)
		for (int j = 0; j < i+1; j++)
			in >> piramide[i][j];
	out << discesa_dinamica() << endl;//discesa(0,0) << endl;
	/*for (int i = 0; i < A; i++){
		for (int j = 0; j < i+1; j++)
			cout << piramide[i][j] << " ";
		cout << endl;
	}*/
	return 0;
}
