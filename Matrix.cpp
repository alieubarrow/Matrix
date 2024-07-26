//Header files
#include <iostream>
#include <cstring>
#include  <cstdlib>
#include <iomanip>
using namespace std;

const int MAXDIM = 5; // max number of rows and columns supported by program
typedef double Matrix[MAXDIM][MAXDIM];

void readMatrix(Matrix M, int row, int col);
// Reads a matrix with row number of rows and col number of columns

void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p);
// Multiplies m*p-matrix A with p?n matrix B and stores the result in the m*n-matrix C

void printMatrix(const Matrix M, int row, int col);
// Prints the matrix M

int main() {

        int m, p, n;
        Matrix A, B, C;
        char answer;

        cout << "Matrix Multiplication" << endl;
        cout << "==================" << endl;

        do {
                cout << "Enter dimesnsion of matrix A (row * col) with space between: ";
                cin >> m >> p;

                readMatrix(A, m, p); //Read Matrix A

                cout << "Enter dimesnsion of matrix B (row * col) with space between: ";
                cin >> p >> n;

                readMatrix(B, p, n); //Read Maxtric B
                multMatrix(A, B, C, m, n, p); //Multiply matrices

                printMatrix(C, m, n); //Print matrices

                cout << "One more time (Y/N)?: ";
                cin >> answer;

        } while (toupper(answer) == 'Y');
}

//Function reads matrices
void readMatrix(Matrix M, int row, int col) {

        M[row][col];

        cout << "Enter matrix A in free format: " << endl;

        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                        cin >> M[i][j];
                }
        }
}

//Function mutiplies matrices
void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p) {

        C[m][n];

        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        for (int k = 0; k < p; k++) {
                                C[i][j] += A[i][k] * B[k][j];
                        }
                }
        }
}

//Function prints matrices 
void printMatrix(const Matrix M, int row, int col) {

        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                        cout << fixed << showpoint << setprecision(1) << M[i][j];
                }
                cout << endl;
        }
        cout << endl;
}