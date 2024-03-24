#include <stdio.h>

#include "Menu.h"
#include "Typedef.h"

int main (void) {

    int choice;
    LinkStack *L = (LinkStack *) malloc(sizeof(LinkStack));

    DisplayMenu();
    do
    {
        Choose(choice,L);
        scanf("%d",&choice);
    } while (1);
    
    return 0;
}