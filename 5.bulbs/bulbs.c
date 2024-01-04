#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

char *convert_to_binary(int decimal);

int main(void)
{
    char msg[50];
    printf("Word [max 50 chars]: ");
    scanf("%s", msg);

    for (int j = 0, len = strlen(msg); j < len; j++)
    {
        int binarr[BITS_IN_BYTE];
        int reversearr[BITS_IN_BYTE];

        for (int i = 0; i < BITS_IN_BYTE; i++)
        {
            binarr[i] = (int) msg[j] % 2;
            msg[j] /= 2;
        }

        for (int i = 0, n = BITS_IN_BYTE - 1; i <= n; i++)
        {
            print_bulb(binarr[n - i]);
        }
        printf("\n");
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
