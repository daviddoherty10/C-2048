#include <stdio.h>
#include <stdlib.h>

char *takeInput(const char *prompt) {
	printf("%s", prompt);
	char *input = calloc(1, sizeof(char));
	if (input == NULL) {
		return NULL;
	}
	scanf("%s", input);
	return input;
}
