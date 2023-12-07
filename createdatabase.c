#include "main.h"

int createdflag=0;
Status createdatabase(filelist **head, mainnode *hashtable[])
{
	createdflag=1;
	char word[20]; int idx;
	FILE* file;
	filelist* p=*head;
    printf("INFO: Creating Database..\n");
	while(p != NULL)
	{
		file=fopen(p->fname,"r");
		while(fscanf(file,"%s",word) != -1)
		{
			if( ('a'<=word[0] && word[0]<='z') || ('A'<=word[0] && word[0]<='Z')) //this condition to find index 0 to 25 for 'a' to 'z' and 'A'to 'z' else are in 26th index
			    idx=tolower(word[0])%97;
			else
				idx=26;

			if(hashtable[idx] == NULL)										//if hashtable null add mainnode and that have one subnode
			{
                mainnode *diffwords = malloc(sizeof(mainnode));
				subnode     *infile = malloc(sizeof(subnode));
				if(!diffwords || !infile)
				{
					printf("Out of memory\n");
					return FAILURE;
				}
		        hashtable[idx]=diffwords;

				diffwords->filecount=1;
				strcpy(diffwords->word,word);
				diffwords->nextmainlink=NULL;
				diffwords->sublink=infile;

				infile->count=1;
			    infile->fname=p->fname;
				infile->nextsublink=NULL;
			}
			else
			{
				int flag1=0;
				mainnode *mt;
				mainnode *mp=mt=hashtable[idx];
			    while(mt != NULL)
				{
					if(strcmp(mt->word,word)==0)
					{
						int flag2=0;
						subnode *st;
						subnode *sp=st=mt->sublink;
						while(st != NULL)
						{
							if(strcmp(st->fname,p->fname)==0)				//in one main node sublink samefile increment the count of words;
							{
								(st->count)++;
								flag1=flag2=1;
								break;
							}
							sp=st;
							st=st->nextsublink;
						}

						if(flag2==0)										//find the mainnode and adding extra sublink for sameword different file
						{
							subnode *news=malloc(sizeof(subnode));
							if(!news)
							{
								printf("Out of memory\n");
								return FAILURE;
							}
							sp->nextsublink=news;
							news->count=1;
							news->fname=p->fname;
							news->nextsublink=NULL;

							(mt->filecount)++;
							flag1=1;
							break;
						}
					}
					mp=mt;
					mt=mt->nextmainlink;
				}
				if(flag1==0)													//different words in same index add in mainnode to nextmainnode
				{
					mainnode *newm=malloc(sizeof(mainnode));
					subnode *newss=malloc(sizeof(subnode));
					if(!newm || !newss)
					{
						printf("Out of memory\n");
						return FAILURE;
					}
					mp->nextmainlink=newm;

					strcpy(newm->word,word);
					newm->filecount=1;
					newm->nextmainlink=NULL;
					newm->sublink=newss;

					newss->fname= p->fname;
					newss->count=1;
					newss->nextsublink=NULL;
				}
			}
		}
		p=p->link;
	}
	/*
	for(int i=0; i<27; i++){
		if(hashtable[i]!=NULL)
		printf("%s\n", (hashtable[i])->word);
	}*/
	return SUCCESS;
}
