#include <iostream>

int collapse_collatz_bin(long num) {
    int bounces = 0;
    while (num!=1){
        if((num & 1) == 0){
            //even
            num = num >> 1;
        } else {
            //odd
            num = 3*num + 1;
        }
        bounces+=1;
    }
    return bounces;
}

int main() {
    int max = 0;
    int largest = 0;
    for (long i = 1; i <= 1000000; i=i+1){
        int bounces = collapse_collatz_bin(i);
        if (bounces > max){
            largest = i; 
            max=bounces;
        }
    }
    std::cout << largest;
}

//Ouput: 837799
