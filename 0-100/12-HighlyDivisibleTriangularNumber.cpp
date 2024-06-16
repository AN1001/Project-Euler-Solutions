#include <iostream>
#include <cmath>

int find_divisors_count(int num) {
    int count = 0;
    for(int i = 1; i <= sqrt(num); i++) {
        if(num % i == 0){
            
            if(i==num/i){
                count+=1;
            } else {
                count+=2;
            }
        }
    }
    return count;
}

int main() {
    for(int n = 0; n<100000; n++){
        int i = (n)*(n+1)/2;
        
        if(find_divisors_count(i) > 500){
            std::cout << i;
            break;
        }
    }
}

//Output: 76576500
