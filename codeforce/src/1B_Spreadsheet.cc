#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cctype>
#include <algorithm>

typedef long long ll;

std::string to26(ll &x){
    std::string loc;
    while (x != 0){
        if (x % 26 != 0){
            loc += (char)(x % 26 + 64); 
            x /= 26;
        }else{
            loc += 'Z';
            x = x / 26 - 1;
        }
    }
    std::reverse(loc.begin(), loc.end());
    return loc;
}

std::string RXCYtoSS(std::string &s){
    std::vector<ll> a;
    std::regex r("\\d+");
    auto sbegin = std::sregex_iterator(s.cbegin(), s.cend(), r);
    auto send = std::sregex_iterator();
    for (std::sregex_iterator i = sbegin; i != send; ++i)
        a.push_back(std::stoi(i->str()));

    std::string loc = to26(a[1]);
    std::string result = loc + std::to_string(a[0]);
    return result;
}

std::string SStoRXCY(std::string &s){
    ll sum(0);
    std::string loc, result;
    for(char k:s)
        if(isalpha(k))
            sum = sum * 26 + k - 64;
        else
            loc.push_back(k);
    result = "R" + loc + "C" + std::to_string(sum); 
    return result;
}

int main(){
    ll n;
    std::cin >> n;
    std::string s;
    while(std:: cin >> s)
        if (std::regex_match(s, std::regex("R\\d+C\\d+")))
            std::cout << RXCYtoSS(s) << std::endl;
        else
            std::cout << SStoRXCY(s) << std::endl;
    return 0;
}
