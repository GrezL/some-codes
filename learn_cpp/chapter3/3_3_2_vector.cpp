#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string word;
    vector<string> text;
    while (cin >> word){
        text.push_back(word);
        for (string a: text)
            cout << a << "\n"<< endl;
            cout << text.size() << endl;
    }
}
