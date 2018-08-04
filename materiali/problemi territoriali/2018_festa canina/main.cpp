#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for (int test = 1; test <= T; test++)
    {
        out << "Case #" << test << ": ";
        int n, bellezza = 0;
        in >> n;
        for (int i = 0; i < n; i++)
        {
            int valore;
            in >> valore;
            if (valore > 0)
                bellezza += valore;
        }
        out << bellezza << endl;
    }
    return 0;
}
