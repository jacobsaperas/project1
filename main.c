#include <stdio.h>
#include <string.h> // used to manipulate strings.
#include <ctype.h> // used to open files.
#include <stdlib.h> // used for macros and to set the size of a string.
#include "input.h" // header file made, calling it from the file, "input.h".

/* This code will give you choices to either use a rotation or substitution cipher to encrypt and then decrypt text.
All inputs are entered into the header file, "input.h".
step 1: input your message in the header file, "input.h" after "INPUT" as a string.
step 2: choose between a rotation cipher or substitution cipher. The rotation and substitution ciphers will then encrypt and decrypt the
text. I chose to encrypt and decrypt as 1 option, not 2 seperate ones, since decrypting is useless if the text hasn't first been encrypted.
Input your choice in the header file after "CHOOSE", where rotation = 1 and substitution = 2.
step 3: If you chose a rotation cipher, you can input the number of rotations in the header file after "ROT".
step 4: If you chose a substitution cipher, you will be asked to input the substituted alphabet to the header file after "ALPHA" as a string.
The rotation or substitution cipher will then print the output in upper case letters even if the input has 
lower case letters. Anything that isn't a letter will be unmodified.
All information printed the the screen will also be written to the file, "output.txt" as an output. */

/* Below are function prototypes. These are declared at the top to clearly show what functions are used. */

char *encryptrot(char *text); // this function will be called when encrypting a rotation cipher.
char *decryptrot(char *text); // this function will be called when decrypting a rotation cipher.
char *encryptsub(char *text, char sub[]); // this function will be called when encrypting a substitution cipher.
char *decryptsub(char *text, char sub[]); // this function will be called when decrypting a subsitution cipher
int find(char sub[], char c); // this function is used to find the index of a character when decrypting a substitution cipher.

/* This is the main function. This function holds all values from the header file, "input.h", and chooses which functions to call based
on this information. It also converts the string to upper case letters here so it doesn't have to be done in every other function.
Everything being printed onto the screen and file, "output.txt", is done in this main function. */

int main() {
    FILE *output; // declaring a file that will be used in this function. They can be named anything.
    char text[] = INPUT; // type "char" since it holds a string. The strings length is whatever the length of "INPUT" is.
    //... INPUT is called from the header file, "input.h", since the file was included at the top of the function.
    int flag = CHOOSE;
    int n = ROT; // declared here so the file, "output.txt", can hold the rotation.
    char sub[] = ALPHA; // variable for substituted alphabet with size 26 as there as 26 letters in "ALPHA".
    output = fopen("output.txt", "w"); // opening the file, "output.txt" and writes it to the file ("w").
    printf("enter text: %s\n", text); // prints the string from file, "input.txt", to display it on the screen as an output.
	fprintf(output, "enter text: %s\n", text); // prints to file, "output.txt".
        
    for(int i = 0; i < strlen(text); ++i) { // "for" loop includes the whole string from start to finish. The function, ...
	//... "strlen", represents the length of the string, so the "for" loop reads every character until the end of the string.
       text[i] = toupper((char) text[i]); // "[i]" is the ASCII index of the text, and the "toupper" function converts...
       //... lower case letters to upper case from "text[i]", which is the string inputed after "INPUT".
    }
    printf("Rotation cipher: Press 1\nSubstitution cipher: Press 2\nYou chose: %d\n", flag); // displays what cipher you chose.
	fprintf(output, "Rotation cipher: Press 1\nSubstitution cipher: Press 2\nYou chose: %d\n", flag); 
    if (flag == 1) { // "flag" is the number inputed after "CHOOSE" and chooses the case by the number.
	   encryptrot(text); // if 1 was inputed, the code jumps to "encryptrot" function.
	   printf("Rotation amount: %d\n", n);
	   fprintf(output, "Rotation amount: %d\n", n); // printed here so it can be stored in the file, "output.txt" since if it was printed...
	   //... in function, "encryptrot", a new file for output would have to be made.
	   printf("encrypted text: %s\n", text); // altered text printed here.
	   fprintf(output, "encrypted text: %s\n", text); // altered text sent to file, "output.txt".
	   decryptrot(text); // after "encryptrot" jumps to "decryptrot" function.
	   printf("decrypted text: %s", text);
       fprintf(output, "decrypted text: %s", text);
   } 
   if (flag == 2) { // "if" loop was used instead of a switch case since variables can't be declared in switch cases.
       char *e_text = encryptsub(text, sub); // to encrypt we need the arguements, "message" and the substituted alphabet ("sub") of...
       //... "encryptsub" and their memory address is held in "*e_text". Has to be redeclared in main function.
       printf("substituted alphabet: %s\n", sub);
       fprintf(output, "substituted alphabet: %s\n", sub);
       printf("Encrypted message: %s\n", e_text);
       fprintf(output, "Encrypted message: %s\n", e_text);
       char *d_text = decryptsub(e_text, sub); // decrypted message held in pointer, "d_text" (decrypted text).
       printf("Decrypted message: %s\n", d_text);
       fprintf(output, "Decrypted message: %s\n", d_text);
   }
   return 0;
}

/* This function is for rotation encryptions. This means an inputed letter will be shifted forward "n" times and will turn into a different
letter. For example, "A" a with rotation of 2 will become "C". If the rotation causes a letter to exceed "Z" the letter will be sent to the
start of the alphabet. For example, "Z" with a rotation of 1 will become "A".
The rotation is held in the header file after "ROT".
The rotation and encrypted text will be written to the file, *output.txt", in the main function. 
It is type "char" as it will hold a string of characters from "text". The function name and "text" are pointers so they will
hold the memory address of strings. The memory address of "text" will be returned to the main function, hence the need of pointers. */

char *encryptrot(char *text) { // the function definition. It has type "char" as it returns a value.
	//... If you chose a rotation cipher, "case 1" will jump to this function.
    int n = ROT; // variable is redclared here to give n a value in this different function. The variable only exists inside this function.
	
	for (int i = 0; i < strlen(text); ++i) { // this "for" loop allows every character in the...
	    //... string to be read and changed accordingly one at a time until it reaches the end of the string. "int i" declared here.
		  
		/* the two "if" loops below shift upper case letters forward "n" times. The lower case letters have
		already been converted to upper case in the main function.
		It uses the ASCII index of the letters to shift it accordingly. */
		  	
		if (text[i] >= 65 && text[i] <= 90) { // if the character's ASCII index is between 65-90 (A-Z)
	       text[i] += n; // "n" is added shifting the ASCII index forward by "n".
		    
		       if (text[i] > 90) { // If the shift puts the ASCII index above 90. Also, this "if" loop is inside the previous...
			   //... "if" loop so forward rotation of "n" has already occured.
			       text[i] -= 26; // "-26" takes the letter to the start of the alphabet.
			   }
	    } // end of loop for upper case letters.
	} // end of "for" loop. Every character in the string runs through the "for" loop before the string exits the loop.
	    //... It exits as a rotated and upper case string.
	return text; // returns text back to main function since the function and text are pointers.
}
	
/* This function is for rotation decryptions and works the same as a rotation decryption but shifts the letter backwards "n" times
in the alphabet instead of forward. For example, "B" with a rotation of 1 will become "A". If the rotation causes the letter to drop below
"A", the letter will be sent to the end of the alphabet. For example, "A" with a rotation of 1 will become "Z".
The rotation is held in the header file after "ROT".
This function will be printed after the rotation encryption to see the original text, if you chose a rotation cipher. */
    
char *decryptrot(char *text) { // same as an "encryptrot" function but rotates the letters backwards instead of forwards. 
    int n = ROT; // variable only exists inside this function. The variable has the same names as ...
    // "encryptrot" function to show the similarities between the 2 functions.
	    
	for (int i = 0; i < strlen(text); ++i) { 
			
	    if (text[i] >= 65 && text[i] <= 90) { 
		    text[i] -= n; // "-n" shifts the inputed letter backward "n" times.
		    
			if (text[i] < 65) { // if the shift puts the ASCII index below 65. Also inside previous "if" loop
				    text[i] += 26; // "+26" to take the upper case letter to the end of the alphabet.
			}
	    }
    }
    return text;
}

/* This function is for substitution encryptions. It converts an original letter to a letters position in a substituted alphabet.
For example, if a substituted alphabet's first 2 letters were "ba" instead of "ab", a would become b and b would become a. 
So "abs" would become "bas".
The substituted alphabet is held in the header file after "ALPHA".
The substituted alphabet will be written to the file, *output.txt" in the main function. 
It is type "char" as it will hold a string of characters from "text". "sub[]" holds the substituted cipher. 
The encrypted string will be returned to the main function using pointers. */

char *encryptsub(char *text, char sub[]) { // pointers used to return the memory address to the main function.
    char *e_text = (char *) malloc(sizeof(char)*strlen(text)); // allocates memory for "message" and returns a pointer to the...
    //... allocated memory. The memory space allocated is the length of the string ("strlen") so it doesn't waste memory.    
    
    for(int i = 0; i < strlen(sub); ++i) {
        sub[i] = toupper((unsigned char) sub[i]); // converts the alphabet substitution to upper case since the output is upper case.
    }
    for(int i = 0; i < strlen(text); ++i) { // every character of "text" goes through this loop.
        int e_index = text[i] - 'A'; // The string, "text", holds upper case letters. "- 'A'" subtracts the ASCII index so...
        //... the characters index is between 0-26. "e_index" is type "int" since it holds a number.
        
        if(e_index >= 0 && e_index <= 26) {
            e_text[i] = sub[e_index]; // if the input was a letter, it will be converted to the allocated letter based off "sub"'s index.
            //... "sub" is the substituted alphabet and has 26 letters which is why the index of the characters was set between 0-26. 
        } else { // if it's not a letter.
            e_text[i] = text[i]; // it remains unmodified.
        }
    }
    return e_text; // encrytped message is returned as either a substituted letter or an unmodified input.
}

/* this function is for substitution decryptions. This function decrypts the encrypted substitution and converts it back to the original
message using the function, "find". It does this by changing the current substituted index to the original index and adds 'A' back to the letters index, since the
old index existed between 0-26. This converts it back to the original message. Using the "abs" example from the "encryptsub" function,
the "find" function will find the converted letter in the alphabet and convert it back to the original alphabet, so "ba" would become "ab"
again. This converts "bas" to "abs".
The substituted alphabet is held in the header file after "ALPHA".
If a substitution cipher was chosen this function will be returned to the main function and printed after the substitution encryption. */

char *decryptsub(char *text, char sub[]) {
    char *d_text = (char *) malloc(sizeof(char)*strlen(text));
    
    for(int i = 0; i < strlen(text); ++i) {
        int d_index = text[i] - 'A'; // same as "encryptsub" but uses variable name "d_index" to represent decrypted index.
        
        if(d_index >= 0 && d_index < 26) {
            int c_index = find(sub, text[i]); // sets variable, "c_index" as the function "find" and calls the function to this function.
            d_text[i] = 'A' + c_index; // "c_index + 'A'" means the letter is added to 'A' where the letter is between 0-26, since...
            //... the substituted alphabet has an ASCII index between 0-26.
        } else { // if it isn't a letter.
            d_text[i] = text[i]; // equals original character.
        }
    }
    return d_text;
}

/* this function is used to be called to the function, "decryptsub" and finds the index of the substituted alphabet so it can be converted
back to the normal alphabet. If the character isn't a letter it's ASCII index doesn't change.*/

int find(char sub[], char c) { // type "int" since it holds the character's ASCII index in the string. "char sub[]" is an arguement...
//... since it holds the substituted alphabet.
    for(int i = 0; i < 26; i ++) { // for every letter in the alphabet (since the substituted alphabet contains every letter).
        
        if(sub[i] == c) { // if it is a character, since "c" has data type "char".
            return i; // return character index.
        }
    }
    return -1; // if it isn't a letter return character unmodified, hence "-1".
}

