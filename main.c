/*Mathew Scott Dexhimer, Savannah Puckett, Emily Falker
  Group 22 https://github.com/SDexh/The-big-22-a.k.a.-the-cool-kids-group */
#include "common.h"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    
    source_file = init_lister(*argv, source_name, date);
	
    return 0;
}

//creates the file stream and the name and date to appropriate arrays
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
	//used for getting the time in string format
    time_t timer, *timep;
	struct tm *timetm;
	//stores the file to be opened
    FILE *file;
	//index
	int i = 0;
	//creates a pointer for timer
	timep = &timer;
	//converts it into a usable format
	timetm = localtime(timep);
	//writes the date in string format to the date array
	strftime(dte, DATE_STRING_LENGTH, "%x", timetm);
	//copies name to sourcefilename
	while(*name != '\0')
	{
		source_file_name[i] = *name;
		name++;
		i++;
	}
	//creates the filestream
	file = fopen(source_file_name, "r");
	//returns the file stream
    return file;
}

//gets the line to print and calls print line
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
	//initializes the first element in the array to be null, this is used to check the success of fgets
	source_buffer[0] = '\0';
	//attempts to copy the string from the stream
    fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file);
	//if the first char is not the null char
    if (source_buffer[0])
    {
		//copies the string from the source buffer to the print buffer
		strcpy(print_buffer, source_buffer);
		//increments the line number
		line_number++;
		//calls print line
		print_line(print_buffer, src_name, todays_date);
		//rturns true
        return (TRUE);
    }
    else
    {
		//returns false
        return (FALSE);
    }
}

