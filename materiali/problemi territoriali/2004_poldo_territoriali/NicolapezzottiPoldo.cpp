#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAX 100
#define PESOMAX 100000

FILE*in,*out;
int panini[MAX];
int N;

int dieteggia(int, int*,int,int);

int main(){

    in = fopen("input.txt","r");
    out = fopen("output.txt","w");

    fscanf(in,"%d",&N);
    for(int i = 0; i < N; i++)  
        fscanf(in,"%d",&panini[i]);
    
    int appo = dieteggia(0,panini,0,PESOMAX);
    fprintf(out,"%d",appo);
    
}

int dieteggia(int p, int* liv_mangiata, int cont,int p_minimo){
    
    /*cout<<p<<" "<<*liv_mangiata<<" "<<cont<<" "<<p_minimo<<"\n";
    system("PAUSE");              */
    int panini2=0,panini1=0;
    
    if(cont >= N) return p;    
    if(*liv_mangiata < p_minimo)
        panini2 = dieteggia( p + 1, liv_mangiata + 1, cont + 1, *liv_mangiata);
    panini1 = dieteggia( p, liv_mangiata + 1, cont + 1, p_minimo);
    
   
//    cout<<panini1<<" "<<panini2<<"\n";
//    system("PAUSE");      
    if(panini1 >= panini2) return  panini1;
    else                   return  panini2;


    
}
