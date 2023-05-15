#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <list>
using namespace std;

/*
La complejidad de esta solucion seria O(n), siendo n la cantidad de caracteres de la palabra a recibir
generando al mismo tiempo la nueva cadena solicitada.
*/

int main(){

	string linea;
	list<char> texto;

	while (getline(cin , linea)){

		list<char>::iterator it = texto.end();
		for(int i=0 ; i < linea.size() ; i++){	

			if(linea[i] == '['){
				it=texto.begin();
			}
			else if(linea[i] == ']'){
				it=texto.end();
			}
			else{
				texto.insert(it, linea[i]);
			}

		}

		for(list<char>::iterator it = texto.begin() ; it != texto.end() ; it++){
			cout << *it ;
		}

		cout << endl;

		texto.clear();
	}

	return 0;
}