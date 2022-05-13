#include <stdio.h>

#include <string.h>

//Defining characters
const char characters[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

//Defining morsecode "letters"
const char* morsecode[] = {"/", ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-", ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....", "--...","---..","----.","-----"};

//Function for encoding. In the while loop, it compares i element of our input and j element of characters. When they match, the j element of morsecode gets printed.
void textEncoder(unsigned char * message) {

    int i = 0;
    while (message[i] != 0) {
        int j = 0;
        while (characters[j] != 0) {
            if (message[i] == characters[j]) {
                printf("%s ", morsecode[j]);
            }
            j++;
        }
        i++;
    }
}

//Function for decoding. Firstly, we separate characters of our input when we see a space(' '). Now, if the i element of morsecode matches the token, we print the i element of the characters.
void textDecoder(char *string) {

    char *token = strtok(string, " ");

    while (token != NULL) {
        for (int i = 0; i < 37; i++) {
            if (strcmp(token, morsecode[i]) == 0) {
                printf("%c", characters[i]);
            }
        }

        token = strtok(NULL, " ");
    }
}

int main() {
	
	unsigned char data1[] = "SOS";
	textEncoder(data1);

	printf("\n");

    	char data2[] = ".. / .-..  ---  ...-  . / .-  ..-  .-";
  	textDecoder(data2);

    	return 0;
}
