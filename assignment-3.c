#include<stdio.h>

long int modularExponentiation(long int base,long int exponent,long int modulus){
    long int result=1;
    // so as to reduce the value in case of larger value of base
    long int newBase=base%modulus;
    for(int i=0;i<exponent;i++){
        result = (result*newBase) % modulus;
    }
    return result;
}

int main(){
    long int base=0,exponent=0,modulus=0;
    printf("Enter base: \n");
    scanf("%ld",&base);
    printf("Enter exponent whose value should be equal to or greater than zero.\n");
    scanf("%ld",&exponent);
    printf("Enter modulus whose value should be greater than 1.\n");
    scanf("%ld",&modulus);

    if(exponent<0 || modulus <1){
        printf("Not able to find the solution because of invalid input.Kindly correct it.\n");
    }
    long int result = modularExponentiation(base,exponent,modulus);
    printf("The result is %ld",result);
}