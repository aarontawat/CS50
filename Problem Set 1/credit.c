#include <cs50.h>
#include <stdio.h>
int digit_count(long num);
int checksum(long num);
int sub_digit(int num);
bool check_valid(int digits);
int start_second_num(long num);
int start_first_num(long num);


int main(void) {
    long num = get_long("Number: ");
    //  check sums' digits use Luhn’s Algorithm
    int sum_digits = checksum(num);
    //check if last digit in that sum is a 0, so a card is legit
    bool valid = check_valid(sum_digits);
    if(valid){
        //American Express uses 15-digit numbers, numbers start with 34 or 37
        //MasterCard uses 16-digit numbers, numbers start with 51, 52, 53, 54, or 55
        //Visa uses 13- and 16-digit numbers, numbers start with 4
        int start_num = start_second_num(num);
        int digits_num = digit_count(num);
        //check if American Express
        if(digits_num == 15 & start_num == 34 || start_num == 37){
            printf("AMEX\n");      
        }
        //check if MasterCard
        else if(digits_num == 16 & start_num == 51 || start_num == 52 || start_num == 53 || start_num == 54 || start_num == 55){
            printf("MASTERCARD\n");
        } 
        //check if Visa 
        else if(digits_num == 13 || digits_num == 16 & start_first_num(num) == 4){
            printf("VISA\n");
        } 
        else {
           printf("INVALID\n"); 
        }
    }
    else {
        printf("INVALID\n");
    }
}


int digit_count(long num) {
    int count = 0;
    while(num > 0){
        num/=10;
        count +=1;
    }
    return count;
}


int checksum(long num){
    int product;
    int sum = 0;
    int sum_other = 0;
    int total_sum = 0;
    int count = 0;
    int temp;
    while(num > 0){
        product = 2;
        temp = num%10;
        //sum of every other digits Multiply by 2, starting with the number’s second-to-last digit
        if(count%2 != 0){
            product *= temp;
            if(product > 9){
                sum += sub_digit(product);
            } else {
               sum += product; 
            }          
        } 
        //add sum_digits (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end)
        else {
            sum_other += temp;
        }
        num/=10;
        count +=1;
    }
    total_sum = sum + sum_other;
    return total_sum;
}


int sub_digit(int num){
    int n = 0;
    int temp;
    while(num > 0){
        temp = num%10;
        n += temp;
        num/=10;
    }
    return n;
}


bool check_valid(int digits){
    if(digits%10 == 0){
        return true;
    }
    else {
        return false;
    }
}

//get start numbers for American Express and MasterCard
int start_second_num(long num){
    while(num > 99){
        num/=10;
    }
    return num;
}

//get start numbers for Visa
int start_first_num(long num){
    while(num > 9){
        num/=10;
    }
    return num;
}

