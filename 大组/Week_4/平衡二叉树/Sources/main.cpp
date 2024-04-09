#include <stdio.h>
#include <windows.h>

#include "Typedef.h"
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
