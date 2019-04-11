#include<stdio.h>
 
/* this function will print a string of characters in upper case letters.
Anything that isn't a letter will have the same input and output.
i.e. 5: 56 will be printed as 5:56
The inputed letters will then be shifted right "n" spaces if it's an encryption,
or left "n" spaces if it's a decryption.
The value of "n" can be inputed depending on the rotation of letters you want*/
int main()
{
	/* to input characters a string needs to be used.
	When using characters the data type "char" must be used.*/
	char text[100] = "XYZ";  // declares a string of length 100.
	int index;  // "int index" will represent the index (ASCII placement) of a character.
	int n = 1; // variable "n" will be used to represent the letter's rotation.
	
	printf("Message being encrytped: "); // prints text between " " to screen.
	gets(text);                         // the "gets" function basically works as a "scanf" but includes spaces.
	//... This is useful since when inputing text it is seen as one string of characters.
	//.... The "gets" function will hold the text inputed onto the screen.
	printf("Enter rotation: "); // acts as a prompt to enter rotation to the screen
	scanf("%d", &n);  // The "scanf" function holds an integer of size "n" and stores it in the memory adress.
	//.... The number inputed represents the letter's rotation. 	
	
	/* The code below will encrypt text by shifting letters "n" times to the right.*/
	
	for (index = 0; text[index] != '\0'; ++index) { // This will run every character...
	// .... from the start of the string to the end.
		
		if (text[index] >= 'A' && text[index] <= 'Z') { // if a character of the input was an...
		//... upper case letter it will go through this if statement.
			text[index] = text[index] + n;  // shifts letter from "text[index]", "n" places.
		
            if (text[index] > 'Z') { // If the letter's ASCII position exceeds 'Z'...
			//... i.e Z with rotation of 2, then the character will go through this if statement.
				text[index] = text[index] - 26; // since there are 26 letters, -26 will take the ...
				// letter back 26 places in it's ASCII position. i.e Z with rotation 2 would become B.
			}
		}

	}
	
	printf("Encrypted message: %s", text);
	
	return 0;
}