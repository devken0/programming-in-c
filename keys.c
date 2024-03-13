#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define PRIME 23
//#define BASE 5 

int mod_exp(int base, int exponent, int modulus) {
	int result = 1;
	while (exponent--)result=(result * base) % modulus;
	return result;
}

int main(){
	//int g = BASE, p = PRIME;
	int g, p;

	printf("Enter base number: ");
	scanf("%d", &g);
	printf("Enter prime number: ");
	scanf("%d", &p);

	int private_key_A = rand() %p, private_key_B = rand() % p;
	int public_key_A = mod_exp(g, private_key_A, p);
	int public_key_B = mod_exp(g, private_key_B, p);

	printf("Public key of Alice: %d\n", public_key_A);
	printf("Public key of Bob: %d\n", public_key_B);

	printf("Shared secret key for Alice: %d\n", mod_exp(public_key_B, private_key_A, p));
	printf("Shared secret key for Bob: %d\n", mod_exp(public_key_A, private_key_B, p));
	
	return 0;
}


