#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
/* this code will give you choices to either use a rotation or substitution cipher and encrypt or decrypt text.
You will first be asked to input your message. Then you will be asked to choose between a rotation or 
substitution encryption or decryption. If you chose a rotation cipher, you will input the rotation of letters.
The rotation or substitution cipher will then print the output in upper case letters even if the input has 
lower case letters. Anything that isn't a letter will be unmodified.*/

/* Below are function prototypes. These are declared at the top to clearly show what functions are used. */

void encryptrotation(char text[]); // this function will be called when encrypting a rotation cipher.
void decryptrotation(char text[]); // this function will be called when decrypting a rotation cipher.
void encryptsubstitution(char text[]); // this function will be called when encrypting a substitution cipher.
void decryptsubstitution(char text[]); // this function will be called when decrypting a substitution cipher.

/* this main function lets you enter your message and choose your cipher. */

int main()
{
	int flag; // "flag" will be a number inputed so it's data type is "int".
	char text[100]; // "text[100]" represents a string of characters so it's data type is "char".
	FILE *input;
	FILE *number;
	input = fopen("input.txt", "r");
	number = fopen("number.txt", "r");
	printf("enter text: "); 
	
	while (feof(input) == 0) {
	    // prompt to enter text.
	fscanf(input, "%[^\n]s", text);
	for(int i = 0; i < strlen(text); i++) {
    	text[i] = toupper((unsigned char) text[i]);
    }
}
    while (feof(number) == 0) {
       fscanf (number, "%d", &flag); 
    }
    printf("Rotation ciphers:\nPress 1 to encrypt or 2 to decrypt\n"); // prompt for choosing your cipher.
	printf("Substitution ciphers:\nPress 3 to encrypt or 4 to decrypt: %d", flag); // a second "printf" so it fits neater.
	 // number inputed will choose what cipher will be used. "&" means the number is stored...
	// ... in the memory adress of "flag", giving it that value.
	
	/* This switch case will call the function that will be used. For example, if you chose to do a
    rotation decryption then you would have pressed 1 and the switch case will choose case 1 and exit (break). */
	
	switch(flag) { // "flag" is the number inputed and chooses the case by number.
	    case 1: encryptrotation(text); // if 1 was inputed, the code jumps to "encryptrotation" function.
	    break;                         // "break" means the code exits if case 0 was chosen.
	    case 2: decryptrotation(text); // if 2 was inputed, the code jumps to "decryptrotation" function.
	    break;
	    case 3: encryptsubstitution(text); 
	    break;
	    case 4: decryptsubstitution(text);
	} // end of switch case.

	return 0;
}
    /* This function is for encrytping a rotation cipher. First, the rotation will be entered, and then
    the letters will be rotated by that number. Lower case letters will also be converted to upper case. */	
	
	void encryptrotation(char text[]) { // this is a function definition. 
	//... If you chose a rotation encryption, "case 0" will jump to this...
	//... function. The function is "void", meaning it doesnt return a value.
	    int index, n; // these variables only exist inside this function.
	    printf("\nEnter rotation: "); // prompt to enter rotation.
	    scanf("%d", &n); // enter rotation here.
	    for (index = 0; text[index] != '\0'; ++index) { // this "for" loop allows every character in the...
	    //... string to be read and changed accordingly one at a time until it reaches the end of the string.
		  
		  	/* the two "if" loops below changes lower case letters to upper case and shifts the letter forward
		  	"n" times.It uses the ASCII position of the letters to shift it accordingly. */
		  	
		  	if (text[index] >= 65 && text[index] <= 90) { // if the character's ASCII index is between...
	    	//... 65-90 (A-Z)
			text[index] += n; // "n" is added shifting the ASCII index forward by "n".
		    
			    if (text[index] > 90) { // If the shift puts the ASCII index above 90. Also inside the previous...
			    //... "if" loop so rotation has already occured.
				    text[index] -= 26; // "-26" takes the letter back to the start of the alphabet in upper case.
			    }
	    	} // end of loop for upper case letters.
	    } // end of "for" loop. Every character in the string runs through the "for" loop before the string...
	    //... exits the loop. It exits as a rotated and upper case string.
	    printf("encrypted text: %s", text); // changes in the "for" loop printed here.
    	 // puts the rotated string as the output. Works like a "scanf" function and works with the...
    	//... "gets" function. The "gets" function gets the text and the "puts" function takes the text and...
    	//... puts it onto the screen.
	} // end of "encryptrotation" function.
	
    void decryptrotation(char text[]) { // works the same as the "encryptrotation" function but rotates...
    //... the letters backwards instead of forwards. 
        int index, n; // variables only exist inside this function. These variables have the same names as ...
        // "encryptrotation" function to show the similarities between the 2 functions.
        printf("\nEnter rotation: "); 
	    scanf("%d", &n);  
	    for (index = 0; text[index] != '\0'; ++index) { 
			
			if (text[index] >= 65 && text[index] <= 90) { 
			    text[index] -= n; // "-n" shifts the imputed letter left "n" times.
		    
			    if (text[index] < 65) {
				    text[index] += 26; 
			    }
	    	}
    	}
    	printf("decrypted text: %s", text);
    }
    /* The function below will substitute a letter of the alphabet for a letter from a given alphabet substitution.
    In this case, the alphabet substitution is the qwerty keyboard layout. For example, "A" becomes "Q".
    Lower case letters will also become upper case.*/
    
    void encryptsubstitution(char text[]) {
        int index;
        for (index = 0; text[index] != '\0'; ++index) {
		
		switch(text[index]) { // This switch case will change each letter's ASCII index to a new index...
		//... , represented by '' around a letter. For example, "A" is represented as "'A'".
		//... Since every letter is already in upper case there are 26 switch cases instead of 52.
		    case 'A': text[index] = 'Q'; // "'A'" is the letter being changed from the "text[index]". It's ASCII...
		    //... index will change from "'A'" to "'Q'", converting the letter to "Q".
		        break; // if the inputed letter was "A" or "a" then the letter will exit here as Q. 
		        //... If the input wasn't "A" or "a" the letter would go to the next case unchanged
		    case 'B': text[index] = 'W';
		        break; // If the letter wasn't "A" or "B" it would go to the next case and so on.
		    case 'C': text[index] = 'E';
		        break;
		    case 'D': text[index] = 'R';
		        break;
		    case 'E': text[index] = 'T';
		        break;
		    case 'F': text[index] = 'Y';
		        break;
		    case 'G': text[index] = 'U';
		        break;
		    case 'H': text[index] = 'I';
		        break;
		    case 'I': text[index] = 'O';
		        break;
            case 'J': text[index] = 'P';
		        break;
		    case 'K': text[index] = 'A';
		        break;
		    case 'L': text[index] = 'S';
		        break;
		    case 'M': text[index] = 'D';
		        break;
		    case 'N': text[index] = 'F';
		        break;
		    case 'O': text[index] = 'G';
		        break;
            case 'P': text[index] = 'H';
		        break;
		    case 'Q': text[index] = 'J';
		        break;
		    case 'R': text[index] = 'K';
		        break;
		    case 'S': text[index] = 'L';
		        break;
		    case 'T': text[index] = 'Z';
		        break;
		    case 'U': text[index] = 'X';
		        break;
		    case 'V': text[index] = 'C';
		        break;
            case 'W': text[index] = 'V';
		        break;
		    case 'X': text[index] = 'B';
		        break;
		    case 'Y': text[index] = 'N';
		        break;
		    case 'Z': text[index] = 'M';
		        break;
			}
        }
        printf("decrypted text: %s", text); 
     // Prints (or puts) the substituted encrypted text onto the screen.
    }
    
    /* This function works like the "encryptsubstitution" function but converts the keyboard qwerty layout back
    to the normal alphabet (a-z). */ 
    
    void decryptsubstitution(char text[]) {
        int index;
        for (index = 0; text[index] != '\0'; ++index) { 
		
		switch(text[index]) {
		    case 'Q': text[index] = 'A'; // "Q" changes to "A" instead of "A" to "Q".
		        break;
		    case 'W': text[index] = 'B';
		        break;
		    case 'E': text[index] = 'C';
		        break;
		    case 'R': text[index] = 'D';
		        break;
		    case 'T': text[index] = 'E';
		        break;
		    case 'Y': text[index] = 'F';
		        break;
		    case 'U': text[index] = 'G';
		        break;
		    case 'I': text[index] = 'H';
		        break;
		    case 'O': text[index] = 'I';
		        break;
            case 'P': text[index] = 'J';
		        break;
		    case 'A': text[index] = 'K';
		        break;
		    case 'S': text[index] = 'L';
		        break;
		    case 'D': text[index] = 'M';
		        break;
		    case 'F': text[index] = 'N';
		        break;
		    case 'G': text[index] = 'O';
		        break;
            case 'H': text[index] = 'P';
		        break;
		    case 'J': text[index] = 'Q';
		        break;
		    case 'K': text[index] = 'R';
		        break;
		    case 'L': text[index] = 'S';
		        break;
		    case 'Z': text[index] = 'T';
		        break;
		    case 'X': text[index] = 'U';
		        break;
		    case 'C': text[index] = 'V';
		        break;
            case 'V': text[index] = 'W';
		        break;
		    case 'B': text[index] = 'X';
		        break;
		    case 'N': text[index] = 'Y';
		        break;
		    case 'M': text[index] = 'Z';
		        break;
			}
        }
        printf("decrypted text: %s", text);
    	 // Prints (or puts) the substituted decrypted text onto the screen.
    }
    
