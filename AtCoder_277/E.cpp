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

int n, m, k, x, y, w;
vector<ii>G[N];
vector<int>can(N, 0);
vector<vector<int>>dist(N, vector<int>(2, INF));

void solve() {
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }

    for(int i = 0; i < k; i++)
        cin >> x, can[x] = 1;

    dist[1][0] = 0;
    deque<array<int, 3>>dq;
    // priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; // also use pq
    dq.push_back({0, 1, 0});

    while(!dq.empty()) {
        auto arr = dq.front();
        dq.pop_front();
        int d = arr[0], u = arr[1], mode = arr[2];

        if(d != dist[u][mode])
            continue;
        
        if(u == n) { cout << d << endl; return; }

        for(auto &[v, bit] : G[u]) {
            if((bit ^ mode) == 1) { // you can move in this edge:D
                if(dist[v][mode] > d + 1) {
                    dist[v][mode] = d + 1;
                    dq.push_back({d + 1, v, mode});
                }
            }
        }

        if(can[u]) { //if this vertice can flip, we can extend this vertice with cost = 0, so this problem can be bfs 0 - 1
            if(dist[u][mode ^ 1] > d) {
                dist[u][mode ^ 1] = d;
                dq.push_front({d, u, mode ^ 1});
            }
        }
        
    }

    cout << -1 << endl;
}

int main(){
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
