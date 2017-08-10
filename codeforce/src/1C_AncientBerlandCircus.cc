#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<double> a, b, c; 
    double ai, bi, ci;
    for (int i = 0; i != 1; ++i)
        cin >> ai;
        a.push_back(ai);

    for (int i = 0; i != 1; ++i)
        cin >> bi;
        b.push_back(bi);

    for (int i = 0; i != 1; ++i)
        cin >> ci;
        c.push_back(ci);
 
    cout.setf(ios::showpoint);
    cout.precision(6);
    cout.setf(ios::fixed);

    cout << a.size() << endl;
    return 0;
}
