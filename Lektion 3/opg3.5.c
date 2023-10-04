#include <stdio.h>

int main(void)
{

    int percent, grade;

    printf("How many percent? ");
    scanf("%d", &percent);

    if (percent >= 90)
        grade = 11;
    else if (percent >= 82)
        grade = 10;
    else if (percent >= 74)
        grade = 9;
    else if (percent >= 66)
        grade = 8;
    else if (percent >= 58)
        grade = 7;
    else if (percent >= 50)
        grade = 6;
    else if (percent >= 40)
        grade = 5;
    else if (percent >= 10)
        grade = 3;
    else
        grade = 0;

    printf("%d percent corresponds to the Danish grade %d\n\n",
           percent, grade);

    return 0;
}

/* Hvis vi gjorde det paa foelgende maade
 ville man faa 3 som karaktere hvis man havde
 over 10% i score. Altsaa raekkefoelgen betyder
 meget i denne case.

 Dog kunne vi loese det ved at aendre operatoren til
 at vaere <= i alle tilfaelde. Saa vil man kun faa 3 hvis
 man havde 10 % eller under


*/

// int main(void) {

//   int percent, grade;

//   printf("How many percent? ");
//   scanf("%d",&percent);

//   if (percent >= 10)
//     grade = 3;
//   else if (percent >= 40)
//     grade = 5;
//   else if (percent >= 50)
//     grade = 6;
//   else if (percent >= 58)
//     grade = 7;
//   else if (percent >= 66)
//     grade = 8;
//   else if (percent >= 74)
//     grade = 9;
//   else if (percent >= 82)
//     grade = 10;
//   else if (percent >= 90)
//     grade = 11;
//   else grade = 0;

//   printf("%d percent corresponds to the Danish grade %d\n\n",
//           percent, grade);

//   return 0;
// }