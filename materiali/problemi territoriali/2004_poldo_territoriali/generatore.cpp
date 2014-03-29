/*
  Name: Dieta Poldo
  Copyright: 
  Author: Alessandro Bugatti
  Date: 05/03/04 21.09
  Description: Generatore di input per Dieta Poldo
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
  fstream out;
  int n;
  srand(time(NULL));
  out.open("input.txt",ios::out);
  if (argc == 2)
  {
    sscanf(argv[1],"%d",&n);
    out << n << endl;
  }   
  for (int i=0; i < n ; i++)
  {
    out << rand()%400+1 << endl;
  }
  out.close();
  return 0;  
}
