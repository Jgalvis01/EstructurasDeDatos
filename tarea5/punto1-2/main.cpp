#include "lista.h"
#include <iostream>


/*

La complejidad de la operacion obtenerMenores es O(n) ya que
si o si nos toca recorrer toda la lista para saber cuantos menores
a v hay en la lista.

Y la complejidad de la operacion contarOcurrencias tambien seria O(n)
ya que nos toca recorrer por completo la lista para saber cuantos v
hay en la lista.

*/
Lista obtenerMenores(Lista l , int v){
	Lista ans;
	int i;
	int k=l.longLista();
	for(i=1 ; i <= k; i++){
		if(l.infoLista(i) < v){
			ans.anxLista(l.infoLista(i));
		}
	}

	return ans;
}

// Complejidad: O(n)
int contarOcurrencias(Lista l, int v){
	int ans=0;
	int i;
	int k = l.longLista();
	for(i=1 ; i<= k; i++){
		if(l.infoLista(i) == v){
			ans += 1;
		}
	}
	return ans;
}

int main(){
	Lista l;
	l.anxLista(8);
  	l.anxLista(10);
  	l.anxLista(12);
  	l.anxLista(15);
  	l.anxLista(3);
  	l.anxLista(5);

  	int ocurrencias = contarOcurrencias(l , 5);

  	cout << ocurrencias << endl;

  	int i;
  	Lista menores = obtenerMenores(l,9);
  	for(i = 1 ; i<= menores.longLista() ; i++){
  		cout << menores.infoLista(i) << endl;
  	}

	return 0;
}