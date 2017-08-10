#include <iostream>
#include <string>

using namespace std;

int main(){
    string s("Hello World!!!");
    decltype(s.size()) punch_cnt = 0;
    for (auto c : s)
        if (ispunct(c))
            ++punch_cnt;
    cout << punch_cnt << " punch_cnt in " << s << endl;

    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
    
    string a("some string");
    if (!a.empty())
        a[0] = toupper(a[0]);
    cout << a << endl;

    for (decltype(a.size()) index = 0; index != a.size() && !isspace(s[index]); ++index)
        a[index] = toupper(a[index]);
    cout << a << endl; 
    return 0;
}
