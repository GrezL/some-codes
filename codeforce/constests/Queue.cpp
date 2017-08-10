#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ll n, k;  
    cin >> n;
    vector<int> a;
    for(ll i = 0; i != n; ++i){
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(), a.end());

    ll sum(0), result(0); 
    for (auto i:a){
        if (sum <= i){
            ++result;
            sum += i;
        }
    }
    cout << result << endl;
    return 0;
}
