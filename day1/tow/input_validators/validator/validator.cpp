#include "validator.h"

void run() {
	Int(0, 100);
	Endl();

	int t = Int(1, 100);
	Space();

	{
		int kp = Arg("k");
		int k100p = Arg("k100");

		int k0 = Int(kp, kp);
		Space();
		int k100 = Int(k100p, k100p);
		Endl();
	}

	int is_halfset = Arg("is_halfset", 0);

	int nlp = Arg("nl");
	int nhp = Arg("nh");

	while (t--) {
		int n = Int(nlp, nhp);
		Endl();
		vector<int> seen(n, -1);
		for (int i = 0; i < n; i++) {
			int tmp = Int(0, n-1);
			if (i < n-1) Space();
			assert(seen[tmp] == -1);
			seen[tmp] = i;
		}

		Endl();

		if (is_halfset) {
			for (int i = n / 2; i < n; i++) {
				assert(seen[i] == i);
			}
		}
	}
}
