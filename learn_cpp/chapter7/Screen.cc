#include "Screen.h"
#include <iostream>
#include <vector>

using namespace std;

inline Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const{
    pos row = r * width;
    return contents[row + c]; 
}

void Screen::some_member() const{
    ++access_ctr;
}

class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
        ScreenIndex addScreen(const Screen&);
        Screen::pos getCursor(const Screen&);
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};
};

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s){
    screens.push_back(s);
    return screens.size() - 1;
}

Screen::pos Window_mgr::getCursor(const Screen &s){
    return s.cursor;
}

void Window_mgr::clear(ScreenIndex i){
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
};

inline Screen &Screen::set(char c){
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch){
    contents[r*width + col] = ch;
    return *this;
}

int main(){
    Screen myscreen;
    char ch = myscreen.get();
    ch = myscreen.get(0,0);
    cout << "ch: " << ch << endl;
    myscreen.some_member();
    myscreen.some_member();

    cout << "ctr: " << myscreen.get_access_ctr() << endl;

    myscreen.move(4,0).set('#');

    Window_mgr newscreen;

    auto value =  newscreen.getCursor(myscreen);
    cout << "check cursor: " << value << endl;
    myscreen.dummy_fcn(3);
    value = newscreen.getCursor(myscreen);

    cout << "check cursor: " << value << endl;
    return 0;
}
