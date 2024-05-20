#include <stdio.h>
#include <string.h>
void railFenceCipher(char *plaintext, int key) {
 int length = strlen(plaintext);
 char rail[key][length];
 for (int i = 0; i < key; i++) {
 for (int j = 0; j < length; j++) {
 rail[i][j] = '\0';
 }
 }
 int row = 0, dir = 0;
 for (int i = 0; i < length; i++) {
 rail[row][i] = plaintext[i];
 if (row == 0)
 dir = 0;
 if (row == key - 1)
 dir = 1;
RAIL FENCE
 if (dir == 0)
 row++;
 else
 row--;
 }
 for (int i = 0; i < key; i++) {
 for (int j = 0; j < length; j++) {
 if (rail[i][j] != '\0')
 printf("%c", rail[i][j]);
 }
 }
 printf("\n");
}
int main() {
 char plaintext[100];
 int key;
 printf("Enter plaintext: ");
 fgets(plaintext, sizeof(plaintext), stdin);
 plaintext[strcspn(plaintext, "\n")] = '\0';
 printf("Enter key (number of rails): ");
 scanf("%d", &key);
 railFenceCipher(plaintext, key);
 return 0;
}
