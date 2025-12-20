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
#define int long long

int n, q;
int a[N];
set<int>id;
void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++)
        id.insert(i);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> q;
    int t, base = 0, pos, val;
    while(q--) {
        cin >> t;

        if(t == 1) {
            for(auto &i : id)
                a[i] = 0;
            id.clear();
            cin >> base;
        } else {
            if(t == 2) {
                cin >> pos >> val;
                a[pos] += val;
                id.insert(pos);
            } else {
                cin >> pos;
                cout << base + a[pos] << endl;
            }
        }
    }
}

int32_t main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
