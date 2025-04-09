#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    float a[10][10];

    cout << "Gauss Elimination Method with Partial Pivoting\n\n";
    cout << "Enter the number of equations (matrix size n x n): ";
    cin >> n;

    // Input augmented matrix (including constants)
    cout << "\nEnter the augmented matrix (each row should include coefficients and constant term):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n+1; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    // Partial pivoting to make matrix diagonally dominant
    for(int i = 0; i < n; i++) {
        // Find the row with maximum element in current column
        int max_row = i;
        float max_val = abs(a[i][i]);
        for(int k = i+1; k < n; k++) {
            if(abs(a[k][i]) > max_val) {
                max_val = abs(a[k][i]);
                max_row = k;
            }
        }

        // Swap the maximum row with current row
        if(max_row != i) {
            for(int j = 0; j <= n; j++) {
                swap(a[i][j], a[max_row][j]);
            }
        }

        // Check for singularity
        if(a[i][i] == 0) {
            cout << "\nMatrix is singular or not diagonally dominant!\n";
            return 1;
        }

        // Gaussian elimination
        for(int k = i+1; k < n; k++) {
            float factor = a[k][i] / a[i][i];
            for(int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Back substitution
    float x[10];
    for(int i = n-1; i >= 0; i--) {
        x[i] = a[i][n];
        for(int j = i+1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Display solution
    cout << "\nSolution:\n";
    for(int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}

