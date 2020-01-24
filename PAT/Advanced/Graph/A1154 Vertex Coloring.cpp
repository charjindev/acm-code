// https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, u, v;
    scanf("%d%d", &n, &m);
    vector<pair<int, int> > e(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        e[i] = pair<int, int>(u, v);
    }
    scanf("%d", &k);
    while (k--) {
        vector<int> color(n);
        unordered_set<int> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (color[e[i].first] == color[e[i].second]) {
                flag = false;
                break;
            }
        }
        if (flag) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int main() {
    int n, m, u, v, k, c;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> e;
    while (m--) {
        scanf("%d%d", &u, &v);
        e.push_back({u, v});
    }
    scanf("%d", &k);
    int color[N];
    while (k--) {
        unordered_set<int> s;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        for (int i = 0; i < e.size(); i++) {
            if (color[e[i].first] == color[e[i].second]) {
                flag = false;
                break;
            }
        }
        if (flag) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
    return 0;
}
*/