#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Typedef.h"
#include "StackOperation.h"
#include "Define.h"

char * InputFormula (LinkStack *L) {
    char *str = (char*)malloc(sizeof(char) * MAXCHAR);
    InitStack(L);
    while ( getchar() != '\n');
    printf("请一次性输入中缀表达式：（只限数字、运算符号+-*/以及括号()）\n");
    fgets(str,sizeof(char) * MAXCHAR,stdin);

    return str;
}

char * Transform (int *count) {

    LinkStack *L = (LinkStack *) malloc(sizeof(LinkStack));
    char *str,*ret = (char*)malloc(sizeof(char) * MAXCHAR);
    int dot = 0;
    *count = 0;
    memset(ret,'\0',sizeof(ret));

    str = InputFormula(L);

    for (int i = 0; i < strlen(str) - 1; i++)
    {

        if ( ! ( str[i] >= '(' && str[i] <= '9'  &&  str[i] != ',' ) ) {
            printf("输入中有非法字符！\n");
            return;
        }

        if ( (str[i] >= '0' && str[i] <= '9') || str[i] == '.' ) {
            if ( str[i] == '.' ) {
                if ( dot == 0 ) dot = 1;
                else {printf("输入中有非法字符！\n");return;}
            }
            ret[(*count)++] = str[i];
        }
        else {

            ret[(*count)++] = ' ';
            dot = 0;
            if ( str[i] == '(' ) {
                PushStack(L,&str[i]);
            }

            else if ( str[i] == ')' || str[i] == '+' || str[i] == '-'  ) {

                while ( !EmptyStack(L) && *(char *) TopStack(L) != '(') {
                    memcpy(&ret[(*count)++], TopStack(L), 1);
                    PopStack(L);
                }

                if ( str[i] == ')' ) PopStack(L);
                else PushStack(L,&str[i]);

            }

            else if ( str[i] == '*' || str[i] == '/' ) {

                while ( !EmptyStack(L) &&  (*(char *) TopStack(L) == '*' || *(char *) TopStack(L) == '/' ) ) {
                    memcpy(&ret[(*count)++], TopStack(L), 1);
                    PopStack(L);
                }
                PushStack(L,&str[i]);

            }

        }
    }

    while ( !EmptyStack(L) ) {
        ret[(*count)++] = ' ';
        memcpy(&ret[(*count)++],TopStack(L),1 );
        PopStack(L);
    }

    ret[*count] = '\0';
    printf("后缀表达式为：%s\n",ret);
    free(str);
    free(L);
    return ret;
}

double Calculate (void) {
    LinkStack *L = (LinkStack *) malloc(sizeof(LinkStack));
    int count = 0;
    char *ret = Transform(&count);
    if ( ret == NULL ) return;
    double EndRet;
    InitStack(L);

    for (int i = 0; i < count ; i++)
    {

        while (ret[i] == ' ') i++;

        if ( ret[i] >= '.' && ret[i] <= '9' && ret[i] != '/' ) {

            double sum = 0;
            int begin = i,dot = 0,next;

            for ( next = i ; ret[next] != ' ' ; next++)
            {
                if ( ret[next] == '.' ) {
                    if ( next == 0 ) {printf("后缀表达式出错！\n");return;}
                    else dot = next;
                }
            }
            if ( dot != 0 ) dot = next - dot;

            for (; next - begin >= 1 ; begin++ )
            {
                if ( ret[begin] != '.' ) {
                    double num = ret[begin] - '0';
                    sum += num * pow(10, next - begin - 1 - dot);
                } else dot--;
            }
            i = next;
            PushStack(L,&sum);
        }
        else {

            if ( EmptyStack(L) ) {printf("后缀表达式出错！\n");return;}

            else {
                double num1,num2,num;

                num1 = *(double *) TopStack(L);
                PopStack(L);
                if ( EmptyStack(L) ) {printf("后缀表达式出错！\n");return;}

                num2 = *(double *) TopStack(L);
                PopStack(L);

                if ( ret[i] == '+' ) num = num2 + num1;
                else if ( ret[i] == '-' ) num = num2 - num1;
                else if ( ret[i] == '*' ) num = num2 * num1;
                else if ( ret[i] == '/' ) {
                    if ( num1 == 0 ) {printf("后缀表达式出错！\n");return;}
                    else num = num2 / num1;
                }

                PushStack(L,&num);
            }
        }

    }

    EndRet = *(double *)TopStack(L);
    free(L);
    free(ret);

    return EndRet;
}
