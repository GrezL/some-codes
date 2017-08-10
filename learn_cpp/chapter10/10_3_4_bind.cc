#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

bool check_size(const string &s, string::size_type sz){
    return s.size() >= sz;
}

auto check_6 = bind(check_size, std::placeholders::_1, 6);

bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

ostream &print(ostream &os, const string &s, char c){
    return os << s << c;
}

int main(){
    string a = "hello";
    bool b1 = check_6(a);
    cout << b1 << endl;

    vector<string> words({"cat", "dog", "elephant", "snack", "kangroo", "zibra", "pineapple"});
    stable_sort(words.begin(), words.end(), isShorter);
    for_each(words.begin(), words.end(), [=](const string &s){cout << s << ' ';});
    cout << endl;
    stable_sort(words.begin(), words.end(), bind(isShorter, std::placeholders::_2, std::placeholders::_1));
    ostream &os = cout;
    for_each(words.begin(), words.end(), bind(print, ref(os), std::placeholders::_1, ' '));
    cout << endl;
    return 0;
}
