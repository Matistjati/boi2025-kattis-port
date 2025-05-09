#include "validator.h"

void run() {
	int n = Int(1, Arg("n"));
	Endl();

	for (int i = 0; i < n; i++)
		SpacedInts(n - i, 1, n);

	int is_bo = (int)Arg("is_bo", 0); // we trust that the files are faithful
	int is_noeqconsec = (int)Arg("is_noeqconsec", 0); // we trust that the files are faithful
}
