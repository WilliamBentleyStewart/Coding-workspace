#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scorer(string word);

int main()
{
    // different points for each letter
    string player1Word = get_string("Player 1's word: ");
    string player2Word = get_string("Player 2's word: ");
    int player1Score = scorer(player1Word);
    int player2Score = scorer(player2Word);
    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1Score < player2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

int scorer(string word)
{
    int score = 0;
    const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
