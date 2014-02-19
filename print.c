#include "common.h"

static void print_page_header(char source_name[], char date[]);
void print_line(char line[], char source_name_to_print[], char date_to_print[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(source_name_to_print, date_to_print);
		line_count = 0;
    }

	printf("%d\t", line_count);

    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
		char Temp[MAX_PRINT_LINE_LENGTH], *tptr;
		int i;
		for(i = 0; i < MAX_PRINT_LINE_LENGTH - 1; i++)
		{
			Temp[i] = line[i];
		}
		Temp[i] = '\0';
		printf("%s\n", Temp);
		tptr = &line[i];
		print_line(tptr, source_name_to_print, date_to_print);
    }
	else
	{
		printf("%s\n", line);
	}
}

static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
	page_number ++;    
	printf("%s %d %s\n", source_name, page_number, date);
}