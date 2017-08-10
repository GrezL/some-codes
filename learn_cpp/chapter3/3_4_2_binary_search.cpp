#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> text;
    string sought("");
    auto beg = text.begin();
    auto end = text.end();
    auto mid = text.begin() + (end - beg)/2;
    while (mid != end && *mid != sought){
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end-beg)/2;
    }
}
