#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encryptrotation(char message[]); // this function will be called when encrypting a rotation cipher.
void decryptrotation(char message[]); // this function will be called when decrypting a rotation cipher.
char *encrypt(char *message, char code[]);
char *decrypt(char *message, char code[]);
int find_index(char code[], char char_to_find);

int main() {
    FILE *choose, *output;
    char message[1000];
    char code[26];
    int flag;
    choose = fopen("choose.txt", "r");
    output = fopen("output.txt", "w"); // opening the file, "output.txt" and writes it to the file ("w").
    FILE *input;
    input = fopen("input.txt", "r");
    while (feof(input) == 0) {
        fscanf(input, "%[^\n]s", message); // "fscanf" reads the file, "input.txt", as a string that includes spaces, and stores it as "text".
	   printf("enter text: %s\n", message); // prints the string from file, "input.txt", to display it on the screen as an output.
	   fprintf(output, "enter text: %s\n", message); // prints to file, "output.txt".
        for(int i = 0; i < strlen(message); ++i) {
            message[i] = toupper((unsigned char) message[i]);
        }
    }

    while (feof(choose) == 0) {
       fscanf (choose, "%d", &flag); // reads from the file, "choose". "&" used to store the number in "flags" memory adress.
       // Not needed for strings.
    }
    printf("Rotation ciphers:\nPress 1 to encrypt or 2 to decrypt\n"); // prints choices to screen and shows what choice you made.
	printf("Substitution ciphers:\nPress 3: %d\n", flag); // a second "printf" so it fits neater.
	fprintf(output, "Rotation cipher:\nPress 1 to encrypt or 2 to decrypt\n"); // prints to file, "output.txt".
	fprintf(output, "Substitution cipher: \nPress 3: %d\n", flag); // prints to file, "output.txt".
   if (flag == 1) { // "flag" is the number inputed to the file, "choose.txt", and chooses the case by the number.
	     encryptrotation(message); // if 1 was inputed, the code jumps to "encryptrotation" function.
	    }                 // "break" means the code exits if case 1 was chosen.
	if (flag == 2) {
	   decryptrotation(message); // if 2 was inputed, the code jumps to "decryptrotation" function.
    }
   if (flag == 3) {
     char *encrypted_message = encrypt(message, code);
    printf("Encrypted message: %s\n", encrypted_message);
    fprintf(output, "Encrypted message: %s\n", encrypted_message);
     char *decrypted_message = decrypt(encrypted_message, code);
    printf("Decrypted message: %s\n", decrypted_message);
    fprintf(output, "Decrypted message: %s\n", decrypted_message);
}

    return 0;
}

/* this function is for rotation encryptions and the rotation is held in file, "rot.txt".
The rotation and decrypted text will be written to the file, *output2.txt". */

void encryptrotation(char message[]) { // the function definition. It has type "void" as it doesn't return a value.
	//... If you chose a rotation encryption, "case 1" will jump to this function.
    int i, n; // these variables only exist inside this function.
	FILE *rot; // file declared inside function as it isn't needed for substitutuion ciphers.
	FILE *output2; // file declared in every function.
	rot = fopen("rot.txt", "r"); // file is opened and named "rot". The file, "rot.txt", will be read 
    output2 = fopen("output2.txt", "w"); 
	while (feof(rot) == 0) {
        fscanf (rot, "%d", &n);
    }
    printf("Enter rotation: %d\n", n); // prints the rotation onto the screen
	fprintf(output2, "Enter rotation: %d\n", n); // prints the rotation to file, "output2.txt". 
	    for (i = 0; i < strlen(message); ++i) { // this "for" loop allows every character in the...
	    //... string to be read and changed accordingly one at a time until it reaches the end of the string.
		  
		  	/* the two "if" loops below shift upper case letters forward "n" times. The lower case letters have
		  	already been converted to upper case in the main function.
		  	It uses the ASCII position of the letters to shift it accordingly. */
		  	
		  	if (message[i] >= 65 && message[i] <= 90) { // if the character's ASCII index is between 65-90 (A-Z)
			message[i] += n; // "n" is added shifting the ASCII index forward by "n".
		    
			    if (message[i] > 90) { // If the shift puts the ASCII index above 90. Also, this "if" loop is inside the previous...
			    //... "if" loop so forward rotation of "n" has already occured.
				    message[i] -= 26; // "-26" takes the letter to the start of the alphabet.
			    }
	    	} // end of loop for upper case letters.
	    } // end of "for" loop. Every character in the string runs through the "for" loop before the string exits the loop.
	    //... It exits as a rotated and upper case string.
	printf("encrypted text: %s", message); // altered text printed here.
	fprintf(output2, "encrypted text: %s", message);
	fclose(rot); // closing the file to save RAM.
	fclose(output2);   
	} // end of "encryptrotation" function.
	
    /* this function is for rotation decryptions and the rotation is held in the file, "rot.txt".
    The rotation and decrypted text will be written to the file, *output2.txt". */
    
    void decryptrotation(char message[]) { // same as an "encryptrotation" function but rotates the letters backwards instead of forwards. 
        int i, n; // variables only exist inside this function. These variables have the same names as ...
        // "encryptrotation" function to show the similarities between the 2 functions.
        FILE *rot; // file for rotatition declared here again as it exists only inside this function.
        FILE *output2; // file declared again since it's in a different function.
        rot = fopen("rot.txt", "r");
        output2 = fopen("output2.txt", "w");
        while (feof(rot) == 0) {
       fscanf (rot, "%d", &n);
    }
    printf("Enter rotation: %d\n", n);
    fprintf(output2, "Enter rotation: %d\n", n);
	    for (i = 0; i < strlen(message); ++i) { 
			
			if (message[i] >= 65 && message[i] <= 90) { 
			    message[i] -= n; // "-n" shifts the inputed letter backward "n" times.
		    
			    if (message[i] < 65) { // if the shift puts the ASCII index below 65. Also inside previous "if" loop
				    message[i] += 26; // "+26" to take the upper case letter to the end of the alphabet.
			    }
	    	}
    	}
    	printf("decrypted text: %s", message);
    	fprintf(output2, "decrypted text: %s", message);
    	fclose(rot);
    	fclose(output2);
    }

int find_index(char code[], char char_to_find) {
    for(int i = 0; i < 26; i ++) {
        if(code[i] == char_to_find) {
            return i;
        }
    }
    return -1;
}

char *encrypt(char *message, char code[]) {
    int length = strlen(message);
    FILE *alpha;
    FILE *output2;
    alpha = fopen("alpha.txt", "r");
    output2 = fopen("output2.txt", "w");
    while (feof(alpha) == 0) {
       fscanf (alpha, "%s", code);
       fprintf(output2, "alphabet substitution: %s", code);
    for(int i = 0; i < strlen(code); ++i) {
            code[i] = toupper((unsigned char) code[i]);
        }
    }

    char *encrypted_message = (char *) malloc(sizeof(char)*length);
    
    for(int i = 0; i < length; ++i) {
        int encryption_index = toupper(message[i]) - 'A';
        if(encryption_index >= 0 && encryption_index < 26) {
            encrypted_message[i] = code[encryption_index];
        } else {
            encrypted_message[i] = message[i];
        }
    }
    return encrypted_message;
}

char *decrypt(char *message, char code[]) {
    int length = strlen(message);
    char *decrypted_message = (char *) malloc(sizeof(char)*length);
    
    for(int i = 0; i < length; ++i) {
        int decryption_index = toupper(message[i]) - 'A';
        if(decryption_index >= 0 && decryption_index < 26) {
            int code_index = find_index(code, toupper(message[i]));
            decrypted_message[i] = 'A' + code_index;
        } else {
            decrypted_message[i] = message[i];
        }
    }
    return decrypted_message;
}


