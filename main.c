#include<stdio.h>
 
/* this function will print a string of characters in upper case letters.
Anything that isn't a letter will have the same input and output.
i.e. 5: 56 will be printed as 5:56
The inputed letters will then be shifted right "n" spaces if it's an encryption,
or left "n" spaces if it's a decryption.
The value of "n" can be inputed depending on the rotation of letters you want*/

void encryption(char text[]); // this function will be called when encrypting
void decryption(char text[]); // this function will be called when decrypting

/* this main function lets you enter your message that you want to encrypt or decrypt.
 You then choose to encrypt or decrypt.*/
int main()
{
	int flag;
	char text[100];
	printf("enter message: ");
	gets(text);
	printf("Press 0 to enrypt this message or press 2 to decrypt: ");
	scanf("%d", &flag);
	
	if (flag < 1) {
	    encryption(text);
	}
	else if (flag > 1) {
	    decryption(text);
    }

	return 0;
}
	
	void encryption(char text[100]) {
	    int index, n;
	    printf("\nEnter rotation: ");
	    scanf("%d", &n);  
	    for (index = 0; text[index] != '\0'; ++index) { 
		  
	    	if (text[index] >= 'A' && text[index] <= 'Z') { 
			text[index] = text[index] + n;
		}
			if (text[index] > 'Z') { 
				text[index] = text[index] - 26; 
			}
	    }
	    printf("encrypted text: ");
    	puts(text);
	}
	
    void decryption(char text[100]) {
        int index, n;
        printf("\nEnter rotation: "); 
	    scanf("%d", &n);  
	    for (index = 0; text[index] != '\0'; ++index) { 
		
	    	if (text[index] >= 'A' && text[index] <= 'Z') { 
			text[index] = text[index] - n; 
		}
			if (text[index] < 'A') { 
				text[index] = text[index] + 26; 
			}
    	}
    	printf("decrypted text: ");
    	puts(text);
    }