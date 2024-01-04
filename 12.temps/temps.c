// Practice working with structs
// Practice applying sorting algorithms

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CITIES 10

typedef struct
{
    char city[100];
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);
void bubbleSort(void);

int main(void)
{
    strcpy(temps[0].city, "Austin");
    temps[0].temp = 97;

    strcpy(temps[1].city, "Boston");
    temps[1].temp = 82;

    strcpy(temps[2].city, "Chicago");
    temps[2].temp = 85;

    strcpy(temps[3].city, "Denver");
    temps[3].temp = 90;

    strcpy(temps[4].city, "Las Vegas");
    temps[4].temp = 105;

    strcpy(temps[5].city, "Los Angeles");
    temps[5].temp = 82;

    strcpy(temps[6].city, "Miami");
    temps[6].temp = 97;

    strcpy(temps[7].city, "New York");
    temps[7].temp = 85;

    strcpy(temps[8].city, "Phoenix");
    temps[8].temp = 107;

    strcpy(temps[9].city, "San Francisco");
    temps[9].temp = 66;

    bubbleSort();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }

    return 0;
}

void bubbleSort(void)
{
    int i, j;
    bool swapped;
    for (i = 0; i < NUM_CITIES - 1; i++)
    {
        swapped = false;
        for (j = 0; j < NUM_CITIES - i - 1; j++)
        {
            if (temps[j].temp > temps[j + 1].temp)
            {
                avg_temp tempo = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = tempo;
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

void sort_cities(void)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < NUM_CITIES - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < NUM_CITIES; j++)
            if (temps[j].temp < temps[min_idx].temp)
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            avg_temp tempo = temps[min_idx];
            temps[min_idx] = temps[i];
            temps[i] = tempo;
        }
    }
}
