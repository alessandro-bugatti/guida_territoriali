/* Prima soluzione con utilizzo di una matrice*/
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int osso[1001][1001];
//
//void inizializza()
//{
//    for (int i = 0 ; i < 1001; i++)
//        for (int j = 0; j < 1001; j++)
//            osso[i][j] = 0;
//}
//
//void riempi_colonna(int c, int n)
//{
//    for (int i = 0; i < n; i++)
//        osso[i][c] = 1;
//}
//
//int intervalli(int r, int n)
//{
//    int i = 0;
//    int conta = 1;
//    while (osso[r][i] == 0) i++;
//    while (i < n)
//    {
//        while(i < n && osso[r][i] == 1) i++;
//        while(i < n && osso[r][i] == 0) i++;
//        if (i < n) conta++;
//    }
//    return conta;
//}
//
//int main()
//{
//    ifstream in("input.txt");
//    ofstream out("output.txt");
//    int T;
//    in >> T;
//    for (int test = 1; test <= T; test++)
//    {
//        int n, massimo = 0;
//        out << "Case #" << test << ": ";
//        inizializza();
//        in >> n;
//        for (int i = 0; i < n; i++)
//        {
//            int temp;
//            in >> temp;
//            if (temp > massimo)
//                massimo = temp;
//            riempi_colonna(i, temp);
//        }
//        int movimenti = 0;
//        for (int i = 0; i < massimo; i++)
//            movimenti += intervalli(i,n);
//        out << movimenti << endl;
//    }
//    return 0;
//}

/* Seconda soluzione con utilizzo di un vettore*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int osso[1001];

int intervalli(int livello, int n)
{
    int i = 0;
    int conta = 1;
    while (osso[i] <= livello) i++;
    while (i < n)
    {
        while(i < n && osso[i] > livello) i++;
        while(i < n && osso[i] <= livello) i++;
        if (i < n) conta++;
    }
    return conta;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for (int test = 1; test <= T; test++)
    {
        int n, massimo = 0;
        out << "Case #" << test << ": ";
        in >> n;
        for (int i = 0; i < n; i++)
        {
            in >> osso[i];
            if (osso[i] > massimo)
                massimo = osso[i];
        }
        int movimenti = 0;
        for (int i = 0; i < massimo; i++)
            movimenti += intervalli(i,n);
        out << movimenti << endl;
    }
    return 0;
}

