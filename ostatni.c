// Badanie, czy graf zawiera cykl lub �cie�k� Eulera
// Data: 4.01.2014
// (C)2013 mgr Jerzy Wa�aszek
//--------------------------------------------------
/

#include <iostream>

using namespace std;

// Typy dla dynamicznej tablicy list s�siedztwa i stosu

struct slistEl
{
  slistEl * next;
  int v;
};

class stack
{
  private:
    slistEl * S;   // lista przechowuj�ca stos

  public:
    stack();       // konstruktor
    ~stack();      // destruktor
    bool empty(void);
    int  top(void);
    void push(int v);
    void pop(void);
};

//---------------------
// Metody obiektu stack
//---------------------

// Konstruktor
//------------
stack::stack()
{
  S = NULL;
}

// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
stack::~stack()
{
  while(S) pop();
}

// Sprawdza, czy stos jest pusty
//------------------------------
bool stack::empty(void)
{
  return !S;
}

// Zwraca szczyt stosu
//--------------------
int stack::top(void)
{
  return S->v;
}

// Zapisuje na stos
//-----------------
void stack::push(int v)
{
  slistEl * e = new slistEl;
  e->v    = v;
  e->next = S;
  S = e;
}

// Usuwa ze stosu
//---------------
void stack::pop(void)
{
  if(S)
  {
    slistEl * e = S;
    S = S->next;
    delete e;
  }
}

// Funkcja bada graf pod k�tem posiadania cyklu lub �cie�ki Eulera
// n    - liczba wierzcho�k�w w grafie
// graf - tablica list s�siedztwa
// Wynik:
// 0 - graf nie zawiera �cie�ki lub cyklu Eulera
// 1 - graf zawiera �cie�k� Eulera
// 2 - graf zawiera cykl Eulera
//-----------------------------------------------------------------
int isEulerian(int n, slistEl ** graf)
{
  int no,nc,i,v,u;
  stack S;
  bool * visited;
  slistEl *p;

  for(i = 0; i < n && !graf[i]; i++); // Szukamy pierwszego wierzcho�ka z s�siadami

  if(i == n) return 1;        // Graf nie ma kraw�dzi

  visited = new bool [n];     // Tworzymy dynamicznie tablic� odwiedzin
  for(v = 0; v < n; v++)      // Wype�niamy j� warto�ciami false
    visited[v] = false;

  no = 0;                     // Zerujemy licznik wierzcho�k�w o stopniu nieparzystym

  S.push(i);                  // Wierzcho�ek startowy na stos
  visited[i] = true;          // oznaczamy go jako odwiedzony

  // Uruchamiamy przej�cie DFS, aby wyznaczy� sp�jn� sk�adow� zawieraj�c�
  // wierzcho�ek startowy oraz policzy� stopnie wierzcho�k�w i wyznaczy�
  // liczb� wierzcho�k�w o stopniach nieparzystych

  while(!S.empty())
  {
    v = S.top();              // Pobieramy do v wierzcho�ek ze stosu
    S.pop();                  // Pobrany wierzcho�ek usuwamy ze stosu

    nc = 0;                   // Licznik s�siad�w na zero

    for(p = graf[v]; p; p = p->next) // Przegl�damy s�siad�w wierzcho�ka v
    {
      nc++;                   // Zwi�kszamy licznik s�siad�w
      u = p->v;
      if(!visited[u])         // Szukamy nieodwiedzonych s�siad�w
      {
        visited[u] = true;    // Zaznaczamy ich jako odwiedzonych
        S.push(u);            // i umieszczamy na stosie
      }
    }

    if(nc % 2 == 1) no++;     // Nieparzysta liczba s�siad�w?
  }

  for(v = i + 1; v < n; v++)  // Przegl�damy pozosta�e wierzcho�ki grafu
    if(!visited[v] && graf[v])
    {
      delete [] visited;      // Usuwamy tablic� odwiedzin
      return 0;               // graf nie jest sp�jny
    }

  delete [] visited;          // Usuwamy tablic� odwiedzin

  if(!no) return 2;           // Graf zawiera cykl Eulera

  if(no == 2) return 1;       // Graf zawiera �cie�k� Eulera

  return 0;                   // Graf nie posiada �cie�ki lub cyklu Eulera
}

// **********************
// *** PROGRAM G��WNY ***
// **********************

int main()
{
  int n,m,i,v1,v2;
  slistEl * p,* r,** A;

  cin >> n >> m;         // Czytamy liczb� wierzcho�k�w i kraw�dzi

  A = new slistEl * [n]; // Tworzymy tablic� list s�siedztwa

  // Tablic� wype�niamy pustymi listami

  for(i = 0; i < n; i++) A[i] = NULL;

  // Odczytujemy kolejne definicje kraw�dzi

  for(i = 0; i < m; i++)
  {
    cin >> v1 >> v2;    // Wierzcho�ek startowy i ko�cowy kraw�dzi
    p = new slistEl;    // Tworzymy nowy element
    p->v = v2;          // Numerujemy go jako v2
    p->next = A[v1];    // Dodajemy go na pocz�tek listy A[v1]
    A[v1] = p;
    p = new slistEl;    // Kraw�d� w drug� stron�, bo graf jest nieskierowany
    p->v = v1;
    p->next = A[v2];
    A[v2] = p;
  }

  cout << endl;

  switch(isEulerian(n,A))
  {
    case 0: cout << "NOT AN EULERIAN GRAPH\n";
            break;
    case 1: cout << "SEMI-EULERIAN GRAPH\n";
            break;
    case 2: cout << "EULERIAN GRAPH\n";
            break;
  }

  // Usuwamy tablic� list s�siedztwa

  for(i = 0; i < n; i++)
  {
    p = A[i];
    while(p)
    {
      r = p;
      p = p->next;
      delete r;
    }
  }

  delete [] A;

  return 0;
} 
<<<<<<< HEAD
/
=======
>>>>>>> galaz
