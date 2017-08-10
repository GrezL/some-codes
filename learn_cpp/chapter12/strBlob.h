#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class StrBlob;
class StrBlobPtr {
    public:
        friend class StrBlob;
        StrBlobPtr(): curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0);
        std::string& deref() const;
        StrBlobPtr& incr();
    private:
        std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
        std::weak_ptr<std::vector<std::string>> wptr;
        std::size_t curr;
};


class StrBlob {
    public:
        friend class StrBlobPtr;
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        size_type size() const {return data->size();};
        bool empty() const {return data->empty();};

        void push_back(const string &t) { data->push_back(t); };
        void pop_back();

        string& front();
        string& back();
        StrBlobPtr begin(){
            return StrBlobPtr(*this);
        }
    private:
        std::shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const {
            if (i >= data->size())
                throw out_of_range(msg);
        };
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {};
string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front(); 
}
string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}


StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz): wptr(a.data), curr(sz){}
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string& StrBlobPtr::deref() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
