#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// prototypes
void labb1(void);
int labb1function(int first, int second, int third);
void labb2(void);
const char* labb2function(const char* string1, const char* string2);
const char* labb2function2(const char* string1, const char* string2);
void labb3(void);
const char* labb3function(float convertme);
void labb3william(char* string, float convertme);
void labb4(void);
bool labb4function(int age);
void labb5(void);
bool labb5function(int age, char location[]);



int main(void)
{
	labb1();
	labb2();
	labb3();
	labb4();
	labb5();
}
void labb1(void)
/*
	Write a function that takes 3 integers and returns the greatest of the integers
*/
{
	int first = 1, second = 2, third = 3; // declaring and initializing integers

	printf("\nlargest number: %d", labb1function(first, second, third));
	/*
		printing out the return value of our function.
	*/

}
/*
	"int labb1function(int first, int second, int third" function declaration.
	tells us the return type(the "int" before the function name), name of the function
	and what the function arguments are. their type and names.

	these functions arguments are passed-by-value so we're working with copies of those
	values.
*/
int labb1function(int first, int second, int third)
{
	if (first > second && first > third) return first;
	else if (second > first && second > third) return second;
	else return third;
}
void labb2(void)
/*
	write a function that takes two strings and returns the longest.
*/
{
	char string1[] = "something", string2[] = "something else";

	printf("\nfunc1 longest: %s", labb2function(string1, string2));
	printf("\nfunc2 longest: %s", labb2function2(string1, string2));
}
const char* labb2function(const char* string1, const char* string2)
{
	/*
		Uses strlen from "string.h" to check the length of strings
		returns longest string.
	*/
	if (strlen(string1) > strlen(string2)) return string1;
	else return string2;
}
const char* labb2function2(const char* string1, const char* string2)
{
	/*
		Creates new pointers that will be for return.
		since the pointers(string) from the function argument
		will be incremented to loop through and compare
		their elements
	*/
	const char* s1 = string1;
	const char* s2 = string2;
	do
	{
		string1++;
		string2++;
		if (*string2 == EOF) return s1;
	} while (*string1 != EOF);
	return s2;
}
void labb3(void)
/*
	create a function "ToPercentage".
		User enters a number between 0 and 1
		Function converts number to percent. ex. 0.5 should return "50%". OBS: "50%" should be a "string".
*/
{
	char string[30];
	float topercentage = 0;
	printf("\nEnter a number between 0 and 1: ");
	scanf(" %f", &topercentage);
	strcpy(string, labb3function(topercentage));
	printf("\nconverted: %s", string);
	
	labb3william(string,topercentage);
  	printf("\nconverted: %s%%", string);
}
/*
	Passing strings as function arguments and modifying them is
	always better than trying to return pointers to strings.
*/
void labb3william(char* string, float convertme) // praise be William
{
  sprintf(string, "%d", (int)(convertme *= 100)); // formats string using sprintf
}
const char* labb3function(float convertme)
{
	convertme *= 100; // just to turn ex. 0.5 to 50

	char string[10]; // declare string that will be formatted, can't be returned though
	char* return_string = string; // creates string that will be returned and points it at "string"

	sprintf(string, "%d", (int)convertme); // formats string using sprintf
	strcat(string, "%"); // Adds "%" to string, I just remembered I could've just done this while formatting the string


	return return_string; // returns pointer to string

}
void labb4(void)
/*
	Create a program where user is asked to input their age.
		Create a function that takes age as input and checks if age >= 18
		Function returns True or False(Boolean), print out if the user is over 18 or not.
*/
{
	int age = 0;

	printf("\nEnter age: ");
	scanf(" %d", &age);
	if (labb4function(age)) printf("\nOver 18");
	else printf("\nUnder 18");

}
bool labb4function(int age)
{
	return age >= 18 ? true : false;
	/*
		Ternary Operator == "condition ? do this if condition true : do this if condition false"
	*/
}
void labb5(void)
/*
	Create a method called CanBuyBeer
		takes age and location (char *).
		if 18 and "krogen" -> true
		if 20 and "systemet" -> true
		Figure out a way to get rid of magic strings (ENUM)
*/
{
	int age = 0;
	char location[30];

	printf("\nEnter age: ");
	scanf(" %d%*c", &age);
	printf("\nEnter location: ");
	scanf("%s", location);
	if (labb5function(age, location)) printf("\nYou can buy beer! wohoo!");
	else printf("\nNo beer for you");
}
bool labb5function(int age, char location[])
{
	enum BeerPlaces
	{
		krogen,
		systemet,
	};
	/*
		Enumerations... enumerate their members starting at 0, so krogen == 0, systemet == 1.
		the integer value increasing for every member of the enumeration.

		You can also set the value of an enumeration member, "krogen = 12" if you'd like.

		These are used for indexes in the places array below.
			Where places[krogen] == places[0] and returns the string at index[0]
	*/
	const char* places[] = { "krogen", "systemet" }; // these are the strings being compared by places[krogen], places[systemet]
	if (age >= 18 && !strcmp(location, places[krogen])) return true;
	else if (age >= 20 && !strcmp(location, places[systemet])) return true;
	else return false;
}
