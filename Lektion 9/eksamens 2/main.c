/*

Name: Emil Lykke Grann
Email: egrann23@student.aau.dk
Education: Software (SW)
Assignment: Eksamens opgave 2
Description:
A yatzy type program which has the capability to roll n dies.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enum for defining all the rounds in yatzy
typedef enum Rounds
{
    ones,
    twos,
    threes,
    fours,
    fives,
    sixes,
    bonus,
    onePair,
    twoPairs,
    threeSimilar,
    fourSimilar,
    littleStraight,
    bigStraight,
    house,
    chance,
    yatzy
} Rounds;

// Defining all the prototypes for the program to ensure other functions can access them
int roundPoints(int *, int, Rounds, int);
int *roll_multiple_dies(int);
void game(int);

int main(void)
{
    // Giving the random function a seed using the time functio
    srand(time(NULL));
    int n = 5;
    // while loop to keep the game running
    while (n >= 5)
    {
        printf("Yatzy with how many dies (a number less than 5 terminates): ");
        scanf("%d", &n);
        if (n < 5)
        {
            break;
        }
        // function which runs the game with n dies
        game(n);
    }

    return 0;
}

// Function for rolling n dies. Returns dice array
int *roll_multiple_dies(int n)
{
    int *diceArray = malloc(sizeof(int) * n);
    if (diceArray == NULL)
    {
        printf("Memory allocation to diceArray failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        diceArray[i] = rand() % 6 + 1;
        printf("%d ", diceArray[i]);
    }
    return diceArray;
}

void game(int n)
{
    // Delcaring varibales for storing dice array, round points, bonus, and total sum.
    int *diceCastArray;
    int points[16];
    int bonusSum = 0;
    int totalSum = 0;

    printf("\nPrinting dies:\n");
    // For loop which goes over every round in the game, each round in the Rounds enum
    for (Rounds round = ones; round <= yatzy; round++)
    {
        // Swtich for cheking the round
        switch (round)
        {
        case ones:
            printf("1s: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 1);
            break;

        case twos:
            printf("2s: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 2);
            break;

        case threes:
            printf("3s: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 3);
            break;

        case fours:
            printf("4s: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 4);
            break;

        case fives:
            printf("5s: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 5);
            break;

        case sixes:
            printf("6s: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 6);
            break;
        case bonus:
            for (int i = 0; i < round; i++)
            {
                bonusSum += points[i];
            }
            /*
            Checking if the person got a bonus by having a score of 63 or more so far
            3*1+3*2+3*3+3*4+3*5+3*6 = 63
            */
            if (bonusSum >= 63)
            {
                points[round] = 50;
            }
            else
            {
                points[round] = 0;
            }

            break;

        case onePair:
            printf("One pair: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case twoPairs:
            printf("Two pairs: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case threeSimilar:
            printf("Three similar: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case fourSimilar:
            printf("Four similar: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case littleStraight:
            printf("Little straight: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case bigStraight:
            printf("Big straight: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case house:
            printf("House: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        case chance:
            printf("Chance: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;
        case yatzy:
            printf("Yatzy: ");
            diceCastArray = roll_multiple_dies(n);
            points[round] = roundPoints(diceCastArray, n, round, 0);
            break;

        default:
            points[round] = 0;
            break;
        }
    }

    // Printing the scoreboard
    printf("\nScore board:\n");
    for (Rounds round = ones; round <= yatzy + 1; round++)
    {
        switch (round)
        {
        case ones:
            printf("1s: %d\n", points[round]);
            break;

        case twos:
            printf("2s: %d\n", points[round]);
            break;

        case threes:
            printf("3s: %d\n", points[round]);
            break;

        case fours:
            printf("4s: %d\n", points[round]);
            break;

        case fives:
            printf("5s: %d\n", points[round]);
            break;

        case sixes:
            printf("6s: %d\n", points[round]);
            break;

        case bonus:
            printf("Bonus: %d\n", points[round]);
            break;

        case onePair:
            printf("One pair: %d\n", points[round]);
            break;

        case twoPairs:
            printf("Two pairs: %d\n", points[round]);
            break;

        case threeSimilar:
            printf("Three similar: %d\n", points[round]);
            break;

        case fourSimilar:
            printf("Four similar: %d\n", points[round]);
            break;

        case littleStraight:
            printf("Little straight: %d\n", points[round]);
            break;

        case bigStraight:
            printf("Big straight: %d\n", points[round]);
            break;

        case house:
            printf("House: %d\n", points[round]);
            break;

        case chance:
            printf("Chance: %d\n", points[round]);
            break;

        case yatzy:
            printf("Yatzy: %d\n", points[round]);
            break;

        // Adding an extra case (round) to display the total score
        case yatzy + 1:
            for (int i = 0; i < 16; i++)
            {
                totalSum += points[i];
            }
            printf("Total: %d\n", totalSum);
            break;

        default:
            points[round] = 0;
            break;
        }
    }
}

// Function for calculating the points for the spicific round.
int roundPoints(int *diceArr, int n, Rounds round, int val)
{
    int points = 0;

    // Searies of if statements which does different calcualtions for the different rounds
    if (round == onePair)
    {
        for (int dice = 6; dice > 0; dice--)
        {
            if (points > 0)
            {
                break;
            }
            for (int i = 0; i < n; i++)
            {
                if (diceArr[i] == dice)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (i != j && diceArr[i] == diceArr[j])
                        {
                            points = diceArr[i] * 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    else if (round == twoPairs)
    {
        int pair1 = 0, pair2 = 0;
        int dice, i, j, k, l;
        for (dice = 6; dice > 0; dice--)
        {
            if (pair1 > 0)
            {
                break;
            }

            for (i = 0; i < n; i++)
            {
                if (diceArr[i] == dice)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (i != j && diceArr[i] == diceArr[j])
                        {
                            pair1 = diceArr[i] * 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        for (dice = 6; dice > 0; dice--)
        {
            if (pair2 > 0)
            {
                break;
            }
            for (k = 0; k < n; k++)
            {
                if (diceArr[k] == dice && diceArr[k] != diceArr[i])
                {
                    for (l = 0; l < n; l++)
                    {
                        if (k != l && diceArr[k] == diceArr[l])
                        {
                            pair2 = diceArr[k] * 2;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if (pair1 > 0 && pair2 > 0)
        {
            points = pair1 + pair2;
        }
    }
    else if (round == threeSimilar)
    {
        int dice, size = 0;
        for (dice = 6; dice > 0; dice--)
        {
            for (int i = 0; i < n; i++)
            {
                if (diceArr[i] == dice)
                {
                    if (size == 3)
                    {
                        break;
                    }
                    size++;
                }
            }
            if (size == 3)
            {
                points = dice * 3;
                break;
            }
            size = 0;
        }
    }
    else if (round == fourSimilar)
    {
        int dice, size = 0;
        for (dice = 6; dice > 0; dice--)
        {
            for (int i = 0; i < n; i++)
            {
                if (diceArr[i] == dice)
                {
                    if (size == 4)
                    {
                        break;
                    }
                    size++;
                }
            }
            if (size == 4)
            {
                points = dice * 4;
                break;
            }
            size = 0;
        }
    }
    else if (round == littleStraight)
    {
        int size = 0;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (diceArr[j] == i)
                {
                    size++;
                    break;
                }
            }
        }
        if (size == 5)
        {
            points = 15;
        }
    }
    else if (round == bigStraight)
    {
        int size = 0;
        for (int i = 2; i <= 6; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (diceArr[j] == i)
                {
                    size++;
                    break;
                }
            }
        }
        if (size == 5)
        {
            points = 20;
        }
    }
    else if (round == house)
    {
        int diceThree, diceTwo, size = 0;
        int threeH = 0, twoH = 0;
        // Triplet for house
        for (diceThree = 6; diceThree > 0; diceThree--)
        {
            for (int i = 0; i < n; i++)
            {
                if (diceArr[i] == diceThree)
                {
                    if (size == 3)
                    {
                        break;
                    }
                    size++;
                }
            }
            if (size == 3)
            {
                threeH = diceThree * 3;
                break;
            }
            size = 0;
        }

        // Pair for house
        for (int diceTwo = 6; diceTwo > 0; diceTwo--)
        {
            if (twoH > 0)
            {
                break;
            }
            if (diceTwo != diceThree)
            {
                for (int i = 0; i < n; i++)
                {
                    if (diceArr[i] == diceTwo)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (i != j && diceArr[i] == diceArr[j])
                            {
                                twoH = diceArr[i] * 2;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        if (threeH > 0 && twoH > 0)
        {
            points = threeH + twoH;
        }
    }
    else if (round == chance)
    {
        int size = 0, total = 0;
        for (int dice = 6; dice > 0; dice--)
        {
            for (int i = 0; i < n; i++)
            {
                if (size == 5)
                {
                    break;
                }
                else if (diceArr[i] == dice)
                {
                    total += dice;
                    size++;
                }
            }
            if (size == 5)
            {
                break;
            }
        }
        points = total;
    }
    else if (round == yatzy)
    {
        int size = 0;
        for (int dice = 6; dice > 0; dice--)
        {
            for (int i = 0; i < n; i++)
            {
                if (diceArr[i] == dice)
                {
                    if (size == 5)
                    {
                        break;
                    }

                    size++;
                }
            }
            if (size == 5)
            {
                points = 50;
                break;
            }
            size = 0;
        }
    }
    else
    {
        // This else is used to calculate the points for the top part of the yatzy game 1-6
        for (int i = 0; i < n; i++)
        {
            if (points >= val * 5)
            {
                break;
            }
            else if (diceArr[i] == val)
            {
                points += val;
            }
        }
    }
    printf("-- %d \n", points);
    return points;
}