#include<stdio.h>

int main(){
  int a,b,c,d,grades;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  while ((a!=0) || (b!=0) || (c!=0) || (d!=0)){
    grades=1080;
    if (a == 0 && a < b){
      grades += ((40 - b))*9;
    }
    if(a < b && a!= 0){
      grades+= (40-b+a)*9;
    }
    if(a > b){
      grades+= (a-b)*9;
    }
    
    if(b<c){
      grades += (c-b)*9;

    }
    if(b>c){
      grades += (40-b+c) *9;
    }
    if(c>d){
      grades+=(c-d)*9;

    }
    if(c<d){
      grades+=(40-d+c)*9;
    }
    printf("%d\n",grades);
    scanf("%d %d %d %d",&a,&b,&c,&d);
  }

  return 0;
}