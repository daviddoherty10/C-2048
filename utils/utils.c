#include <stdlib.h>

int secure_rand_int(int maxRange) { return arc4random_uniform(maxRange); }
