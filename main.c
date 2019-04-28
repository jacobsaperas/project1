#include <stdio.h> 
#include <string.h> // used to manipulate strings.
#include <ctype.h> // used to open files.
#include <stdlib.h> // used for macros and to set the size of a string.
#include "input.h"

/* this code will give you choices to either use a rotation or substitution cipher to encrypt and then decrypt text.
You will first be asked to input your message in the file, "input.txt".
Then you will choose between a rotation cipher or substitution cipher. 
This is inputed in file, "choose.txt", where rotation = 1 and substitution = 2.
If you chose a rotation cipher, you can input the number of rotations in the file, "rot.txt".
If you chose a substitution cipher, you will be asked to input the substituted alphabet to the file, "alpha.txt".
The rotation or substitution cipher will then print the output in upper case letters even if the input has 
lower case letters. Anything that isn't a letter will be unmodified.
The files, "input.txt", "choose.txt", and the altered string for the substitution cipher or rotation cipher, 
are written to the file, "output.txt".
The file, "alpha.txt" or "rot.txt" are written to the file, "output2.txt", depending on what cipher you chose. 
These are written here since they are in a new function and 1 file couldn't hold the information of multiple functions. */

/* Below are function prototypes. These are declared at the top to clearly show what functions are used. */

char *encryptrot(char *text); // this function will be called when encrypting a rotation cipher.
char *decryptrot(char *text); // this function will be called when decrypting a rotation cipher.
char *encryptsub(char *text, char sub[]); // this function will be called when encrypting a substitution cipher.
char *decryptsub(char *text, char sub[]); // this function will be called when decrypting a subsitution cipher
int find(char sub[], char c); // this function is used to find the index of a character when decrypting a substitution cipher.

int main() {
    FILE *output; // declaring files that will be used in this function. They can be named anything.
    char text[1000] = INPUT; // type "char" since it holds a string. The string has length "[1000]" so it can hold a lot of characters.
    char sub[] = ALPHA; // variable for substituted alphabet with size 26 as there as 26 letters in the alphabet.
    int flag = CHOOSE;
    output = fopen("output.txt", "w"); // opening the file, "output.txt" and writes it to the file ("w")..
    printf("enter text: %s\n", text); // prints the string from file, "input.txt", to display it on the screen as an output.
	fprintf(output, "enter text: %s\n", text); // prints to file, "output.txt".
        
    for(int i = 0; i < strlen(text); ++i) { // "for" loop inside the "while" loop because the string is being altered. The function, ...
	//... "strlen", represents the length of the string, so the "for" loop reads every character until the end of the string.
       text[i] = toupper((char) text[i]); // "[i]" is the ASCII index of the text, and the "toupper" function converts...
       //... lower case letters to upper case from "text[i]", which is the string from the file, "input.txt".
    }
    printf("Rotation cipher: Press 1\n"); // prints choices to screen and shows what choice you made.
	printf("Substitution cipher: Press 2\nYou chose: %d\n", flag); //a second "printf" so it fits neater.
	fprintf(output, "Rotation cipher: Press 1\n"); // prints to file, "output.txt".
	fprintf(output, "Substitution cipher: Press 2\nYou chose: %d\n", flag); // prints to file, "output.txt".
   if (flag == 1) { // "flag" is the number inputed to the file, "choose.txt", and chooses the case by the number.
	   encryptrot(text); // if 1 was inputed, the code jumps to "encryptrotation" function.
	   printf("encrypted text: %s\n", text); // altered text printed here.
	   fprintf(output, "encrypted text: %s\n", text); // altered text sent to file, "output.txt".
	   decryptrot(text);
	   printf("decrypted text: %s", text);
       fprintf(output, "decrypted text: %s", text);
   } 
   if (flag == 2) { // "if" loop was used instead of a switch case since variables can't be declared in switch cases.
       char *e_text = encryptsub(text, sub); // to encrypt we need the arguements, "message" and the substituted alphabet ("sub") of...
       //... "encryptsub" and their memory address is held in "*e_text".
       fprintf(output, "substituted alphabet: %s\n", sub);
       printf("Encrypted message: %s\n", e_text);
       fprintf(output, "Encrypted message: %s\n", e_text);
       char *d_text = decryptsub(e_text, sub); // decrypted message held in pointer, "d_text" (decrypted text).
       printf("Decrypted message: %s\n", d_text);
       fprintf(output, "Decrypted message: %s\n", d_text);
   }

    return 0;
}

/* this function is for rotation encryptions and the rotation is held in file, "rot.txt".
The rotation will be written to the file, *output2.txt". 
It is type "char" as it will hold a string of characters from "text". The function name and "text" are pointers so they will
hold the memory address of strings. The memory address of "message" will be returned to the main function, hence the need of pointers. */

char *encryptrot(char *text) { // the function definition. It has type "char" as it returns a value.
	//... If you chose a rotation cipher, "case 1" will jump to this function.
    int n = ROT; // the variable only exists inside this function.
	FILE *output2; // file declared in every function.
    output2 = fopen("output2.txt", "w"); 
    printf("Enter rotation: %d\n", n); // prints the rotation onto the screen.
	fprintf(output2, "Enter rotation: %d\n", n); // prints the rotation to file, "output2.txt". 
	
	for (int i = 0; i < strlen(text); ++i) { // this "for" loop allows every character in the...
	    //... string to be read and changed accordingly one at a time until it reaches the end of the string. "int i" declared here.
		  
		  	/* the two "if" loops below shift upper case letters forward "n" times. The lower case letters have
		  	already been converted to upper case in the main function.
		  	It uses the ASCII position of the letters to shift it accordingly. */
		  	
		  	if (text[i] >= 65 && text[i] <= 90) { // if the character's ASCII index is between 65-90 (A-Z)
			    text[i] += n; // "n" is added shifting the ASCII index forward by "n".
		    
			    if (text[i] > 90) { // If the shift puts the ASCII index above 90. Also, this "if" loop is inside the previous...
			    //... "if" loop so forward rotation of "n" has already occured.
				    text[i] -= 26; // "-26" takes the letter to the start of the alphabet.
			    }
	    	} // end of loop for upper case letters.
	    } // end of "for" loop. Every character in the string runs through the "for" loop before the string exits the loop.
	    //... It exits as a rotated and upper case string.
	return text; // returns text back to main function.
	fclose(output2); // closing the file to save RAM. Closed after "return text" since "output2.txt" holds rotation.
} // end of "encryptrotation" function.
	
    /* this function is for rotation decryptions and the rotation is held in the file, "rot.txt".
    This function will be printed after the rotation encryption to see the original text, if you chose a rotation cipher.
    The rotation will be written to "output2.txt". */
    
   char *decryptrot(char *text) { // same as an "encryptrot" function but rotates the letters backwards instead of forwards. 
        int n = ROT; // variable only exists inside this function. The variables have the same names as ...
        // "encryptrot" function to show the similarities between the 2 functions.
        FILE *output2; // file for rotatition declared here again as it exists only inside this function.
        output2 = fopen("output2.txt", "w");
	    for (int i = 0; i < strlen(text); ++i) { 
			
			if (text[i] >= 65 && text[i] <= 90) { 
			    text[i] -= n; // "-n" shifts the inputed letter backward "n" times.
		    
			    if (text[i] < 65) { // if the shift puts the ASCII index below 65. Also inside previous "if" loop
				    text[i] += 26; // "+26" to take the upper case letter to the end of the alphabet.
			    }
	    	}
    	}
    	return text;
    	fclose(output2);
    }

/* this function is for substitution encryptions and the substituted alphabet is held in file, "alpha.txt".
The substituted alphabet will be written to the file, *output2.txt". 
It is type "char" as it will hold a string of characters from "text". "sub[]" holds the substituted cipher. 
The encrypted string will be returned to the main function. */

char *encryptsub(char *text, char sub[]) { // pointers used to return the memory address to the main function.
    FILE *output2; 
    output2 = fopen("output2.txt", "w");
        printf("alphabet substitution: %s\n", sub);
        fprintf(output2, "alphabet substitution: %s", sub);
        
        for(int i = 0; i < strlen(sub); ++i) {
           sub[i] = toupper((unsigned char) sub[i]); // converts the alphabet substitution to upper case since the output is upper case.
        }
    char *e_text = (char *) malloc(sizeof(char)*strlen(text)); // allocates memory for "message" and returns a pointer to the...
    //... allocated memory. The memory space allocated is the length of the string ("strlen") so it doesn't waste memory.
    for(int i = 0; i < strlen(text); ++i) { // every character of "message" goes through this loop.
        int e_index = text[i] - 'A'; // The string, "message", holds upper case letters. "- 'A'" subtracts the ASCII index so...
        //... the characters index is between 0-26. "e_index" is type "int" since it holds a number (ASCII index).
        
        if(e_index >= 0 && e_index <= 26) {
            e_text[i] = sub[e_index]; // if the input was a letter, it will be converted to the allocated letter based off "code"'s index.
            //... "code" is the substituted alphabet and has 26 letters which is why the ASCII index of the characters was set between 0-26. 
        } else { // if it's not a letter.
            e_text[i] = text[i]; // it remains unmodified.
        }
    }
    return e_text; // encrytped message is returned as either a substituted letter or an unmodified input.
}

/* this function is for substitution decryptions and the substituted alphabet is held in file, "alpha.txt".
The substituted alphabet will be written to the file, *output2.txt". 
If a substitution cipher was chosen this function will be returned to the main function and printed after the substitution encryption. */

char *decryptsub(char *text, char sub[]) {
    char *d_text = (char *) malloc(sizeof(char)*strlen(text));
    
    for(int i = 0; i < strlen(text); ++i) {
        int d_index = text[i] - 'A'; // same as "encryptsub" but uses variable name "d_index" to represent decrypted index.
        
        if(d_index >= 0 && d_index < 26) {
            int c_index = find(sub, text[i]); // sets variable, "c_index" as the function "find" and calls the function to this function.
            d_text[i] = 'A' + c_index; // "c_index + 'A'" means the letter is added to 'A' where the letter is between 0-26, since...
            //... the substituted alphabet has ASCII positions 0-26. For example, 'B' would have position 1 so 1 +'A' = 'B'.
        } else { // if it isn't a letter.
            d_text[i] = text[i];
        }
    }
    return d_text;
}

/* this function is called through the function, "decryptsub" and finds the index of the substituted alphabet so it can be converted back
to the normal alphabet. If the character isn't a letter it's ASCII index doesn't change.*/

int find(char sub[], char c) { // type "int" since it holds the character's ASCII index in the string. "char sub[]" is an arguement...
//... since it holds the substituted alphabet.
    for(int i = 0; i < 26; i ++) { // for every letter in the alphabet (since the substituted alphabet contains every letter).
        if(sub[i] == c) { // if it is a character, since "c" has data type "char".
            return i; // return character index.
        }
    }
    return -1; // if it isn't a letter return character unmodified, hence "-1".
}

