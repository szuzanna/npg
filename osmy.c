// Struktura zbior�w roz��cznych
// Data : 28.03.2014
// (C)2014 mgr Jerzy Wa�aszek
//----------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;                 // Liczba element�w

// Element listy dwukierunkowej

struct dlistEl
{
  dlistEl *next,*prev;
  int data;
};

// Tworzy jednoelementow� list�
//-----------------------------
void MakeSet(dlistEl *x)
{
  x->next = x->prev = NULL;
}

// Zwraca pierwszy element listy
//------------------------------
dlistEl * FindSet(dlistEl *x)
{
  dlistEl * p;

  for(p = x; p->prev; p = p->prev);

  return p;
}

// ��czy dwie listy w jedn�
//-------------------------
void UnionSets(dlistEl *x, dlistEl *y)
{
  dlistEl *rx,*ry,*p;

  rx = FindSet(x);
  ry = FindSet(y);
  if(rx != ry)
  {
    for(p = x; p->next; p = p->next);
    p->next  = ry;
    ry->prev = p;
  }
}

// **********************
// *** PROGRAM G��WNY ***
// **********************

int main()
{
  dlistEl Z[N],*p;
  int i,x,y,c;

  srand(time(NULL));              // Inicjujemy generator pseudolosowy

  for(i = 0; i < N; i++)
  {
    Z[i].data = i;               // Elementy numerujemy kolejno
    MakeSet(&Z[i]);              // i tworzymy z nich zbiory
  }

  for(i = 0; i < N; i++)
  {
    x = rand() % N;             // Losujemy dwa elementy
    y = rand() % N;
    UnionSets(&Z[x],&Z[y]);
  }

  // Wypisujemy wyniki

  c = 0;
  for(i = 0; i < N; i++)
  {
    x = FindSet(&Z[i])->data;
    if(x == i) c++;
    cout << i << " is in set " << x << endl;
  }
  cout << endl << "Numeber of sets = " << c << endl << endl;
  for(i = 0; i < N; i++)
  {
    p = FindSet(&Z[i]);
    if(p->data == i)
    {
      cout << "Set " << i << " : ";
      while(p)
      {
        cout << p->data << " ";
        p = p->next;
      }
      cout << endl;
    }
  }

  return 0;
} 
/

