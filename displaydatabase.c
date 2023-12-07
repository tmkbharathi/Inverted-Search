#include"main.h"

extern int createdflag;
void displaydatabase(mainnode **hashtable)
{
    printf("INFO: Displaying Database...\n");
	printf("========================================================================================================\n");
	printf("Index\t   Word\t\t    Filecount\t\tFilename(wordcount)\n");
	printf("========================================================================================================\n");
	
	if(createdflag == 0)
	{
		printf("\n\t\t\t\tDatabase is empty\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
	}

    for(int i=0; i<27; i++)
	{
		if(hashtable[i] != NULL)
		{
			mainnode *mt=hashtable[i];
			while(mt != NULL)
			{
				printf("[%d]\t%-20s\t%d\t", i, mt->word, mt->filecount);
				subnode *st=mt->sublink;
				while(st != NULL)
				{
					printf("\t%s(%d)", st->fname, st->count);
					st=st->nextsublink;
				}
				mt=mt->nextmainlink;
				printf("\n");
			}
				printf("--------------------------------------------------------------------------------------------------------\n");
		}
	}
//	printf("========================================================================================================\n");
}
