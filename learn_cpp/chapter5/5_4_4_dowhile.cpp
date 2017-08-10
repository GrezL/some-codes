#include <iostream>
#include <string>

using namespace std;

string rsp;
do {
    cout << "enter two numbers:";
    int val1 = 0, val2 = 0;
    cin >> val1 >> val2;
    cout << "the sum of two values " << val1 << "and" << val2 << "is" << val1 + val2 << "\n\n";
    cin >> rsp;
} while(rsp.empty() && rsp[0] != 'n');
