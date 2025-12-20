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

unordered_map<int, vector<int>>G;
void solve() {
    int n; cin >> n;
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    map<int, int>can;
    int ans = 1;
    can[1] = 1;
    queue<int>q;
    q.push(1);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        ans = max(ans, u);
        for(auto v : G[u]) {
            if(!can.count(v)) {
                can[v] = 1;
                q.push(v);
            }
        }
    }

    cout << ans << endl;
}

int main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
