#include "sparse_matrix.hpp"

SparseMatrixCSC::SparseMatrixCSC(int r, int c) : rows(r), cols(c) {
    col_ptr.resize(cols + 1, 0);
}

void SparseMatrixCSC::add_value(int row, int col, double value) {
    values.push_back(value);
    row_indices.push_back(row);
    col_ptr[col + 1]++;
}

// CSC × Dense Matrix Multiplication
Matrix SparseMatrixCSC::multiply(const Matrix& dense) const {
    Matrix result(rows, dense.cols);

    #pragma omp parallel for
    for (int j = 0; j < cols; j++) {
        for (int i = col_ptr[j]; i < col_ptr[j + 1]; i++) {
            int row = row_indices[i];
            double val = values[i];

            for (int k = 0; k < dense.cols; k++) {
                #pragma omp atomic
                result.data[row][k] += val * dense.data[j][k];
            }
        }
    }
    return result;
}
