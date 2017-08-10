#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ll n, a, sum(0);
    vector<ll> arr;
    cin >> n;
    for(int i=0; i != n; ++i){
        cin >> a;
        sum += a;
        arr.push_back(sum);
    }
    
    if (sum % 3 != 0 || arr.size() <= 2){
        cout << 0 << endl;
    }else if (sum == 0){
        ll countzero(0);
        for(auto i:arr){
            if (i == 0)
                ++countzero;
        } 
        if (countzero < 3)
            cout << 0 << endl;
        else
            cout << (countzero-2)*(countzero-1)/2 << endl;
    }else{
        const ll a(sum / 3);
        const ll b(2 * a);
        ll count_a(0), result(0);
        for(auto i:arr){
            if (i == a){
                ++count_a;
            }else if(i == b && count_a != 0){
                result += count_a;
            }
        }
        cout << result << endl;
    }
    return 0;
}
