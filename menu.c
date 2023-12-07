#include "main.h"
#include <stdio.h>

extern int createdflag;
extern int onearg;

Status menu(filelist **head, mainnode *hashtable[])
{
    int option=0;
	char ch;
	printf("MENU:\n\t1.Create database\n\t2.Display database\n\t3.Search database\n\t4.Save database\n\t5.Update database\n\t6.Exit\n");
    do
	{
	printf("RESP: Enter the option: ");
	scanf("%d", &option);
    switch(option)
	{
		case 1:
			   if(onearg == 0)
				{
			   if(createdflag==0)
			   {
			   if(createdatabase(head, hashtable)==FAILURE)
			   {
					printf("ERROR: In Database Creation Failure Occurred\n");
					return FAILURE;
			   }
			   else
				   printf("INFO: Database Created Successfully\n");
			   }
			   else
				   printf("INFO: Already Database created\n");}
			   else
				   printf("ERROR: This option is not available\n");
		       break;
		case 2:
			   displaydatabase(hashtable);
			   break;
		case 3:
			   if(createdflag==1)
			   {
					printf("RESP: Enter the words that want to search: ");
					char searchword[20];
				    scanf("%s", searchword);
				    searchdatabase(hashtable, searchword); 
			   }
			   else
					printf("INFO: Database is empty no words to be search :(\n");
			   break;
		case 4:
			   if(createdflag==1)
			   {
				   printf("RESP: Enter the filename to save: ");
				   char filename[20];
				   scanf("%s", filename);
				   if((strchr(filename,'.')==NULL) || strcmp(strchr(filename,'.'),".txt")!=0)
				   {
						printf("INFO: Extension is missing (.txt is added)\n");
						strcat(filename,".txt");
				   }
				   if(savedatabase(hashtable, filename)==SUCCESS)
					   printf("INFO: Database is succesfully saved to '%s' file\n", filename);
				   else
					   printf("INFO: Savedatabase failure\n");
			   }
			   else
				   printf("INFO: Database is empty, unable to proceed savedatabase\n");
			   break;
		case 5:
			   if(createdflag == 0)
			   {
					char filename[20];
					printf("RESP: Enter the backup filename to make database: ");
					scanf("%s", filename);
				    FILE*fptr =fopen(filename,"r");
					if(fptr != NULL)
					{
						char first=fgetc(fptr);
						fseek(fptr, -2, SEEK_END);
						char last=fgetc(fptr);
						rewind(fptr);
						if(first==last)
						{
							if(updatedatabase(hashtable, fptr)==SUCCESS)
								printf("INFO: Updated Successfully\n");
							else
								printf("ERROR: While updating error occured\n");
						}
					    else
						{
							printf("INFO: File is not an backup file\n");
						}
					}
				    else
					{
						printf("INFO: File not exist\n");
					}
			   }
			   else
			   {
				   printf("INFO: Your database is not empty try again:(\n");
				   exit(0);
			   }
			   break;
		case 6:
			   return SUCCESS;
		default:
				printf("ERROR: Enter the valid option\n");
				exit(0);
	}
			printf("RESP: Do you want to continue(Y/y)? ");
			scanf(" %c", &ch);
	}
    while(ch == 'y' || ch == 'Y');
	return SUCCESS;
}

