/*****************************************************************************
 * "Customer Billing System" 
 *
 * This code performs various operations mainly used in medical store.
 *
 * Copyright (C) 2015 Priyanka Devidas Sirsath
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void intro();
void screenheader();
void custheader();
void input();
void writefile();
void search();
void custlist();
void search_cusaccno();
void output();

//structure for date
struct date{
	   int month;
	   int day;
	   int year;
	   };
//structure for account
struct account {
	  int number;
	  char name[100];
	  int acct_no;
	  int mobile_no;
	  char street[100];
	  char city[100];
	  char acct_type;
	  float oldbalance;
	  float newbalance;
	  float payment;
	  struct date lastpayment;
}customer;

struct account customer;
int tl,sl,ts;
FILE *fp;
void main()
{
          
	  int i,n;
	  int ch,cho;
	  system("clear");
          screenheader();
	  intro();
          custheader();
	  printf("\n");
	  printf("\n");
	 
	do{
 
	  printf("*-~**-~**-~**-~* CUSTOMER BILLING SYSTEM *-~**-~**-~**-~*");  
          printf("\n|=|=|=|=|=|=|=|=|==|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|");
          printf("\n|=|=|=|=|=|=|=|=|==|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|");
          printf("\n");
          printf("\n");
   	  printf("\n1: To add account on list\n");
	  printf("2: To search customer account\n");
          printf("3: To display customer account list\n");
          printf("4: To search customer by account number\n");
	  printf("5: Exit\n");
	  printf("\n================================\n");
	
	  printf("\nselect what do you want to do?\n");
	  scanf("%d",&cho);
	
	  switch(cho) {
		case 1:
			system("clear");
			printf("\nhow many customer accounts?");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				input();
				if(customer.payment>0)
					customer.acct_type=(customer.payment<0.1*customer.oldbalance)? 'O': 'D';
				else
					customer.acct_type=(customer.oldbalance>0)?'D' : 'C';
				customer.newbalance=customer.oldbalance - customer.payment;
				writefile();
			      }

			break;
			
		case 2:
			system("clear");
			printf("search by what?\n");
			printf("\n1 --- search by customer number\n");
			printf("2 --- search by customer name\n");


			search();
			scanf("%c",&ch);
	                break;
               case 3:
                        system("clear");
			printf("customer details...\n");
			printf("------------------------\n");
                        cust_list();
                        scanf("%c",&ch);
                        break;
               case 4:
                        system("clear");
			printf("search customer by account number\n");
			printf("-----------------------------------\n");
                        search_cusaccno();
                        scanf("%c",&ch);
                        break;

			
	       case 5:
                        system("clear");
			exit(1);
                        break;
             
               default:
                        printf("Wrong choice!!!!......\n");
			printf("---------------------------------\n");
                        printf("Please Enter what you want.......\n");
			printf("------------------------\n");
                        printf("Enter your choice in between 1 to 3\n");
			printf("---------------------------------\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        break;


	         }  

             }while(cho!=5);
          }
void screenheader()
{
   	printf("\n                       :::::::::::::::::::::::::::::::::::::");
  	printf("\n                       ::                                 ::");
   	printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   	printf("\n                       ::     @                     @     ::");
   	printf("\n                       ::     @      WELCOME TO     @     ::");
   	printf("\n                       ::     @                     @     ::");
   	printf("\n                       ::     @    Lovely  Coding   @     ::");
   	printf("\n                       ::     @                     @     ::");
   	printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   	printf("\n                       ::                                 ::");
   	printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
}
void intro()
  {
       printf("\n\t             Near VPJ Chowk, Beed by Pass Road, Aurangabad City,\n\t\t\t\t Maharashtra 431001, INDIA");
       printf("\n\n                              Ph. No.:011-2245785623");
       printf("\n\n\n                             WELCOMES YOU..............");

       printf("\n\n\n\tHotel Ganga is one of the newest Hotel in Aurangabad. The Hotel is equipped with with all the general amenities    and facilities that go along with memorable stay. Set amidst beautifully landscaped gardens,it proves to be a ideal dream destination for perceptive traveller.");

       printf("\nPress any character to continue:");
}
void custheader()
{
      printf("\n                       ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
      printf("\n                       ::                                                     ::");
      printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @            WELCOME TO     		@     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @         CUSTOMER BILLING                @     ::");
      printf("\n                       ::     @              SYSTEM                     @     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @                                         @     ::");
      printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ::");
      printf("\n                       ::                                                     ::");
      printf("\n                       ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}
void input()
{
          fp=fopen("file.txt","rb");
	  fseek (fp,0,SEEK_END);
	  tl=ftell(fp);
	  sl=sizeof(customer);
	  ts=tl/sl;
	  fseek(fp,(ts-1)*sl,SEEK_SET);
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\ncustomer no:%d\n",++customer.number);
	  fclose(fp);
	  printf("         Account number:");
	  scanf("%d",&customer.acct_no);
	  printf("\n       Name:");
	  scanf("%s",customer.name);
	  printf("\n       mobile no:");
	  scanf("%d",&customer.mobile_no);
	  printf("         Street:");
	  scanf("%s",customer.street);
	  printf("         City:");
	  scanf("%s",customer.city);
	  printf("         previous balance:");
	  scanf("%f",&customer.oldbalance);
	  printf("         Current payment:");
	  scanf("%f",&customer.payment);
	  printf("         Payment date(mm/dd/yyyy):");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  return;
}

void writefile()
{

	  fp=fopen("file.txt","ab");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
}

//===========================Search by Customer Name and Customer No =========================
void search()
{
	 char ch;
	 char nam[100];
	 int n,i,m=1,cho;

	 fp=fopen("file.txt","rb");
	 printf("\nenter your choice:");
	 scanf("%d",&cho);
			 
	 switch(cho) {

	      case 1:

	      		printf("\n choose customer number:");
		        scanf("%d",&n);
		    	fseek(fp,0,SEEK_END);
		    	tl=ftell(fp);
		    	sl=sizeof(customer);
		    	ts=tl/sl;
			
			
			if(n<=0 || n>ts)
			printf("\nEnter correct\n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&customer,sl,1,fp);
			    output();
			    }
				
		    	fclose(fp);
		    	break;
	      case 2:

	      	        printf("\nEnter the name:");
		        scanf("%s",nam);
		        fseek(fp,0,SEEK_END);
		        tl=ftell(fp);
		        sl=sizeof(customer);
		        ts=tl/sl;
		        fseek(fp,(ts-1)*sl,SEEK_SET);
		        fread(&customer,sizeof(customer),1,fp);
		        n=customer.number;

			
			fseek(fp,0,SEEK_SET);
			for(i=1;i<=n;i++)
			{
			     fread(&customer,sizeof(customer),1,fp);
			     if(strcmp(customer.name,nam)==0)
			     {
				output();
				m=0;
				break;
			     }
			}
			if(m!=0)
			printf("\n\ndoesn't exist\n");
                        printf("\n\nplease enter correct information..\n");
			fclose(fp);
	       }
	         return;
}
//======================customer details============================
void cust_list()
{
     char ch;
     system("clear");
     fp=fopen("file.txt","r");
	   printf(" account_no\t| name \t| mobile\t| city\t|\n");
   		int count = 0;
		struct  account ar[10000];
            	while(fread(&customer,sizeof(customer),1,fp)==1){
				ar[count] =customer;
				count++;
                    	}	
		printf("%d", count);
		int i, j;
		for(i = 0;i < count; i++) 
                        {
			for(j = i + 1; j < count; j++) 
                              {
				if(strcmp(ar[i].name, ar[j].name) > 0) 
                                     {
					struct  account temp = ar[i];
					ar[i] = ar[j];
					ar[j] = temp;
				     }
			      }
		        }
		for(i = 0; i < count; i++)
                  		printf("\n|%-10d| %-10s| %-10d\t| %-10s|\n",ar[i].acct_no,ar[i].name,ar[i].mobile_no ,ar[i].city);
}

//===========================Search by Customer account no =========================
void search_cusaccno()
{
    
      int acc_no;
      system("clear");

	 printf("Enter account number to be searched:");
	 scanf("%d",&acc_no);
	 fp=fopen("file.txt","r");
	        if(customer.acct_no==acc_no)
                  {
	              while(fscanf(fp,"%d %s %S %d ",customer.acct_no, customer.name,customer.mobile_no,customer.city)!=EOF)
	                {
		            printf("Account Number= %d\n",customer.acct_no);
			    printf("Customer Name =%s\n",customer.name);
			    printf(" City=%s\n",customer.city);
			    printf("Mobile Number= %d\n",customer.mobile_no);
			
	            	    printf("\nPress Any key to go to CUSTOMER MENU ...........");
			    break;
		       }
		
       	         }

        	else if(customer.acct_no!=acc_no)
	         {
		
                          printf("Record not found!!!!!!!");
                          printf("\nPress Any key to go to CUSTOMER MENU ...........");
	        }
       fclose(fp);
       getchar();
}

//===========================Bill of customer =========================
void output()
{
	   printf("\n\nCustomer no    :%d\n",customer.number);
	   printf("    Name 	      :%s\n",customer.name);
	   printf("    Mobile no      :%.d\n",customer.mobile_no);
	   printf("    Account number :%d\n",customer.acct_no);
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%.2f\n",customer.oldbalance);
	   printf("    Current payment:%.2f\n",customer.payment);
	   printf("    New balance    :%.2f\n",customer.newbalance);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf("    Account status :");
	   
	   switch(customer.acct_type)
	      {
	      case 'C':
		 printf("CURRENT\n\n");
		 break;
	      case 'O':
		 printf("OVERDUE\n\n");
		 break;
	      case 'D':
		 printf("DELINQUENT\n\n");
		 break;
	      default:
		 printf("ERROR\\n\n");
	      }

	      return;
} 
