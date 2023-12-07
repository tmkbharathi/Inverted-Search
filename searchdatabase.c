#include "main.h"

void searchdatabase(mainnode **hashtable, char*word)
{
	 printf("INFO: Searching in Database...\n");
	 int idx;
	 if( ('a'<=word[0] && word[0]<='z') || ('A'<=word[0] && word[0]<='Z') )
		idx=tolower(word[0])%97;
	 else
		 idx=26;
	 if(hashtable[idx]==NULL)
	 {
		  printf("INFO: The word '%s' is not found in anyfiles\n", word);
	 }
	 else
	 {
		  mainnode *tmp=hashtable[idx];
		  int flag=0;
		  while(tmp != NULL)
		  {
              if(strcmp(tmp->word, word)==0)
			  {
				  flag=1;
				  printf("The word '%s' is found as", word);
				  subnode* tsp=tmp->sublink;
				  while(tsp != NULL)
				  {
                      printf(", %d times in %s", tsp->count, tsp->fname);
					  tsp=tsp->nextsublink;
				  }
				  printf(" => totally in %d files", tmp->filecount);
				  printf("\n");
			  }
			  tmp=tmp->nextmainlink;
		  }
		  if(flag==0)
			   printf("SEARCH: The word '%s' is not found in anyfiles\n", word);
	 }
}

