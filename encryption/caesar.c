#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int upperNum = 65;
const int lowerNum = 97;
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key_string = argv[1];
    for (int i = 0; key_string[i] != '\0'; i++)
    {
        if (!isdigit(key_string[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(key_string);
    string plaintext = get_string("plaintext: ");
    int plaintextc = strlen(plaintext);
    char ciphertext[plaintextc];
    for (int i = 0, n = plaintextc; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {

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
}