#include"main.h"
#include "types.h"
extern int onearg;
int onearg=0;
int main(int argc, char**argv)
{
	filelist* head=NULL;
	mainnode *hashtable[27]={NULL};
	if(argc==1)
	{
		onearg=1;
		printf("INFO: No files passed\n");
	}
	if(read_and_validate_args(argv, &head) == SUCCESS)
		{			
			printf("INFO: Read and Validate Success\n");
			if(head!=NULL)
				printf("INFO: File is included\n");
			else
				printf("INFO: No file is included\n");
				
		    	printlist(head);
				if(menu(&head, hashtable)==SUCCESS)
					printf("INFO: Program Closed Successfully :) \n");
				else
					printf("ERROR: Sorry for Error occured\n");
		}
		else
		{
			printf("INFO: Read and Validate Failure\n");
			return FAILURE;
		} 
	

return 0;
}


