#include "lista.h"
 
Nodo::~Nodo(){
  cout << "Borrando nodo " << dato << endl;
  sig = NULL;
  ant = NULL;
  delete sig;
  delete ant;
}

Lista::Lista(){
  act = NULL;
  size = 0;
}

void Lista::anxLista(Elemento elem){
  Nodo *tmp, *primero;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = nuevo;
  nuevo->ant = nuevo;

  if(act == NULL){
    act = nuevo;
    size += 1;
  }
  else{
    tmp = act->ant;
    tmp->sig = nuevo;
    nuevo->ant = tmp;
    nuevo->sig = act;
    act->ant = nuevo;
    size += 1;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  nuevo->ant = NULL;

  if(pos >= 1 && pos <= size){
    if(pos == 1){
      tmp = act->ant;
      tmp->sig = nuevo;
      nuevo->ant = tmp;
      nuevo->sig = act;
      act->ant = nuevo;
      act = nuevo;
      size += 1;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
        tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      nuevo->ant = tmp;
      tmp->sig->ant = nuevo;
      tmp->sig = nuevo;
      size += 1;
    }
  }
}
 
void Lista::elimLista(int pos){
  Nodo *tmp, *borrar;
  if(pos >= 1 && pos <= size){
    if(pos == 1){
      if(act != act->sig){
        tmp = act->ant;
        borrar = tmp->sig;
        act = act->sig;
        act->ant = tmp;
        tmp->sig = act;
        size -= 1;
      }
      else{
        borrar = act;
        act = NULL;
        size -= 1;
      }
    }
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
          tmp = tmp->sig;
      borrar = tmp->sig;
      Nodo* sig = tmp->sig->sig;
      tmp->sig = sig;
      sig->ant = tmp;
      size -= 1;
    }

    delete borrar;
  }
}

Elemento Lista::infoLista(int pos){
   Nodo* tmp = act;
   
   for(int i = 1; i < pos; i++)
      tmp = tmp->sig;
      
   return tmp->dato;
}

bool Lista::vaciaLista(){
   return act == NULL;
}
