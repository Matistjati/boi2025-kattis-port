#include "validate.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  init_io(argc, argv);

  int score;
  judge_in >> score;
  int t, k0, k100;
  int total_queries = 0;
  judge_in >> t >> k0 >> k100;

  cout << t << ' ' << k0 << endl;

  for (int _ = 0; _ < t; _++) {
    int n;
    judge_in >> n;

    cout << n << endl;

    vector<int> perm(n);
    vector<int> perm_to_idx(n + 1);
    for (int i = 0; i < n; i++) {
      judge_in >> perm[i];
      perm_to_idx[perm[i]] = i;
    }

    string op;
    while (true) {
      if (!(cin >> op))
        wrong_answer("No operation sent");

      if (op == "!") {
        vector<int> usr_perm(n);
        int usr_strt = -1;
        for (auto &i : usr_perm) {
          if (!(cin >> i))
            wrong_answer("Too few numbers in answer");
        }

        int step = 0;

        for (int i = 0; i < n; i++) {
          if (usr_perm[i] == perm[0]) {
            usr_strt = i;
            if (usr_perm[(i + 1) % n] == perm[1])
              step = 1;
            else
              step = -1;
            break;
          }
        }

        if (usr_strt == -1)
          wrong_answer("The permutations do not match");

        if (step == 0)
          judge_error("Step is somehow zero");

        for (int i = 0; i < n; i++, usr_strt = (usr_strt + step + n) % n)
          if (perm[i] != usr_perm[usr_strt])
            wrong_answer("The permutations do not match");

        break;
      }

      if (op != "?")
        wrong_answer(("Invalid query start, it began with: " + op).c_str());

      total_queries++;

      array<int, 3> inp;
      for (int i = 0; i < 3; i++)
        if (!(cin >> inp[i]))
          wrong_answer("Too few numbers in query");
      sort(inp.begin(), inp.end());

      array<tuple<int, int, int>, 3> dists;

      int cntr = 0;
      for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
          int d0 = perm_to_idx[inp[i]];
          int d1 = perm_to_idx[inp[j]];
          int dist = min(abs(d1 - d0), min(d0 + n - d1, d1 + n - d0));

          dists[cntr++] = {dist, i, j};
        }
      }

      sort(dists.begin(), dists.end());

      int num = 1;
      for (int i = 1; i < 3; i++) {
        if (get<0>(dists[i]) == get<0>(dists[i - 1]))
          num++;
        else
          break;
      }

      cout << num << endl;
      for (int i = 0; i < num; i++) {
        cout << inp[get<1>(dists[i])] << ' ' << inp[get<2>(dists[i])] << endl;
      }
    }
  }

  if (total_queries > k0 * t)
    wrong_answer("Too many queries");

  if (k0 == k100) {
    accept_with_score(score);
  } else {
    double avg_q = (double)total_queries / t;
    accept_with_score((int)(floor(
        score * min(1.0, max(0.0, (k0 - avg_q) / (k0 - k100 - 1000))))));
  }
}
