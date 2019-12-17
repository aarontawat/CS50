#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string shift(string text, int key);

int main(int argc, string argv[]){
    //Check if program is executed without any command-line arguments or with more than one command-line argument,
    //if true program will print an error message and return 1 to exit program
    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Check if any of the characters in the command-line argument is not a decimal digit,
    //if true program will print an error message and return 1 to exit program
    for(int i = 0; i < strlen(argv[1]); i++){
        if(!(isdigit(argv[1][i]))){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //convert command-line argument to an integer
    int k = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");
    int text_lenght = strlen(plain_text);
    printf("ciphertext: ");
    //shift characters
    for(int i = 0; i < text_lenght; i++){
        if(!(isalpha(plain_text[i]))){
            printf("%c", plain_text[i]);
        }
        else if(isupper(plain_text[i])){
           printf("%c", (((plain_text[i] - 65) + k) % 26) + 65);
        }
        else {
           printf("%c", (((plain_text[i] - 97) + k) % 26) + 97);
        }
    }
    printf("\n");
    return 0;
}
