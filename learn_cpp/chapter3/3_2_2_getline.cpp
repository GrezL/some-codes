#include <string>
#include <iostream>

using namespace std;

int main(){
    string line;
    while (getline(cin, line))
        cout << line << " " << line.size() << endl;
    return 0;
}
