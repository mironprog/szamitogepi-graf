#include "matrix.h"

int main(int argc, char* argv[])
{

    float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };

    float b[3][3];

    print_matrix(a);
    init_identity_matrix(b);
    print_matrix(b);

    scalar_multiplication(3,b);
    print_matrix(b);

    float c[3][3];
    multiply_matrices(a, b, c);
    print_matrix(c);

    return 0;
}