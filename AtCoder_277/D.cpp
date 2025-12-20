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

const int N = 4e5 + 15;
const int INF = 1e9 + 1;
int n, m, a[N];
void solve() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    a[2 * n] = INF;
    for(int i = n; i < 2 * n; i++)
        a[i] = a[i - n];

    ll sum = a[0], cur = a[0], total = accumulate(a, a + n, 0ll);
    for(int i = 1; i < 2 * n; i++) {
        if(a[i] == a[i - 1] || (a[i] == (a[i - 1] + 1) % m))
            sum = sum + a[i];
        else
            sum = a[i];
        cur = max(cur, sum);
    }

    cout << max(0ll, total - cur) << endl;
}

int main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
