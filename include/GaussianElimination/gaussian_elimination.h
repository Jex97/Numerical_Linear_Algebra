#include <vector>


class GaussianElimination {

public:
    GaussianElimination() = default;
    ~GaussianElimination() = default;

    void solve(std::vector<std::vector<double>>& matrix, std::vector<double>& result){
        int n = matrix.size();
        int m = matrix[0].size();

        // Check if the matrix is square
        if (n != m) {
            throw std::invalid_argument("Matrix must be square.");
        }

        // Check if the result vector has the correct size
        if (result.size() != n) {
            throw std::invalid_argument("Result vector size must match matrix size.");
        }

        // Perform Gaussian elimination
        for (int i = 0; i < n; ++i) {
            // Find pivot
            double pivot = matrix[i][i];
            if (pivot == 0) {
                throw std::runtime_error("Matrix is singular.");
            }

            // Normalize pivot row
            for (int j = i; j < n; ++j) {
                matrix[i][j] /= pivot;
            }
            result[i] /= pivot;

            // Eliminate other rows
            for (int k = i + 1; k < n; ++k) {
                double factor = matrix[k][i];
                for (int j = i; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
                result[k] -= factor * result[i];
            }
        }

        // Back substitution
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                result[i] -= matrix[i][j] * result[j];
            }
        }
    }
    

    
private:

};
