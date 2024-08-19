#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
        std::cout << std::endl;
        std::string row;

        std::ifstream data("./Desktop/proj_euler/triangle.txt");

        if(!data){
                std::cout << "No such file found" << std::endl;
        }      

        //Should be using 'constexpr' instead of 'const', but on old compiler :( so not supported
        const int number_rows = 100;

        int previous_row[number_rows] = { 0 };
        int current_row[number_rows] = { 0 };
        int width = 0;
        while (getline (data, row)) {
                int* p = current_row;
                int* q = previous_row;

                //clone arrays
                while(p != current_row + number_rows) {
                        *q++ = *p++;
                }

                std::stringstream ss(row);
                std::string token;
                int index = 0;

                while(ss >> token) {
                        int number = std::stoi(token);
                        current_row[index] = number;
                        index++;
                }

                current_row[0] += previous_row[0];
                for(int i=1; i<number_rows; i++){
                        current_row[i] += std::max(previous_row[i], previous_row[i-1]);
                }

        }
        data.close();

        int max = 0;
        for(int i=0; i<number_rows; i++){
                if(current_row[i] > max){
                        max = current_row[i];
                }
        }
        std::cout << std::endl << max;

}
//Output: 7273
