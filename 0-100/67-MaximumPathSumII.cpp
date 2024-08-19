#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main() {
        std::cout << std::endl;
        std::string row;

        std::ifstream data("./Desktop/proj_euler/triangle.txt");

        if(!data){
                std::cout << "No such file found" << std::endl;
        }

        int number_rows = 100;

        int previous_row[100] = { 0 };
        int current_row[100] = { 0 };
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

                for(int i=0; i<number_rows - 1; i++){
                //      std::cout << previous_row[i] << "->";
                        current_row[i] += previous_row[i];
                        current_row[i+1] += previous_row[i];
                //      std::cout << current_row[i] << std::endl;
                }

                std::cout << std::endl;

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
