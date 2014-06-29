#include <stdio.h>

unsigned long long int fibonacci(unsigned int pos){
    if (pos == 0) return 0;
    else if (pos == 1) return 1;
    else {
        return (fibonacci(pos-1) + fibonacci(pos-2));
    }
}

int main(){
  printf("O fibo de 40 é %lld\n", fibonacci(40));
  return 0;
}