#include <stdio.h>

struct hundeStamtrae
{
    char tophund[20];
    struct hundeStamtrae *mor;
    struct hundeStamtrae *far;
};

typedef struct hundeStamtrae hundeStamtrae;

void printDawgs(hundeStamtrae, int);
int main(void)
{
    hundeStamtrae daisy = {"Daisy", NULL, NULL};
    hundeStamtrae rollo = {"Rollo", NULL, NULL};
    hundeStamtrae molly = {"Molly", &daisy, &rollo};
    hundeStamtrae king = {"King", NULL, NULL};
    hundeStamtrae stella = {"Stella", &molly, &king};

    printDawgs(stella, 0);

    return 0;
}

void printDawgs(hundeStamtrae topdawg, int indent)
{
    for (int i = 0; i < indent; i++)
    {
        printf("  ");
    }

    printf("%s\n", topdawg.tophund);
    if (topdawg.mor != NULL)
    {
        printDawgs(*topdawg.mor, indent + 1);
    }
    if (topdawg.far != NULL)
    {
        printDawgs(*topdawg.far, indent + 1);
    }
}