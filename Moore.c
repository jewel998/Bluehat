#include<stdio.h>
#include<string.h>

int ninputs;

int moore(char,int,int); //function declaration
int dfa[10][10],conti,l=0,len,output[10];
char c[10], string[10]; int final[10];

int main()
{
     int nstates;
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

     

     printf("\n-----------------------------------------------------------------------");
     printf("\n\nDefine Transition Rule as (Initial State, Input Symbol ) = Final State\n");  //Defined transition rules as (q0,a)=q1 etc.
     printf("\n∂: Q x ∑ -> Q\n");
     printf("\nX: Q x ∑ -> O\n");
     for(i=0; i<ninputs; i++)
     {
          for(j=0; j<nstates; j++)
          {
               printf("\n(q%d , %c ) = q",j,c[i]);
               scanf("%d",&dfa[i][j]);
          }
     }
     for(j=0;j<nstates;j++);
     {
     printf("Enter the output value for state q%d:",j);
     scanf("%d",&output[j]);
     }
     printf("Enter the string to check output:");
     scanf("%s",string);
     len=strlen(string);
     moore(string[0],0,len);
     
}

int moore(char ch, int present_state, int len)
	{
		int i=0;
		if(len==0)
		return 0;
		while(ch!=c[i])
		{ i++;
		}
		printf("%d",output[present_state]);
		l+=1;
		moore(string[l],dfa[i][present_state],len-1);
		return 0;
	}