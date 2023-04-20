/*

La complejidad de esta operacion concatenarListas es O(n^3)
ya que primero tendria que recorrer toda la lista 2, luego
la operacion anxLista tiene que recorrer toda la lista 1 y
por ultimo la operacion infoLista depende de i, y en el peor
de los casos i terminaria siendo igual a longLista y tendria que
recorre infoLista el mismo tamaño que la lista2

*/

#include "lista.h"
#include <iostream>

void concatenarListas(Lista l1, Lista l2){
  int i;
  for(i=1 ; i <= l2.longLista() ; i++){
    l1.anxLista(l2.infoLista(i));
  } 
}

int main(){
  Lista l1;
  l1.anxLista(5);
  l1.anxLista(10);
  l1.anxLista(12);
  l1.anxLista(15);

  Lista l2;
  l2.anxLista(5);
  l2.anxLista(10);
  l2.anxLista(12);
  l2.anxLista(15);  

  concatenarListas(l1,l2);

  int i;

  for(i = 1 ; i<= l1.longLista() ; i++){
      cout << l1.infoLista(i) << endl;
    }


  return 0;
}
