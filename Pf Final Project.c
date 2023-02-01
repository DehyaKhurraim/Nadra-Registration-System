#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>

// Global variables
int valid=0,ok=0;

// decleration of functions
void gotoxy(int , int);
int title();
int welcome();
void description();
int login();
int menu();
int cnic_create();
void cnic_update();
void cnic_verification();
void search_record();
void ex_it();

// struture
struct nadra
{
	char f_name[20];
	char l_name[20];
	char father_name[35];
	int age;
	char phone_no[20];
	char bayform_no[20];
	char gender;
	char crnt_address[15];
	char per_address[15];
	int birth_date;
	int issue_date;
	char filename[13];
};
struct nadra e;
struct nadra e1;

// definition of gotoxy function
void gotoxy(int x, int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

// main function
int main()
{
	welcome();
	description();
	login();
	return 0;
}

//description
void description()
{
	system("cls");
	title();

	FILE *m;
	char ch;

	m=fopen("description.txt","r");

	while(!feof(m))
	{
		ch=fgetc(m);
		printf("%c",ch);
	}

	getch();

}

// definition of welcome function
int welcome()
{
	printf("\n\n\n\n\n\n\t\t\t  ***************************");
	printf("\n\n\t\t\t\t   WELCOME TO");
	printf("\n\n\t\t\t   NADRA REGISTRATION SYSTEM");
	printf("\n\n\t\t\t  ***************************");

	printf("\n\n\n\n\n\n\n\n \t\t\t  Press any key to Continue...");

	getch();
	system("cls");
}

// definition of title function
int title()
{
	printf("\n\n\t\t\t    *****************************************************");
	printf("\n\n\t\t\t                  NADRA REGISTRATION SYSTEM");
	printf("\n\n\t\t\t    *****************************************************");
}

// definition of login function
int login()
{
	system("cls");
	title();
	int chances;
	char orgname[10]="nadra";
	char orgpass[10]="12345";
	char name[10];
	char pass[10];

	for(chances=1; chances<=3; chances++)
	{
		printf("\n\n\n\t\t\t\t  USERNAME : ");
		gets(name);
		printf("\n\n\t\t\t\t  PASSWORD : ");
		gets(pass);

		if(strcmp(orgname,name)==0 && strcmp(pass,orgpass)==0)
		{
			printf("\n\n\t\t\t\t  Login Successful");
			printf("\n\n\t\t\t\t  Press any key to Continue....");
			getch();
			system("cls");
			menu();
			break;
		}

		else
		{
			if(chances==3)
			{
				printf("\n\n\t\t\t\t  You have crossed the limit.You can't Login\n");
				ex_it();
				break;
			}
			system("cls");
			title();
			printf("\n\n\n\t\t\t\t  Incorrect Password OR Username Entered\n\n");
			printf("\t\t\t\t\t       TRY AGAIN!\n");
		}
	}

}

// definition of menu function
int menu()
{
	title();
	int choice,valid=1;

	do
	{
		printf("\n\n\n\t\t\t\t   PRESS 1 FOR CNIC CREATION");
		printf("\n\n\n\t\t\t\t   PRESS 2 FOR CNIC VERIFICATION");
		printf("\n\n\n\t\t\t\t   PRESS 3 FOR CNIC UPDATION");
		printf("\n\n\n\t\t\t\t   PRESS 4 TO SEARCH RECORD");
		printf("\n\n\n\t\t\t\t   PRESS 5 TO TERMINATE PROGRAM");

		printf("\n\n\n\n\n\t\t\t\t   CHOOSE FROM 1 TO 5 : ");
		scanf("%d",&choice);

		fflush(stdin);

		switch(choice)
		{
			case 1:
				system("cls");
				cnic_create();
				break;

			case 2:
				system("cls");
				cnic_verification();
				break;

			case 3:
				system("cls");
				cnic_update();
				break;

			case 4:
				system("cls");
				search_record();
				break;

			case 5:
				ex_it();
				break;

			default:
				system("cls");
				title();
				printf("\n\n\t\t\t\t * OPPS! YOU HAVE ENTERED INVALID CHARACTER");
				valid=0;
				break;
				getch();
		}
	}
	while(valid==0);

}

//definition of cnic creation function
int cnic_create()
{
	system("cls");
	title();
	printf("\n");

	FILE* nad;
	FILE* record;

	printf("\n\n\t\t\t\t     !!!!!!!!!!CNIC CREATION!!!!!!!!!!");
	printf("\n\n\n\n\t\t\t\t  Enter Your File Name (ANY NAME) : ");
	gets(e.filename);
	printf("\n");

	nad=fopen(e.filename,"w");
	record=fopen("RECORD.txt","a");

	// first name
A :
	printf("\n\n\t\t\t\t  FIRST NAME : ");
	gets(e.f_name);

	*(e.f_name+0) = toupper(*(e.f_name+0));

	if(strlen(e.f_name)>20 || strlen(e.f_name)<3)
	{
		printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID NAME\n");
		goto A ;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.f_name); i++)
		{
			if(isalpha(*(e.f_name+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * NAME CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
			goto A ;
		}
	}

	fflush(stdin);

	// last name
a:
	printf("\n\n\t\t\t\t  LAST NAME : ");
	gets(e.l_name);

	*(e.l_name+0) = toupper(*(e.l_name+0));

	if(strlen(e.l_name)>20 || strlen(e.l_name)<3)
	{
		printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID NAME\n");
		goto a;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.l_name); i++)
		{

			if(isalpha(*(e.l_name+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * NAME CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
			goto a;
		}
	}

	fflush(stdin);

	// father name
D :
	printf("\n\n\t\t\t\t  FATHER NAME : ");
	gets(e.father_name);

	*(e.father_name+0) = toupper(*(e.father_name+0));

	if(strlen(e.father_name)>20 || strlen(e.father_name)<3)
	{
		printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID NAME\n");
		goto D;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.father_name); i++)
		{
			if(isalpha(*(e.father_name+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * NAME CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
			goto D ;
		}
	}

	fflush(stdin);

	// Age
	printf("\n\n\t\t\t\t  AGE : ");
	scanf("%d",&e.age);

	if(e.age!=18 && e.age<18)
	{
		printf("\n\n\t\t\t\t  YOU ARE UNDER AGE, AGE LIMIT IS 18 OR ABOVE :(\n");
		ex_it();
	}

	fflush(stdin);

	// phone number
B:
	printf("\n\n\t\t\t\t  PHONE NUMBER : ");
	gets(e.phone_no);

	if(strlen(e.phone_no)>11 || strlen(e.phone_no)!=11)
	{
		printf("\n\t\t\t\t  * INVALID NUMBER\n");
		goto B;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.phone_no); i++)
		{
			if(isdigit(*(e.phone_no+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * NUMBER CONTAIN INVALID CHARACTER\n");
			goto B;
		}
	}

	fflush(stdin);

	// Bay form no
C:
	printf("\n\n\t\t\t\t  BAYFORM NUMBER : ");
	gets(e.bayform_no);

	if(strlen(e.bayform_no)>13 || strlen(e.bayform_no)!=13)
	{
		printf("\n\t\t\t\t  * INVALID NUMBER\n");
		goto C;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.bayform_no); i++)
		{
			if(isdigit(*(e.bayform_no+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * NUMBER CONTAIN INVALID CHARACTER\n");
			goto C;
		}
	}

	fflush(stdin);

	// gender
	do
	{
	E:
		printf("\n\n\t\t\t\t  GENDER [M/F] : ");
		scanf(" %c",&e.gender);

		if(toupper(e.gender)=='M'|| toupper(e.gender)=='F')
		{
			ok=1;
		}

		else
		{
			ok=0;
		}

		if(!ok)
		{
			printf("\n\t\t\t\t  * INVALID ENTRY,ENTER ONLY [M/F]\n");
			goto E;
		}
	}
	while(!ok);

	fflush(stdin);

	// current address
x:
	printf("\n\n\t\t\t\t  CURRENT ADDRESS (CITY NAME) : ");
	gets(e.crnt_address);

	*(e.crnt_address+0) = toupper(*(e.crnt_address+0));

	if(strlen(e.crnt_address)>15 || strlen(e.crnt_address)<4)
	{
		printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID ADDRESS\n");
		goto x ;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.crnt_address); i++)
		{
			if(isalpha(*(e.crnt_address+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * ADDRESS CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
			goto x ;
		}
	}

	fflush(stdin);

	// perment address
n:
	printf("\n\n\t\t\t\t  PERMENENT ADDRESS (CITY NAME) : ");
	gets(e.per_address);

	*(e.per_address+0) = toupper(*(e.per_address+0));

	if(strlen(e.per_address)>15 || strlen(e.per_address)<4)
	{
		printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID ADDRESS\n");
		goto n ;
	}

	else
	{
		int i;

		for(i=0; i<strlen(e.per_address); i++)
		{
			if(isalpha(*(e.per_address+i)))
			{
				valid=1;
			}

			else
			{
				valid=0;
				break;
			}
		}

		if(!valid)
		{
			printf("\n\t\t\t\t  * ADDRESS CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
			goto n ;
		}
	}

	fflush(stdin);

	// date of birth
	printf("\n\n\t\t\t\t  DATE OF BIRTH (YYYYMMDD) : ");
	scanf("%d",&e.birth_date);

	fflush(stdin);

	//date
	int expire_date;

	printf("\n\n\t\t\t\t  DATE (YYYYMMDD) : ");
	scanf("%d",&e.issue_date);

	expire_date = e.issue_date + 100000;

	//filling
	fprintf(nad,"\t\t=================================================\n\t\tPAKISTAN (NATIONAL IDENTITY CARD)\n\t\t-----------------------------\n\t\tISLAMIC REPUBLIC OF PAKISTAN\n\n\t\tNAME                              : %s %s\n\n\t\tFATHER NAME                       : %s\n\n\t\tDATE OF BIRTH (YYYYMMDD)          : %d\n\n\t\tIDENTITY NUMBER                   : %s\n\n\t\tGENDER                            :  %c\n\n\t\tISSUE DATE (YYYYMMDD)             : %d\n\n\t\tEXPIRY DATE (YYYYMMDD)            : %d\n\n\t\tCURRENT ADDRESS (CITY NAME)       : %s\n\n\t\tPERMENENT ADDRESS (CITY NAME)     : %s\n\t\t=================================================",e.f_name,e.l_name,e.father_name,e.birth_date,e.bayform_no,e.gender,e.issue_date,expire_date,e.crnt_address,e.per_address);
	fprintf(record,"%s\t%s %s\t%s\t%d\t%c\t%d\t%d\t%s\t%s\n",e.bayform_no,e.f_name,e.l_name,e.father_name,e.birth_date,e.gender,e.issue_date,expire_date,e.crnt_address,e.per_address);

	printf("\n\n\t\t\t\tINFORMATION STORED SUCCESSFULLY IN FINAL NADRA FILE ");
	printf("\n\n\t\t\t\tPRESS ANY KEY TO GO BACK TO MENU....");
	getch();

	fclose(nad);
	fclose(record);

	system("cls");
	menu();

}

// definition of Cnic updation
void cnic_update()
{
	system("cls");
	title();
	printf("\n\n\t\t\t\t     !!!!!!!!!!CNIC UPDATION!!!!!!!!!!");

	FILE *nad;
	FILE *record;
	FILE *temp;

	int result=1,found=0;
	int expire_date,expire_date1;
	char putname;

	record=fopen("RECORD.txt","r");

	if(record==NULL)
	{
		gotoxy(35,15);
		printf("\tRECORD FILE DOES NOT EXIST");

		gotoxy(35,18);

	H :
		printf(" Do You Want To Create NIC File[Y/N] : ");
		scanf(" %c",&putname);

		if(putname=='Y' || putname=='y')
		{
			system("cls");
			fflush(stdin);
			cnic_create();
		}

		else if(putname=='N' || putname=='n')
		{
			system("cls");
			menu();
		}

		else
		{
			printf("\n\t\t\t\t    Enter Only [Y/N]\n\n\n\t\t\t\t   ");
			goto H;
		}
	}

	printf("\n\n Enter Your New File Name : ");
	gets(e1.filename);

	nad=fopen(e1.filename,"w");

	printf("\n Enter The CNIC To Update : ");
	gets(e1.bayform_no);
	fflush(stdin);

	temp=fopen("temp.txt","w");

	while(fscanf(record,"%s\t%s %s\t%s\t%d\t%c\t%d\t%d\t%s\t%s\n",e.bayform_no,e.f_name,e.l_name,e.father_name,&e.birth_date,&e.gender,&e.issue_date,&expire_date,e.crnt_address,e.per_address)!=EOF)
	{
		if(strcmp(e.bayform_no,e1.bayform_no)==0)
		{
			found=1;

			gotoxy(15,16);
			printf("EXISTING RECORD!");
			printf("\n=============================================================");
			gotoxy(1,19);
			printf("IDENTITY NUMBER");
			gotoxy(1,21);
			printf("FULL NAME");
			gotoxy(1,23);
			printf("FATHER NAME");
			gotoxy(1,25);
			printf("DATE OF BIRTH (YYYYMMDD)");
			gotoxy(1,27);
			printf("GENDER");
			gotoxy(1,29);
			printf("DATE OF ISSUE (YYYYMMDD)");
			gotoxy(1,31);
			printf("DATE OF EXPIRY (YYYYMMDD)");
			gotoxy(1,33);
			printf("CURRENT ADDRESS (CITY NAME)");
			gotoxy(1,35);
			printf("PERMENENT ADDRESS (CITY NAME)");

			gotoxy(32,19);
			printf(": %s",e.bayform_no);
			gotoxy(32,21);
			printf(": %s %s",e.f_name,e.l_name);
			gotoxy(32,23);
			printf(": %s",e.father_name);
			gotoxy(32,25);
			printf(": %d",e.birth_date);
			gotoxy(32,27);
			printf(": %c",e.gender);
			gotoxy(32,29);
			printf(": %d",e.issue_date);
			gotoxy(32,31);
			printf(": %d",expire_date);
			gotoxy(32,33);
			printf(": %s",e.crnt_address);
			gotoxy(32,35);
			printf(": %s",e.per_address);
			printf("\n=============================================================\n\n");

			printf("\n\t\t\t\t  UPDATE YOUR RECORD BELOW");
			printf("\n\t\t\t\t  ________________________\n");

			// first name
		A :
			printf("\n\n\t\t\t\t  FIRST NAME : ");
			gets(e1.f_name);

			*(e1.f_name+0) = toupper(*(e1.f_name+0));

			if(strlen(e1.f_name)>20 || strlen(e1.f_name)<3)
			{
				printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID NAME\n");
				goto A ;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.f_name); i++)
				{
					if(isalpha(*(e1.f_name+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * NAME CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
					goto A ;
				}
			}

			fflush(stdin);

			// last name
		a:
			printf("\n\n\t\t\t\t  LAST NAME : ");
			gets(e1.l_name);

			*(e1.l_name+0) = toupper(*(e1.l_name+0));

			if(strlen(e1.l_name)>20 || strlen(e1.l_name)<3)
			{
				printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID NAME\n");
				goto a;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.l_name); i++)
				{
					if(isalpha(*(e1.l_name+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * NAME CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
					goto a;
				}
			}

			fflush(stdin);

			// father name
		D :
			printf("\n\n\t\t\t\t  FATHER NAME : ");
			gets(e1.father_name);

			*(e1.father_name+0) = toupper(*(e1.father_name+0));

			if(strlen(e1.father_name)>20 || strlen(e1.father_name)<3)
			{
				printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID NAME\n");
				goto D;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.father_name); i++)
				{
					if(isalpha(*(e1.father_name+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * NAME CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
					goto D ;
				}
			}

			fflush(stdin);

			// Age
			printf("\n\n\t\t\t\t  AGE : ");
			scanf("%d",&e1.age);

			if(e1.age!=18 && e1.age<18)
			{
				printf("\n\n\t\t\t\t  YOU ARE UNDER AGE, AGE LIMIT IS 18 OR ABOVE :(\n");
				ex_it();
			}

			fflush(stdin);

			// phone number
		B:
			printf("\n\n\t\t\t\t  PHONE NUMBER : ");
			gets(e1.phone_no);

			if(strlen(e1.phone_no)>11 || strlen(e1.phone_no)!=11)
			{
				printf("\n\t\t\t\t  * INVALID NUMBER\n");
				goto B;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.phone_no); i++)
				{
					if(isdigit(*(e1.phone_no+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * NUMBER CONTAIN INVALID CHARACTER\n");
					goto B;
				}
			}

			fflush(stdin);

			// Bay form no
		C:
			printf("\n\n\t\t\t\t  BAYFORM NUMBER : ");
			gets(e1.bayform_no);

			if(strlen(e1.bayform_no)>13 || strlen(e1.bayform_no)!=13)
			{
				printf("\n\t\t\t\t  * INVALID NUMBER\n");
				goto C;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.bayform_no); i++)
				{
					if(isdigit(*(e1.bayform_no+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * NUMBER CONTAIN INVALID CHARACTER\n");
					goto C;
				}
			}

			fflush(stdin);

			// gender
			do
			{
			E:
				printf("\n\n\t\t\t\t  GENDER [M/F] : ");
				scanf(" %c",&e1.gender);

				if(toupper(e1.gender)=='M'|| toupper(e1.gender)=='F')
				{
					ok=1;
				}

				else
				{
					ok=0;
				}

				if(!ok)
				{
					printf("\n\t\t\t\t  * INVALID ENTRY,ENTER ONLY [M/F]\n");
					goto E;
				}
			}
			while(!ok);

			fflush(stdin);

			// current address
		x:
			printf("\n\n\t\t\t\t  CURRENT ADDRESS (CITY NAME) : ");
			gets(e1.crnt_address);

			*(e1.crnt_address+0) = toupper(*(e1.crnt_address+0));

			if(strlen(e1.crnt_address)>15 || strlen(e1.crnt_address)<4)
			{
				printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID ADDRESS\n");
				goto x ;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.crnt_address); i++)
				{
					if(isalpha(*(e1.crnt_address+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * ADDRESS CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
					goto x ;
				}
			}

			fflush(stdin);

			// perment address
		n:
			printf("\n\n\t\t\t\t  PERMENENT ADDRESS (CITY NAME) : ");
			gets(e1.per_address);

			*(e1.per_address+0) = toupper(*(e1.per_address+0));

			if(strlen(e1.per_address)>15 || strlen(e1.per_address)<4)
			{
				printf("\n\t\t\t\t  * YOU HAVE ENTERED INVALID ADDRESS\n");
				goto n ;
			}

			else
			{
				int i;

				for(i=0; i<strlen(e1.per_address); i++)
				{
					if(isalpha(*(e1.per_address+i)))
					{
						valid=1;
					}

					else
					{
						valid=0;
						break;
					}
				}

				if(!valid)
				{
					printf("\n\t\t\t\t  * ADDRESS CONTAIN INVALID CHARACTER OR YOU HAVE TAKEN SPACE BETWEEN THE TWO WORDS\n");
					goto n ;
				}
			}

			fflush(stdin);

			// date of birth
			printf("\n\n\t\t\t\t  DATE OF BIRTH (YYYYMMDD) : ");
			scanf("%d",&e1.birth_date);

			fflush(stdin);

			//date
			int expire_date;

			printf("\n\n\t\t\t\t  DATE (YYYYMMDD) : ");
			scanf("%d",&e1.issue_date);

			expire_date1 = e1.issue_date + 100000;

			fprintf(nad,"\t\t=================================================\n\t\tPAKISTAN (NATIONAL IDENTITY CARD)\n\t\t-----------------------------\n\t\tISLAMIC REPUBLIC OF PAKISTAN\n\n\t\tNAME                              : %s %s\n\n\t\tFATHER NAME                       : %s\n\n\t\tDATE OF BIRTH (YYYYMMDD)          : %d\n\n\t\tIDENTITY NUMBER                   : %s\n\n\t\tGENDER                            :  %c\n\n\t\tISSUE DATE (YYYYMMDD)             : %d\n\n\t\tEXPIRY DATE (YYYYMMDD)            : %d\n\n\t\tCURRENT ADDRESS (CITY NAME)       : %s\n\n\t\tPERMENENT ADDRESS (CITY NAME)     : %s\n\t\t=================================================",e1.f_name,e1.l_name,e1.father_name,e1.birth_date,e1.bayform_no,e1.gender,e1.issue_date,expire_date1,e1.crnt_address,e1.per_address);
			fprintf(temp,"%s\t%s %s\t%s\t%d\t%c\t%d\t%d\t%s\t%s\n",e1.bayform_no,e1.f_name,e1.l_name,e1.father_name,e1.birth_date,e1.gender,e1.issue_date,expire_date1,e1.crnt_address,e1.per_address);
		}

		else
		{
			fprintf(temp,"%s\t%s %s\t%s\t%d\t%c\t%d\t%d\t%s\t%s\n",e.bayform_no,e.f_name,e.l_name,e.father_name,e.birth_date,e.gender,e.issue_date,expire_date,e.crnt_address,e.per_address);
		}
	}

	fclose(temp);
	fclose(record);
	fclose(nad);

	if(!found)
	{
		remove("temp.txt");
		gotoxy(36,17);
		printf("Record Not Found!\n\n");
		gotoxy(28,19);
		printf("PRESS ANY KEY TO GO BACK TO MENU....");
		getch();
		system("cls");
		menu();
	}

	else
	{
		remove("RECORD.txt");
		rename("temp.txt","RECORD.txt");
		printf("\n\n\t\t\t\tINFORMATION UPDATED SUCCESSFULLY IN FINAL NADRA FILE ");
		printf("\n\n\t\t\t\tPRESS ANY KEY TO GO BACK TO MENU....");
		getch();
		system("cls");
		menu();
	}

}

// definition of Cnic verification
void cnic_verification()
{
	system("cls");
	title();

	FILE *record;
	record = fopen("RECORD.txt","r");

	char CNIC1[20];
	int date,expire_date,valid=0;

	printf("\n\n\t\t\t\t    !!!!!!!!!!CNIC VERIFICATION!!!!!!!!!!");
	printf("\n\n\n\n\t\t\t\tENTER THE CNIC NUMBER TO VERIFY : ");
	scanf("%s",CNIC1);
	fflush(stdin);

	while(fscanf(record,"%s\t%s %s\t%s\t%d\t%c\t%d\t%d\t%s\t%s\n",e.bayform_no,e.f_name,e.l_name,e.father_name,&e.birth_date,&e.gender,&e.issue_date,&expire_date,e.crnt_address,e.per_address)!=EOF)
	{
		if(strcmp(e.bayform_no,CNIC1)==0)
		{
			valid=1;
			printf("\n\n\t\t\t\tEnter The Current Date (YYYYMMDD) : ");
			scanf("%d",&date);

			if(date<=expire_date)
			{
				printf("\n\n\t\t\t\tYOUR CNIC IS VALID.\n\n\n\n");
			}

			else
			{
				printf("\n\n\t\t\t\tYOUR CNIC HAS BEEN EXPIRED.\n\n\n\n");
			}
		}
	}

	if(!valid)
	{
		gotoxy(35,15);
		printf("\n\n\t\t\t\t\t  Record Not Found!\n\n\n\n");
	}

	fclose(record);
	printf("\t\t\t\t  PRESS ANY KEY TO GO BACK TO MENU....");
	getch();
	system("cls");
	menu();
}

// definition of Search Record
void search_record()
{
	title();

	FILE *record;
	record = fopen("RECORD.txt","r");

	char Search_CNIC[20];
	int expire_date;

	printf("\n\n\t\t\t\t     !!!!!!!!!!SEARCH RECORD!!!!!!!!!!");
	printf("\n\n\n\nENTER YOUR CNIC NUMBER TO CHECK YOUR RECORD : ");
	scanf("%s",&Search_CNIC);
	fflush(stdin);

	while(fscanf(record,"%s\t%s %s\t%s\t%d\t%c\t%d\t%d\t%s\t%s\n",e.bayform_no,e.f_name,e.l_name,e.father_name,&e.birth_date,&e.gender,&e.issue_date,&expire_date,e.crnt_address,e.per_address)!=EOF)
	{
		if(strcmp(Search_CNIC,e.bayform_no)==0)
		{
			printf("\n=============================================================");
			gotoxy(1,15);
			printf("IDENTITY NUMBER");
			gotoxy(1,17);
			printf("FULL NAME");
			gotoxy(1,19);
			printf("FATHER NAME");
			gotoxy(1,21);
			printf("DATE OF BIRTH (YYYYMMDD)");
			gotoxy(1,23);
			printf("GENDER");
			gotoxy(1,25);
			printf("DATE OF ISSUE (YYYYMMDD)");
			gotoxy(1,27);
			printf("DATE OF EXPIRY (YYYYMMDD)");
			gotoxy(1,29);
			printf("CURRENT ADDRESS (CITY NAME)");
			gotoxy(1,31);
			printf("PERMENENT ADDRESS (CITY NAME)");

			gotoxy(32,15);
			printf(": %s",e.bayform_no);
			gotoxy(32,17);
			printf(": %s %s",e.f_name,e.l_name);
			gotoxy(32,19);
			printf(": %s",e.father_name);
			gotoxy(32,21);
			printf(": %d",e.birth_date);
			gotoxy(32,23);
			printf(": %c",e.gender);
			gotoxy(32,25);
			printf(": %d",e.issue_date);
			gotoxy(32,27);
			printf(": %d",expire_date);
			gotoxy(32,29);
			printf(": %s",e.crnt_address);
			gotoxy(32,31);
			printf(": %s",e.per_address);
			printf("\n=============================================================\n\n");
			break;
		}

	}

	if(strcmp(Search_CNIC,e.bayform_no)!=0)
	{
		gotoxy(35,15);
		printf("\n\n\t\t\t\t\tRecord Not Found!\n\n");
	}

	fclose(record);
	printf("\t\t\t\tPRESS ANY KEY TO GO BACK TO MENU....");
	getch();
	system("cls");
	menu();

}

// definition of exit function
void ex_it()
{
	printf("\n\n\t\t\t\t  THANKS FOR VISTING US\n");
	printf("\n\t\t\t\t  PRESS ANY KEY TO TERMINATE PROGRAM...\n");
	exit(0);
}
