#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b) {
 if (b == 0)
 return a;
 return gcd(b, a % b);
}
int power_mod(int x, unsigned int y, int p) {
 int res = 1;
 x = x % p;
 while (y > 0) {
 if (y & 1)
 res = (res * x) % p;
 y = y >> 1;
RSA ALGORITHM
 x = (x * x) % p;
 }
 return res;
}
int mod_inverse(int a, int m) {
 int m0 = m;
 int y = 0, x = 1;
 if (m == 1)
 return 0;
 while (a > 1) {
 int q = a / m;
 int t = m;
 m = a % m, a = t;
 t = y;
 y = x - q * y;
 x = t;
 }
 if (x < 0)
 x += m0;
 return x;
}
int main() {
 int p = 3;
 int q = 11;
 int n = p * q;
 int phi_n = (p - 1) * (q - 1);
 int e = 7;
 int d = mod_inverse(e, phi_n);
 printf("Public key: {%d, %d}\n", e, n);
 printf("Private key: {%d, %d}\n", d, n);
 int plaintext = 31;
 int ciphertext = power_mod(plaintext, e, n);
 printf("Encrypted message: %d\n", ciphertext);
 int decrypted_text = power_mod(ciphertext, d, n);
 printf("Decrypted message: %d\n", decrypted_text);
 return 0;
}
