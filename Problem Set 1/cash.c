#include <cs50.h>
#include <stdio.h>
#include <math.h>

// coins available
// quarters (25¢) 
// dimes (10¢) 
// nickels (5¢)
// pennies (1¢)
int main(void) {
    float dollars;
    do {
      dollars = get_float("Change owed: ");    
    }
    while(dollars < 0);
    int change  = round(dollars * 100);
    int coins_count = 0;
    while(change > 0){
        if(change/25 > 0){
           change -=25;
           coins_count += 1;
        }
        else if(change/10 > 0){
           change -=10;
           coins_count += 1;
        }
        else if(change/5 > 0){
           change -=5;
           coins_count += 1;
        }
        else {
           coins_count += change; 
           change-=change;
        }
    }
    printf("%i\n", coins_count);
}
