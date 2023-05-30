#include "bigInteger.h"


bool menorSinSigno(vector<int>& num , vector<int>& num1){
	bool ans;
	int cont=0;
	int i = num.size()-1;
	
	if(num[i] < num1[i]){
		ans = true;
	}
	else if(num[i] > num1[i]){
		ans = false;
	}
	else{
		ans = true;
		i -= 1;
		cont +=1;
		for(i ; i >= 0 && ans; i--){
			if(num[i] > num1[i]){
				ans = false;
			}
			else if(num[i] == num1[i]){
				cont +=1;
			}
		}

		if(cont == num1.size()){
			ans = false;
		}
	}

	return ans;
}

void elimCeros(vector<int>& vec){
	int i = vec.size()-1;
	while(vec[i] == 0 ){
		vec.pop_back();
		i--;
	}
}

BigInteger::BigInteger(const string& num){

	if(num[0] == '-'){
			signo = false;
	}
	else{
		signo = true;
	}

	int i = num.size()-1;
	while(i >= 0 ){
		if(num[i] != '-'){
			listaBig.push_back(num[i] - '0');
		}
		i--;
	}

}



BigInteger::BigInteger(const BigInteger& num){
	listaBig = num.listaBig;
	signo = num.signo;
}


void BigInteger::add(BigInteger& num){

	int i,tam=listaBig.size(),tam1=num.listaBig.size();
	BigInteger ans("");
	ans.listaBig = listaBig;
	ans.signo = signo;
	if(signo == num.signo){
		int acarreo = 0;
		int sum;
		if(tam > tam1){
			while(tam1 != tam){
				num.listaBig.push_back(0);
				tam1 = num.listaBig.size();
			}
		}
		else if(tam1 > tam){
			while(tam != tam1){
				listaBig.push_back(0);
				tam = listaBig.size();
			}
		}
		for(i=0 ; i < tam; i++){
			sum  = listaBig[i] + num.listaBig[i] + acarreo;
			if(sum >= 10){
				acarreo = 1;
			}
			else{
				acarreo = 0;
			}

			listaBig[i] = sum % 10;

			if(i == listaBig.size()-1 && sum >= 10){
				listaBig.push_back(sum / 10);
			}	
		}
		elimCeros(num.listaBig);
	}
	else if(signo != num.signo){
		if(listaBig.size() > num.listaBig.size()){
			int res;
			if(tam > tam1){
				while(tam1 != tam){
					num.listaBig.push_back(0);
					tam1 = num.listaBig.size();
				}
			}
			else if(tam1 > tam){
				while(tam != tam1){
					listaBig.push_back(0);
					tam = listaBig.size();
				}
			}

			for(i = 0; i < num.listaBig.size() ; i++){
				res = listaBig[i] - num.listaBig[i];
				if(res < 0){
					listaBig[i] = res + 10;
					listaBig[i+1] -= 1;
				}
				else{
					listaBig[i] = res;
				}
			}

			elimCeros(listaBig);
			elimCeros(num.listaBig);
			
		}
		else if(num.listaBig.size() > listaBig.size()){
			signo = num.signo;
			int res;
			if(tam > tam1){
				while(tam1 != tam){
					num.listaBig.push_back(0);
					tam1 = num.listaBig.size();
				}
			}
			else if(tam1 > tam){
				while(tam != tam1){
					listaBig.push_back(0);
					tam = listaBig.size();
				}
			}
			for(i = 0; i < num.listaBig.size() ; i++){
				res = num.listaBig[i] - listaBig[i];
				if(res < 0){
					listaBig[i] = res + 10;
					num.listaBig[i+1] -= 1;
				}
				else{
					if(!(i == num.listaBig.size()-1 && res==0)){
						listaBig[i] = res;
					}
				}
			}

			elimCeros(listaBig);
			elimCeros(num.listaBig);

		}
		else if(listaBig.size() == num.listaBig.size()){
			if(menorSinSigno(listaBig , num.listaBig)){
				signo = num.signo;
				int res;
				for(i = 0; i < num.listaBig.size() ; i++){		
					res = num.listaBig[i] - listaBig[i];
					if( res < 0){
						res += 10;
						num.listaBig[i+1] -= 1;
					}

					listaBig[i]= res;

				}

				elimCeros(listaBig);
				elimCeros(num.listaBig);
			}
			else{
				int res;
				for(i = 0; i < num.listaBig.size() ; i++){		
					res = listaBig[i] - num.listaBig[i];
					if( res < 0){
						res += 10;
						listaBig[i+1] -= 1;
					}
					listaBig[i]= res;

				}
				elimCeros(listaBig);
				elimCeros(num.listaBig);

				if(listaBig.size() == 0){
					listaBig.push_back(0);
					signo = true;
				}
			}
		}
	}
}

void BigInteger::substract(BigInteger& num){

	int i,tam=listaBig.size(),tam1=num.listaBig.size();

	if(signo != num.signo){
		int acarreo = 0;
		int sum;
		if(tam > tam1){
			while(tam1 != tam){
				num.listaBig.push_back(0);
				tam1 = num.listaBig.size();
			}
		}
		else if(tam1 > tam){
			while(tam != tam1){
				listaBig.push_back(0);
				tam = listaBig.size();
			}
		}
		for(i=0 ; i < tam; i++){
			sum  = listaBig[i] + num.listaBig[i] + acarreo;
			if(sum >= 10){
				acarreo = 1;
			}
			else{
				acarreo = 0;
			}

			listaBig[i] = sum % 10;
			if(i == listaBig.size()-1 && sum >= 10){
				listaBig.push_back(sum / 10);
			}	
		}

		elimCeros(listaBig);
		elimCeros(num.listaBig);
	}
	else if(signo == num.signo){
		if(listaBig.size() > num.listaBig.size()){
			int res;
			if(tam > tam1){
				while(tam1 != tam){
					num.listaBig.push_back(0);
					tam1 = num.listaBig.size();
				}
			}
			else if(tam1 > tam){
				while(tam != tam1){
					listaBig.push_back(0);
					tam = listaBig.size();
				}
			}

			for(i = 0; i < num.listaBig.size() ; i++){
				res = listaBig[i] - num.listaBig[i];
				if(res < 0){
					listaBig[i] = res + 10;
					listaBig[i+1] -= 1;
				}
				else{
					listaBig[i] = res;
				}
			}

			elimCeros(listaBig);
			elimCeros(num.listaBig);
			
		}
		else if(num.listaBig.size() > listaBig.size()){
			if(!num.signo){
				signo = true;
			}
			int res;
			if(tam > tam1){
				while(tam1 != tam){
					num.listaBig.push_back(0);
					tam1 = num.listaBig.size();
				}
			}
			else if(tam1 > tam){
				while(tam != tam1){
					listaBig.push_back(0);
					tam = listaBig.size();
				}
			}
			for(i = 0; i < num.listaBig.size() ; i++){
				res = num.listaBig[i] - listaBig[i];
				if(res < 0){
					listaBig[i] = res + 10;
					num.listaBig[i+1] -= 1;
				}
				else{
					if(!(i == num.listaBig.size()-1 && res==0)){
						listaBig[i] = res;
					}
				}
			}

			elimCeros(listaBig);
			elimCeros(num.listaBig);

		}
		else if(listaBig.size() == num.listaBig.size()){
			if(menorSinSigno(listaBig , num.listaBig)){
				if(num.signo){
					signo = false;
				}
				else if(!num.signo){
					signo = true;
				}
				int res;
				for(i = 0; i < num.listaBig.size() ; i++){		
					res = num.listaBig[i] - listaBig[i];
					if( res < 0){
						res += 10;
						num.listaBig[i+1] -= 1;
					}

					listaBig[i]= res;

				}

				elimCeros(listaBig); 
			}
			else{
				int res;
				for(i = 0; i < num.listaBig.size() ; i++){		
					res = listaBig[i] - num.listaBig[i];
					if( res < 0){
						res += 10;
						listaBig[i+1] -= 1;
					}
					listaBig[i]= res;

				}
				elimCeros(listaBig);

				if(listaBig.size() == 0){
					listaBig.push_back(0);
					signo = true;
				}
			}
		}
	}

}


void BigInteger::product(BigInteger& num){

	BigInteger tmp("0");
	BigInteger tmp1("");
	if(!signo && !num.signo){
		signo = true;
	}
	else if(!signo && num.signo || signo && !num.signo){
		signo = false;
	}



	for(int i=0 ; i < listaBig.size() ; i++){
		int mul;
		int acarreo=0;
		BigInteger tmp1("");
		for(int k=0; k < i ; k++){
			tmp1.listaBig.push_back(0);
		}

		for(int j=0 ; j < num.listaBig.size() ; j++){
			mul = listaBig[i] * num.listaBig[j] + acarreo;
			acarreo = mul / 10;
			if(j == num.listaBig.size()-1 && acarreo != 0){
				tmp1.listaBig.push_back(mul % 10);
				tmp1.listaBig.push_back(acarreo);
			}
			else{
				tmp1.listaBig.push_back(mul % 10);
			}
		}

		tmp.add(tmp1);
	}

	listaBig = tmp.listaBig;

}


void BigInteger::quotient(BigInteger& num){

	int cont=0;
	BigInteger numerador(*this);
	BigInteger divisor(num);
	bool signoau = true;

	if(!signo && !num.signo){
		signoau = true;
	}
	else if(!signo && num.signo || signo && !num.signo){
		signoau = false;
	}

	if(!signo){
		numerador.signo= true;
	}
	if(!num.signo){
		divisor.signo = true;
	}
	BigInteger copy(divisor);
	BigInteger copy2(numerador);
	if(divisor == numerador){
		cont = 1;
	}
	else if(numerador  < divisor){
		cont =0;
	}
	else{
		while((divisor <= numerador ) ){
			int cont2 = 1;
			while(divisor < numerador){
				divisor.listaBig.insert(divisor.listaBig.begin(),0);
				cont2 *= 10;
			}

			if(numerador < divisor){
				divisor.listaBig.erase(divisor.listaBig.begin());
				cont2 /= 10;
			}

			while(divisor < numerador){
				numerador.substract(divisor);
				copy2.substract(divisor);
				cont += cont2;
			}

			while(!(divisor == copy)){
				divisor.listaBig.erase(divisor.listaBig.begin());
			}
		}

	}

	stringstream ss;
	ss << cont;
	string cadena = ss.str();
	BigInteger ans(cadena);
	listaBig = ans.listaBig;
	signo = signoau;
	
}

void BigInteger::remainder(BigInteger& num){
	int cont=0;
	BigInteger numerador(*this);
	BigInteger divisor(num);
	bool signoau = true;

	if(!signo && !num.signo){
		signoau = true;
	}
	else if(!signo && num.signo || signo && !num.signo){
		signoau = false;
	}

	if(!signo){
		numerador.signo= true;
	}
	if(!num.signo){
		divisor.signo = true;
	}
	BigInteger copy(divisor);
	BigInteger copy2(numerador);
	if(divisor == numerador){
		cont = 1;
	}
	else if(numerador  < divisor){
		cont =0;
	}
	else{
		while((divisor <= numerador ) ){
			int cont2 = 1;
			while(divisor < numerador){
				divisor.listaBig.insert(divisor.listaBig.begin(),0);
				cont2 *= 10;
			}

			if(numerador < divisor){
				divisor.listaBig.erase(divisor.listaBig.begin());
				cont2 /= 10;
			}

			while(divisor < numerador){
				numerador.substract(divisor);
				copy2.substract(divisor);
				cont += cont2;
			}

			while(!(divisor == copy)){
				divisor.listaBig.erase(divisor.listaBig.begin());
			}
		}

	}

	copy2.signo = signo;
	if((signo && !num.signo) || (!signo && num.signo)){
		copy2.add(num);
	}

	listaBig = copy2.listaBig;
	signo = copy2.signo;

}


void BigInteger::pow(const int& num) {

    BigInteger aux(*this);
    BigInteger aux2(*this);

    for(int i=1 ; i < num ; i++){
    	aux = aux * aux2;
    }

    listaBig = aux.listaBig;
    signo = aux.signo;

}

string BigInteger::toString(){
		
	string ans = "";
	vector<string> cad;
	if(!signo){
		ans.append("-");
	}

	int i = listaBig.size()-1;
	while(i >= 0){
		ans += to_string(listaBig[i]);
		i--;
	}

	return ans;
}

BigInteger BigInteger::operator+(BigInteger& num){
    BigInteger ans(*this);
    BigInteger ans1(num);
    ans.signo = signo;
    ans.add(ans1);
    return ans;
}

BigInteger BigInteger::operator-(BigInteger& num){
	BigInteger ans(*this);
    BigInteger ans1(num);
    ans.signo = signo;
    ans.substract(ans1);
    return ans;
}

BigInteger BigInteger::operator*(BigInteger& num){
	BigInteger ans(*this);
    BigInteger ans1(num);
    ans.signo = signo;
    ans.product(ans1);
    return ans;
}

BigInteger BigInteger::operator/(BigInteger& num){
	BigInteger ans(*this);
    BigInteger ans1(num);
    ans.signo = signo;
    ans.quotient(ans1);
    return ans;
}

BigInteger BigInteger::operator%(BigInteger& num){
	BigInteger ans(*this);
    BigInteger ans1(num);
    ans.signo = signo;
    ans.remainder(ans1);
    return ans;
}

bool BigInteger::operator==(const BigInteger& num){
	bool ans;
	if(signo != num.signo){
		ans = false;
	}
	else if(listaBig.size() != num.listaBig.size()){
		ans = false;
	}
	else{
		ans = true;
		for(int i = listaBig.size()-1; i >= 0 && ans; i--){
			if(listaBig[i] != num.listaBig[i]){
				ans = false;
			}
		}
	}
	return ans;
}

bool BigInteger::operator<(const BigInteger& num){
	
	bool ans=false;
	int cont=0;
	if(!signo && listaBig.size() > num.listaBig.size()){
		ans = true;
	}
	else if(signo && num.signo && listaBig.size() < num.listaBig.size()){
		ans = true;
	}
	else if(!signo && num.signo){
		ans = true;
	}
	else if(signo && !num.signo){
		ans = false;
	}
	else if(!signo && !num.signo && listaBig.size() > num.listaBig.size()){
		ans = true;
	}
	else if(signo && num.signo && listaBig.size() == num.listaBig.size()){
		ans = true;
		bool ans1 = true;
		int i=listaBig.size()-1;

		if(listaBig[i] < num.listaBig[i]){
			ans = true;
		}
		else if(num.listaBig[i] < listaBig[i]){
			ans = false;
		}
		else{
			for(i; i >= 0 && ans1; i--){
				if(listaBig[i] < num.listaBig[i]){
					ans = true;
					ans1 = false;
				}
				else if(listaBig[i] > num.listaBig[i]){
					ans = false;
					ans1 = false;
				}

				else if(listaBig[i] == num.listaBig[i]){
					cont++;
				}
			}
			if(cont == listaBig.size()){
				ans = false;
			}
		}
		
	}
	else if(!signo && !num.signo && listaBig.size() == num.listaBig.size()){
		ans = true;
		bool ans1 = true;
		int i=listaBig.size()-1;

		if(listaBig[i] > num.listaBig[i]){
			ans = true;
		}
		else if(num.listaBig[i] > listaBig[i]){
			ans = false;
		}
		else{
			for(i; i >= 0 && ans1; i--){
				if(listaBig[i] > num.listaBig[i]){
					ans = true;
					ans1 = false;
				}
				else if(listaBig[i] < num.listaBig[i]){
					ans = false;
					ans1 = false;
				}

				else if(listaBig[i] == num.listaBig[i]){
					cont++;
				}
			}
			if(cont == listaBig.size()){
				ans = false;
			}
		}
	}


	return ans;
}

bool BigInteger::operator<=(const BigInteger& num){
	bool ans;
	BigInteger a(*this);
	BigInteger b(num);
	if(a < b){
		ans = true;
	}
	else if(a == b){
		ans = true;
	}
	else{
		ans = false;
	}


	return ans;
}


BigInteger BigInteger::sumarListaValores(list<BigInteger>& l){

	BigInteger ans("0");
	for(list<BigInteger>::iterator it = l.begin() ;  it  != l.end() ; it++){
		BigInteger sum(*it);
		ans.add(sum);
	}

	return ans;

}

BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& l){

	BigInteger ans("0");
	for(list<BigInteger>::iterator it = l.begin() ;  it  != l.end() ; it++){
		BigInteger sum(*it);
		ans.product(sum);
	}

	return ans;
}
