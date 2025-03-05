#include "sparse_matrix.hpp"
#include <iostream>
#include <matrix.hpp>

SparseMatrix::SparseMatrix(int r, int c) : rows(r), cols(c) {
    row_ptr.resize(rows + 1, 0);
}

// Insert a new non-zero value
void SparseMatrix::add_value(int row, int col, double value) {
    values.push_back(value);
    col_indices.push_back(col);
    row_ptr[row + 1]++;
}

// Multiply SparseMatrix (CSR) with a Dense Matrix
Matrix SparseMatrix::multiply(const Matrix& dense) const {
    Matrix result(rows, dense.cols);

    #pragma omp parallel for
    for (int i = 0; i < rows; i++) {
        for (int j = row_ptr[i]; j < row_ptr[i + 1]; j++) {
            int col = col_indices[j];
            double val = values[j];

            for (int k = 0; k < dense.cols; k++) {
                #pragma omp atomic
                r
