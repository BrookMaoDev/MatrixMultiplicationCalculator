/**
 * @author Brook Mao
 * @date March 8, 2024
 * Matrix Multiplication Algorithm
 * Time Complexity: O(n^3)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MATRIX_COL_WIDTH 10

int **create_matrix(int rows, int cols)
{
    // Allocate memory for matrix.
    int **m = calloc(rows, sizeof(int *));

    // Create rows.
    for (int i = 0; i < rows; i++)
    {
        m[i] = calloc(cols, sizeof(int));
    }

    return m;
}

/**
 * @param length equivalent to m1_col or m2_row
 * @returns the dot product of the m1_row in m1 with the m2_col in m2.
 */
int dot_product(int **m1, int m1_row, int **m2, int m2_col, int length)
{
    int result = 0;

    for (int i = 0; i < length; i++)
    {
        result += m1[m1_row][i] * m2[i][m2_col];
    }

    return result;
}

/**
 * @param m1 the left matrix
 * @param m2 the right matrix
 * @returns a pointer to the multiplied matrix with m1_rows rows and m2_cols columns.
 */
int **matrix_multiply(int **m1, int m1_rows, int m1_cols, int **m2, int m2_rows, int m2_cols)
{
    // Check if the matrices can be multiplied.
    if (m1_cols != m2_rows)
    {
        return NULL;
    }

    int **result = create_matrix(m1_rows, m2_cols);

    // Populating the result matrix with the appropriate values.
    for (int i = 0; i < m1_rows; i++)
    {
        for (int j = 0; j < m2_cols; j++)
        {
            result[i][j] = dot_product(m1, i, m2, j, m1_cols);
        }
    }

    return result;
}

void print_matrix(int **m, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%-*d", MATRIX_COL_WIDTH, m[i][j]);
        }
        printf("\n");
    }
}

void populate_matrix(int **m, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter value for row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &(m[i][j]));
            getchar();
        }
    }
}

void free_matrix(int **m, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(m[i]);
    }

    free(m);
}

int main()
{
    while (true)
    {
        // Get info about size of matrices.

        int m1_rows;
        int m1_cols;
        int m2_rows;
        int m2_cols;

        printf("Please enter information about the matrices you want to multiply!\n\n");

        printf("Entering information for m1:\n");

        printf("Enter rows: ");
        scanf("%d", &m1_rows);
        getchar();

        printf("Enter cols: ");
        scanf("%d", &m1_cols);
        getchar();

        printf("\n");

        printf("Entering information for m2:\n");

        printf("Enter rows: ");
        scanf("%d", &m2_rows);
        getchar();

        printf("Enter cols: ");
        scanf("%d", &m2_cols);
        getchar();

        printf("\n");

        if (m2_rows != m1_cols)
        {
            printf("The number of rows in m2 must match the number of columns in m1. Please try again!\n");
            continue;
        }

        // Create matrices.

        int **m1 = create_matrix(m1_rows, m1_cols);
        int **m2 = create_matrix(m2_rows, m2_cols);

        printf("Entering information for m1:\n");
        populate_matrix(m1, m1_rows, m1_cols);
        printf("\n");
        print_matrix(m1, m1_rows, m1_cols);

        printf("\n");

        printf("Entering information for m2:\n");
        populate_matrix(m2, m2_rows, m2_cols);
        printf("\n");
        print_matrix(m2, m2_rows, m2_cols);

        printf("\n");

        // Output result.

        printf("Result of multiplying m1 by m2:\n");
        int **result = matrix_multiply(m1, m1_rows, m1_cols, m2, m2_rows, m2_cols);
        print_matrix(result, m1_rows, m2_cols);
        printf("\n");

        // Free allocated memory.

        free_matrix(m1, m1_rows);
        free_matrix(m2, m2_rows);
        free_matrix(result, m1_rows);

        // Prompt user if they want to continue.

        printf("Do you want to continue multiplying matrices? Enter 'y' if so: ");
        char response;
        scanf("%s", &response);
        getchar();

        if (response != 'y')
        {
            printf("\nGoodbye!");
            break;
        }

        printf("\n");
    }

    return 0;
}
