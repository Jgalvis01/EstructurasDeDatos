#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

/*
La complejidad de esta solicion seria O(nLogn), siendo n la cantidad de operaciones a realizar, donde
se tendria que realizar busquedas en el diccionario 
*/

int main(){
	int p,c,ac=1;

	scanf("%d %d",&p,&c);

	while(p!=0 && c!=0){
		list<int> pacientes;
		list<int> estados;
		map<int,int> mp;
		printf("Case %d:\n",ac);
		if(p >= 1000){
			for(int i=1 ; i <= 1000 ; i++){
				pacientes.push_back(i);
				estados.push_back(0);
			}
			for(int i=1 ; i <= 1000 ; i++){
				mp[i]=0;
			}

		}
		else{
			for(int i=1 ; i <= p ; i++){
				pacientes.push_back(i);
				estados.push_back(0);
			}
			for(int i=1 ; i <= p ; i++){
				mp[i]=0;
			}


			string linea;
			for(int j=0 ; j < c ; j++){
				//for(list<int>::iterator it=pacientes.begin(); it != pacientes.end() ; it++){
				//cout << *it << " " << endl;
				//}
				getline(cin,linea);
				if(linea[0] == 'E'){
					int key = linea[2] - '0' , ac=1;
					pacientes.push_front(key);
					mp[key] += 1;
					estados.push_front(mp[key]);					
				}
				else if(linea[0] == 'N'){
					int primer = pacientes.front(), estad = estados.front();
					if(estad == mp[primer] ){
						cout << primer << endl;
						pacientes.pop_front();
						pacientes.push_back(primer);
						estados.pop_front();
						estados.push_back(estad);
					}
					else{
						pacientes.pop_front();
						estados.pop_front();
						primer = pacientes.front();
						estad = estados.front();
						cout << primer << endl;
					}

				}
			}


		}



		ac++;
		scanf("%d %d",&p,&c);
	}









	return 0;
}