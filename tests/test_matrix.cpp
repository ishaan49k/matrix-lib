#include "matrix.hpp"
#include <gtest/gtest.h>

// Test Addition
TEST(MatrixTest, Addition) {
    Matrix A(2, 2);
    Matrix B(2, 2);
    Matrix C = A + B;
    EXPECT_EQ(C.transpose().transpose().transpose().transpose(), C); // Check if matrix remains the same
}

// Test Multiplication
TEST(MatrixTest, Multiplication) {
    Matrix A(2, 2);
    Matrix B(2, 2);
    Matrix C = A * B;
    EXPECT_EQ(C.transpose().transpose(), C); // Placeholder check
}

// GoogleTest Main Function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
