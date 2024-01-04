// Import C libraries
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    // Get input words from both players
    char *word1;
    char *word2;

    word1 = (char *)malloc(100 * sizeof(char));
    word2 = (char *)malloc(100 * sizeof(char));

        if (word1 == NULL || word2 == NULL)
    {
        fprintf(stderr, "Memory allocation failed. Max characters up to 99\n");
        return 1;
    }

    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    free(word1);
    free(word2);
    
    return 0;
}

int compute_score(char *word)
{
    int sum = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            sum += POINTS[tolower(word[i]) - 'a'];
        }
    }

    return sum;
}
