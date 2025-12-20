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

int n;
string s;
vector<vector<int>>dp((1 << 16), vector<int>(16, -1));
vector<string>a;
bool flag = 0;
// dp[mask][i] : cac chuoi dc chon trong mask, voi chi so cuoi cung hien tai la i
// <=> dp[mask][i] : nuoc di hien tai co the khien doi thu thang hoac thua voi 0 va 1
int dfs(int mask, int i) {
    if(dp[mask][i] != -1)
        return dp[mask][i];

    for(int j = 0; j < n; j++) {
        if(mask & (1 << j)) 
            continue;

        if(a[i][1] != a[j][0]) // last and first char
            continue;

        if(!dfs(mask | (1 << j), j)) 
            return dp[mask][i] = 1; // current user can win, another user can be lose
    }

    return dp[mask][i] = 0; // lose
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        a.push_back({s.front(), s.back()});
    }

    for(int i = 0; i < n; i++) {
        if(!dfs((1 << i), i)) {
            flag = 1;
            break;
        }
    }

    cout << (flag ? "First" : "Second") << endl;
}


int32_t main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
