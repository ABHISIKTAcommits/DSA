// Program 2: Count frequency of each character in a string [Day: 1] 
#include <stdio.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str); 
    int hash[256] = {0}; 
    for (int i = 0; str[i] != '\0'; i++) {
        hash[str[i]]++;
    }
    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (hash[i] > 0) {
            printf("'%c' appears %d times\n", i, hash[i]);
        }
    }
    return 0;
}