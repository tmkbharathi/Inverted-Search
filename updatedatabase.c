#include"types.h"
#include <stdio.h>

extern int createdflag;

Status updatedatabase(mainnode **hashtable, FILE* file)
{
    printf("INFO: Updating Database...\n");
	createdflag=1;
	int index, filecount, wordcount;
	char *word;
	char filename[20];
	char *delims="#;";
	char oneline[50];
	while(fscanf(file,"%s", oneline) != EOF)
	{
			index=atoi(strtok(oneline, delims));	
			word=strtok(NULL, delims);
			filecount=atoi(strtok(NULL, delims));
			mainnode* memp=malloc(sizeof(mainnode));
			strcpy(memp->word,word);
			memp->filecount=filecount;
			memp->nextmainlink=NULL;
			memp->sublink=NULL;
			for(int i=1; i<=filecount; i++)
			{
					strcpy(filename,strtok(NULL,delims));
					wordcount=atoi(strtok(NULL, delims));
					subnode* semp=malloc(sizeof(subnode));
					semp->fname=malloc(strlen(filename) + 1);
					strcpy(semp->fname, filename);
					semp->count=wordcount;
					semp->nextsublink=NULL;
				
					if(memp->sublink == NULL){
						memp->sublink=semp;
					}
					else{
						subnode* st=memp->sublink;
						while(st->nextsublink!=NULL){
							st=st->nextsublink;
						}
						st->nextsublink=semp;
					}
			}
			if(hashtable[index]==NULL)
				hashtable[index]=memp;
			else
			{
				mainnode *tm=hashtable[index];
				while(tm->nextmainlink != NULL)
				{
					tm=tm->nextmainlink;
				}
				tm->nextmainlink=memp;
			}
	}

	return SUCCESS;
}
