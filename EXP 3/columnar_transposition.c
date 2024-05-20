#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_KEY_LENGTH 100
char key[MAX_KEY_LENGTH];
int keyMap[MAX_KEY_LENGTH];
void setPermutationOrder() {
 int i;
 for (i = 0; i < strlen(key); i++) {
 keyMap[key[i]] = i;
 }
}
char* encryptMessage(char* msg) {
 int row, col, i, j, k = 0;
 char cipher[MAX_KEY_LENGTH * MAX_KEY_LENGTH];
 col = strlen(key);
 row = strlen(msg) / col;
 if (strlen(msg) % col)
 row += 1;
COLUMNAR TRANSPOSITION
 char matrix[row][col];
 for (i = 0; i < row; i++) {
 for (j = 0; j < col; ) {
 if (msg[k] == '\0') {
 // Adding the padding character '_'
 matrix[i][j] = '_';
 j++;
 }
 if (isalpha(msg[k]) || msg[k] == ' ') {
 // Adding only space and alphabet into matrix
 matrix[i][j] = msg[k];
 j++;
 }
 k++;
 }
 }
 for (int i = 0; i < col; i++) {
 j = keyMap[key[i]];
 for (int k = 0; k < row; k++) {
 if (isalpha(matrix[k][j]) || matrix[k][j] == ' ' || matrix[k][j] == '_') {
 cipher[i * row + k] = matrix[k][j];
 }
 }
 }
 cipher[i * row] = '\0';
 return strdup(cipher);
}
char* decryptMessage(char* cipher) {
 int row, col, i, j, k;
 char decCipher[MAX_KEY_LENGTH * MAX_KEY_LENGTH];
 col = strlen(key);
 row = strlen(cipher) / col;
 char cipherMat[row][col];
 k = 0;
 for (j = 0; j < col; j++) {
 for (i = 0; i < row; i++) {
 cipherMat[i][j] = cipher[k++];
 }
 }
 int index = 0;
 for (i = 0; i < strlen(key); i++) {
 keyMap[key[i]] = index++;
 }
 k = 0;
 for (i = 0; i < strlen(key); i++) {
 j = keyMap[key[i]];
 for (int l = 0; l < row; l++) {
 decCipher[k++] = cipherMat[l][j];
 }
 }
 decCipher[k] = '\0';
 char msg[MAX_KEY_LENGTH * MAX_KEY_LENGTH];
 k = 0;
 for (i = 0; i < strlen(decCipher); i++) {
 if (decCipher[i] != '_') {
 msg[k++] = decCipher[i];
 }
 }
 msg[k] = '\0';
 return strdup(msg);
}
int main(void) {
 char msg[] = "Hello World";
 strcpy(key, "HACK");
 setPermutationOrder();
 char* cipher = encryptMessage(msg);
 printf("Encrypted Message: %s\n", cipher);
 char* decryptedMsg = decryptMessage(cipher);
 printf("Decrypted Message: %s\n", decryptedMsg);
 free(cipher);
 free(decryptedMsg);
 return 0;
}
