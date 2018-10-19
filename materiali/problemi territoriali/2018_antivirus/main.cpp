#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
        int trash;
        int l_virus;
        string F[4];
        vector<string> viruses;
        string soluzione;
        in >> trash >> trash >> trash >> trash;
        in >> l_virus;
        in >> F[0] >> F[1] >> F[2] >> F[3];
        for (int i = 0; i < F[0].size() - l_virus; i++)
            viruses.push_back(F[0].substr(i, l_virus));
        for (auto virus: viruses)
        {
            bool trovato = true;
            for (int j = 1; j < 4; j++)
                if (F[j].find(virus) == string::npos)
                    trovato = false;
            if (trovato)
                soluzione = virus;
        }
        for (auto i: F)
            out << i.find(soluzione) << " ";
        out <<  endl;
    }
    return 0;
}
