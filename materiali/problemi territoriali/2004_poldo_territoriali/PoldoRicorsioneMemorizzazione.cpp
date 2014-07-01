#include <stdio.h>
#include <stdlib.h>


#define MAX 100
#define PESOMAX 100000

FILE*in,*out;
int panini[MAX];
int mangiati[MAX];
int N;

int poldo(int pos, int ultimo)
{
	if(pos==N) return 0;
	int mangio=1, nonmangio=0;
	//printf("%d %d\n",pos, ultimo);
	if (mangiati[pos]!=-1) return mangiati[pos];
	//printf("Nuovo\n");
	if (panini[pos] < ultimo)
		mangio = 1 + poldo(pos + 1,panini[pos]);
	nonmangio = poldo (pos + 1, ultimo);
	if (pos == 9) printf("%d %d\n",mangio, nonmangio);
	if (mangio >= nonmangio)
	{
	    printf("Mangiato %d %d %d\n",pos,mangio,nonmangio);
		mangiati[pos] = mangio;
		return mangio;
	}
	else 
	{
	    printf("Non mangiato %d %d %d\n",pos,mangio,nonmangio);
		mangiati[pos] = nonmangio;
		return nonmangio;
	}
}

int poldoric(int posizione, int ultimo)
{
	if (posizione == N) return 0;
	int mangio=0, nonmangio=0;
	if (panini[posizione] < ultimo)
		mangio = 1 + poldoric(posizione + 1, panini[posizione]);
	nonmangio = poldoric(posizione + 1, ultimo);
	if (mangio > nonmangio)
		return mangio;
	else
		return nonmangio;
}

int main(){

    in = fopen("input.txt","r");
    out = fopen("output.txt","w");

    fscanf(in,"%d",&N);
    for(int i = 0; i < N; i++)  
    {
        fscanf(in,"%d",&panini[i]);
        //printf ("%d %d\n",i, panini[i]);
        //mangiati[i]=-1;
    }
    /*
    for(int i = 0; i < N; i++)  
    {
        printf ("%d %d\n",i, mangiati[i]);
     
    }
    
    for(int i = 0; i < N; i++)  
    {
        printf ("%d %d\n",i, mangiati[i]);
     
    }
    */
    int appo = poldoric(0,PESOMAX+1);
    fprintf(out,"%d",appo);
    
}


