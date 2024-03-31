#include <stdio.h>

#include "Menu.h"

int main (void) {
    int choice;

    DisplayMenu();
    do
    {
        scanf("%d",&choice);
        Choose(choice);
    } while (1);

    return 0;
}