#include "Typedef.h"
#define TYPEDEF

Bool InitStack (LinkStack *L);
void PushStack (LinkStack *L,ElemType target);
Bool EmptyStack (LinkStack *L);
void PopStack (LinkStack *L);
ElemType TopStack (LinkStack *L);
int SizeStack (LinkStack *L);
void DestroyStack (LinkStack *L);
void PrintStack (LinkStack *L);
void ClearStack (LinkStack *L);

