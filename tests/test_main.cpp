#include <gtest/gtest.h>
#include <GaussianElimination/gaussian_elimination.h>
#include <vector>
#include <stdexcept>

// Test a simple 2x2 system
TEST(GaussianEliminationTest, Solve2x2System) {
    GaussianElimination solver;

    std::vector<std::vector<double>> matrix = {
        {0.02, 61.3},
        {3.43, -8.5}
    };
    std::vector<double> result = {61.5, 25.8};

    solver.solve(matrix, result);
    std::cout << "Result: " << result[0] << ", " << result[1] << std::endl;
    EXPECT_NEAR(result[0], 10.0, 1e-6); // x = 1
    EXPECT_NEAR(result[1], 1.0, 1e-6); // y = 2
}

// Test a larger 3x3 system
TEST(GaussianEliminationTest, SolveWellConditioned3x3System) {
    GaussianElimination solver;
    
    // 测试矩阵 (行列式 = 4.0，良态)
    std::vector<std::vector<double>> matrix = {
        {2.0, 1.0, 1.0},  // 2x + y + z = 7
        {1.0, 3.0, 2.0},  // x + 3y + 2z = 13
        {1.0, 0.0, 1.0}   // x + z = 4
    };
    std::vector<double> rhs = {7.0, 13.0, 4.0};  // 准确解为 [1.0, 2.0, 3.0]

    solver.solve(matrix, rhs);

    const double abs_error = 1e-8;
    EXPECT_NEAR(rhs[0], 1.0, abs_error);  // x
    EXPECT_NEAR(rhs[1], 2.0, abs_error);  // y
    EXPECT_NEAR(rhs[2], 3.0, abs_error);  // z
}

// Test a SolveWithPartialPivoting
// TEST(GaussianEliminationTest, SolveWithPartialPivoting) {
//     GaussianElimination solver;

//     // 需要行交换的测试矩阵
//     std::vector<std::vector<double>> matrix = {
//         {0.0, 2.0, 3.0},  // 0x + 2y + 3z = 13
//         {4.0, 5.0, 6.0},  // 4x + 5y + 6z = 32
//         {7.0, 8.0, 9.0}   // 7x + 8y + 9z = 50
//     };
//     std::vector<double> rhs = {13.0, 32.0, 50.0};  // 准确解为 [1.0, 2.0, 3.0]

//     solver.solve(matrix, rhs);

//     const double abs_error = 1e-8;
//     EXPECT_NEAR(rhs[0], 1.0, abs_error);
//     EXPECT_NEAR(rhs[1], 2.0, abs_error);
//     EXPECT_NEAR(rhs[2], 3.0, abs_error);
// }

// Test singular matrix
TEST(GaussianEliminationTest, SingularMatrixThrows) {
    GaussianElimination solver;

    std::vector<std::vector<double>> singularMatrix = {
        {1.0, 1.0, 1.0},
        {2.0, 2.0, 2.0},
        {3.0, 3.0, 3.0}
    };
    std::vector<double> result = {6.0, 12.0, 18.0};

    EXPECT_THROW(solver.solve(singularMatrix, result), std::runtime_error);
}

// Test invalid input dimensions
TEST(GaussianEliminationTest, InvalidInputDimensions) {
    GaussianElimination solver;

    std::vector<std::vector<double>> invalidMatrix = {
        {2.0, 1.0},
        {1.0, 2.0}
    };
    std::vector<double> result = {5.0};

    EXPECT_THROW(solver.solve(invalidMatrix, result), std::invalid_argument);
}