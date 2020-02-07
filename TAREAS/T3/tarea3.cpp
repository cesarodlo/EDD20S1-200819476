
#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int n, string nom, nodo *sig = NULL)
    {
       carne = n;
       nombre= nom;
       siguiente = sig;
    }

   private:
    int carne;
    string nombre;
    nodo *siguiente;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void Insertar(int no, string nom);
    void Borrar(int no);
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    bool Actual() { return actual != NULL; }
    int ValorActual() { return actual->valor; }
    
   private:
    pnodo primero;
    pnodo actual;
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

void lista::Insertar(int num, string nom)
{
   pnodo anterior;
   if(ListaVacia() || primero->carne > num) {
      // Asignamos a lista un nievo nodo  con el numero de carne y su siguiente elemento es la lista actual                    
      primero = new nodo(num,nom, primero);
   }
   else {
      // Buscar el nodo de valor menor a carne
      anterior = primero;
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que carne
      while(anterior->siguiente && anterior->siguiente->carne <= num) 
         anterior = anterior->siguiente;
      // Crear un nuevo nodo después del nodo anterior, y cuyo siguiente es el siguiente del anterior
      anterior->siguiente = new nodo(num, nom, anterior->siguiente);
   }
}

void lista::Borrar(int num)
{
   pnodo anterior, nodo;
   
   nodo = primero;
   anterior = NULL;
   while(nodo && nodo->carne < num) {
      anterior = nodo; 
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->carne != num) return;
   else { // Borrar el nodo 
      if(!anterior) // Primer elemento 
         primero = nodo->siguiente;
      else  // un elemento que no es el buscado
         anterior->siguiente = nodo->siguiente;
      delete nodo;
   }   
}

void lista::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->carne << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void lista::Primero()
{
   actual = primero;
}

void lista::Ultimo()
{
   actual = primero;  
   if(!ListaVacia()) 
      while(actual->siguiente) Siguiente();
}

int main()
{
   lista Lista;
   
   Lista.Insertar(200819476, "cesar rod");
   Lista.Insertar(20189658,"probando");
   Lista.Insertar(400057849,"sigo probando");
  

   Lista.Mostrar();

   cout << "Lista de elementos:" << endl;
   Lista.Primero();
   while(Lista.Actual()) {
      cout << Lista.ValorActual() << endl;
      Lista.Siguiente();
   }
   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;
   
   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;
   
   Lista.Borrar(200819476);
   
   Lista.Mostrar();

   cin.get();
   return 0;
}
