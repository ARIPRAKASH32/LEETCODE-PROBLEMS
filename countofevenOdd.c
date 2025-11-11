#include<stdio.h>

int main(){
	int v,evenc=0,oddc=0,digit;
	scanf("%d",&v);
	while(v>0){
	    digit=v%10;
	    v=v/10;
	   if(digit%2==0){
	      evenc++;
	   }
	   else{
	    oddc++;
	   }
	}
	   printf("Even count = %d \n",evenc);
	   printf("Odd count = %d ",oddc);
	   return 0;
}
