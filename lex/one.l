%{
	#include<stdio.h>
	int op=0,id=0,v=0;
%}
%%
[0-9]+ {id++;}
[\+\-\*\/] {op++;}
[(] {v++;}
[)] {v--;}
.|\n return '\n' ;
%%
int main()
{
	printf("Enter an expression\n");
	yylex();
	if(id==op+1 && v==0)
	{
		printf("Its a valid expression\n");
		printf("Operators= %d Identifiers= %d\n",op,id);
	}
	else
	printf("Invalid expression\n");
	return;
}

