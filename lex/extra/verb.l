%%
is |
am |
are |
was |
were { printf ("%s : is a verb\n", yytext); }
[a-z A-Z]* { printf("%s :is a sentence ",yytext); }
%%
