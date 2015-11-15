
/*****************************************************************************
 * Copyright (C) Akshada Ramdas Tonde. akshadart1997@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int i,j,k;
int main_exit;
void menu();
struct date {
	int month,day,year;
};

struct {
	double phone;
    	char acc_type[10];
    	float amt;
	char name[60];
    	int acc_no,age;
    	char address[60];
    	char citizenship[15];
    	struct date dob;
    	struct date deposit;
    	struct date withdraw;
}add,upd,check,rem,transaction;
/* In main it is called for checking password whether password entered by user is correct or not */
void fordelay(int j) {
	int i;
	for(i=0;i<j;i++) {
	k=i;
	}
}
/* For Interest*/
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
/*when a close() is called returns void*/
void close(void) {
}

/*1.new_acc():-
             Which creates new user bank account means takes all details of user and updates all the records in a file name givan.
             If any user enters same account number that is already in file will show an error i.e warning.
*/
void new_acc() {
	FILE *ptr;
	ptr=fopen("record.ods","a+");
	account_no:
	printf("\tADDING RECORDS:\n\n\t");
	printf("Enter today's date(dd/mm/yyyy):\n\t");
	scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
	printf("\tEnter the account number:\n\t");
	scanf("%d",&check.acc_no);
	while(fscanf(ptr,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
		/*(fscanf(ptr,"%d\t",&add.acc_no) &&
		fscanf(ptr,"%s\t",&add.name) &&
		fscanf(ptr,"%d/%d/%d\t",&add.dob.day,&add.month.day,&add.dob.year) &&
		fscanf(ptr,"%d\t",&add.age) &&
		fscanf(ptr,"%s\t",add.address) &&
		fscanf(ptr,"%s\t",add.citizenship) &&
		fscanf(ptr,"%lf\t",&add.phone) &&
		fscanf(ptr,"%s\t",add.acc_type) &&
		fscanf(ptr,"%f\t",&add.amt) &&
		fscanf(ptr,"%d/%d/%d\n",&add.deposit.day,&add.deposit.month,&add.deposit.year))!EOF) */{
			if (check.acc_no==add.acc_no) { 
				printf("Account no. already in use!\n\t");
				fordelay(1000);
		                goto account_no;
		        }
		}
	add.acc_no=check.acc_no;
        printf("\tEnter the name:\n\t");
        scanf("%s",add.name);
	printf("\tEnter the date of birth(dd/mm/yyyy):\n\t");
	scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
	printf("\tEnter the age:\n\t");
	scanf("%d",&add.age);
	printf("\tEnter the address:\n\t");
	scanf("%s",add.address);
	printf("\tEnter the citizenship:\n\t");
	scanf("%s",add.citizenship);
	printf("\tEnter the phone number:\n\t");
	scanf("%lf",&add.phone);
	printf("\tEnter the amount to deposit:\n\t");
	scanf("%f",&add.amt);
	printf("\n\t\tType of account:\n\t\t");
	printf("1.Saving\n\t\t");
	printf("2.Current\n\t\t");
	printf("3.Fixed(for n year)\n\t\t");
	printf("Enter your choice:");
	scanf("%s",add.acc_type);
/*        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
fprintf(ptr,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
*/
	fprintf(ptr,"%d\t",add.acc_no);
	fprintf(ptr,"%s\t",add.name);
	fprintf(ptr,"%d/%d/%d\t",add.dob.day,add.dob.month,add.dob.year);
	fprintf(ptr,"%d\t",add.age);
	fprintf(ptr,"%s\t",add.address);
	fprintf(ptr,"%s\t",add.citizenship);
	fprintf(ptr,"%lf\t",add.phone);
	fprintf(ptr,"%s\t",add.acc_type);
	fprintf(ptr,"%f\t",add.amt);
	fprintf(ptr,"%d/%d/%d\n",add.deposit.day,add.deposit.month,add.deposit.year);

	fclose(ptr);
	printf("\nAccount created successfully!\n\n\n");
	add_invalid:
	printf("Enter 1 to go to the main menu and 0 to exit:\n");
	scanf("%d",&main_exit);
	if (main_exit==1) {
	        menu();
	}
	else if(main_exit==0) {
		exit(0);
	}
	else {
		printf("\nInvalid!\a");
		goto add_invalid;
        }
}

/*2.edit():-
             Which allow user to edit the changes like address and phone number.
             and saves again int file name given.
*/
void edit()
{
	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.ods","r");
	newrec=fopen("new.ods","w");
	printf("\nEnter the account no. of the customer whose info you want to change:");
	scanf("%d",&upd.acc_no);
	while(fscanf(old,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
	        if (add.acc_no==upd.acc_no) {
	        	test=1;
		        printf("\nWhich information do you want to change?\n");
		        printf("1.Address\n");
		        printf("2.Phone\n\n");
		        printf("Enter your choice i.e 1 for address and 2 for phone:\n");
			scanf("%d",&choice);
				if(choice==1) {
					printf("Enter the new address:");
					scanf("%s",upd.address);
					fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);							
			                printf("Changes saved!");
                		}
            			else if(choice==2) {
                    			printf("Enter the new phone number:");
                			scanf("%lf",&upd.phone);
                			fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                			printf("Changes saved!");
                		}

        	}
        	else {
            		fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);				
            	}
    	}
    	fclose(old);
    	fclose(newrec);
    	remove("record.ods");
    	rename("new.ods","record.ods");
    	if(test!=1) {   
    		printf("\nRecord not found!!\a\a\a");
            	edit_invalid:
              		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              		scanf("%d",&main_exit);
                 	if (main_exit==1) {
				menu();
			}
                	else if (main_exit==2) {
                    		close();
                    	}
                	else if(main_exit==0) {
                    		edit();
                    	}
                	else {
                    		printf("\nInvalid!\a");
                    		goto edit_invalid;
                    	}
        }
    	else {
        	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
        	if (main_exit==1) {
            		menu();
            	}
        	else {
            	close();
            	}
        }
}
/*3.transact():-
             Allows user to do transactions on account balaence.
             i.e deposit and withdraw transactions.
*/
void transact() {   
	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.ods","r");
	newrec=fopen("new.ods","w");
        printf("\tEnter the account no. of the customer:");
	scanf("%d",&transaction.acc_no);
	while (fscanf(old,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
		if(add.acc_no==transaction.acc_no) {
			test=1;
	                if(strcmp(add.acc_type,"fixed")==0) {
                    		printf("\n\n\tYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!\n\n\t\t\t");
                    		fordelay(1000);
                    		menu();
			}
                	printf("\n\n\tDo you want to\n\t1.Deposit\n\t2.Withdraw?\n\n\tEnter your choice(1 for deposit and 2 for withdraw):");
                	scanf("%d",&choice);
                	
                	
                	if (choice==1) {
                    		printf("\tEnter the amount you want to deposit:");
                    		scanf("%f",&transaction.amt);
                    		add.amt+=transaction.amt;
                    		fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    		printf("\n\n\tDeposited successfully!");
                	}
                	
                	
                	else {
                    		printf("\tEnter the amount you want to withdraw:");
                    		scanf("%f",&transaction.amt);
                    		add.amt-=transaction.amt;
                    		fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    		printf("\n\n\tWithdrawn successfully!");
                	}

            	}
            	else {
               		fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            	}
   	}
   		fclose(old);
   		fclose(newrec);
   		remove("record.ods");
   		rename("new.ods","record.ods");
   		
   		/*If Wrong:*/
   		if(test!=1) {
       			printf("\n\n\tRecord not found!!");
       			transact_invalid:
      			printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      			scanf("%d",&main_exit);
      	      		if (main_exit==0) {
        			transact();
        		}
    			else if (main_exit==1) {
        			menu();
        		}
    			else if (main_exit==2) {
        			close();
        		}
    			else {
        			printf("\nInvalid!");
        			goto transact_invalid;
    			}

   		}
   		else {
       			printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        		scanf("%d",&main_exit);
        		if (main_exit==1) {
            			menu();
            		}
        		else {
            			close();
            		}
   		}

}
/*4.see():-
             Allows user to see the user details based on name or account number.
             and displays it on screen.
*/
void see() {
	FILE *ptr;
    	int test=0,rate;
    	int choice;
    	float time;
    	float intrst;
    	ptr=fopen("record.ods","r");
    	printf("Do you want to check by:\n");
    	printf("1.Account no.\n");
    	printf("2.Name\n");
    	printf("Enter your choice:");
    	scanf("%d",&choice);
    	if (choice==1) {
    		printf("Enter the account number:");
        	scanf("%d",&check.acc_no);
		while (fscanf(ptr,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
            		if(add.acc_no==check.acc_no) {
                		test=1;
				printf("\nAccount NO.:%d\n",add.acc_no);
				printf("Name:%s \n",add.name);
				printf("DOB:%d/%d/%d \n",add.dob.month,add.dob.day,add.dob.year);
				printf("Age:%d \n",add.age);
				printf("Address:%s \n",add.address);
				printf("Citizenship No:%s \n",add.citizenship);
				printf("Phone number:%.0lf \n",add.phone);
				printf("Type Of Account:%s \n",add.acc_type);
				printf("Amount deposited:$ %.2f \n",add.amt);
				printf("Date Of Deposit:%d/%d/%d\n\n",add.deposit.month,add.deposit.day,add.deposit.year);
                		if(strcmp(add.acc_type,"fixed")==0) {
                        		time=1.0;
                        		rate=9;
                        		intrst=interest(time,add.amt,rate);
                        		printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                   		}
                 		else if(strcmp(add.acc_type,"saving")==0) {
                        		time=(1.0/12.0);
                        		rate=8;
                        		intrst=interest(time,add.amt,rate);
                        		printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
				}
                 		else {
                        		printf("\n\nYou will get no interest\a\a");
                        	}
			}
  		}		
	}
    	else if (choice==2) {
      		printf("Enter the name:");
        	scanf("%s",
        	check.name);
        	while (fscanf(ptr,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
            	if(strcmp(add.name,check.name)==0) {
            		system("cls");
                	test=1;
                	printf("\n\tAccount No.:%d",add.acc_no);
                	printf("\n\tName:%s ",add.name);
                	printf("\n\tDOB:%d/%d/%d",add.dob.month,add.dob.day,add.dob.year);
                	printf("\n\tAge:%d ",add.age);
                	printf("\n\tAddress:%s ",add.address);
                	printf("\n\tCitizenship No:%s",add.citizenship);
                	printf("\n\tPhone number:%.0lf ",add.phone);
                	printf("\n\tType Of Account:%s",add.acc_type);
                	printf("\n\tAmount deposited:$%.2f",add.amt);
                	printf("\n\tDate Of Deposit:%d/%d/%d\n\n",add.deposit.month,add.deposit.day,add.deposit.year);
                	if(strcmp(add.acc_type,"fixed")==0) {
                        	time=1.0;
                        	rate=9;
                        	intrst=interest(time,add.amt,rate);
                        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
 			}
                	
                 	else if(strcmp(add.acc_type,"saving")==0) {
                        	time=(1.0/12.0);
                        	rate=8;
                        	intrst=interest(time,add.amt,rate);
                        	printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
			}
                 	else {
                        	printf("\n\nYou will get no interest\a\a");
                     	}

            	}
        }
    }


    	fclose(ptr);
     	if(test!=1) {
		printf("\nRecord not found!!\a\a\a");
            	see_invalid:
              	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              	scanf("%d",&main_exit);
              		if (main_exit==1)
                    		menu();
                	else if (main_exit==2)
                    		close();
                	else if(main_exit==0)
                    		see();
                	else {
                        	printf("\nInvalid!\a");
                        	goto see_invalid;
                        }
        }
   	else {
   		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
        }
        if (main_exit==1) {
       		menu();
       	}
       	else {
       		close();
       	}
}
/*5.erase():-
             This function deletes all the records of a user.
             i.e all details gain during account creation based on account number.
*/
void erase() {
	FILE *old,*newrec;
    	int test=0;
    	old=fopen("record.ods","r");
    	newrec=fopen("new.ods","w");
    	printf("Enter the account no. of the customer you want to delete:");
    	scanf("%d",&rem.acc_no);
    	while (fscanf(old,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
        	if(add.acc_no!=rem.acc_no)
            	fprintf(newrec,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		else {
			test++;
            		printf("\nRecord deleted successfully!\n");
            	}
   	}
   	fclose(old);
   	fclose(newrec);
   	remove("record.ods");
   	rename("new.ods","record.ods");
   	if(test==0) {
            	printf("\nRecord not found!!\a\a\a");
            	erase_invalid:
              	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              	scanf("%d",&main_exit);
		if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else {
                	printf("\nInvalid!\a");
                    	goto erase_invalid;
                }
        }
    	else { 
    		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
        	if (main_exit==1)
            		menu();
        	else
            		close();
        }

}
/*6.view_list():-
             It will displays all the users.
             i.e Display all users who have account in bank.
*/
void view_list()
{
	FILE *view;
    	view=fopen("record.ods","r");
    	int test=0;
    	printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
	while(fscanf(view,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%lf\t%s\t%f\t%d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
        	printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           	test++;
       	}
	fclose(view);
    	if (test==0) {
            	printf("\nNO RECORDS!!\n");
        }
	view_list_invalid:
     	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
/*7.for_exchange():-
             Converts the indian money.
             i.e into foreign money.
*/
void for_exchange() {
	char ch;  
	float y,z; 
//	int main_exit(); 
        printf("Welcome to the foreign exchange convertor section.\n"); 
	printf("Select the currency you wish to convert:\n"); 
  	printf("a.US Dollar\n");  
  	printf("b.Euro\n");  
   	printf("c.Pound\n");
	printf("d.Exit\n");
	while(1) {
		printf("Enter Your choice:\n");
    		scanf("%s",&ch);  
    		switch(ch) {  
				case 'a':  
				printf("Please enter the amount of rupees you wish to convert in US Doller:\n");  
				scanf("%f",&y);  
				z=y/60;  
				printf("The converted rate is $ %f\n",z);  
	    			break;  
    			case 'b':  
				printf("Please enter the amount of rupees you wish to convert in Euro:\n");  
    				scanf("%f",&y);  
    				z=75/y;  
    				printf("The converted rate is Euro %f\n",z);  
   				break;  
    			case 'c':  
    				printf("Please enter the amount of rupees you wish to convert in Pound:\n");  
    				scanf("%f",&y);  
    				z=60/y;  
    				printf("The converted rate is Pound %f\n",z);  
    				break; 
			case 'd':
				exit(0);
				break; 
		}	
	}
return;
}    			

/* Is there any new scheme available in the bank or not.
             based on type of account.
*/
void newscheme() {
	int age;
	char type[10];
	printf("Different schemes for different age of people and different type of account:\n");
	printf("Enter your age:\n");
	scanf("%d",&age);
	printf("Enter type of account:\n");
	scanf("%s",type);
	if((age>18 || age<50) && (strcmp(type,"saving")==0)) {
		printf("You will get dam duppat i.e extra money\n");
	}
	/*else {
		printf("No any scheme for your age\n");
	}*/
	else if(age>50 && (strcmp(type,"saving")==0)) {
		printf("there will be pention scheme for you\n");
	}
	else {
		printf("No current scheme for ur age:");
	}
}
/*9.loan():-
for taking loan from bank*/
void loan() {
	int loan,val;
	char d;
	printf("How much loan do you want and for how much duration:\n");
	scanf("%d%d",&loan,&val);
	if(loan>100000) {
		printf("You cannot take loan more than 1,00,000\n");
	}
	else {
		printf("you'll get loan soon!!!Please submit documents to complete formalities:\n");
		printf("Do you have submitted your documents:y/n\n");
		scanf("%c",&d);
		//getchar();
		if(getchar()=='y') {
			printf("You w'll get loan soon!!!!!\n");
		}
		else {
			printf("First submit ur all documents then only u'll get loan otherwise it w'll be cancelled\n");
		}
	}
}
		
	

void menu(void) {   
	int choice;
	printf("\t\t\t       BANK MANAGEMENT SYSTEM");
	printf("\n\n\n\t*********************************************************************\n");
	printf("\t\t\t       WELCOME TO THE MAIN MENU\n");
	printf("\t*********************************************************************");
	printf("\n\n\t\t\t1.Create new account\n\t\t\t");
	printf("2.Update information of existing account\n\t\t\t");
	printf("3.For transactions\n\t\t\t");
	printf("4.Check the details of existing account\n\t\t\t");
	printf("5.Removing existing account\n\t\t\t");
	printf("6.View customer's list\n\t\t\t");
	printf("7.Foreign Exchange:\n\t\t\t");
	printf("8.Newscheme:\n\t\t\t");
	printf("9.Loan:\n\t\t\t");
	printf("15.Exit\n\n\n\n\n\t");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice) {
        	case 1:
        		new_acc();
        		break;
        case 2:
        	edit();
        	break;
        case 3:
        	transact();
	        break;
        case 4:
        	see();
        	break;
        case 5:
        	erase();
        	break;
        case 6:
        	view_list();
        	break;
        case 7:
        	for_exchange();
        	break;
        case 8:
        	newscheme();
        	break;
        case 9:
        	loan();
        	break;
        case 15:
        	close();
        	break;
        }
}


int main() {
	char pass[20],password[20]="myaccountlogin";
	int i=0;
	printf("Enter the password to login:\n");
	scanf("%s",pass);
	/*do {
		//if (pass[i]!=13&&pass[i]!=14) {
			printf("*");
			pass[i]=return 0;
			i++;
		}
	}while (pass[i]!=13);
	pass[10]='\0';*/
	if (strcmp(pass,password)==0) {
		printf("\nPassword Match!\nLOADING");
		for(i=0;i<=6;i++) {
			fordelay(1000);
		        printf(".");
		}
	        printf("\n\n\n\n\n\n\n"); 
            	menu();
        }
	else {
		printf("Wrong password!!\n");
		login_try:
			printf("Enter 1 to try again and 0 to exit:\n");
            		scanf("%d",&main_exit);
            		if (main_exit==1) {
                        	main();
                    	}
			else if (main_exit==0) {
                    		close();
                    	}
            		else { 
            			printf("\nInvalid!");
                    		fordelay(1000);
                    		goto login_try;
                    	}

        }
        return 0;
}
