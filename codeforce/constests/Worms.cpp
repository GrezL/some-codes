#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll bsearch(const vector<vector<ll> >& v, ll l, ll h, ll n){
    if (l > h)
        return -1;
    ll m = l + (h - l) / 2;
    if (v[m][0] <= n && v[m][1] >= n)
        return m + 1;
    else if (v[m][1] < n)
        return bsearch(v, m + 1, h, n);
    else
        return bsearch(v, l, m - 1, n);
}

int main(){
    ll n, sum(0);
    vector<vector<ll>> a;

    cin >> n;

    for (ll i=0; i != n; ++i){
        ll ai;
        cin >> ai;
        a.push_back({sum + 1, sum + ai});
        sum += ai;
    }

    ll m;
    cin >> m;

    for (ll i = 0; i != m; ++i){
        ll pi;
        cin >> pi;
        cout << bsearch(a, 0, n, pi) << endl;
    }
    return 0;
}
