#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
void railFenceCipher(char plaintext[], char ciphertext[]) {
int len = strlen(plaintext);
char a[MAX_LEN] = "", b[MAX_LEN] = "", s[MAX_LEN] = "";
int index = 0;
for (int i = 0; i < len; i++) {
if (i % 2 == 0)
a[strlen(a)] = plaintext[i];
else
b[strlen(b)] = plaintext[i];
}
strcat(ciphertext, a);
strcat(ciphertext, b);
}
int main() {
char plaintext[MAX_LEN], ciphertext[MAX_LEN];
printf("Enter plaintext: ");
RAIL FENCE
fgets(plaintext, sizeof(plaintext), stdin);
plaintext[strcspn(plaintext, "\n")] = '\0';
railFenceCipher(plaintext, ciphertext);
printf("Ciphertext: %s\n", ciphertext);
return 0;
}
