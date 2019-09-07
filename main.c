#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//A-(B/C+(D%E*F))/G*H
char A[155],*B,C[155];
int top=-1,i=0,k=0;
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void pop()
{ if(isempty())
    {printf("Your stack is empty\n");
    }
  else
  { if(*(B+top)!='(')
       {C[k]=*(B+top);
         k++;
       }
    printf("%c has been poped out\n",*(B+top));
    top--;
  }
}
void push(char b)
{   top++;
    *(B+top)=b;
    printf("%c has been pushed in\n",b);
}
void prefer(char a)
{
    switch(a)
    { case '-':if(!isempty()&&*(B+top)!='(')
               pop();
               push(a);
               break;
      case '+': if(*(B+top)!='-'||*(B+top)!='(')
                pop();
                push(a);
                break;
      case '%': if(*(B+top)!=='+'||*(B+top)!=='-'||*(B+top)!='(')
                pop();
                push(a);
                break;
      case '/': if(*(B+top)=='*'||*(B+top)=='^')
                pop();
                push(a);
                break;
      case '*': if(*(B+top)=='^')
                pop();
                push(a);
                break;
      case '^': push(a);
                break;
      case '(': push(a);
                break;
      case ')': while(*(B+top)!='(')
                {   pop();
                }
                pop();
                break;

    }

}
int main()
{   int j;
    printf("Enter the infix\n");
    gets(A);
    i=strlen(A);
    printf("%d\n",i);
    B=(char*)malloc(i*sizeof(char));
    for(j=0;j<i;j++)
    { if((int)A[j]>64&&(int)A[j]<92)
      { C[k]=A[j];
          k++;
      }
       else
      {
        prefer(A[j]);
      }
    }
    printf("Your Postfix is\n");
    puts(C);
    return 0;
}
