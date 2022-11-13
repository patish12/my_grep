#include "main.h"

/* 
    parse_arguments() recieves argc and argv and copies the command line
    parameters to the output buffers pattern and filename. 
*/
void parse_arguments(int argc, char *argv[], char* pattern, char* filename)
{
    strcpy(pattern, argv[1]);
    strcpy(filename, argv[2]);
}

/* 
    match_pattern() receives a pattern and filename and goes through every line in 
    the file and searches for the pattern. Upon a match, it prints the entire line 
*/
void match_pattern(char* pattern, char* filename)
{
    FILE *f;
    char line[STR_MAX_SZ];

    f = fopen(filename, "rt");
    if(f==NULL)
    {
        printf("File %s not found", filename);
        return;
    }

    while(!feof(f))
    {
        fgets(line, STR_MAX_SZ, f);
        if(f==NULL)
            break;
        if(strstr(line, pattern))
            printf("%s", line);
    }
    fclose(f);
    
}

/*
    main program entry
*/
int main(int argc, char*argv[])
{
    char filename[STR_MAX_SZ], pattern[STR_MAX_SZ];

    if(argc != 3)
    {
        printf(USAGE);
        return 1;
    }

    parse_arguments(argc, argv, pattern, filename);
    match_pattern(pattern, filename);

    return 0;
}