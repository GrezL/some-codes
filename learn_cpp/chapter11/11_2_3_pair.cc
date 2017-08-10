#include <utility>
#include <iostream>
#include <vector>

using namespace std;

pair<string, int> process(vector<string> &v){
    if(!v.empty())
        return {v.back(), v.back().size()};
    else
        return pair<string, int>();
}

int main(){
    pair<string, string> anon;
    pair<string, string> author("James", "Joyce");
    cout << author.first << " and " << author.second << endl;
    return 0;
}
