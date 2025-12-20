#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> ii;
typedef pair<ll, int> lli;
typedef unsigned long long ull;
#define fi first
#define se second
#define pb push_back
#define el cout << "\n"
#define no cout << "NO\n"
#define ye cout << "YES\n"
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define mem(a,b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define sz(A) (int) A.size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 2e5 + 15;
const int INF = 1e9;

unordered_map<int, unordered_map<int, int>>mark;
int n, q, t, x, y;
void solve() {
    cin >> n >> q;

    while(q--) {
        cin >> t >> x >> y;

        if(t == 1)
            mark[x][y] = 1;
        if(t == 2)
            mark[x][y] = 0;
        if(t == 3)
            if(mark[x][y] == 1 && mark[y][x] == 1)
                cout << "Yes\n";
            else
                cout << "No\n";
    }
}

int main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
