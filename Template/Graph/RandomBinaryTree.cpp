#include "testlib.h"
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> RandomBinaryTree(int n) { // rooted at 0
  std::vector<std::pair<int, int>> v(n, std::make_pair(-1, -1));
  std::vector<int> cand{0, 0};
  for (int i = 1; i < n; ++ i) {
    int p = rnd.next(0, (int)cand.size() - 1);
    if (v[cand[p]].first == -1) {
      v[cand[p]].first = i;
    } else {
      v[cand[p]].second = i;
    }
    cand.insert(cand.end(), {i, i});
    std::swap(cand[p], cand.back());
    cand.pop_back();
  }
  for (int i = 0; i < n; ++ i) {
    if (rnd.next(1, 2) == 1) {
      std::swap(v[i].first, v[i].second);
    }
  }
  return v;
}