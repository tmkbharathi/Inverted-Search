#include"types.h"

Status read_and_validate_args(char **, filelist **);

Status insert_at_last(filelist **, char *);

Status checksize(FILE*);

Status menu(filelist** , mainnode**);

Status createdatabase(filelist** , mainnode**);

void displaydatabase(mainnode **);

void searchdatabase(mainnode **, char*);

Status savedatabase(mainnode **, char*);

Status updatedatabase(mainnode **, FILE *);

void printlist(filelist* );
