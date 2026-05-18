#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    int id;
    double priority;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ll> skill(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> skill[i];
    }

    // Graph
    vector<vector<int>> adj(N + 1);
    vector<int> degree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    // Compute heuristic priority
    vector<Node> nodes;

    for (int i = 1; i <= N; i++) {

        // Higher skill and lower conflicts preferred
        double priority = (double)skill[i] / (degree[i] + 1);

        nodes.push_back({i, priority});
    }

    // Sort descending by priority
    sort(nodes.begin(), nodes.end(),
         [&](const Node &a, const Node &b) {

             if (fabs(a.priority - b.priority) > 1e-12)
                 return a.priority > b.priority;

             return skill[a.id] > skill[b.id];
         });

    vector<bool> selected(N + 1, false);
    vector<bool> blocked(N + 1, false);

    vector<int> answer;
    ll totalSkill = 0;

    // Greedy independent set construction
    for (auto &node : nodes) {

        int u = node.id;

        if (blocked[u])
            continue;

        // Select node
        selected[u] = true;
        answer.push_back(u);
        totalSkill += skill[u];

        // Block all neighbors
        blocked[u] = true;

        for (int v : adj[u]) {
            blocked[v] = true;
        }
    }

    // Sort indices as required
    sort(answer.begin(), answer.end());

    // Output
    cout << totalSkill << '\n';

    for (int x : answer) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}