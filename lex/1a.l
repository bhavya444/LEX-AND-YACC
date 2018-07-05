%{
#include<stdio.h>
 int op=0,id=0,v=0;
%}


%%
[0-9]+ {id++;}
[\+\-\*\/]+ {op++;}
[(]+ {v++;}
[)]+ {v--;}
.|\n {return 0;}
%%

int main()
 {
printf("enter the expression\n");
yylex();
if(id==op+1 && v==0)
 {
  printf("valid expression");
  printf("number is %d \n operator is %d \n",id,op);
}
else 
printf("invalid");
return 0;
}
