#include "Typedef.h"
#define TYPEDEF

Bool InitLQueue (LQueue *Q);
void DestoryLQueue(LQueue *Q);
Bool IsEmptyLQueue(LQueue *Q);
ElemType GetHeadLQueue(LQueue *Q);
int LengthLQueue(LQueue *Q);
void EnLQueue(LQueue *Q, ElemType data);
void DeLQueue(LQueue *Q);
void ClearLQueue(LQueue *Q);
void LPrint(LQueue *Q);

