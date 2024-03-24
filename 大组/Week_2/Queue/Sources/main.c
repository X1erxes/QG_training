#include <stdio.h>
#include <stdlib.h>

#include "Typedef.h"
#include "Menu.h"
#include "Queue.h"

int main (void) {

    int choice;
    LQueue * Q = (LQueue *)malloc(sizeof(LQueue));

    DisplayMenu();
    do
    {
        scanf("%d",&choice);
        Choose(choice,Q);
    } while (1);
    return 0;
}