#include<stdio.h>
#include<string.h>

int ninputs;

int check(char,int ); //function declaration
int dfa[10][10],conti;
char c[10], string[10];

int main()
{
     int nstates, nfinal;
     int f[10];
     int i,j,s=0,final=0;
     printf("Enter the number of states that your DFA consist of :\n");         //Entering No. of states
     scanf("%d",&nstates);
     printf("Enter the number of input symbol that DFA have :\n");              //Entering the no. of symbols in Alphabet Set
     scanf("%d",&ninputs);
     printf("\nEnter input symbols:\t");                //The symbols are prementioned as {a,b,c,d,e,f,g,h,i,j}
     c[0]='a'; c[1]='b'; c[2]='c'; c[3]='d'; c[4]='e'; c[5]='f'; c[6]='g'; c[7]='h'; c[8]='i'; c[9]='j';
     for(i=0; i<ninputs; i++)           //printing the no. of input symbols if 3, then {a,b,c}
     {
           printf("\n\n %d input\t %c", i+1,c[i]);
     }

     printf("\n\nEnter number of final states\t");      //Entering the no. of final states
     scanf("%d",&nfinal);

     for(i=0;i<nfinal;i++)
     {
          printf("\n\nFinal state %d : q",i+1);         //Entering the final states as the states q0,q1,q2,q3,q4 etc.
          scanf("%d",&f[i]);
     }

     printf("-----------------------------------------------------------------------");
     printf("\n\nDefine Transition Rule as (Initial State, Input Symbol ) = Final State\n");  //Defined transition rules as (q0,a)=q1 etc.
     printf("\n∂: Q x ∑ -> Q\n");
     for(i=0; i<ninputs; i++)
     {
          for(j=0; j<nstates; j++)
          {
               printf("\n(q%d , %c ) = q",j,c[i]);
               scanf("%d",&dfa[i][j]);                          //Saving the vaules in a table, as of a matrix 
          }
     }

     do
     {
          i=0;
          printf("\n\nEnter Input String.. ");
          scanf("%s",string);                                   //Initializing the string to be checked

          while(string[i]!='\0')                                /* loop for checking the string, */
          if((s=check(string[i++],s))<0)                        //the next state is returned by check to s
          break;                                                //if it is an NDFA it will return -1 and break the loop
          for(i=0 ;i<nfinal ;i++)
          if(f[i] == s )                              //Checking if the state returned by check is one of final states
          {
          final=1;
          }
          if(final==1)
          printf("\n The String is Accepted by DFA. \n"); 
          else
          printf("\n The String is Rejected by DFA. \n");
          

          printf("\nDo you want to continue.?  \n(0=No/1=Yes)\n ");
          scanf("%d",&conti);
     }
     while(conti==1);

}
int check(char b,int d)                                 //the function checks the values according to the transition table formed.
{
     int j;
     for(j=0; j<ninputs; j++)
     if(b==c[j])
     return(dfa[d][j]);                                 //returns the next state
     return -1;                                         //returns -1 if it is a NDFA
}
