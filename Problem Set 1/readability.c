#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void) {
    //prompt the user for a string of text
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (float)letters/(float)words * 100;
    float S = (float)sentences/(float)words * 100;
    int index = (int)round(0.0588 * L - 0.296 * S - 15.8);
    //If the resulting index number is 16 or higher
    if(index >= 16){
        printf("Grade 16+\n");
    }
    //If the index number is less than 1
    else if(index < 1){
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text){
    int text_length = strlen(text);
    int count = 0;
    for(int i = 0; i < text_length; i++){
        if(isalpha(text[i])){
            count += 1;
        }
    }
    return count;
}


int count_words(string text){
    int text_length = strlen(text);
    int count = 0;
    for(int i = 0; i < text_length; i++){
        if(isspace(text[i])){
            count += 1;
        }
    }
    return count + 1;
}


int count_sentences(string text){
    int text_length = strlen(text);
    int count = 0;
    for(int i = 0; i < text_length; i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            count += 1;
        }
    }
    return count;
}
