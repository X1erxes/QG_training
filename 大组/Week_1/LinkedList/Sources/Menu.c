#include <stdio.h>
#include <windows.h>

#include "global.h"

void DisplayMenu(void) {
    system("cls");
    printf("          ********************************               ********************************\n");
    printf("          *         1.输入单链表         *               *         2.输入双链表         *\n");
    printf("          *         3.销毁单链表         *               *         4.销毁双链表         *\n");
    printf("          *         5.插入单链表         * 15.输出单链表 *         6.插入双链表         *\n");
    printf("          *         7.删除单链表         * 16.退出系统   *         8.删除双链表         *\n");
    printf("          *         9.查找单链表         * 17.输出双链表 *         10.查找双链表        *\n");
    printf("          *         11.奇偶反转          *               *         12.中间链表          *\n");
    printf("          *         13.判断是否成环      *               *         14.反转链表          *\n");
    printf("          ********************************               ********************************\n");
    printf("请输入对应数字(1-17)：");
    return;
}

void Choose(void) {

	if ( choice == 1 ) {head = AcceptSingleData();Reset();}
	else if ( choice == 2 ) {head = AcceptCoupleData();Reset();}
	else if ( choice == 3 ) {DestroySingleList(&head);Reset();}
	else if ( choice == 4 ) {DestroyCoupleList(&head);Reset();}
	else if ( choice == 5 ) {InsertSingleNode(&head);Reset();}
	else if ( choice == 6 ) {InsertCoupleNode(&head);Reset();}
	else if ( choice == 7 ) {DeleteSingleNode(&head);Reset();}
	else if ( choice == 8 ) {DeleteCoupleNode(&head);Reset();}
	else if ( choice == 9 ) {SearchSingleNode(head);Reset();}
	else if ( choice == 10) {SearchCoupleNode(head);Reset();}
	else if ( choice == 11) {SwapOddEven(&head);Reset();}
	else if ( choice == 12) {SearchMid(head);Reset();}
	else if ( choice == 13) {JudgeLoop(head);Reset();}
	else if ( choice == 14) {ReverseList(&head);Reset();}
    else if ( choice == 15) {PrintSingleList(head);Reset();}
    else if ( choice == 16) {exit(0);}
    else if ( choice == 17) {PrintCoupleList(head);Reset();}

    return;
}

void Reset(void) {
    printf("输入r继续...\n");
    char tmp;
    while (getchar() != '\n');
    scanf("%c",&tmp);
    if (tmp == 'r') {
        DisplayMenu();
        scanf("%d",&choice);
    }
    return;
}