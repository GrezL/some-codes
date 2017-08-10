#include <iostream>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string s2){
    return s1.size() < s2.size();
}

string::size_type find_char(const string &s, char c, string::size_type &occurs){
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
        if (s[i] == c)
            if (ret == s.size())
                ret = i;
            ++occurs;
    return ret;
}


int main(){
    const string a = "hello111o";
    const string b = "world1";

    string::size_type ctr;
    auto index = find_char(a, 'o', ctr);
    cout << index << endl;
}
