#include<bits/stdc++.h>
using namespace std;

int cnt[100]{0};
int maxDepth = 0;


void dfs(vector<vector<int>>&tree,int id,int depth){
    maxDepth = max(maxDepth, depth);
    if(tree[id].size()==0){
        cnt[depth]++;
    }
    for (int i = 0; i < tree[id].size();i++){
        dfs(tree, tree[id][i], depth + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m,parent,child,k;
    cin >> n >> m;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < m;i++){
        cin >> parent >> k;
        for (int j = 0; j < k;j++){
            cin >> child;
            tree[parent].push_back(child);
        }
    }

    dfs(tree, 1, 0);
    for (int i = 0; i <= maxDepth;i++){
        if(i!=0)
            cout << ' ';
        cout << cnt[i];
    }
}