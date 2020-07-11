#include <iostream>
#include <cmath>

#include "matrix.h"

using std::cout;
using std::endl;
using std::cin;


int main() {

    Matrix mat ("mat.txt");
    mat.display_matrix();

    Matrix mat2 ("mat2.txt");

    mat.check_for_product(mat2);

    mat2.check_for_product(mat);


    /*int rows, cols;
    std::cout << "Insert number of rows: " << std::endl;
    std::cin >> rows;

    std::cout << "Insert numbre of columns: " << std::endl;
    std::cin >> cols;

    Matrix mat1 (rows, cols);
    mat1.display_matrix();

    bool running = true;
    int selection;

    while (running) {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "OPERATION MENU" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << '\t' << "1 - Change matrix " << std::endl;
        std::cout << '\t' << "2 - Calculate determinant " << std::endl;
        std::cout << '\t' << "3 - Exit program " << std::endl;
        std::cout << "---------------------------------" << std::endl;

        std::cout << "Select option: " << std::endl;
        cin >> selection;
    }*/



    return 0;
}
