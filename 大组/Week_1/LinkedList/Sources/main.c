#include <stdio.h>

#include "RequiredList.h"
#include "OptionalList.h"
#include "struct.h"
#include "Menu.h"
#include "global.h"

int main (void) {

	DisplayMenu();
	scanf("%d",&choice);
	while(1) Choose();

    return 0;
}