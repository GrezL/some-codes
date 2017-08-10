#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main(){
    unordered_map<string, size_t> word_count;
    cout << word_count.bucket_count() << endl;
    word_count["a"] = 1;
    cout << word_count.bucket_count() << endl;
    cout << word_count.max_bucket_count() << endl;
    cout << word_count.bucket("a") << endl;
    return 0;
}
