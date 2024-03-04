#include "matrix.h"

#include <stdio.h>

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        
        for (j = 0; j < 3; j++) {
            
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void scalar_multiplication(int scalar, float matrix[3][3]) 
{
    int i;
    int j;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

float multiply_matrices(float matrix1[3][3], float matrix2[3][3], float result_matrix[3][3])
{
    
    int i;
    int j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++ ) {
            result_matrix[i][j]=matrix1[i][j] * matrix2[i][j];
        }
    }

    return result_matrix[3][3];
}