#include "struct.h"
#define STRUCT


SingleList * AcceptSingleData(void); //接收单向链表
CoupleList * AcceptCoupleData(void); //接收双向链表
void DeleteSingleNode (SingleList **head);
void DeleteCoupleNode (CoupleList **head);
void InsertSingleNode (SingleList **head);
void InsertCoupleNode (CoupleList **head);
void DestroySingleList (SingleList **head);
void DestroyCoupleList (CoupleList **head);
void SearchSingleNode (SingleList *head);
void SearchCoupleNode (CoupleList *head);
void PrintSingleList(SingleList *head);
void PrintCoupleList(CoupleList *head);


