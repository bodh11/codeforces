// https://c...content-available-to-author-only...s.com/problemset/problem/580/C
#include<bits/stdc++.h>

using namespace std;

# define sz(x) (int)(x.size())

int ans;
int maxCatAllowed;
int visited[123456];

void dfs(vector<int> G[], vector<int> &catPos,int ind, int cats) {

    visited[ind] = 1;
    // added cat on this node
    if(catPos[ind] == 1) cats++;
    else cats = 0;
    // prune
    if(cats > maxCatAllowed) return;

    int isLeaf = 1;
    for(int i = 0; i < sz(G[ind]); i++) {
        int v = G[ind][i];
        if(visited[v] == 0) {
            isLeaf = 0;
            dfs(G, catPos, v, cats);
        }
    }
    if(isLeaf) {
        // you can visit this restaurant
        if(cats <= maxCatAllowed) ans++;
    }
}

int main() {
    
    
    int n, m;
    cin >> n >> m;
    maxCatAllowed = m;
    
    for(int i = 0; i <= n; i++) 
     visited[i] = 0;

    vector<int> catPos;
    for(int i = 0; i < n; i++) {
        int isCat; cin >> isCat;
        catPos.push_back(isCat);
    }

    vector<int> G[n + 1];
    // un-directed graph
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

     ans = 0;
     dfs(G, catPos, 0, 0);
     cout << ans << endl;
    return 0;
}
