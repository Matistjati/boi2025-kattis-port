#include "validator.h"

void run() {
	int n = Int(2, Arg("n"));
	Endl();

	SpacedInts(n, 1, (int)1e7);
}
