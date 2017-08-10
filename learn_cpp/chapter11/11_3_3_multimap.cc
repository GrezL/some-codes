#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(){
    multimap<string, string> author;
    author.insert({"Barth, John", "Sot-wet fact"});
    author.insert({"Barth, John", "Lost in th funhouse"});
    author.insert({"Alain de Botton", "A horny widow"});
    author.insert({"Alain de Botton", "flushing pussy"});

    string search_item("Alain de Botton");
    auto entry = author.count(search_item);
    auto iter = author.find(search_item);
    while(entry){
        cout << iter->second << endl;
        ++iter;
        --entry;
    }
    cout << endl;

    for(auto beg = author.lower_bound(search_item), end = author.upper_bound(search_item); beg != end; ++beg)
        cout << beg->second << endl;
    cout << endl;

    for(auto pos = author.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl;
    cout << endl;

    return 0;
}
