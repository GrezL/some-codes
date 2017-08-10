#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen {
    friend class Window_mgr;
    public:
        typedef std::string::size_type pos;
        Screen() = default;

        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){}
        char get() const {return contents[cursor];}
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        void some_member() const;
        //
        Screen &set(char);
        Screen &set(pos, pos, char);

        size_t get_access_ctr() {
            return access_ctr;
        };

        //
        Screen &display(std::ostream &os){
            do_display(os); return *this;
        }
        const Screen &display(std::ostream &os) const{
            do_display(os); return *this;
        }

        void dummy_fcn(pos height){
            cursor = width * this->height;
        }

    private:
        pos cursor = 0;
        pos height = 0, width = 1;
        string contents;
        mutable size_t access_ctr;
        void do_display(std::ostream &os) const {os << contents;}
};
