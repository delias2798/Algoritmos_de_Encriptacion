//
// Created by elias on 03/10/18.
//
/*
 * Este código calcula la clave para dos personas
 * usando el algoritmo de encriptación Diffie-Hellman
 *
 * Step 1: Alice and Bob get public numbers P = 23, G = 9
 * Step 2: Alice selected a private key a = 4 and
 *      Bob selected a private key b = 3
 * Step 3: Alice and Bob compute public values
 *      Alice:    x =(9^4 mod 23) = (6561 mod 23) = 6
 *      Bob:    y = (9^3 mod 23) = (729 mod 23)  = 16
 * Step 4: Alice and Bob exchange public numbers
 * Step 5: Alice receives public key y =16 and
 *      Bob receives public key x = 6
 * Step 6: Alice and Bob compute symmetric keys
 *      Alice:  ka = y^a mod p = 65536 mod 23 = 9
 *      Bob:    kb = x^b mod p = 216 mod 23 = 9
 * Step 7: 9 is the shared secret.
 */
#include<stdio.h>
#include<math.h>

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b,
                    long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}

//Driver program
int main()
{
    long long int P, G, x, a, y, b, ka, kb;

    // Both the persons will be agreed upon the
    // public keys G and P
    P = 23; // A prime number P is taken
    printf("The value of P : %lld\n", P);

    G = 9; // A primitve root for P, G is taken
    printf("The value of G : %lld\n\n", G);

    // Alice will choose the private key a
    a = 4; // a is the chosen private key
    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, P); // gets the generated key

    // Bob will choose the private key b
    b = 3; // b is the chosen private key
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, P); // gets the generated key

    // Generating the secret key after the exchange
    // of keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);

    return 0;
}
