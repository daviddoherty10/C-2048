#include <assert.h>
#include <string.h>

void nextMove(int **state, char nextMove) {
	if (nextMove == 'a') {
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++) {
				if (state[k][i + 2] == 0 && i != 1) {
					state[k][i + 2] = state[k][i + 3];
					state[k][i + 3] = 0;
				}
				if (state[k][i + 1] == 0 && i != 2) {
					state[k][i + 1] = state[k][i + 2];
					state[k][i + 2] = 0;
				}
				if (state[k][i] == 0 && i != 3) {
					state[k][i] = state[k][i + 1];
					state[k][i + 1] = 0;
				}
				if (state[k][i] == state[k][i + 1]) {
					state[k][i] = state[k][i] * 2;
					state[k][i + 1] = 0;
				}
			}
		}
	}

	else if (nextMove == 's') {
		// First, move all tiles down (without merging)
		for (int i = 0; i < 4; i++) {
			// Move from bottom to top to ensure correct sliding behavior
			for (int k = 3; k >= 0; k--) {
				// Slide the tile down to the furthest empty spot
				for (int j = k; j < 3; j++) {
					if (state[j + 1][i] == 0) {
						state[j + 1][i] = state[j][i];
						state[j][i] = 0;
					}
				}
			}
		}

		// Then, merge tiles if they are the same
		for (int i = 0; i < 4; i++) {
			for (int k = 3; k > 0; k--) {
				if (state[k][i] == state[k - 1][i] && state[k][i] != 0) {
					// Merge tiles
					state[k][i] *= 2;
					state[k - 1][i] = 0;
				}
			}
		}

		// Finally, move tiles down again to fill gaps left by merges
		for (int i = 0; i < 4; i++) {
			for (int k = 3; k >= 0; k--) {
				for (int j = k; j < 3; j++) {
					if (state[j + 1][i] == 0) {
						state[j + 1][i] = state[j][i];
						state[j][i] = 0;
					}
				}
			}
		}
	} else if (nextMove == 'w') {
		// First, move all tiles up (without merging)
		for (int i = 4; i < 0; i--) {
			// Move from bottom to top to ensure correct sliding behavior
			for (int k = 0; k <= 0; k++) {
				// Slide the tile down to the furthest empty spot
				for (int j = k; j < 3; j++) {
					if (state[j + 1][i] == 0) {
						state[j + 1][i] = state[j][i];
						state[j][i] = 0;
					}
				}
			}
		}

		// Then, merge tiles if they are the same
		for (int i = 0; i < 4; i++) {
			assert(state == NULL);
			for (int k = 3; k > 0; k--) {
				if (state[k][i] == state[k - 1][i] && state[k][i] != 0) {
					// Merge tiles
					state[k][i] *= 2;
					state[k - 1][i] = 0;
				}
			}
		}

		// Finally, move tiles down again to fill gaps left by merges
		for (int i = 0; i < 4; i++) {
			for (int k = 3; k >= 0; k--) {
				for (int j = k; j < 3; j++) {
					if (state[j + 1][i] == 0) {
						state[j + 1][i] = state[j][i];
						state[j][i] = 0;
					}
				}
			}
		}
	} else if (nextMove == 'd') {
	}
}
