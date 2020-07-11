#include <iostream>
#include <fstream>

#include "matrix.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::cerr;
using std::ifstream;


Matrix::Matrix(int a, int b) {
    // Sets the number of rows and columns
    nrows = a;
    ncols = b;

    // Allocate the matrix
    mat = new double*[nrows];
    for (int i = 0; i < b; i++){
        mat[i] = new double[ncols];
    }

    // Ask for the matrix values
    std::cout << "Insert matrix data (row by row): " << '\n';
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << "[" << i << "][" << j << "]" << std::endl;
            cin >> mat[i][j];
        } // End j loop
    } // End i loop
    std::cout  << std::endl;
}


Matrix::Matrix(int a, int b, double **matrix) {
    nrows = a;
    ncols = b;
    mat = matrix;
}


Matrix::Matrix(string file_name) {
    ifstream inFile;

    // Open file. If cannot be opened, an exception raises.
    inFile.open(file_name);
    if (!inFile) {
        std::cerr << "Unable to open. File doesn't exist." << std::endl;
        return;
    }

    // Reads number of rows and columns
    inFile >> nrows;
    inFile >> ncols;
    if (nrows <= 0 || ncols <= 0) {
        std::cerr << "Wrong format, matrix dimentions have to be posite integers." << '\n';
        return;
    }

    // Allocate matrix array
    mat = new double*[nrows];
    for (int i = 0; i < nrows; i++) {
        mat[i] = new double[ncols];
    }

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            inFile >> mat[i][j];
        } // End j loop
    } // End i loop
    std::cout  << std::endl;
}


// nrows getter
int Matrix::getNrows()
{
    return nrows;
}


// ncols getter
int Matrix::getNcols()
{
    return ncols;
}


// Displays the matrix in the console
void Matrix::display_matrix() {
    std::cout << std::string(8*ncols, '-') << '\n';
    for (int i = 0; i < nrows; i++) {
        std::cout << "|";
        for (int j = 0; j < ncols; j++) {
            std::cout << mat[i][j] << '\t';
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string(8*ncols, '-') << std::endl << std::endl;
}


// Given an index, change the value stored there
void Matrix::modify_matrix(int a, int b, double numb) {
    mat[a][b] = numb;
}


// Checks if two matrices can be multiplied
// If they can, calls for the multMat method, which multiplies the matrices
// If not, an error message is shown
void Matrix::check_for_product(Matrix mat2)
{
    if (ncols == mat2.nrows) {
        multMat(mat2);
    } else if (nrows == mat2.ncols) {
        std::cout << "Switching matrices..." << '\n';
        mat2.multMat(*this);
    } else {
        std::cout << "Error: Cannot multiply matrices" << std::endl;
    }
}


void Matrix::multMat(Matrix mat2)
{
    int res_nrows = nrows, res_cols = mat2.ncols;

    double **res = new double*[res_nrows];
    for (int i = 0; i < res_nrows; i++){
        res[i] = new double[res_cols];
    }

    for (int i = 0; i < res_nrows; i++) {
        for (int j = 0; j < res_cols; j++) {
            res[i][j] = 0;
            for (int k = 0; k < nrows; k++) {
                    res[i][j] = res[i][j] + mat[i][k] * mat2.mat[k][j];
            }
        }

    }

    std::cout << "Matrix product: " << std::endl;
    Matrix (res_nrows, res_cols, res).display_matrix();
}

// double Matrix::determinant() {}
