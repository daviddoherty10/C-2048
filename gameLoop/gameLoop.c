#include "gameLoop.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../edgeDetection/nextMove.h"
#include "../screen/clearScreen.h"
#include "../screen/drawScreen.h"
#include "../takeInput/takeInput.h"
#include "../utils/utils.h"

struct Positions {
	int x;
	int y;
};

int gameLoop(char *flags) {
	int nextCollum = (rand() % 5) - 1;
	int nextRow = (rand() % 5) - 1;
	int drawScreenError = 0;
	int counter = 0;
	char *userMovement = NULL;
	char listOfInstructions[2] = {'a', 's'};

	if (strcmp(flags, "test") == 0) {
		counter = 300;
	} else {
		counter = 100000;
	}

	int **state = (int **)calloc(4, sizeof(int *));
	if (state == NULL) {
		printf("State was null. Main:35");
		abort();
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		state[i] = (int *)calloc(4, sizeof(int));
		if (state[i] == NULL) {
			printf("Memory allocation failed for row %d\n", i);
			for (int j = 0; j < i; j++) {
				free(state[j]);
			}
			free(state);
			return 1;
		}
	}

	if (nextCollum + 2 < 4) {
		state[nextRow][nextCollum] = 2;
		state[nextRow][nextCollum + 2] = 2;
	}

	// Main Game Loop

	for (int i = 0; i < counter; i++) {
		clearScreen();
		drawScreenError = drawScreen(state);
		if (drawScreenError == 1) {
			printf("Null Pointer");
		}

		if (strcmp(flags, "test") == 0) {
			userMovement = &listOfInstructions[secure_rand_int(2)];
		} else {
			userMovement = takeInput("");
		}

		nextMove(state, *userMovement);

		clearScreen();

		struct Positions freeSquares[15] = {{0, 0}};
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

		if (index > 0) {
			int randIndex = secure_rand_int(index);
			state[freeSquares[randIndex].y][freeSquares[randIndex].x] = 2;
		}
	}

	drawScreenError = drawScreen(state);
	if (drawScreenError == 1) {
		printf("Null Pointer");
	}

	for (int i = 0; i < 4; i++) {
		free(state[i]);
	}
	free(state);

	return 0;
}
