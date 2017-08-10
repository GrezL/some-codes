#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void elimDups(vector<string> &words){
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter (const string &s1, const string &s2){
    return s1.size() < s2.size();
}


int main(){
    vector<string> words({"aksdfj", "kdj", "djf", "ksajfklja"});
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    
    return 0;
}
