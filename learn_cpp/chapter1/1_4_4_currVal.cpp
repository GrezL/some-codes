#include <iostream>

using namespace std;

int main(){
    int currVal = 0, val = 0, cnt = 0;
    while (cin >> val){
        if (val == currVal){
            ++cnt;
        }
        else {
            if (currVal != 0){
                cout << currVal << " appears " << cnt << " times" << endl;
            }
            cnt = 1;
            currVal = val; 
        }
    }
    cout << currVal << " appears " << cnt << " times" << endl;
    return 0;
}
