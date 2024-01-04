// Include C libraries
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    for (int i = 0; key[i] != '\0'; i++)
    {
        int hits = 0;
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for (int j = 0; key[j] != '\0'; j++)
        {
            if (key[i] == key[j])
            {
                hits++;
            }
        }
        if (hits > 1)
        {
            printf("Key must contain unique letters\n");
            return 1;
        }
    }

    if (strlen(key) != 26)
    {
            printf("33333\n");
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *plaintext;
    plaintext = (char *)malloc(100 * sizeof(char));

    if(plaintext == NULL)
    {
        fprintf(stderr, "Memory allocation failed. Max characters up to 99\n");
        return 1;
    }

    printf("plaintext: ");
    scanf("%s", plaintext);
    
    int plaintextc = strlen(plaintext);
    
    char ciphertext[plaintextc];
    
    for (int i = 0; i < plaintextc; i++)
    {
        if (isalpha(plaintext[i]))
        {
            ciphertext[i] = isupper(plaintext[i]) ? toupper(key[plaintext[i] - 'A']) : tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    
    ciphertext[plaintextc] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    
    return 0;
}