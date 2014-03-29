#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
//#define DEBUG
      int N;
struct Mat{
 int x, y;
}mat[100];;
bool cmpMatx( Mat mata, Mat matb ) {
     return mata.x < matb.x;
}
bool cmpMaty( Mat mata, Mat matb ) {
     return mata.y < matb.y;
}

void w() {

      for( int i = 0; i < N; i++ ) {
           cout << mat[i].x << ' ' << mat[i].y << endl;
      }
      cout << endl;
}
int main()
{
      ifstream fin( "input.txt" );
      ofstream fout( "output.txt" );
      fin >> N;
      for( int i = 0; i < N; i++ ) {
           fin >> mat[i].x >> mat[i].y;
      }
      sort( mat, mat+N, cmpMatx );
      int tmp = 0;
      for(int i = 0; i < N; i++ ) {
              if(mat[i].x - mat[i+1].x) {
                        sort(mat+tmp, mat+i, cmpMaty);
                        tmp = i;
              }
      }
      w();
      int n;
      tmp = 0;
      for( int i = 0; i < N; i++ ) {
      cout << tmp+ mat[i].x << ' ' << mat[i].y << endl;
           if( tmp + mat[i].x <= mat[i].y ) {
                  tmp+= mat[i].x;
                  n++;
           }
      }
      #ifdef DEBUG
      cout << "N: " << n;
      #else
      fout << n;
      #endif
      cin.get();
      return 0;
}
