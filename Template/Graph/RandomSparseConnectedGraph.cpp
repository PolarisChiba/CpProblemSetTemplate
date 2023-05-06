// include random_tree (line 7)

// 0-based
vector<pair<int, int>> RandomSparseConnectedGraph(int n, int m) {
    // n - 1 <= m

    auto v = RandomTree(n);
    set<pair<int, int>> s;
    for (auto i : v) s.insert(i);

    while ((int)v.size() < m) {
        int a = rnd.next(0, n - 1);
        int b = rnd.next(0, n - 1);
        if (a == b || s.find({a, b}) != s.end() || s.find({b, a}) != s.end()) continue;
        
        v.push_back({a, b});
        s.insert({a, b});
    }
    return v;
}