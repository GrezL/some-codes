#include <iostream>

int main(){
    long long n, m, a;
    long long l, h;
    std::cin >> n >> m >> a;
    if (n % a == 0)
        l = (n/a);
    else
        l = (n/a + 1);
    if (m % a == 0)
        h = (m/a);
    else
        h = (m/a + 1);
    std::cout << h * l << std::endl; 
    return 0;
}
