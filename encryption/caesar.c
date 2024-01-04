#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int upperNum = 65;
const int lowerNum = 97;
int main(int argc, char *argv[])
{
    // if no argument provided, end program
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // store key argument in variable
    char *key_string = argv[1];

    // check if key is a number
    for (int i = 0; key_string[i] != '\0'; i++)
    {
        if (!isdigit(key_string[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert input to integer
    int key = atoi(key_string);

    // ask for text to be encrypted
    char *plaintext;

    // memory allocation
    plaintext = (char *)malloc(100 * sizeof(char));  // Assuming a maximum length of 99 characters

    if (plaintext == NULL)
    {
        fprintf(stderr, "Memory allocation failed. Max characters up to 99\n");
        return 1;
    }

    printf("plaintext: ");
    scanf("%s", plaintext);

    int plaintextc = strlen(plaintext);
    char ciphertext[plaintextc];

    for (int i = 0, n = plaintextc; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // convert each plaintext character to its encrypted char by adding the provided key
            int cipherChar = ((plaintext[i] - (isupper(plaintext[i]) ? 'A' : 'a')) + key) % 26;
            char final = cipherChar + (isupper(plaintext[i]) ? upperNum : lowerNum);
            ciphertext[i] = final;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("\n");
    printf("ciphertext: %s\n", ciphertext);
    
    // Free the allocated memory
    free(plaintext);
    return 0;
}