#include <iostream>
#include <string>

class Account {
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);
    private:
        std::string owener;
        double amount;
        static double interestRate;
        static double initRate();
};

void Account::rate(double newRate){
    interestRate = newRate;
}

int main(){
    return 0;
}