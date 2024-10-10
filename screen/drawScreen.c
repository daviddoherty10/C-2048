#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
/*
int **multiply(int matrix1[6][2], int matrix2[2][6], int rows1, int cols1,
			   int rows2, int cols2, int *error) {
	// Check that the Matrixs have been defined
	if (matrix1 == NULL || matrix2 == NULL) {
		*error = 1;	 // Error: One of the matrices is NULL
		return NULL;
	}

	// Check if matrix dimensions are valid for multiplication
	if (cols1 != rows2) {
		*error =
			2;	// Error: Matrices can't be multiplied due to dimension mismatch
		return NULL;
	}

	int **returnMatrix = (int **)malloc(rows1 * sizeof(int *));
	for (int i = 0; i < rows1; i++) {
		returnMatrix[i] = (int *)malloc(cols2 * sizeof(int));
	}

	// Perform matrix multiplication
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			returnMatrix[i][j] = 0;
			for (int k = 0; k < cols1; k++) {
				returnMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	*error = 0;
	return returnMatrix;
}

int main(void) {
	int error = 0;

	// Define two matrices with appropriate sizes
	int matrix1[6][2] = {
		{2, 4}, {5, 6}, {6, 3}, {5, 3}, {2, 4}, {5, 6},
	};
	int matrix2[2][6] = {
		{2, 4, 1, 2, 3, 4},
		{5, 6, 7, 8, 9, 0},
	};

	// Multiply matrix1 (6x2) with matrix2 (2x6)
	int **result = multiply(matrix1, matrix2, 6, 2, 2, 6, &error);

	if (error != 0) {
		printf("Error: %d\n", error);
		return 1;  // Exit with an error
	}

	// Print the result matrix
	printf("Result matrix:\n");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	// Free the allocated memory
	for (int i = 0; i < 6; i++) {
		free(result[i]);
	}

	free(result);

	return 0;
}*/

int getTerminalWidth() {
	struct winsize w;
	// Use ioctl to get terminal size
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;  // Return the number of columns (width)
}

int getTerminalHeight() {
	struct winsize w;
	// Use ioctl to get terminal size
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;  // Return the number of columns (width)
}

int drawScreen(int **state) {
	int screenWidth = getTerminalWidth();
	int screenHeight = getTerminalHeight();

	if (state == NULL) {
		return 1;
	}
	for (int i = 0; i < ((screenHeight / 2) - 4); i++) {
		printf("\n");
	}
	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < ((screenWidth / 2) - 4); i++) {
			printf(" ");
		}

		for (int j = 0; j < 4; j++) {
			if (state[i][j] < 10) {
				printf("  %d  ", state[i][j]);
			} else if (state[i][j] < 100) {
				printf(" %d  ", state[i][j]);
			} else if (state[i][j] < 1000) {
				printf("%d ", state[i][j]);
			} else if (state[i][j] < 10000) {
				printf("%d ", state[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
