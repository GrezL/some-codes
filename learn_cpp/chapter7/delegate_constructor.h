#include <iostream>
#include <string>

using namespace std;

class Sales_data {
friend std::istream &read(std::istream&, Sales_data&);
    public:
        Sales_data(std::string s, unsigned cnt, double price):
            bookNo(s), units_sold(cnt), revenue(cnt * price) {}
        Sales_data(): Sales_data("", 0, 0) {}
        Sales_data(std::string s): Sales_data(s, 0, 0) {}
        Sales_data(std::istream &is): Sales_data(){read (is, *this);}
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

std::istream &read(std::istream&, Sales_data&);
