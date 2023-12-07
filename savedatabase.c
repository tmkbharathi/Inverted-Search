#include"main.h"


Status savedatabase(mainnode **hashtable, char *newfname)
{
	printf("INFO: Saving Database...\n");
	FILE *fptr=fopen(newfname,"w");
	if(fptr == NULL)
	{
		printf("ERROR: Error occured while opening newfile\n");
		return FAILURE;
	}
	for(int i=0; i<27; i++)
	{
		mainnode* p=hashtable[i];
		while(p != NULL)
		{
	        fprintf(fptr, "#%d;%s;%d", i, p->word, p->filecount);
			subnode *q=p->sublink;
			while(q != NULL)
			{
				fprintf(fptr, ";%s;%d", q->fname, q->count);	
				q=q->nextsublink;
			}
			fprintf(fptr, "#\n");
			p=p->nextmainlink;
		}
	}

	return SUCCESS;
}
