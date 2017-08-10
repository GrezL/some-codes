#include <iostream>
<<<<<<< HEAD
#include <string>

using namespace std;

void reset(int &a){
    a = 0;
    cout << "change value of number: " << a << endl;
}

bool isShorter(string &s1, string &s2){
    return s1.size() < s2.size();
}


int main(){
    int number = 123;
    cout << "the value of number is: " << number << endl;
    reset(number);
    cout << "the value of number is: " << number << endl;
    

    int b = 123;
    int *c = &b;
    cout << "the value of b:" << *c << endl;
    c = 0;

    string test1 = "a";
    string test2 = "hello";

    cout << isShorter(test1, test2) << endl;
    return 0;

=======

using namespace std;

void reset(int *number){
    number = 0;
    cout << "the changed value: " << number << endl;
}

int main(){
    int a = 123;
    cout << "the value of a: " << a << endl;
    reset(&a);
    cout << "the value of a: " << a << endl;
    return 0;
>>>>>>> a2cc0018c2d973e58c2a06e0e2572e7de6662fc8
}
