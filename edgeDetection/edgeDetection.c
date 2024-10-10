void nextMove(int **state, char nextMove) {
	if (nextMove == 'a') {
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++) {
				if (state[k][i] != 0) {
					if (state[k][i + 1] == state[k][i]) {
						state[k][i] = state[k][i] * 2;
					}
				}
			}
		}
	}

	else if (nextMove == 'd') {
		for (int k = 4; k > 0; k--) {
			for (int i = 0; i < 4; i++) {
				if (state[k][i] != 0) {
					if (state[k][i - 1] == state[k][i]) {
						state[k][i] = state[k][i] * 2;
					}
				}
			}
		}
	}
}

void edgeDection() {}
