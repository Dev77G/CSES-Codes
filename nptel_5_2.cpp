#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void f(Node *root, long long sum, vector<long long >&ans) {
    if ( root->left == NULL && root->right == NULL ) {
        ans.push_back( sum * 10 + root->val );
        return ;
    }
    if ( root->left ) {
        f( root->left , sum * 10 + root->val , ans );
    }
    if ( root->right ) {
        f( root->right , sum * 10 + root->val , ans );
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    Node *p;
    p = new Node*[n];

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[i]->val = x;
    }

    for (int i = 0; i < n; i++) {
        int x , y;
        cin >> x >> y;

        if (x == -1) p[i]->left = NULL;
        else p[i]->left = p[x - 1];

        if (y == -1) p[i]->right = NULL;
        else p[i]->right = p[y - 1];
    }

    vector<long long>ans;
    f(p[0], 0, ans);

    long long finalans = 0 ;
    for (int i = 0; i < ans.size() ; i++ )
        finalans += ans[i];

    cout << finalans;
    return 0;
}