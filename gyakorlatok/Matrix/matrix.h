#ifndef MATRIX_H
#define MATRIX_H

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);


/**
 * Initializes the the identity matrix
*/
void init_identity_matrix(float matrix[3][3]);

/*
 * Performs scalar  multiplication
*/
void scalar_multiplication(int scalar, float matrix[3][3]);

/*
 * Multiplies matrices
*/
float multiply_matrices(float matrix1[3][3], float matrix2[3][3], float result_matrix[3][3]);


#endif // MATRIX_H