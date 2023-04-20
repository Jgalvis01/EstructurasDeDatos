/*

La complejidad de la operacion insertarEnListaOrdenada seria O(n)
ya que en el peor de los casos, el elemento a agregar seria el mayor
de todos y nos tocaria recorrer toda la lista hasta el final

*/

#include "lista.h"
#include <iostream>

void insertarEnListaOrdenada(Lista& l , int v){
  int i;
  bool flag=true;
  for(i=1 ; i <= l.longLista() && flag; i++){
    if(v <= l.infoLista(i)){
      l.insLista(v,i);
      flag = false;
    }

  }
  if(i-1 == l.longLista()){
    l.anxLista(v);
  }
}

int main(){
  Lista l;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);
  int i;

  for(i = 1 ; i<= l.longLista() ; i++){
      cout << l.infoLista(i) << endl;
    }

  insertarEnListaOrdenada(l,16); 

  for(i = 1 ; i<= l.longLista() ; i++){
      cout << l.infoLista(i) << endl;
    }

  return 0;
}
