#include <stdio.h>
#include <string.h>

#define STR_MAX_SZ 256

#define USAGE "Incorrect number of arguments passed to my_grep.\n\tUsage: my_grep [switches] pattern filename\n"

void parse_arguments(int, char **, char*, char*);