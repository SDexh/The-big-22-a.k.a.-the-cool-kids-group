/*Mathew Scott Dexhimer, Savannah Puckett, Emily Falker
  Group 22 https://github.com/SDexh/The-big-22-a.k.a.-the-cool-kids-group 
  Each Member of our group did an even share of the work on this project even though not all
  of us have the same amount of commits. We found it easier to all work on one computer (Scott's) that
  is why he has the most commits and Savanah only has one*/
#include "common.h"

#define MAX_FILE_NAME_LENGTH 32
#define DATE_STRING_LENGTH 26

//disable annoying warnings
#pragma warning(disable: 4996)
//new function that converts the structure tm into a desired string
void inttostring(char str[], struct tm *now);

int main ()//int argc, const char *argv[])
{
    FILE *source_file;
	char argv[] = "NEWTON.PAS";
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];

    source_file = init_lister(argv, source_name, date); //makes the pointer source_file and calls the init_lister
	while (get_source_line(source_file, source_name, date)) // calls the boolean command.
	{}
	return 0;
}

//creates the file stream and the name and date to appropriate arrays
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
	//used for getting the time in string format
    time_t timer = time(0);
	struct tm *timetm;
	//stores the file to be opened
    FILE *file;
	//index
	int i = 0;

	struct tm *now = localtime(&timer);
	
    inttostring(dte, now);
	//copies name to sourcefilename
	while(*name != '\0')
	{
		source_file_name[i] = *name;
		name++;
		i++;
	}
	source_file_name[i] = '\0';
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

//converts the tm to a desired string format
void inttostring(char str[], struct tm *now)
{
	//number forms
	int year, month, day, hour, min, i, j, k, l, m;
	//string forms
	char syear[5], smonth[3], sday[3], shour[3], smin[4];
	//pointer used for writing to string
	char *strp;
	//points it to the string
	strp = str;
	//initializes the number
	year = (now->tm_year + 1900);
	month = (now->tm_mon + 1);
	day = now->tm_mday;
	hour = now->tm_hour;
	min = now->tm_min;
	//converts each element to string
	sprintf(syear, "%d", year);
	sprintf(smonth, "%d", month);
	sprintf(sday, "%d", day);
	sprintf(shour, "%d", hour);
	sprintf(smin, "%d", min);

	//concatinating the string
	i = 0;
	while(i < 4)
	{
		*strp = syear[i];
		i++;
		strp++;
	}
	*strp = '/';
	strp++;
	j = 0;
	while(j < 2)
	{
		*strp = sday[j];
		j++;
		strp++;
	}
	*strp = '/';
	strp++;
	k = 0;
	while(k < 2)
	{
		*strp = smonth[k];
		k++;
		strp++;
	}
	*strp = ' ';
	strp++;
	l = 0;
	while(l < 2)
	{
		*strp = shour[l];
		l++;
		strp++;
	}
	*strp = ':';
	strp++;
	m = 0;
	while(m < 2)
	{
		*strp = smin[m];
		m++;
		strp++;
	}
	*strp = '\0';
}