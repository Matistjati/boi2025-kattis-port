#include "validator.h"

void run() {
	int n = Int(1, Arg("n"));
	Endl();

	vector<int> a_vals = SpacedInts(n, 0, (int)Arg("a_max"));

	if ((int)Arg("is_inc", 0)) {
		for (int i = 0; i < n-1; i++)
			assert(a_vals[i] < a_vals[i+1]);
	}
}
