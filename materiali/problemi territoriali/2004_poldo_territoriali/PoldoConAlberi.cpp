#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class nodo
{
    public:
    int peso; //peso nel nodo
    nodo* next; // puntatore a un nodo allo stesso livello
    nodo* sub;  // puntatore a un nodo di un livello sottostante
    nodo(int p):peso(p),next(NULL),sub(NULL){};
};

int panini[100];

void insert(nodo *p,int peso)
{
    static int i=0;
    if (peso >= p->peso) 
    {
        
        if (p->next==NULL)
        {
            //cout << i++ << " next creato " << peso << endl;
            p->next=new nodo(peso);
        }
        else 
        {
            //cout << i++ << " next al prossimo " << peso << endl;
            insert(p->next,peso);
        }
    }
    else if (p->sub == NULL)
        {
            //cout << i++ << " sub creato " << peso << endl;
            p->sub=new nodo(peso);
        }
        else 
            {
                //cout << i++ << " ramificazione " << peso << endl;
                insert(p->sub,peso);
                if (p->next!=NULL)
                    insert(p->next,peso);
            }
}

void stampa(nodo *p)
{
    if (p==NULL) 
    {
        cout << endl;
        return;
    }
    cout << p->peso <<" ";
    stampa (p->sub);
    stampa (p->next);
    //stampa (p->sub);
}

int height(nodo *p)
{
    if (p==NULL) return -1;
      int u=height(p->sub), v=height(p->next)-1;
      if (u > v) return u+1;
      else return v+1;
}

int main(int argc, char *argv[])
{
  fstream in,out;
  int numeroPanini;
  int conta=0,max=0;
  nodo* root=NULL;
  root = new nodo(-1);
  in.open("input.txt",ios::in);
  out.open("output.txt",ios::out);
  in >> numeroPanini;    
  for (int i=0;i<numeroPanini;i++) 
    {
        in >> panini[i];
    }
  for (int i=0;i<numeroPanini;i++) 
    {
        insert(root,panini[i]);
    }
  //stampa(root);
  out << height(root)+1;
  in.close();
  out.close();
}
