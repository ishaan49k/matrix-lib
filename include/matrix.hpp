#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<double>> data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<double>(c, 0)) {}

    // Operator Overloading for Addition
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = this->data[i][j] + other.data[i][j];
        return result;
    }

    // Operator Overloading for Subtraction
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = this->data[i][j] - other.data[i][j];
        return result;
    }

    // Matrix Multiplication
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
        return result;
    }

    // Transpose of a Matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[j][i] = this->data[i][j];
        return result;
    }

    // Print Matrix (For Debugging)
    void print() const {
        for (const auto& row : data) {
            for (double val : row)
                std::cout << val << " ";
            std::cout << "\n";
        }
    }
};

#endif // MATRIX_HPP
