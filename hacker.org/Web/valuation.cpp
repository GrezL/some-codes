#include <iostream>
#include <string>
#include <vector>

using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::strcat;
std::string recive = "93752xxx746x27x1754xx90x93xxxxx238x44x75xx08750912738x8461x8759383xx328x4x4935903x6x5550360535004x0xx945958961296x267x8842xxx5x6xx61x4x48482x80xxx83316843x7x4x83x9521731xxx25x51xx457x6x5x9698222x771237745034x5133592x27xx8x87xx35221x36x0x50x23x7x63x998418xx";
std::string strSum = "";
int sum = 0;

int main(){
    for (int i = 0; i <= recive.size(); ++i){
        if (recive[i] != 'x'){
            strSum.append(recive.substr(i, 1));
        }else{
            strSum.append(strSum.substr(strSum.length() - 2, 2));
        }
    }
    for (int i = 0; i <= strSum.size(); ++i){
        int number = atoi(strSum.substr(i,1).c_str());
        sum += number;
    }
    cout << sum << endl;
    return 0;
}
