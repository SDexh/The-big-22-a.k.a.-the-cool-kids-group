#include "common.h"

static void print_page_header(char source_name[], char date[]);
void print_line(char line[], char source_name_to_print[], char date_to_print[]);

//prints the line of the given char array
void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
	//statically stores the line number
    static int line_count = MAX_LINES_PER_PAGE;
    //checks if the next line will exceed the maximum number of lines per page
    if (++line_count > MAX_LINES_PER_PAGE)
    {
		//if it does, calls print header and resets the line count
        print_page_header(source_name_to_print, date_to_print);
		line_count = 1;
    }

	//prints the line number and tabs
	printf("%d\t", line_count);

	//if the string length exceed the max string length
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
		//creates a temp array and pointer used to seperate the strings
		char Temp[MAX_PRINT_LINE_LENGTH], *tptr;
		//index
		int i;
		//copies from line to temp
		for(i = 0; i < MAX_PRINT_LINE_LENGTH - 1; i++)
		{
			Temp[i] = line[i];
		}
		//adds a null terminator at the end
		Temp[i] = '\0';
		//prints the temp array
		printf("%s\n", Temp);

		//if the next character is not a null
		if(line[i] != '\0')
		{
			//sets the tptr to where we left off
			tptr = &line[i];
			//recursively calls itself until the char fits
			print_line(tptr, source_name_to_print, date_to_print);
		}
    }
	//if it does not exceed the max char length
	else
	{
		//it prints
		printf("%s\n", line);
	}
}


static void print_page_header(char source_name[], char date[]) //creates a page header
{
    static int page_number = 0; //satically creates a variable called page number

	page_number ++;    //increases the page number up by one.
	printf("%s %d %s\n", source_name, page_number, date); //prints out a header with the file name, page number and the date
}