#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// COLOUR CODE FOR FORMATTING OUTPUT.
#define BRED "\033[1;31m" 
#define BYELLOW "\033[01;33m"
#define BCYAN "\033[1;36m"
#define CYAN "\033[0;36m"
#define BLINK "\033[5;32;40m"
#define BGREEN "\033[1;32m"
#define BMAGENTA "\033[1;35m"
#define BBLUE "\033[1;34m"
#define RESET "\033[0m"
 
// MAIN STRUCTURE TO STORE DETAILS INTO FILE.
struct alumni
{
	char name[20],email[50],edu[150];
	int admno,yr;
	char mob[10];
	char password[50];
}ob,temp,check;


int maintenance();
int search();
int reports();
int newreg();
void mainmenu();
void modify();
void putdata();
void notifications();
void doesnotexist();
void heading();
void changecase(char n[50],char str[50]);
void gotoxy(int x,int y);

int i;
char key;
FILE *p1;
FILE *p2;
FILE *p3;	

int main()
{
	int ch1,ch,a,f=0;	
	char pass[50],p;

	// WELCOME MENU.	
	system("clear");
	printf("\n\n\n\n\n\t\t\t\t#########################################################################\n");
	printf("\n\n\t\t\t\t\t\t");
	printf(BRED);
	printf("\t  THE PUBLIC SCHOOL\n\t\t\t\t\t\t\t\tKOCHI\n\n");
	printf(BYELLOW);
  	printf("\n\n");
  	printf("\t\t\t\t\t    **      *        *     *  *     *  *    *  * \n ");
  	printf("\t\t\t\t\t   *  *     *        *     *  * * * *  * *  *  * \n");
  	printf("\t\t\t\t\t  *    *    *        *     *  *  *  *  *  * *  * \n");
  	printf("\t\t\t\t\t ********   *        *     *  *     *  *   **  * \n");
  	printf("\t\t\t\t\t*        *  * * * *   * * *   *     *  *    *  * \n");
	printf(RESET);
	printf("\n\n\n\t\t\t\t#########################################################################\n");
	gotoxy(60,25);
	printf(BYELLOW);		
	printf("\" STAY CONNECTED \"");
	printf(RESET);
	scanf("%c",&key);
	
	//SUB MENU	
	do
	{
	system("clear");
	gotoxy(25,4);
	for(i=0;i<89;i++)
	printf(".");
	printf(BGREEN);
	gotoxy(50,6);
	printf("WELCOME TO THE PUBLIC SCHOOL ALUMNI\n");
	//gotoxy(50,7);
	//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n\n\t\t\t\t\t\t");
	printf(CYAN);
	gotoxy(27,12);
	printf("\" LET US ALWAYS MEET EACH OTHER WITH A SMILE, FOR THE SMILE IS THE BEGINNING OF LOVE \"");
	gotoxy(65,13);
	printf("-Mother Teressa\n");
	printf(RESET);
	gotoxy(25,18);
	printf("1. New member.\n");
	gotoxy(25,19);
	printf("2. Existing member.\n");
	gotoxy(25,30);
	for(i=0;i<89;i++)
	printf(".");
	gotoxy(25,32);
	printf(BMAGENTA);
	printf("ADMINISTRATION");
	//printf(RESET);
	gotoxy(25,34);
	printf("Co-ordinator : Abhirami A");
	gotoxy(25,21);
	printf(RESET);
	printf("Enter your choice :: ");
	scanf("%d",&ch);
	if(ch==1)
	 newreg();
	else if(ch==2)
	{
	   system("clear");
	   printf("\n\n\t\t");
	   gotoxy(25,4);
	   gotoxy(60,10);
	   printf(BCYAN);
	   printf("LOGIN");
	   gotoxy(60,11);
	   printf("~~~~~~");
	   printf(RESET);
	   gotoxy(30,15);
	   printf("Enter admission number  : ");
	   scanf("%d",&a);
	   gotoxy(30,16);
	   printf("Enter password          : ");
	   scanf("%s",pass);
	   p1= fopen("alumni.txt","r");
	   p2= fopen("password.txt","r");
   	   while(fread(&ob,sizeof(ob),1,p1)==1)
  	   {
	    if(a==ob.admno)
	    {
	     while(fread(&ob,sizeof(ob),1,p2)==1)
	     {
	     if(strcmp(pass,ob.password)==0)
	     {
	     fclose(p1);
	     fclose(p2);
	     f=1;
	     mainmenu();
	     }
	     }
	    }
	   }
	    if(f==0)
	     {
		gotoxy(30,20);
		printf(BRED);
		printf("Incorrect password or admission no.!!");
		printf(RESET);
		scanf("%*c%c",&key);
		//break;
	     }
			
	    
	   fclose(p1);
	 }
	else 
	{
	 gotoxy(25,27);
	 printf(BRED);
	 printf("INVALID CHOICE!!");
	 printf(RESET);
	 scanf("%*c%c",&key);
	 
	}
	}while(1);
}
	

	
// MAIN MENU.
void mainmenu()
{	
	int ch1;
	do
	{
	system("clear");
	printf("\n\n\n\n");
	printf(BYELLOW);
	gotoxy(60,6);
	printf("THE PUBLIC SCHOOL");
	gotoxy(66,8);
	printf("KOCHI");
	printf(BGREEN);
	gotoxy(59,11);
   	printf("ALUMNI ASSOCIATION\n\n\n");
	printf(BBLUE);
   	printf("\t\t1.Notifications\n\n\t\t2.Search\n\n\t\t3.Reports\n\n\t\t4.Maintenance\n\n\t\t5.Exit\n\n");
	printf(RESET);
   	printf("\n\n\t\tEnter your choice :: ");
   	scanf("%d",&ch1); 
	switch(ch1)
   	{
    	 case 1:notifications();
	   break;
    	 case 2:search();
	   break;
    	 case 3:reports();
	   break;
    	 case 4:maintenance();
	   break;
    	 case 5:system("clear");
	        printf(BRED);
	        printf("\n\n\t\tEXITING...\n\n\n\n");
	        printf(RESET);
	        scanf("%c",&key);
	        exit(0);
    	 default:
		 printf(BRED);
		 printf("\n\n\t\tINVALID CHOICE!!");
		 scanf("%*c%c",&key);
		 printf(RESET);
	  	

   	}
	
	}while(1);
	
}

int newreg()
{
	
	system("clear");
   	printf(BYELLOW);
   	printf("\n\n\n\n\t\t\t\t\t\t\tNEW REGISTRATION\n\n");
	printf("\t\t");
	printf(RESET);
	for(i=0;i<100;i++)
	 printf("#");
	printf("\n\n\n");
	p1=fopen("alumni.txt","a");
	p2=fopen("alumni.txt","r");
	p3=fopen("password.txt","a");

	// ACCEPTING DETAILS.
	printf(BBLUE);
	printf("\t\tEnter admission no.             : ");
	printf(RESET);  
   	 scanf("%d",&ob.admno);fflush(stdin);
	while(fread(&check,sizeof(check),1,p2)==1)
	{
	  if(ob.admno==check.admno)
	  {
	   printf(BRED);
	   printf("\n\n\t\tMember with the admission no. already exist !!");
	   printf("\n\n\t\tRegistration failed !!");
	   printf(RESET);
	   scanf("%*c%c",&key);
	   fclose(p2);
	   fclose(p1);
	   return;
	  }
	}
	printf(BBLUE);
	printf("\t\tEnter name                      : ");  
	printf(RESET);  
	scanf(" %[^\n]",ob.name);fflush(stdin);
	printf(BBLUE);
	printf("\t\tEnter email id                  : ");
	printf(RESET);  
   	 scanf("%s",ob.email);fflush(stdin);
	printf(BBLUE);
	printf("\t\tEnter mobile no.                : ");
	printf(RESET);  
   	 scanf("%s",ob.mob);fflush(stdin);
	printf(BBLUE);
	printf("\t\tEnter present educational status: ");
	printf(RESET);  
   	 scanf(" %[^\n]",ob.edu);fflush(stdin);
	printf(BBLUE);
	printf("\t\tEnter year of passing out       : ");
	printf(RESET);  
   	 scanf("%d",&ob.yr);fflush(stdin);
	fwrite(&ob,sizeof(ob),1,p1);
	fclose(p1);
	
	printf(BBLUE);
	printf("\n\n\t\tSet password		        : ");
	printf(RESET);  
   	 scanf(" %s",ob.password);fflush(stdin);
	fwrite(&ob,sizeof(ob),1,p3);
	fclose(p3);
	
	printf(BGREEN);
	printf(BLINK);
	printf("\n\n\t\tSuccessfully Registered!!");
	printf(RESET);
	
	gotoxy(18,40);
	printf(BYELLOW);
	printf("NOTE : Do not forget your admission number and password.");
	printf(RESET);
	scanf("%*c%c",&key);
	return 1;

}

//FUNCTION DISPLAYING NOTIFICATIONS
void notifications()
{
	system("clear");
	printf(BYELLOW);
	gotoxy(30,6);
   	printf("NOTIFICATIONS");
	printf("\t\t");
	printf(RESET);
	gotoxy(30,8);
	printf("1. Reunion of 2011-12 batch on September 12, 2019 at school.");
	gotoxy(30,10);
	printf("2. Seminar for class X students on Cyber Security will be conducted on 12-7-2019 by alumni."); 
	gotoxy(30,30);
	printf("Press any key to continue.");
	scanf("%*c%c",&key);
}
	

// FUNCTION TO PERFORM SEARCH OPERATION.
int search()
{
	system("clear");
 	int a,f=0,ch2;
 	char n[50],c,str[50];
	
	do
	{
	system("clear");
 	printf(BYELLOW);
   	printf("\n\n\n\n\t\t\t\t\t\t\t\tSEARCH\n\n");
	printf("\t\t");
	printf(RESET);
	for(i=0;i<100;i++)
	 printf("#");
	printf("\n\n\n");
	printf(BBLUE);
 	printf("\t\tSearch based on ::\n\n\t\t1.Admission No.\n\n\t\t2.Name\n\n\t\t3.Back to main menu");
	printf(RESET);
 	printf("\n\n\n\t\tEnter your choice :: ");
 	scanf("%d",&ch2);
	if (ch2==3)
 	 {
   	  return 0;
 	 }

	// SEARCH BASED ON ADMISSION NUMBER.
 	else if(ch2== 1)
 	 {
	   system("clear");
   	   printf("\n\t\tEnter the admission number to be searched :: ");
   	   scanf("%d",&a);
   	   p1= fopen("alumni.txt","r");
   	   if(!p1)
  	    doesnotexist();
	   printf("\n\n");
	   heading();
   	   while(fread(&ob,sizeof(ob),1,p1)==1)
  	   {
	    if(a==ob.admno)
	    {
	     f=1;
	     putdata();
	    
	    }
	   }

   	  
	if(f==0)
	{
	 printf(BRED);
	 printf("\n\n\t\tRECORD NOT FOUND !!");
	 printf(RESET);
	}

	    fclose(p1);
	    printf("\n\n\t\tPress any key to continue.");
	    scanf("%*c%c",&key);
	}

	// SEARCH BASED ON NAME.
 	else if(ch2== 2)
	 {
	   int f=0;
	   system("clear");
	   printf("\n\n\t\tEnter the name to be searched :: ");
	   scanf(" %[^\n]",n);
	   p1=fopen("alumni.txt","r");
	   if(!p1)
	     doesnotexist();
	printf("\n\n");
	heading();
	
	while(fread(&ob,sizeof(ob),1,p1)==1)
	{

	  strcpy(str,ob.name);
	  changecase(n,str);
	  if(strcmp(n,str)==0)
	  {
	    f=1;
	    putdata();
	  }
	  
	}

	if(f==0)
	{
	 printf(BRED);
	 printf("\n\n\t\tRECORD NOT FOUND !!");
	 printf(RESET);
	}

	    fclose(p1);
	    printf("\n\n\t\tPress any key to continue.");
	    scanf("%*c%c",&key);
	}

	if(ch2>3)
	{
	 printf(BRED);
	 printf("\n\t\tINVALID CHOICE!!");
	 printf(RESET);
	 scanf("%*c%c",&key);
	}
	}while(1);
	
}

// FUNCTION TO DISPLAY DETAILS.
int reports()
{
	int ch2,f=0;  
	int year;char qual[80],str[50];
 	do
 	{
  	  system("clear");
	  printf(BYELLOW);
   	  printf("\n\n\n\n\t\t\t\t\t\t\t\tREPORTS\n\n");
	  printf("\t\t");
	  printf(RESET);
	  for(i=0;i<100;i++)
	    printf("#");
	  printf("\n\n\n");

	  printf(BBLUE);	
 	  printf("\n\n\n\t\t1.Display all details\n\n\t\t2.Display alumni of a particular year\n\n\t\t3.Display alumni based on qualification\n\n\t\t4.Back to main menu\n");
	  printf(RESET);
	  printf("\n\n\n\t\tEnter your choice :: ");
  	  scanf("%d",&ch2);

	  p1=fopen("alumni.txt","r");
	   if(!p1)
	     doesnotexist();

	 // DISPLAYING ALL DETAILS.
  	 if(ch2==1)
  	  {
	    system("clear");
	    printf(BYELLOW);
	    printf("\n\n\n\t\tALL MEMBERS\n");
	    printf(RESET);
	    heading();
  	    while(fread(&ob,sizeof(ob),1,p1)==1)
  	    {
	      f=1;
	      putdata();
	      
	    }
	    if(f==0)
		{
		 printf(BRED);
		 printf("\n\n\t\tRECORD NOT FOUND !!");
		 printf(RESET);
		}
	    fclose(p1);
	    printf("\n\n\t\tPress any key to continue.");
	    scanf("%*c%c",&key);
	  }
	  
	// DISPLAYING ALUMNI OF A PARTICULAR YEAR.
  	else if(ch2==2)
  	{
	  f=0;
   	  system("clear");
   	  printf("\n\n\t\tEnter the year of passing out ::");
    	  scanf("%d",&year);
	  printf(BYELLOW);
	  printf("\n\t\tALUMNI OF %d\n",year);
	  printf(RESET); 
	  heading();
  	   while(fread(&ob,sizeof(ob),1,p1)==1)
  	    {
	      if(year==ob.yr)
	      {
	       f=1;
	       putdata();
	      }  
	    }

	  if(f==0)
	   {
            printf(BRED);
	    printf("\n\n\t\tRECORD NOT FOUND !!");
	    printf(RESET);
           }
	  fclose(p1);
	  printf("\n\n\t\tPress any key to continue.");
	  scanf("%*c%c",&key);
	 }
	
	// DISPLAYING ALUMNI BASED ON QUALIFICATION.
	else if(ch2==3)
  	{
	 f=0;
   	 system("clear");
   	 printf("\n\n\t\tEnter education qualification :: ");
    	 scanf(" %[^\n]",qual);
	 printf(BYELLOW);
	 printf("\n\t\tALUMNI WITH %s\n",qual);
	 printf(RESET);
	 heading();
  	  while(fread(&ob,sizeof(ob),1,p1)==1)
  	    {
	      strcpy(str,ob.edu);
	      changecase(qual,str);
	      if(strcmp(qual,str)==0)
	      {
	       f=1;
	       putdata();
	      }  
	    }

	  if(f==0)
		{
		 printf(BRED);
		 printf("\n\n\t\tRECORD NOT FOUND !!");
		 printf(RESET);
		}
	  fclose(p1);
	  printf("\n\n\t\tPress any key to continue.");
	  scanf("%*c%c",&key);
	 }
	

	if (ch2==4)
 	 {
   	  return 0;
 	 }

	if(ch2>=4)
	{
	 printf(BRED);
	 printf("\n\t\tINVALID CHOICE!!");
	 printf(RESET);
	 scanf("%*c%c",&key);
	}
	
      }while(1);
}

// FUNCTION TO MAINTAIN RECORDS - DELETE,MODIFY.
int maintenance()
 {
	  long pos;
	  int ch2,flag=0,ano;
          system("clear");
          do
	  {
	    system("clear");
	    printf(BYELLOW);
   	    printf("\n\n\n\n\t\t\t\t\t\t\t\tMAINTENANCE\n\n");
	    printf("\t\t");
	    printf(RESET);
	    for(i=0;i<100;i++)
	     printf("#");
	    printf("\n\n\n");
	    printf(BBLUE);
	    printf("\n\n\t\t1.Modify\n\n\t\t2.Delete\n\n\t\t3.Back to main menu");
	    printf(RESET);
	    printf("\n\n\t\tEnter your choice :: ");
	    scanf("%d",&ch2);
	  
	   // MODIFYING.
	   if(ch2==1)
	    {
		    flag=0;
		    system("clear");
		    printf("\n\n\t\tEnter your admission no. ::");
		    scanf("%d",&ano);
		    p1=fopen("alumni.txt","r");
		    p2=fopen("temp.txt","a");
		    if(!p1)
		     doesnotexist();

		    while(fread(&ob,sizeof(ob),1,p1))
		    {
		     if(ano!=ob.admno)
		     {
		      fwrite(&ob,sizeof(ob),1,p2);
		     }
		     else
		     {
		      modify();
		      flag=1;
		      fwrite(&ob,sizeof(ob),1,p2);
		     }
	    }
	     fclose(p1);
	     fclose(p2);
	     remove("alumni.txt");
	     rename("temp.txt","alumni.txt");
	     if(flag==1)
	     {
	      printf(BGREEN);
	      printf("\n\n\t\tRecord modified successfully!!");
	      printf(RESET);
	     }
	     else
	     {
	      printf(BRED);
	      printf("\n\n\t\tInvalid admission no.!!");
	      printf(RESET);
	     }
	     scanf("%*c%c",&key);
	   }

	   //DELETING.
	   if(ch2==2)
	   {
		    system("clear");
		    flag=0;
	    	    printf("\n\n\t\tEnter the admission no. ::");
		    scanf("%d",&ano);
		    p1=fopen("alumni.txt","r");
		    p2=fopen("temp.txt","a");
		    if(!p1)
		      doesnotexist();

		    while(fread(&ob,sizeof(ob),1,p1))
		    {
		     if(ano!=ob.admno)
		      fwrite(&ob,sizeof(ob),1,p2);
		     else
		      flag=1;
		    }
		    fclose(p1);
		    fclose(p2);
		     remove("alumni.txt");
		     rename("temp.txt","alumni.txt");
		    if(flag==0)
		    {
		     printf(BRED);
	             printf("\n\n\t\tInvalid admission no.!!");
	             printf(RESET);
		    }
		    else
		    {
		     printf(BYELLOW);
		     printf("\n\n\t\tRecord Deleted!!");
		     printf(RESET);
		    }
		     scanf("%*c%c",&key);
	   }

	  if(ch2==3)
	    return 0;

	  if(ch2>=4)
	  {
	  printf(BRED);
	  printf("\n\t\tINVALID CHOICE!!");
	  printf(RESET);
	  scanf("%*c%c",&key);
	  }

	 }while(1);
}

//FUNCTION TO MODIFY DEATILS.
void modify()
{
	
	 printf(BBLUE);
	 printf("\n\t\tPresent details:\n");
	 printf("\t\t");
         for(i=0;i<80;i++)
	   printf("-");
	 printf("\n\n");	
         printf("\n\n\t\tName                              :");
         puts(ob.name);
         printf("\t\tAdmission No.                     :%d",ob.admno);
         printf("\n\t\tEmail Id                          :");
         puts(ob.email);
         printf("\t\tMobile No.                        :%s",ob.mob);
         printf("\n\t\tEducational status                :");
         puts(ob.edu);
         printf("\t\tYear of passing out               :%d\n\n",ob.yr);
         printf(RESET);
	 
	 //ACCEPTING DETAILS TO BE MODIFIED.
	 printf("\n\n\t\tModify your details:\n ");
	 printf("\t\t");
	 for(i=0;i<80;i++)
	   printf("-");
	 printf("\n\n");	
	 printf("\t\tPress 1 to retain old details\n\n");
	 printf("\t\tName		    		 :");fflush(stdin);
	 scanf(" %[^\n]",temp.name);fflush(stdin);
	 printf("\t\tAdmission no.       		 :");fflush(stdin);
	 scanf("%d",&temp.admno);fflush(stdin);
	 printf("\t\tEmail id	    		 :");
	 scanf("%s",temp.email);fflush(stdin);fflush(stdin);
	 printf("\t\tMobile no.          		 :");
	 scanf("%s",temp.mob);fflush(stdin);
	 printf("\t\tEducational status  		 :");
	 scanf("%s",temp.edu);fflush(stdin);
	 printf("\t\tYear of passing out 		 :");
	 scanf("%d",&temp.yr);

	 //COPYING MODIFIED DETAILS
	 if(strcmp(temp.name,"1")!=0)
	     strcpy(ob.name,temp.name);
	 if(temp.admno!=1)
	     ob.admno=temp.admno;
	 if(strcmp(temp.email,"1")!=0)
	     strcpy(ob.email,temp.email);
	 if(strcmp(temp.mob,"1")!=0)
	     strcpy(ob.mob,temp.mob);
	 if(strcmp(temp.edu,"1")!=0)
             strcpy(ob.edu,temp.edu);
	 if(temp.yr!=1)
	     ob.yr=temp.yr;
	     // scanf("%*c%c",&key);
 }


// FUNCTION TO DISPLAY STORED DATA.
void heading()
{
	
        gotoxy(5,6);
	printf("\t\t============================================================================================");
	gotoxy(5,7);
	printf(BCYAN);
	printf("\t\tName\t\tAdmno.\t\tEmail Id\t\tMobile No.\tEducation\tYear\n");
	printf(RESET);	
	gotoxy(5,8);
	printf("\t\t============================================================================================\n");
	
} 

void doesnotexist()
{
	system("clear");
	printf("\n\n\t\tFile does not exist !!");
	scanf("%*c%c",&key);
	fclose(p1);
   	return;
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
	

void putdata()
{
	printf(CYAN);
	printf("    \t\t%-10s\t%d\t   %-25s\t%s\t%s\t\t%d\n",ob.name,ob.admno,ob.email,ob.mob,ob.edu,ob.yr);
	printf(RESET);
}

void changecase(char n[50],char str[50])
{
	int c=0;
	while(n[c]!='\0')
	{
	 if(n[c]>='a' && n[c]<='z')
	 {
	   n[c]-=32;
	 }
	 c++;
	}

	c=0;
	while(str[c]!='\0')
	{
	 if(str[c]>='a' && str[c]<='z')
	 {
	   str[c]-=32;
	 }
	 c++;

	}
	
}


