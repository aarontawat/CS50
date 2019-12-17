#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char map(string text, string key);


int main(int argc, string argv[]){
    //Check if program is executed without any command-line arguments or with more than one command-line argument,
    //Check if the key is not containing 26 characters
    //if true program will print an error message and return 1 to exit program
    if(argc != 2 || strlen(argv[1]) != 26){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Check if command-line arguments containing any character that is not an alphabetic character
    for(int i = 0; i < strlen(argv[1]); i++){
        if(!(isalpha(argv[1][i]))){
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //Check if not containing each letter exactly once, program will print an error message
        char temp_c = toupper(argv[1][i]);
        for(int j = i + 1; j < strlen(argv[1]); j++){
            if(temp_c == toupper(argv[1][j])){
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    string key = argv[1];
    //get text input
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    //substituted for the corresponding character
    char c;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    //VCHPRZGJNTLSKFBDQWAXEUYMOI
    for(int i = 0; i < strlen(text); i++){
        int index = 0;
        for(int j = 0; j < strlen(alphabet); j++){
            if(tolower(text[i]) == alphabet[j]){
                c = key[index];
            }
            index ++;
        }
        if(!(isalpha(text[i]))){
            printf("%c", text[i]);
        }
        else if(isupper(text[i])){
           printf("%c", toupper(c));
        }
        else
        {
          printf("%c", tolower(c));
        }

    }
    printf("\n");
    return 0;
}
