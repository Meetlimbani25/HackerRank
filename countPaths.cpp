#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;

// Helper functions for string handling
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// DFS to find reachable nodes
void dfsReachable(int node, vector<vector<int>>& graph, vector<bool>& reachable) {
    reachable[node] = true;
    for (int neighbor : graph[node]) {
        if (!reachable[neighbor]) {
            dfsReachable(neighbor, graph, reachable);
        }
    }
}

// DFS to detect cycle in graph
bool dfsCycle(int node, vector<vector<int>>& graph, vector<bool>& visited,
              vector<bool>& inStack, vector<bool>& reachable_from_start, vector<bool>& reachable_to_end) {
    visited[node] = true;
    inStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!reachable_from_start[neighbor] || !reachable_to_end[neighbor]) continue;

        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, graph, visited, inStack, reachable_from_start, reachable_to_end)) {
                return true;
            }
        } else if (inStack[neighbor]) {
            return true;
        }
    }

    inStack[node] = false;
    return false;
}

// DFS for topological sort
void dfsTopo(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& topo_order) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsTopo(neighbor, graph, visited, topo_order);
        }
    }
    topo_order.push_back(node);
}

// Main logic function
void countPaths(int n, vector<vector<int>> edges) {
    vector<vector<int>> adj(n + 1), rev_adj(n + 1);

    // Build graph and reverse graph
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<bool> reachable_from_start(n + 1, false);
    vector<bool> reachable_to_end(n + 1, false);

    // Mark reachable nodes from start (1) and to end (n)
    dfsReachable(1, adj, reachable_from_start);
    dfsReachable(n, rev_adj, reachable_to_end);

    // Detect cycles on the valid path (from 1 to n)
    vector<bool> visited(n + 1, false), inStack(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (reachable_from_start[i] && reachable_to_end[i] && !visited[i]) {
            if (dfsCycle(i, adj, visited, inStack, reachable_from_start, reachable_to_end)) {
                cout << "INFINITE PATHS" << endl;
                return;
            }
        }
    }

    // Topological sort
    visited.assign(n + 1, false);
    vector<int> topo_order;
    for (int i = 1; i <= n; i++) {
        if (reachable_from_start[i] && !visited[i]) {
            dfsTopo(i, adj, visited, topo_order);
        }
    }

    reverse(topo_order.begin(), topo_order.end());

    // DP to count number of paths
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;

    for (int u : topo_order) {
        for (int v : adj[u]) {
            if (reachable_from_start[v] && reachable_to_end[v]) {
                dp[v] = (dp[v] + dp[u]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
}

// ---------- MAIN AND INPUT HANDLING ----------
int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int nodes = stoi(first_multiple_input[0]);
    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);
            edges[i][j] = edges_row_item;
        }
    }

    countPaths(nodes, edges);

    return 0;
}

// ---------- STRING UTILS ----------
string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(),
        not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(),
        not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0, end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
