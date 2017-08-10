#include <stack>
#include <vector>
#include <deque>

int main(){
    std::deque<int> deq;
    std::stack<int> stk(deq);

    std::stack<std::string, std::vector<std::string>> str_stk;
    return 0;
}
