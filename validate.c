#include"main.h"
#include "types.h"
#include <stdio.h>

Status read_and_validate_args(char **argv, filelist **head){

    printf("INFO: Read and Validate Started\n");
    int i=1;
	FILE* fptr;
	if (argv[1]==NULL)
	{
		printf("INFO: Create database only from update database\n");
		return SUCCESS;
	}
	while(argv[i] != NULL)
	{
		fptr=fopen(argv[i],"r");
		if(fptr!=NULL)
		{
			if(checksize(fptr)==SUCCESS)
			{
				if(insert_at_last(head,argv[i])==DUPLICATE)
				{
					 printf("INFO: %s is duplicated,so not added\n",argv[i]); 
				}
			}
			else
			{
				printf("INFO: %s is filesize is empty\n", argv[i]);
			}
		}
		else
		{
			printf("INFO: %s file is not existing\n", argv[i]);
		}	
		i++;
	}
	return SUCCESS;
}

Status checksize(FILE* fptr){
		fseek(fptr,0,SEEK_END);
		int size=ftell(fptr);
        if(size>1)
			return SUCCESS;
		else
			return FAILURE;
}


void printlist(filelist* head){
	    if(head == NULL)
		{
			printf("INFO: List is empty\n");
			return;
		}
        while(head != NULL)
        {
                printf("%s -> ", head->fname);
                head=head->link;
        }
		printf("NULL\n");
		return;
}

Status insert_at_last(filelist **head, char *file)
{
    filelist *temp = *head;
    while (temp != NULL){
      if (strcmp(temp->fname, file) == 0)
      {
			return DUPLICATE;
      }
      temp=temp->link;
    }

    filelist *new = malloc(sizeof(filelist));
    if (!new)
        {
			    printf("Out of memory\n");
                return FAILURE;
        }

        new->fname=file;
        new->link=NULL;

        if (*head==NULL)
        {
                *head=new;
                return SUCCESS;
        }
        temp= *head;
        while (temp->link != NULL)
        {
                temp=temp->link;
        }
        temp->link=new;
        return SUCCESS;
}
