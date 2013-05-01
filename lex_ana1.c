
 
//CODE
/* Program to make lexical analyzer that generates the tokens  
Created by: Akhil Mahajan, Anirudh Kishan, Jai pratap Singh Chauhan, Snehasis Saha*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 30
void main()
{
char str[MAX];
int state=0;
int i=0, j, startid=0, endid, startcon, endcon;
for(j=0; j<MAX; j++)
str[j]=NULL; //Initialise NULL
printf("*** Program on Lexical Analysis ***");
printf("\n\nEnter the string: ");
gets(str); //Accept input string
str[strlen(str)]=' ';
printf("\n\nAnalysis:");
while(str[i]!=NULL)
{
while(str[i]==' ') //To eliminate spaces
i++;

switch(state)
{case 0: if(str[i]=='i') state=1; //if 
else if(str[i]=='w') state=3; //while
else if(str[i]=='d') state=8; //do
else if(str[i]=='e') state=10; //else
else if(str[i]=='f') state=14; //for
else if(isalpha(str[i]) || str[i]=='_')
{state=17;
startid=i;} //identifiers
else if(str[i]=='<') state=19;
//relational '<' or '<='
 
else if(str[i]=='>') state=21;
//relational '>' or '>='
else if(str[i]=='=') state=23;
//relational '==' or assignment '='
else if(isdigit(str[i]))
{state=25; startcon=i;}
//constant
else if(str[i]=='(') state=26;
//special characters '('
else if(str[i]==')') state=27;
//special characters ')'
else if(str[i]==';') state=28;
//special characters ';'
else if(str[i]=='+') state=29;
 //operator '+'
else if(str[i]=='-') state=30;
//operator '-'
break;//States for 'if'
case 1: if(str[i]=='f') state=2;
else 
{ state=17;
 startid=i-1;
 i--; }
break;
case 2: if(str[i]=='(' || str[i]==NULL)
{printf("\n\nif : Keyword");
state=0;
i--;}
else { state=17; 
startid=i-2;
 i--; }
break;//States for 'while'
case 3: if(str[i]=='h') state=4;
else { state=17;
 startid=i-1;
 i--; }
break;
case 4: if(str[i]=='i') state=5;
else { state=17; 
startid=i-2;
 i--; }
break;
case 5: if(str[i]=='l') state=6;
else 
{ state=17;
 startid=i-3;
 i--; }
break;
case 6: if(str[i]=='e') state=7;
else
 { state=17;
 startid=i-4;
 i--; }
break;
case 7: if(str[i]=='(' || str[i]==NULL)
{printf("\n\nwhile : Keyword");
state=0;
i--;}
else 
{ state=17;
 startid=i-5;
 i--; }
break;
//States for 'do'
case 8: 
if(str[i]=='o') 
state=9;
else { state=17;
 startid=i-1; 
i--; }
break;
case 9: if(str[i]=='{' || str[i]==' ' || str[i]==NULL || str[i]=='(')
{
printf("\n\ndo : Keyword");
state=0;
i--;}
break;//States for 'else'
case 10: if(str[i]=='l')
 state=11;
else 
{ state=17;
 startid=i-1; 
i--; }
break;
case 11:
 if(str[i]=='s') 
state=12;
else 
{ state=17;
 startid=i-2;
 i--; }
break;
case 12: 
if(str[i]=='e') state=13;
else 
{ state=17;
 startid=i-3;
 i--; }
break;
case 13: if(str[i]=='{' || str[i]==NULL)
{printf("\n\nelse : Keyword");
state=0;
i--;
}
else
 { state=17;
 startid=i-4; 
i--; }
break;
//States for 'for'
case 14: if(str[i]=='o') state=15;
else { state=17; 
startid=i-1; 
i--; }
break;
case 15: if(str[i]=='r') state=16;
else { state=17;
 startid=i-2;
 i--; }
break;
case 16: if(str[i]=='(' || str[i]==NULL)
{printf("\n\nfor : Keyword");
state=0;
i--;}
else 
{ state=17;
 startid=i-3; 
i--; }
break;
//States for identifierscase 17:
case 17:
if(isalnum(str[i]) || str[i]=='_')
{
state=18; 
i++;}
else if(str[i]==NULL||str[i]=='<'||str[i]=='>'||str[i]=='('||str[i]==')'||str[i]==';'||str[i]=='='||str[i]=='+'||str[i]=='-') state=18;
i--;
break;
case 18:if(str[i]==NULL || str[i]=='<' || str[i]=='>' || str[i]=='(' || str[i]==')' ||str[i]==';' || str[i]=='=' || str[i]=='+' ||str[i]=='-')
{
endid=i-1;
printf(" ");
for(j=startid; j<=endid; j++)
printf("\n\n%c", str[j]);
printf(" : Identifier");
state=0;
i--;}
break;

//States for relational operator '<' & '<='
case 19: if(str[i]=='=') state=20;
else if(isalnum(str[i]) || str[i]=='_')
{
printf("\n\n< : Relational operator");
i--;
state=0;}
break;
case 20: if(isalnum(str[i]) || str[i]=='_')
{printf("\n\n<= : Relational operator");
i--;
state=0;}
break;
//States for relational operator '>' & '>='
case 21: if(str[i]=='=') state=22;
else if(isalnum(str[i]) || str[i]=='_')
{printf("\n\n> : Relational operator");
 
i--;
state=0;}
break;
case 22: if(isalnum(str[i]) || str[i]=='_')
{printf("\n\n>= : Relational operator");
i--;
state=0;}
break;
//States for relational operator '==' & assignment operator '='
case 23: if(str[i]=='=') state=24;
else{printf("\n\n= : Assignment operator");
i--;
state=0;}
break;
case 24: if(isalnum(str[i])){
 
printf("\n\n== : Relational operator");
state=0;
i--;}
break;//States for constants
case 25: if(isalpha(str[i]))
{printf("\n\n*** ERROR ***");
puts(str);
for(j=0; j<i; j++)
printf(" ");
printf("^");
printf("\n\nError at position %d\n Alphabet cannot followdigit", i);
state=99;}
else if(str[i]=='(' || str[i]==')' || str[i]=='<' || str[i]=='>' || str[i]==NULL ||str[i]==';' || str[i]=='=')
{endcon=i-1;
printf(" "); 
for(j=startcon; j<=endcon; j++)
printf("\n\n%c", str[j]);
printf(" : Constant");
state=0;
i--;}
break;//State for special character '('
case 26: printf("\n\n( : Special character");
startid=i;
state=0;
i--;
break;//State for special character ')'
case 27: printf("\n\n) : Special character");
state=0;
i--;
break;//State for special character ';'
case 28: printf("\n\n; : Special character");
 
state=0;
i--;
break;//State for operator '+'
case 29: printf("\n\n+ : Operator");
state=0;
i--;
break;//State for operator '-'
case 30: printf("\n\n- : Operator");
state=0;
i--;
break;//Error State
case 99: return 0;
}
i++;}
printf("\n\nEnd of program");
//END:
return 0;}

