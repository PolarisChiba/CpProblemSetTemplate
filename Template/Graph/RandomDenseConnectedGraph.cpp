// include RandomTree.cpp (line 8)

// 0-based
vector<pair<int, int>> RandomDenseConnectedGraph(int n, int m) {
    // n - 1 <= m
    // m close to n*(n-1)/2

    auto v = RandomTree(n);
    set<pair<int, int>> s;
    for (auto i : v) s.insert(i);

    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++ i)
        for (int j = i + 1; j < n; ++ j)
            if (s.find({i, j}) == s.end() && s.find({j, i}) == s.end())
                u.push_back({i, j});

    shuffle(u.begin(), u.end());
    for (int i = n; i <= m; ++ i) v.push_back(u[i - n]);

    return v;
}