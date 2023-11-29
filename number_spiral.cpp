#include <bits/stdc++.h>
#define ll  long long
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // freopen("input1.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
#endif
    int t; cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        ll c = max(x, y);
        c = (c - 1) * (c - 1);
        if ( x == y )
            c += x;
        else {

            if ( x & 1 && x > y ) {
                c += y;
            }
            else if (y & 1 && y > x) {
                c = c + 2 * y - x;
            }
            else if (!(x & 1) && x > y) {
                c = c + 2 * x - y;
            }
            else if (!(y & 1) && y > x) {
                c += x ;
            }
        }
        cout << c << "\n";
    }
    return 0;
}