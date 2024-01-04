// Import C libraries
#include <stdio.h>
#include <stdbool.h>

// Call methods
int get_first(long n);
int get_second(long n);
bool is_valid_card(long cardNumber);

// Check if number length is valid
int valid_len(long n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count > 12;
}

int main(void)
{
    long n;
    printf("Number: ");
    scanf("%ld", &n);
    long first = get_first(n);

    // Check if first digit in input returns 4 from the first method, then is VISA card
    if (first == 4 && valid_len(n) && is_valid_card(n))
    {
        printf("VISA\n");
    }
    else
    {
        // Check rest of the digits
        long second = get_second(n);
        switch (second)
        {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            case 34:
            case 37:
                printf("AMEX\n");
                break;
            default:
                printf("INVALID\n");
        }
    }
}

int get_first(long n)
{
    while (n >= 10)
    {
        n = n / 10;
    }
    return n;
}

int get_second(long n)
{
    while (n >= 100)
    {
        n = n / 10;
    }
    return n;
}

bool is_valid_card(long cardNumber)
{

    int sum1 = 0, num = 0, remainder = 0, sum2 = 0;
    long temp = cardNumber;

    while (temp > 0)
    {
        num = ((temp / 10) % 10) * 2;
        while (num > 0)
        {
            remainder = num % 10;
            sum1 += remainder;
            num /= 10;
        }
        temp /= 100;
    }

    remainder = 0;
    temp = cardNumber;

    while (temp > 0)
    {
        remainder = temp % 10;
        sum2 += remainder;
        temp /= 100;
    }

    return ((sum1 + sum2) % 10) == 0 ? true : false;
}
