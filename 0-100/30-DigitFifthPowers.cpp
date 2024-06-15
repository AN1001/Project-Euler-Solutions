#include <iostream>
#define pow5(x) (x * x * x * x * x)

int main() {
    int num = 1000000;
    int sum = 0;
    
    for(int i = 2; i<num; i++){
        int e = i%10;
        int d = (i/10)%10;
        int c = (i/100)%10;
        int b = (i/1000)%10;
        int a = (i/10000)%10;
        int aa = (i/100000)%10;
        
        int num2 = pow5(aa) + pow5(a) + pow5(b) + pow5(c) + pow5(d) + pow5(e);
        if (i == num2){
            std::cout << i << endl;
            sum += i;
        }
    }
    
    std::cout << sum;
}
