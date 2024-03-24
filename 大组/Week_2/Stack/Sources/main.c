#include <stdio.h>

#include "Menu.h"
#include "Typedef.h"

int main (void) {

    int choice;
    LinkStack *L = (LinkStack *) malloc(sizeof(LinkStack));

    DisplayMenu();
    do
    {
        scanf("%d",&choice);
        Choose(choice,L);
    } while (1);
    
    return 0;
}