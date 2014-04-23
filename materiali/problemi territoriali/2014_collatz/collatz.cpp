//collatz - territoriali 2014
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int lunghezza_collatz(int n)
{
	int lunghezza = 1;
	while (n != 1)
	{
		if (n % 2)
			n = n*3 + 1;
		else
			n = n/2;
		lunghezza++;
	}
	return lunghezza;
}

int lunghezza_collatz_ric(int n)
{
	if (n == 1)
		return 1;
	if (n % 2)
		return lunghezza_collatz_ric(3*n + 1) + 1;
	else
		return lunghezza_collatz_ric(n/2) + 1;
}

int main()
{
	int N;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N;
	/*int vettore[100000];
	int i = 2;
	for_each(vettore, vettore+100000,[&i](int &n){n = lunghezza_collatz(i++);});
	auto m = max_element(vettore,vettore+100000);
	cout << *m;
	for (auto i:vettore)
		cout << i << endl;*/
	out << lunghezza_collatz(N) << endl;
	return 0;
}
