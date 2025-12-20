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

int h, w, n, r, c;
int mr = 0, mc = 0, diff = 0;
int a[363][636];
vector<int>cnt(305, 0);
void solve() { // O(n ^ 3)
    cin >> h >> w >> n >> r >> c;

    mr = h - r, mc = w - c;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
            ++cnt[a[i][j]];
            if(cnt[a[i][j]] == 1)
                diff++;
        }
    }

    auto process = [&](int x, int y) -> void {
        vector<int>color(305, 0);
        for(int i = x; i < x + r; i++) {
            for(int j = y; j < y + c; j++) {
                ++color[a[i][j]];
            }
        }
        int ans = diff;
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0) continue;
            if(color[i] == cnt[i]) --ans;
        }
        cout << ans << ' ';
    };


    for(int x = 0; x <= mr; x++) {
        for(int y = 0; y <= mc; y++) {
            process(x, y);
        }
        el;
    }

}

// to cac o tren doan r : [0 -> mr], size = r
// to cac o tren doan c : [0 -> mc], size = c

int32_t main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
