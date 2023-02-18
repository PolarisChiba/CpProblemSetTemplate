#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 1-based
class ParentGenerator {
    public:
        void push(int x) {
            for (int _ = 0; _ < 2; ++ _) {
                pool.push_back(x);
                swap(pool[rnd.next(0, (int)pool.size() - 1)], pool.back());
            }
        }
        int pop() {
            int p = rnd.next(0, (int)pool.size() - 1);
            int x = pool[p];
            swap(pool[p], pool.back());
            pool.pop_back();
            return x;
        }

        ParentGenerator(int r) {
            pool.clear();
            push(r);
        }
    private:
        vector<int> pool;
};

class BinaryTree {
    public:
        BinaryTree(int n, int r):root(r) {
            v.assign(n + 1, vector<int>(0));
        }
        void add_pedge(int p, int a) {
            // 1 ~ n
            v[p].push_back(a);
        }
        void set_child() { // the left, right child
            for (auto &i : v) {
                if (i.empty()) {
                    i.push_back(0);
                    i.push_back(0);
                } else if ((int)i.size() == 1) {
                    i.push_back(0);
                    if (rnd.next(0, 1) == 0) swap(i.front(), i.back());
                }
            }
        }

    private:
        int root;
        vector<vector<int>> v;
};

BinaryTree GenerateBinaryTree(int n) {
    ParentGenerator pg(1); // rooted at 1
    BinaryTree bt(n, 1);
    for (int i = 2; i <= n; ++ i) {
        int p = pg.pop();
        bt.add_pedge(p, i);
        // cout << p << " " << i << "\n";
        pg.push(i);
    }
    bt.set_child();
    return bt;
}
