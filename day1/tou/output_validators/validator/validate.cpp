#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  init_io(argc, argv);

  int t = 0;
  judge_in >> t;

  while (t--) {
    int n, m;
    judge_in >> n >> m;

    vector<tuple<int, int, int>> edgs;
    for (int i = 0; i < m; i++) {
      int x, y, c;
      judge_in >> x >> y >> c;
      x--, y--, c--;

      edgs.emplace_back(x, y, c);
    }

    auto validate = [&](vector<int> medgs, feedback_function feedback) {
      int firstc = -1;
      int firstn = -1;
      int prev = -1;
      int nod = -1;
      for (auto edg : medgs) {
        auto [x, y, c] = edgs[edg];

        if (firstc == -1) {
          firstc = c;
          firstn = x;
          prev = c;
          nod = y;
          continue;
        }

        if (nod != x)
          feedback("The cycle is not connected");
        if (prev == c)
          feedback("The cycle has two connected edges of the same color");
        nod = y;
        prev = c;
      }

      if (nod != firstn)
        feedback("The cycle is not connected");
      if (prev == firstc)
        feedback("The cycle has two connected edges of the same color");
    };

    auto check = [&](istream &sol, feedback_function feedback) -> bool {
      string pos;
      if (!(sol >> pos))
        feedback("Expected more output");
      if (pos == "NO") {
        return 0;
      } else if (pos != "YES") {
        feedback("The solution answers neither YES or NO");
      }

      int k;
      if (!(sol >> k))
        feedback("Expected more output");

      if (k > m)
        feedback("The solution uses too many edges");
      if (k < 0)
        feedback("The solution uses a negative amount of edges");

      vector<int> edgs(k);
      for (auto &i : edgs) {
        if (!(sol >> i))
          feedback("Expected more output");
        i--;
        if (i < 0 || i >= m)
          feedback("One edge is not in [1, m]");
      }

      validate(edgs, feedback);

      return 1;
    };

    bool judge_found_sol = check(judge_ans, judge_error);
    bool author_found_sol = check(author_out, wrong_answer);

    if (judge_found_sol && !author_found_sol)
      wrong_answer("Valid moves exists, but solution did not find it");
    if (!judge_found_sol && author_found_sol)
      judge_error("NO! Solution found valid moves, but judge says none exists");
  }

  accept();
}
