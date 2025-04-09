#include<iostream>
using namespace std;

int main() {
    // Variable Declarations
    int i, j, k, n;           // Loop counters and matrix size
    float a[10][10], b, x[10];// a = augmented matrix, b = scaling factor, x = solution vector

    // Input: Matrix Size
    printf("\nEnter the size of matrix (number of equations): ");
    scanf("%d", &n);

    // Input: Augmented Matrix (coefficients + constants)
    printf("\nEnter the elements of augmented matrix (row-wise):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= (n + 1); j++) {
            cout << "A[" << i << ", " << j << " ]=";
            cin >> a[i][j];
            // Example for n=2: 
            // [ A[1,1] A[1,2] | A[1,3] ]   (represents 1st equation)
            // [ A[2,1] A[2,2] | A[2,3] ]   (represents 2nd equation)
        }
    }

    // Gaussian Elimination: Convert to Diagonal Matrix
    for(j = 1; j <= n; j++) {
        // For each column j (current pivot column)
        for(i = 1; i <= n; i++) {
            if(i != j) {  // Skip the pivot row
                // Calculate scaling factor to make a[i][j] zero
                b = a[i][j] / a[j][j];
                
                // Row operation: R_i = R_i - b*R_j
                for(k = 1; k <= n + 1; k++) { 
                    a[i][k] = a[i][k] - b * a[j][k];
                    // This zeros out a[i][j] while preserving other relationships
                }
            }
        }
    }

    // Back Substitution: Solve for variables
    cout << "\nThe solution is:\n";
    for(i = 1; i <= n; i++) {
        // x_i = constant term / diagonal coefficient
        x[i] = a[i][n + 1] / a[i][i];
        cout << "x" << i << " = " << x[i] << " ";
    }

    return 0;
}
