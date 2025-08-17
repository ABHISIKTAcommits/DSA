// Program to perform Palindrome number check in C [Day: 17]

#include <stdio.h>
#include <string.h>

int main() {
    int i, k = 0;
    char str1[100], str2[100];
    int check = 1;

    printf("Enter a string: ");
    scanf("%s", str1);

    int len = strlen(str1);

    for(i = 0; i < len; i++) {
        str2[i] = str1[len - i - 1]; 
    }
    str2[len] = '\0'; 

    for(i = 0; i < len; i++) {
        if(str1[i] != str2[i]) {
            check = 0;
            break;
        }
    }

    if(check == 1)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

