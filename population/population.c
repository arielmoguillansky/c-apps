#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Enter start size: ");
    }
    while (start_size < 9);

    int end_size;
    do
    {
        end_size = get_int("Enter end size: ");
    }
    while (end_size < start_size);

    int years = 0;

    while (start_size < end_size)
    {
        start_size += start_size/3 - start_size/4;
        years++;
    }

    printf("Start size: %i\n", start_size);
    printf("End size: %i\n", end_size);
    printf("Years: %i\n", years);

}
