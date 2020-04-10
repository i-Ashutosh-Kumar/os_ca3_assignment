//Billing for gifts while giving priority to the students who have most number 
//of gifts and also their order of billing.


#include <stdio.h> 

	int i,t,j,n;           //declaration of variables
	float cost;
	int B_T[10],p_no[10],bill[10]; //B_T=brust time ,p_no= process number
	
	
 void billfn()              //generation of bill
    {		  
      printf( "STUDENT_ORDER\t\tNO. OF GIFTS PURCHASED\t\tBILL AMOUNT\n\n"); 

	    for (i = 0; i < n; i++) 
		   { 
	           	printf("STUDENT Number. = %d \t\t" ,p_no[i]);
		        printf("%d \t\t\t",B_T[i]);
		        bill[i]= cost * B_T[i];           //calculation of cost 
	         	printf("%d \t\t\t",bill[i]); 
	            printf("\n");
	       }
    }

void get() //No. of gifts taken by students and entered by user
   {

     printf("\n\n");
     printf("---------------NUMBER OF GIFTS---------------\n\n");
	 printf( "\nSTUDENT Num.\t\tNumber OF GIFTS PURCHASED \n"); 

	    for (i = 0; i < n; i++)  
	      { 
		      printf("STUDENT Num. = %d \t\t" ,p_no[i]);   //process no
		      printf("%d \t\t\t",B_T[i]);                  //brust time
	          printf("\n\n");
	      } 
	}

void sorting()    //order of billing for students on the basis of number of gifts purchased
   { 
   
	printf("----------BILLING ORDER OF STUDENTS---------- \n\n");
	    for(i=0;i<n;i++)
          {
    	      for(j=i+1;j<n;++j)
			     {
		            if(B_T[i]<B_T[j])              //priority given on the basis of number of gifts 
					{
		                t=B_T[i];                        //values swapped
                   	    B_T[i]=B_T[j];
                        B_T[j]=t;
                        t=p_no[i];           //temporary variable
                        p_no[i]=p_no[j];                    //process no's swapping
                        p_no[j]=t;
                    }
                 }
}          }


int main() 
{ 

	 printf("TOTAL NUMBER OF STUDENTS WHO PURCHASED GIFTS = ");  // process number initialization
     scanf("%d",&n);
     printf("COST OF EACH GIFT = ");
     scanf("%f",&cost);
     printf("---------------PLEASE ENTER THE NUMBER OF GIFTS FOR EACH STUDENT--------------");
        for(i=0;i<n;i++)
          {
              printf("\nSTUDENT_NO[%d] \n",i+1);
              printf("NUMBER OF GIFTS PURCHASED :");//input by user
              scanf("%d",&B_T[i]);
              p_no[i]=i+1;           //process number 
          }

  
        get();
        sorting();
        billfn();
         
}
