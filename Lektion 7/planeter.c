#include <stdio.h>

typedef enum planet
{
    MERCURY = 1,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
    PLUTO,
    SUN
} planet;

void circumference(planet);
planet convert_to_planet(int);
void printNext(planet);

int main(void)
{
    int planetNumber;
    planet choosenPlanet;
    char planetNavn[100];
    printf("Choose a planet number: ");
    scanf("%d", &planetNumber);

    choosenPlanet = convert_to_planet(planetNumber);

    circumference(choosenPlanet);
    printNext(choosenPlanet);

    return 0;
}

void circumference(planet pla)
{
    switch (pla)
    {
    case MERCURY:
        printf("Circufrence of Mercury: 15.329 km\n");
        break;
    case VENUS:
        printf("Circufrence of Venus: 38.025 km\n");
        break;
    case EARTH:
        printf("Circufrence of Earth: 40.075 km\n");
        break;
    case MARS:
        printf("Circufrence of Mars: 21.344 km\n");
        break;
    case JUPITER:
        printf("Circufrence of Jupiter: 439.264 km\n");
        break;
    case SATURN:
        printf("Circufrence of Saturn: 378.675 km\n");
        break;
    case URANUS:
        printf("Circufrence of Uranus: 160.590 km\n");
        break;
    case NEPTUNE:
        printf("Circufrence of Neptune: 155.600 km\n");
        break;
    case PLUTO:
        printf("Circufrence of Pluto: 7.445 km\n");
        break;
    case SUN:
        printf("Circufrence of Sun: 4.370.006 km\n");
        break;
    default:
        break;
    }
}

planet convert_to_planet(int number)
{
    switch (number)
    {
    case 1:
        return MERCURY;
        break;
    case 2:
        return VENUS;
        break;
    case 3:
        return EARTH;
        break;
    case 4:
        return MARS;
        break;
    case 5:
        return JUPITER;
        break;
    case 6:
        return SATURN;
        break;
    case 7:
        return URANUS;
        break;
    case 8:
        return NEPTUNE;
        break;
    case 9:
        return PLUTO;
        break;
    case 10:
        return SUN;
        break;
    default:
        break;
    }
}

void printNext(planet pla)
{
    int next = pla + 1;
    circumference(convert_to_planet(next));
}
