/*

La complejidad de insListaOrdenada seria de O(n) ya que 
en el peor de los casos, el elemnto a insertar seria el mayor de todos
por lo cual tendriamos que recorrer hasta encontrar null y agregarlo al final

*/

#include "lista.h"
#include <iostream>

int main(){
  Lista l;
  l.insListaOrdenada(5);
  l.insListaOrdenada(10);
  l.insListaOrdenada(8);
  l.insListaOrdenada(7);
  l.insListaOrdenada(7);  
  int i;

  for(i = 1 ; i<= l.longLista() ; i++){
      cout << l.infoLista(i) << endl;
    }

  return 0;
}
