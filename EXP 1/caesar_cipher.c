#include <stdio.h>
#include <ctype.h>
char* encrypt(char* text, int s) {
 char* result = malloc(strlen(text) + 1);
 for (int i = 0; text[i] != '\0'; i++) {
 if (isupper(text[i]))
 result[i] = (char)(((int)text[i] + s - 65) % 26 + 65);
 else if (islower(text[i]))
 result[i] = (char)(((int)text[i] + s - 97) % 26 + 97);
 else
 result[i] = text[i];
 }
 result[strlen(text)] = '\0';
 return result;
}
int main() {
 char text[] = "abcdefghijklmnopqrstuvwxyz";
 int s = 3;
 printf("Text : %s\n", text);
 printf("Shift: %d\n", s);
CAESAR CIPHER
 printf("Cipher: %s\n", encrypt(text, s));
 return 0;
}
