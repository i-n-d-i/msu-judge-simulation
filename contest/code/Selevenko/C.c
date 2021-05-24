#include <stdio.h>
#include <stdlib.h>
 
int formula(){
    char sum;
    char ch;
	ch = getchar();
  if (ch == '\n'){
    return 0; 
  }
	if (ch == '('){
     	sum = formula();
      ch = getchar();
 	}
  	if (ch >= '0' && ch <= '9'){
      sum = (char)ch - (char)'0';
      ch = getchar();
      if(ch == ')'){
        return sum;
      }
      if(ch == '*'){
        sum *= formula();
        return sum;
      }
      if(ch == '+'){
        sum += formula();
        return sum;
      }
      if(ch == '-'){
        sum -= formula();
        return sum;
      }
 	}   
  	if (ch == '+'){
      sum += formula();
  	}   
  	if (ch == '-' ){
      sum -= formula();
  	}
  	if (ch == '*'){
  		sum *= formula();
  	}
  	if (ch == ')'){
      return sum;
  	}
  	return sum;
}
      
  int main(void){
      printf("%d", formula());
      return 0;
 }
