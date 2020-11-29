#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include "calc.h"
#define MAXOP   100
void mathfnc(char s[]);
main()
{
    int i,type,var = 0;
    double op1,op2,v;
    char s[MAXOP];
    double variable[26];
    for ( i = 0; i < 26; i ++)
        variable[i] = 0.0;
    while ((type = getop(s)) != EOF){
        switch ( type){
            case NUMBER:
                 push(atof(s));
                break;
            case NAME:
                mathfnc(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(),op2));
                else 
                    printf("error: zero divisor\n");
                break;
            case '?':   //print top element of the stack
                op2 = pop();
                printf("\t%.8g\n",op2);
                push(op2);
                break;
            case 'c':
                clear();
                break;
            case 'd':   //duplicate top elem. of the stack
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[var - 'A'] = pop();
                else 
                    printf("error: no variable name\n");
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n",v);
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variable[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("error: unknown command %s\n",s);
                break;
        }
        var = type;
    }
    return 0;
}
//mathfnc:check string a for supported math functions
void mathfnc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s,"pow") == 0){
        op2 = pop();
        push(pow(pop(),op2));
    }
    else
    {
        printf("error: %s not supported\n", s);
    }
}
