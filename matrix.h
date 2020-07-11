#ifndef MATRIX_H
#define MATRIX_H

using std::string;

// Represents a matrix
class Matrix {
    // Number of rows and columns of the matrix
    int nrows, ncols;

    // Multidimensional array where the matrix's values are stored
    double **mat;
public:
    Matrix(int a, int b);
    Matrix(int a, int b, double **matrix);
    Matrix(string file_name);
    int getNrows();
    int getNcols();
    void display_matrix();
    void modify_matrix(int a, int b, double numb);
    void check_for_product(Matrix mat2);
    double determinant();
private:
    void multMat(Matrix mat2);
};

#endif
