#include "matrix.hpp"
#include <Accelerate/Accelerate.h>  // Apple’s SIMD library

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);

    // Convert 2D vectors to 1D arrays for Accelerate
    std::vector<double> A_flat(rows * cols);
    std::vector<double> B_flat(cols * other.cols);
    std::vector<double> C_flat(rows * other.cols, 0);

    // Copy data into 1D format
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            A_flat[i * cols + j] = data[i][j];

    for (int i = 0; i < cols; i++)
        for (int j = 0; j < other.cols; j++)
            B_flat[i * other.cols + j] = other.data[i][j];

    // Perform SIMD-optimized matrix multiplication
    vDSP_mmulD(A_flat.data(), 1, B_flat.data(), 1, C_flat.data(), 1, rows, other.cols, cols);

    // Copy results back to Matrix class
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < other.cols; j++)
            result.data[i][j] = C_flat[i * other.cols + j];

    return result;
}
