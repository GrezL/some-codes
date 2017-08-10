#include <string>
#include <iostream>

using namespace std;

struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_soled(n), revenue(p * n) {}
    Sales_data(std::istream &);

    //private
    std::string bookNo;
    unsigned units_soled = 0;
    double revenue = 0.0;
};
