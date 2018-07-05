#include<stdio.h>
#include<stdlib.h>
int p[10],n;
void lru();
void fifo();

void main() {
int choice;
printf("enter the no of pages\n");
scanf("%d",&n);
printf("enter the pages\n");
for(int i=0;i<n;i++)
scanf("%d",&p[i]);
printf("enter 1 for lru and 2 for fifo\n");
scanf("%d", &choice);

switch(choice)
{
case 1: lru(); break;
case 2: fifo(); break;
}

}

void lru()
{
int nof, frame[100],fcount[100],i,j,k,count=0;
printf("enter the no of frames\n");
scanf("%d",&nof);

for(i=0;i<nof;i++)
{
frame[i]=-1;
fcount[i]=0;
}

for(i=0;i<n;i++)
{
int flag=0;
for(j=0;j<nof;j++)
{
if(p[i]==frame[j])
{
fcount[j]=i+1;
flag=1;
}
}
printf("\n\t*******************\n");
printf("%d\t",p[i]);

if(flag==0)
{
int min=0;
for(k=0;k<nof-1;k++)
{
if(fcount[min]>fcount[k+1])
min=k+1;
}

frame[min]=p[i];
fcount[min]=i+1;
count++;

for(j=0;j<nof;j++)
printf("%d\t",frame[j]);
}
}
printf("\npage fault is %d:",count);
}

void fifo() {
int count=0,frame[100],i,j,k,avail,no;

printf("enter no of frame\n");
scanf("%d",&no);
for(i=0;i<no;i++)
frame[i]=-1;
j=0;

printf("\tRFERENCE STRING \t\t\t\t PAGE FRAMES \n");
for(i=0;i<n;i++)
 {  
    printf("%d\t\t\t\t",p[i]);
    avail=0;
    for(k=0;k<no;k++)
     {
        if (frame[k]==p[i])
        avail=1;
      }
     if(avail==0)
      {
         frame[j]=p[i];
         j=(j+1)%no;
         count++;
        for(k=0;k<no;k++)
       {
         if(frame[k]!=-1)
         printf("%d\t",frame[k]);
         else
         printf(" \t");
       }
     } 
  printf("\n");
}
printf("the page fault is %d",count);
}
    
















































