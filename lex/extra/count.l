%{
#include<stdio.h>
 int lines=0,words=0, c_letters=0,s_letters=0,num=0,spl_char=0,total=0;
%}

%%

[\n] { lines++; words++ ; }
[\t ' ' ] words++;
[a-z] c_letters++;

[A-Z] s_letters++;
[0-9] num++;
. spl_char++;

%%

main()
{
yyin= fopen("hello.txt","r");
yylex();
total=s_letters+c_letters+num+spl_char;
printf("\n  total : %d",total);
printf("\n  lines : %d",lines);
printf("\n special characters: %d", spl_char);
}
