/****************************************************************
   PROGRAM:   Assignment 1
   AUTHOR:    Ben Lane
   LOGON ID:  z1806979
   DUE DATE:  2/2/2017

   FUNCTION:  Use various functions to perform manipulations on C strings.

   INPUT:	  standard input      

   OUTPUT:    Output various C string manipulations onto display. 

   NOTES:     
****************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

char* copy(char* destination, const char* source, size_t num);
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);
char* caseChangeCopy(char* destination, const char* source, size_t num);
char* reverseCopy(char* destination, const char* source, size_t num);
void read(char* destination, int n);

int main() {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"cattywampus", "collywobbles", "Lickety Split", "Kerfuffle", "Lollygag", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"cattywampus\", should see \"cattywampus\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;   

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function
   cout << "Replace 'l' in \"collywobbles\" with 'b', should see \"cobbywobbbes\".\n";
   replaceCopy(word, words[1], 'l', 'b', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"Lickety Split\", should see \"lICKETY sPLIT\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;  

   // Test the reverseCopy function
   cout << "Reverse \"Kerfuffle\", should see \"elffufreK\".\n";
   reverseCopy(word, words[3], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"triskaidekaphobia\", should see \"ohpakediaksirt\".\n";
   reverseCopy(word, "triskaidekaphobia", sizeof(word) - 1);
   cout << word << endl << endl;

   cout << "Reverse \"Lollygag\", change case, and replace 'G' with 'Z', should see \"ZAZYLLOl\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'G', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;  

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;  
   
   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
}

/****************************************************************

   FUNCTION:   char* copy(char* destination, const char* source, size_t num);

   ARGUMENTS:  destination 	(where the string is being copied INTO)
   			   source 		(where the string is to be copied FROM)
			   num 			(the number of letters to be changed within the string)
			   
   RETURNS:    Returns a pointer to the variable 'destination'.

   NOTES:      This function copies a string from one variable into another
   			   variable a la 'strcpy' function. The number of characters to
   			   be copied is designated by 'num'.
****************************************************************/
char* copy(char* destination, const char* source, size_t num) {	
	/* copy 'num' amount of characters from 'source' to 'destination'. */
	
	strncpy(destination, source, num);	 
	
	/* Append null terminator. */
	
	destination[num] = '\0';
	
	return destination;
}

/****************************************************************

   FUNCTION:   char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);

   ARGUMENTS:  destination 	(where the string is being copied INTO)
   			   source 		(where the string is to be copied FROM)
   			   target 		(the character that will be changed)
   			   replace 		(the character that will be substituted in for 'target')
			   num 			(the number of letters to be changed within the string)

   RETURNS:    Returns a pointer to the variable 'destination'.

   NOTES:      This function scans a C string character-by-character.
   			   If it finds a certain character 'target', it will
   			   replace it with a character 'replace'.
****************************************************************/
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num) {
	int index = 0;				/* element counter of C string character array */
	
	/* Go through C string character-by-character, copying 'source' characters into 'destination' character. */
		   
	for (index = 0; index < num; index++) {
		destination[index] = source[index];
	
		/* If 'source' character is a 'target', then change it into 'replace' character in 'destination'. */	
	
		if (source[index] == target)
			destination[index] = replace;
	}

	/* Append null terminator. */
	
	destination[num] = '\0';
	
	return destination;
}

/****************************************************************

   FUNCTION:   char* caseChangeCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:  destination 	(where the string is being copied INTO)
   			   source 		(where the string is to be copied FROM)
			   num 			(the number of letters to be changed within the string)

   RETURNS:    Returns a pointer to the variable 'destination'.

   NOTES:      This function will scan every character from 'source'. If it finds
   			   an uppercase letter, it will switch it to lowercase and vice versa.
****************************************************************/
char* caseChangeCopy(char* destination, const char* source, size_t num) {
	int index = 0;				/* element counter of C string character array 		*/
	
	/* Scan 'source' characters one-by-one */
	
	for (index; index < num; index++) {
		
		/* If character is uppercase, change to lowercase in 'destination'.
		   If it is lowercase, change to uppercase in 'destination' 
		   If is is a space, keep it as a space. */
		
		if (isupper(source[index]))
			destination[index] = tolower(source[index]);
		else if (islower(source[index]))
			destination[index] = toupper(source[index]);
		else if (isspace(source[index]))
			destination[index] = 32;
			
	}
	
	/* Append null terminator. */
	
	destination[index] = '\0';
	
	return destination;
}

/****************************************************************

   FUNCTION:   char* reverseCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:  destination 	(where the string is being copied INTO)
   			   source 		(where the string is to be copied FROM)
			   num 			(the number of letters to be changed within the string)

   RETURNS:    Returns a pointer to the variable 'destination'.

   NOTES:      This function will take a string from 'source' and reverse the 
   			   order of the characters so as to read backwards in 'destination'.
****************************************************************/
char* reverseCopy(char* destination, const char* source, size_t num) {
	int index = 0, 				/* element counter of C string character array 										*/
		maxIndexSize;			/* value of array element that is first character to be changed in 'destination'	*/
	
	/* if the length of the 'source' string is larger than the 'num' limit, keep the number
	   of characters to be copied limited to 'num' amount. Else, if the length of the 'source' string 
	   is less than/equal to the 'num' limit, the number of characters to be copied will be same as the 'source' */
	
	if (strlen(source) > num)
		maxIndexSize = num;
	else 
		maxIndexSize = strlen(source);
	
	/* Copy 'source' character array backwards, from end to beginning while writing to 'destination' from beginning to end. */
	
	for (index; index < num; index++) {
		destination[index] = source[maxIndexSize - 1];
		maxIndexSize--;
		
	}
	
	/* Append null terminator. */
	
	destination[num] = '\0';
	
	return destination;	
}

/****************************************************************

   FUNCTION:   void read(char* destination, int n)

   ARGUMENTS:  destination	(where the string is being copied INTO)
   			   n 			(limits the number of characters to be copied into 'destination')

   RETURNS:    nothing

   NOTES:      This function reads in a user-typed string from keyboard and
   			   copies it into 'destination'.
****************************************************************/
void read(char* destination, int n) {
	cin.getline(destination, n, '\n');	
}
