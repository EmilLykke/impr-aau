/*

Name: Emil Lykke Grann
Email: egrann23@student.aau.dk
Education: Software (SW)
Assignment: Eksamens opgave 3
Description:
Simulation of Super Liga matches

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Team struct
typedef struct
{
    char holdNavn[3];
    int point;
    int maal;
    int maalMod;
} hold;

// Match struct
typedef struct
{
    char ugedag[3];
    char dato[5];
    char klokkeslet[5];
    char hold1[5];
    char hold2[5];
    int antalTilskure;

} kamp;

// Prototypes for functions
int antalLinjerIFil(FILE *);
hold *lavHoldArr(FILE *);
int hentHoldIndex(char *, hold *);

void scanKampe(FILE *, kamp *, hold *, int);

int sortPoints(const void *, const void *);
void printHold(hold *);

int main(void)
{

    // Opens stream to match file in read mode
    FILE *stream = fopen("kampe-2023-2024.txt", "r");

    // Uses function to get number of lines
    int antalLinjer = antalLinjerIFil(stream);

    // Rewind the stream to the beginning of the file
    rewind(stream);

    // Make array of all possible teams
    hold *holdArr = lavHoldArr(stream);

    // Rewind stream again
    rewind(stream);

    // Allocate memory for matches array
    kamp *kampeArr = malloc(antalLinjer * sizeof(kamp));

    // Functions which reads the matches from stream
    scanKampe(stream, kampeArr, holdArr, antalLinjer);

    // Print the total scoreboard so far
    printHold(holdArr);

    // Close file
    fclose(stream);

    // Free up memory again
    free(holdArr);
    free(kampeArr);

    return 0;
}

// Function which counts number of lines in file
int antalLinjerIFil(FILE *stream)
{
    char line[1024];
    int i = 0;

    // While loop which adds 1 to i every runthrough.
    // Uses fgets to read 1 line at a time.
    while (fgets(line, sizeof(line), stream))
    {
        i++;
    }

    // Return i, which is the number of lines
    return i;
}

// Functions which scans all matches and assign the different parts of the line
// to the correct variable of the kamp struct
void scanKampe(FILE *stream, kamp *kampeArr, hold *holdArr, int arrSize)
{
    int i = 0;
    char line[1024];

    // Use fgets again to read one line at a time
    while (fgets(line, sizeof(line), stream))
    {

        // Variables to store goals and points for the two teams on every line
        int maalHold1 = 0, maalHold2 = 0;
        int pointHold1 = 0, pointHold2 = 0;

        // Use sscanf to scan different parst of the line into different variables
        sscanf(line, "%s %s %s %s - %s %d - %d %d", kampeArr[i].ugedag, kampeArr[i].dato, kampeArr[i].klokkeslet, kampeArr[i].hold1, kampeArr[i].hold2, &maalHold1, &maalHold2, &kampeArr[i].antalTilskure);

        // If else statement which decides how many points both teams get
        if (maalHold1 == maalHold2)
        {
            pointHold1 = 1;
            pointHold2 = 1;
        }
        else if (maalHold1 > maalHold2)
        {
            pointHold1 = 3;
            pointHold2 = 0;
        }
        else
        {
            pointHold1 = 0;
            pointHold2 = 3;
        }

        // Use function to get the index of the first team on the line, in the teams array
        int holdIndex1 = hentHoldIndex(kampeArr[i].hold1, holdArr);

        // Adds the goals, goals agains and the points to the first team
        holdArr[holdIndex1].maal += maalHold1;
        holdArr[holdIndex1].maalMod += maalHold2;
        holdArr[holdIndex1].point += pointHold1;

        // Use function to get the index of the second team on the line, in the teams array
        int holdIndex2 = hentHoldIndex(kampeArr[i].hold2, holdArr);

        // Adds the goals, goals agains and the points to the second team
        holdArr[holdIndex2].maal += maalHold2;
        holdArr[holdIndex2].maalMod += maalHold1;
        holdArr[holdIndex2].point += pointHold2;

        // Count up index of the kampeArr where every data for each match is stored
        i++;
    }
}

// Function which creates array of teams
hold *lavHoldArr(FILE *stream)
{

    char line[1024];

    // 12 teams is expected, which is why an array is initialized with 12 places for team names
    char holdNavne[12][4];
    int i = 0;
    int pos = 0;

    // fgets again
    while (fgets(line, 1024, stream))
    {
        char tempNavn[3];
        int navnMatch = 0;

        // Scanning the first team name on line, into the tempNavn string
        sscanf(line, "%*s %*[^A-Z] %[A-Z] - %*s", tempNavn);

        for (int i = 0; i < 12; i++)
        {
            // Checks if this name is already in the array
            if (strcmp(tempNavn, holdNavne[i]) == 0)
            {
                navnMatch = 1;
            }
        }

        // If the name is not already in the array we add it
        if (!navnMatch)
        {
            strcpy(holdNavne[pos], tempNavn);
            pos++;
        }

        // else we do nothing

        // Count up index of team name array
        i++;
    }

    // Allocate memory for 12 teams
    hold *holdArr = malloc(12 * sizeof(hold));

    // For loop which copy all names from the holdNavne array to the holdArr array

    for (int i = 0; i < 12; i++)
    {
        strcpy(holdArr[i].holdNavn, holdNavne[i]);

        // We also remember to start every team with goal, goal agains, and points at 0
        holdArr[i].maal = 0;
        holdArr[i].maalMod = 0;
        holdArr[i].point = 0;
    }

    // return team array
    return holdArr;
}

// Gets the index in the holdArr which matches a spicifed team name
int hentHoldIndex(char *holdNavn, hold *holdArr)
{
    int i;
    // For loop which break when the team name is found in the holdArr array
    for (i = 0; i < 12; i++)
    {
        if (strcmp(holdNavn, holdArr[i].holdNavn) == 0)
        {
            break;
        }
    }

    // return team index
    return i;
}

// Prints the final score of the teams
void printHold(hold *holdArr)
{
    // Sorts every team using qsort, by points
    // Uses sortPoints function
    qsort(holdArr, 12, sizeof(hold), sortPoints);

    // Prints the header line with spicific widths for each field
    printf("%3s %-10s %-10s %-10s %-10s\n", " ", "Hold navn", "Point", "Maal", "Maal imod");

    // For loop which prints all team scores, including points, goals, and goals against
    for (int i = 0; i < 12; i++)
    {
        // The same is done here by defining a fixed with for each field
        printf("%2d. %-10s %-10d %-10d %-10d\n", i + 1, holdArr[i].holdNavn, holdArr[i].point, holdArr[i].maal, holdArr[i].maalMod);
    }
}

// Sort based on points function
int sortPoints(const void *ip1, const void *ip2)
{
    hold *ipi1, *ipi2;
    ipi1 = (hold *)ip1;
    ipi2 = (hold *)ip2;

    // Compares the points of 2 teams
    // We want the first item to go before the second if it has greater points which is why we return less than 0
    if (ipi1->point > ipi2->point)
    {
        return -1;
    }
    // We want the first item to go after the second if it has less points which is why we return greater than 0
    else if (ipi2->point > ipi1->point)
    {
        return 1;
    }
    // If they have equal poitns we compare the goal differences
    else
    {
        // The goal difference is between goals scored and goals scored against
        if ((ipi1->maal - ipi1->maalMod) > (ipi2->maal - ipi2->maalMod))
        {
            return -1;
        }
        else if ((ipi2->maal - ipi2->maalMod) > (ipi1->maal - ipi1->maalMod))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}