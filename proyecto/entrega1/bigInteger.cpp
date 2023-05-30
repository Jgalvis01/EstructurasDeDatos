#include "bigInteger.h"

BigInteger::crearBigInteger(string num){

	for(int i=0 ; i < num.size() ; i++){
		listaBig.anxLista(num[i]);
	}
}

BigInteger::copiarBigInteger(BigInteger& num){
	listaBig = num.listaBig;
}

void BigInteger::add(BigInteger& num){
	int i,tam=listaBig.size,tam1=num.listaBig.size;

	if(tam >= tam1){
		tam = listaBig.size;
	}
	else{
		tam = num.listaBig.size;
	}
	
	for(i=tam ; i > 0 ; i--){
		if(){

		}
	}


}























