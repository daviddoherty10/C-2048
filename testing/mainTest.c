#include <stdio.h>
#include <stdlib.h>

#include "./../edgeDetection/nextMove.h"
#include "./../screen/clearScreen.h"
#include "./../screen/drawScreen.h"
#include "./../takeInput/takeInput.h"
#include "./../utils/utils.h"

struct Positions {
	int x;
	int y;
};

int main(void) {
	int nextCollum = (rand() % 5) - 1;
	int nextRow = (rand() % 5) - 1;
	int drawScreenError = 0;
	char *userMovement = "";

	// Correct allocation: 4 rows of int pointers
	int **state = (int **)calloc(4, sizeof(int *));
	for (int i = 0; i < 4; i++) {
		// Correct allocation: each row has 4 integers
		state[i] = (int *)calloc(4, sizeof(int));
	}
	if (state == NULL) {
		printf("State was null. Main:28");
		return 1;
	}
	state[nextRow][nextCollum] = 2;
	state[nextRow][nextCollum + 2] = 2;

	char commandList[2] = {'a', 's'};

	for (int i = 0; i < 1000; i++) {
		clearScreen();
		drawScreenError = drawScreen(state);
		if (drawScreenError == 1) {
			printf("Null Pointer");
		}

		userMovement = &commandList[secure_rand_int(2)];
		nextMove(state, *userMovement);

		clearScreen();

		struct Positions freeSquares[15] = {};
		int index = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (state[i][j] == 0) {
					freeSquares[index].x = j;
					freeSquares[index].y = i;
					index++;
				}
			}
		}

		state[freeSquares[secure_rand_int(index)].y]
			 [freeSquares[secure_rand_int(index)].x] = 2;
	}

	drawScreenError = drawScreen(state);
	if (drawScreenError == 1) {
		printf("Null Pointer");
	}

	// Free allocated memory
	for (int i = 0; i < 4; i++) {
		free(state[i]);
	}
	free(state);

	return 0;
}
