// Import C libraries
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int n;
    char size[1];
    // Valid input should be a number between 1 and 8
    // Keep asking for input until valid value is inserted
    do
    {
        printf("Block size: ");
        fscanf (stdin, "%s", size);
        n = atoi(size);
    }
    while (n < 1 || n > 8);

    // Loop through columns
    for (int i = 1; i <= n; i++)
    {
        // Loop through spaces to build pyramid
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}