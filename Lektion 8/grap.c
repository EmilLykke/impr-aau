/* Draw and fill a polygon that is shaped like a house.
 * The color and fill pattern are selected randomly.
 */
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    /* (x , y) */
    int poly[12] = {
        100, 200, /* top-left corner */
        300, 100, /* roof peak */
        500, 200, /* top-right corner */
        500, 400, /* bottom-right corner */
        100, 400, /* bottom-left corner */
        100, 200, /* top-left corner */
    };
    char ch;
    int color; /* color of house */
    int fill;  /* fill pattern of house */
    char message[] =
        "Press a key to repaint house - press Q to quit";
    initwindow(640, 500, "House");
    outtextxy(100, 450, message);

    srand(time(NULL));
    ch = '*';
    while (!(ch == 'q' || ch == 'Q'))
    {
        color = rand() % 16;
        fill = rand() % 12;
        setfillstyle(fill, color);
        fillpoly(6, poly);
        ch = getch();
    }

    closegraph(); /* close the window */
}