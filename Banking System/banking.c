#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank{
	char name[30];
	char phone[50];
	char password[20];
	float balance;
}Node;

int main(){
	Node user,use;
	char filename[50],phone[50],password[20];
	FILE *fp;
	int opt,choice,amount;
	char count='y';
	printf("\nWhat do you want to do?");
	printf("\n\n1.Create an account");
	printf("\n2.Login to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
		if(opt == 1){
		system("CLS");
		printf("\t******* WELCOME TO CORPORATIVE BANK *******\n\n\n");
		printf("Enter account holder name :\t");
		scanf("%s",user.name);
		printf("Enter your phone number:\t");
		scanf("%s",user.phone);
		printf("Enter your new password:\t");
		scanf("%s",user.password);
		user.balance=0;
		strcpy(filename,user.phone);
		fp=fopen(strcat(filename,".text"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered");
		}
	}
	else if(opt == 2){
		system("CLS");
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".text"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(Node),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(count == 'y' || count == 'Y'){
				system("CLS");
				printf("\n\t******* Welcome To Corparitive Bank ******* \n\n\tAccount holder name :\t%s\n\tRegistered Phone No. :\t%s",user.name,user.phone);
				printf("\n\n\n\tPress 1 for balance inquiry");
				printf("\n\tPress 2 for adding fund");
				printf("\n\tPress 3 for cash withdraw");
				printf("\n\tPress 4 for changing password\n\nEnter Your Choice :   ");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("\tYour current balance is Rs. %.2f",user.balance);
						break;

					case 2:
						system("CLS");
						printf("\tEnter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(Node),1,fp);
						if(fwrite !=0) printf("\n\n\tYou have depostied Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						system("CLS");
						printf("\tEnter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\n\tSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\n\tSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(Node),1,fp);
						if(fwrite !=0) printf("\n\n\tYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;
					
					case 4:
						printf("\n\n\tPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\n\tPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".text"),"w");
							fwrite(&user,sizeof(Node),1,fp);
							fclose(fp);	
							printf("\n\tPassword succesfullly changed");
						}else printf("\n\tSorry your password is wrong");
					
					default:
					break;
				}//switch ends here
				printf("\n\n\tDo you want to countinue?[y/n]:\t");
				scanf("%s",&count);
				}
			}
			else {
				printf("\t===== Invalid password =====");
			}	
		}
		printf("\n\n***Thank you for banking with CORPORATIVE BANK ***\n\n");
	}
	return 0;
}