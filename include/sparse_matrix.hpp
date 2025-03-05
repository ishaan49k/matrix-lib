#ifndef SPARSE_MATRIX_HPP
#define SPARSE_MATRIX_HPP

#include <vector>

class SparseMatrix {
public:
    int rows, cols;
    std::vector<double> values;      // Non-zero values
    std::vector<int> col_indices;    // Column indices of values
    std::vector<int> row_ptr;        // Start index of each row in `values`

    SparseMatrix(int r, int c);
    void add_value(int row, int col, double value);
    Matrix multiply(const Matrix& dense) const; // Multiply with a dense matrix
    void print() const;
};

class SparseMatrixCSC {
    public:
        int rows, cols;
        std::vector<double> values;
        std::vector<int> row_indices;
        std::vector<int> col_ptr;
    
        SparseMatrixCSC(int r, int c);
        void add_value(int row, int col, double value);
        Matrix multiply(const Matrix& dense) const;
    };
    


#endif // SPARSE_MATRIX_HPP
