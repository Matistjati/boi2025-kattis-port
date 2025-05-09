#include "validator.h"

void run() {
	int n = Int(1, Arg("n"));
	Space();
	int q = Int(1, Arg("q"));
	Endl();

	SpacedInts(n, 0, (int)Arg("a_max"));

	for (int i = 0; i < q; i++) {
		int l = Int(1, n);
		Space();
		Int(l, n);
		Endl();
	}
}
