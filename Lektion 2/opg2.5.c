/*

Navn: Emil Lykke Grann
Email: egrann23@student.aau.dk
Studieretning: Software (SW)
Opgave: 2.5 uger, dage, timer, minutter og sekunder
Beskrivelse:
Konveterer sekunder til antallet af uger, dage, timer,
minutter og sekunder som det svarer til

*/

#include <stdio.h>

int main(void)
{
    int uger, dage, timer, minutter, sekunder;

    /*
    Vi skriver en besked i prompten og vi sætter variablen sekunder lig
    med input fra brugeren.
    */
    printf("Skriv antallet af sekunder der skal omregnes til uger, dage, timer, minutter og sekunder. Afslut med enter> ");
    scanf("%d", &sekunder);

    /*
    Vi beregner de forskellige ting og assigner dem
    til vores variabler
    */
    uger = sekunder / 60 / 60 / 24 / 7;
    dage = (sekunder / 60 / 60 / 24) % 7;
    timer = (sekunder / 60 / 60) % 24;
    minutter = (sekunder / 60) % 60;
    sekunder = sekunder % 60;

    /*
    Vi udskriver resultatet til brugeren i prompten
    */
    printf("\n%d uger, %d dage, %d timer, %d minutter og %d sekunder\n", uger, dage, timer, minutter, sekunder);
    return 0;
}