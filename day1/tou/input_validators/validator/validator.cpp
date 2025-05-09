#include "validator.h"

void run() {
	int t = Int(1, (int)Arg("t"));
	Endl();

	int nsum = 0;
	int msum = 0;

	int np = Arg("n");
	int mp = Arg("m");

	while (t--) {
		int n = Int(2, np);
		Space();
		int m = Int(1, mp);
		Endl();

		nsum += n;
		msum += m;

		for (int i = 0; i < m; i++) {
			int x = Int(1, n);
			Space();
			int y = Int(1, n);
			Space();
			int c = Int(1, m);
			Endl();
			assert(x != y);
		}
	}

	assert(nsum <= (int)Arg("N", 1e6));
	assert(msum <= (int)Arg("M", 1e6));
}
