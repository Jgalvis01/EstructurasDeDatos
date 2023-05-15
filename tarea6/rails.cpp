#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

/*
La complejidad de esta solucion seria O(n), siendo n la cantidad de trenes, en otros casos seria 2n donde
se tendria que recorrer tambien la pila para verificar.
*/

int main(){

	int num1;
	cin >> num1;
	stack<int> p;

	while(num1 != 0){
		bool flag = true;

		while (flag){
			vector<int> arr;
			int sec;
			for(int i=0; i < num1 && flag; i++){
				scanf("%d", &sec);
				if(sec == 0){
					flag = false;
				}
				else{
					arr.push_back(sec);
				}
			}

			int h=0;
			int k=1;
			bool flag1=true;
			while(flag1 && h < arr.size()){
				if(!p.empty() && p.top() == arr[h]){
						p.pop();
						h+=1;
				}
				else if(arr[h] == k){
					h+=1;
					k+=1;
				}
				else{
					p.push(k);
					k+=1;
				}
				if(k > num1 + 1){
					flag1 = false;
				}
			}
			if(sec != 0){
				if(h == num1){
				cout << "Yes" << endl;
				}
				else{
					cout << "No" << endl;
				}
			}
		}

		cout << endl;
		cin >> num1;

	}

	
	return 0;
}
