/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 1
   PROGRAMMER: Your name
   LOGON ID:   Your Z-ID
   DUE DATE:   2/2/2017
 
   FUNCTION:   This program tests functions for manipulating C 
               strings.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here
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

// Add your function definitions here

/****************************************************************

   FUNCTION:   char* copy(char* destination, const char* source, size_t num);

   ARGUMENTS:  destination (where the string is being copied INTO).
   			   source (where the string is to be copied FROM).
			   num (the number of letter to be changed within the string).
			   
   RETURNS:    Returns a pointer to the beginning of the destination variable.

   NOTES:      This function copies a string from one variable into another
   			   variable a la 'strcpy' function. The number of characters to
   			   be copied can be limited. 
****************************************************************/
char* copy(char* destination, const char* source, size_t num) {	
	strncpy(destination, source, num);	 
	
	destination[num] = '\0';
	
	return destination;
}

/****************************************************************

   FUNCTION:   char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);

   ARGUMENTS:  a list of argument names and a short description

   RETURNS:    what the function returns

   NOTES:      Copy the first num characters of a string in which each 
               instance of a "target" character is replaced by the "replace" character, 
   			   from the address specified by source to that specified by destination. 
			   Return a pointer to the start of the copied string.
****************************************************************/
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num) {
	int index = 0;
		
	for (index = 0; index < num; index++) {
		destination[index] = source[index];
		if (source[index] == target)
			destination[index] = replace;
	}

	destination[num] = '\0';
	
	return destination;
}

/****************************************************************

   FUNCTION:   char* caseChangeCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:  a list of argument names and a short description

   RETURNS:    what the function returns

   NOTES:      Copy the first num characters of a string in which each 
               instance of a "target" character is replaced by the "replace" character, 
   			   from the address specified by source to that specified by destination. 
			   Return a pointer to the start of the copied string.
****************************************************************/
char* caseChangeCopy(char* destination, const char* source, size_t num) {
	int index = 0;
	
	for (index; index < num; index++) {
		if (isupper(source[index]))
			destination[index] = tolower(source[index]);
		else if (islower(source[index]))
			destination[index] = toupper(source[index]);
		else 
			destination[index] = 32;
			
	}
	
	destination[num] = '\0';
		
	return destination;
}

/****************************************************************

   FUNCTION:   char* caseChangeCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:  a list of argument names and a short description

   RETURNS:    what the function returns

   NOTES:      Copy the first num characters of a string in which each 
               instance of a "target" character is replaced by the "replace" character, 
   			   from the address specified by source to that specified by destination. 
			   Return a pointer to the start of the copied string.
****************************************************************/
char* reverseCopy(char* destination, const char* source, size_t num) {
	int index = 0, copyFromIndex;
	
	if (strlen(source) > num)
		copyFromIndex = num;
	else 
		copyFromIndex = strlen(source);
	
	for (index; index < num; index++) {
		destination[index] = source[copyFromIndex - 1];
		copyFromIndex--;
		
	}
	
	return destination;	
}

/****************************************************************

   FUNCTION:   char* caseChangeCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:  a list of argument names and a short description

   RETURNS:    what the function returns

   NOTES:      Copy the first num characters of a string in which each 
               instance of a "target" character is replaced by the "replace" character, 
   			   from the address specified by source to that specified by destination. 
			   Return a pointer to the start of the copied string.
****************************************************************/
void read(char* destination, int n) {
	cin.getline(destination, n);
	
}
