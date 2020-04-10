#include<stdio.h>
#include<conio.h>
int main()
 {
   int x,i;
   int n;         //n is number of process
   int P[10];   //P is process    
   int P_P[10];   //P_P is process priority
   int B_T[10];   //B_T is process burst time
   int W_T[10];   //W_T is wait time
   int T_A_T[10];   // T_A_T is turnaround time
   int A_W_T;   //A_W_T is average waiting time
   int A_TAT;   //A_TAT is average turnaround time
   int A_T[10];   //A_T is arrival time
   int T_Q;   //T_Q is time qunatum


   printf("Enter the number of processes to be processed = ");
   scanf("%d",&n);
   printf("Time Quantum = ");
   scanf("%d",&T_Q);
   printf("\n\t---------- Enter BURST TIME | PRIORITY | ARRIVAL TIME----------  \n");
 
   for(i=0;i<n;i++)
    {
      printf("\n P%d = ",i+1);
      scanf("%d %d %d",&B_T[i],&P_P[i],&A_T[i]);
	  P[i]=i+1;
    }
 
//priority based sorting
int j;
  for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
       if(P_P[i]<P_P[j])
       {
     x=P_P[i];
     P_P[i]=P_P[j];
     P_P[j]=x;
     x=B_T[i];
     B_T[i]=B_T[j];
     B_T[j]=x;
     x=P[i];
     P[i]=P[j];
     P[j]=x;
      }
   }
}
W_T[0]=0;
A_W_T=0;
T_A_T[0]=B_T[0];
A_TAT=T_A_T[0];
for(i=1;i<n;i++)
 {
 	if(T_Q<n || T_Q>n) {
	 
   W_T[i]=T_A_T[i-1];
   A_W_T+=W_T[i];
   T_A_T[i]=W_T[i]+B_T[i];
   A_TAT+=T_A_T[i];
	 }
 }
 
 //code for Gantt Chart
  
 printf("\n");
 printf("---------------GANTT CHART---------------\n");
 for(i=0;i<n;i++)
 {
 	printf("P %d ",P[i]);
 }
 
//Process displaying
 
printf("\n\nProcess \t Burst Time \t Wait Time \t Turn Around Time   Priority \tArrival time \n");
for(i=0;i<n;i++){
printf("\n  %d",P[i]); printf("\t\t %d",B_T[i]); printf("\t\t %d",W_T[i]); printf("\t\t %d",T_A_T[i]); printf("\t\t %d",P_P[i]); printf("\t\t %d",A_T[i]);

}
A_W_T/=n;
A_TAT/=n;
printf("\n Avg Waiting Time = %d ",A_W_T);
printf("\n Avg Turn Around Time = %d",A_TAT);
getch();
}
