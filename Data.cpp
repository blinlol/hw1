#include <cstring>
#include <iostream>

class Data{
    private:
        int _numb;
        int _sum;
        int _date;
        char *_owner;
    public:
        Data();
        Data(Data& other);
        Data(Data&& other);
        Data(int numb, int sum, int date, char const *owner);
        ~Data();
        void set(int numb, int sum, int date, char* owner);
        int get_numb();
        int get_sum();
        int get_date();
        char* get_owner();
        void print();
        Data& operator=(const Data &other);
};

Data::Data(){
    std::cout << "in Data()" << std::endl;
    _numb = -1;
    _sum = -1;
    _date = -1;
    _owner = nullptr;
}

Data::Data(Data &other){
    std::cout << "in Data(Data &other)" << std::endl;
    _numb = other._numb;
    _sum = other._sum;
    _date = other._date;
    _owner = nullptr;
    if (other._owner != nullptr){
        _owner = new char[strlen(other._owner) + 1];
        strcpy(_owner, other._owner);
    }
}

Data::Data(Data&& other){
    std::cout << "in Data(Data&& other)" << std::endl;
    other._date = _date;
    other._numb = _numb;
    other._sum = _sum;
    other._owner = nullptr;
    if (_owner != nullptr){
        other._owner = new char[strlen(_owner) + 1];
        strcpy(other._owner, _owner);
    }
}

Data::Data(int numb, int sum, int date, char const *owner){
    std::cout << "in Data(...)" << std::endl;
    _numb = numb;
    _sum = sum;
    _date = date;
    _owner = nullptr;
    if (owner != nullptr){
        _owner = new char[strlen(owner) + 1];
        strcpy(_owner, owner);
    }
}

Data::~Data(){
    std::cout << "in ~Data()" << std::endl;
    if (_owner != nullptr){
        delete[] _owner;
        _owner = nullptr;
    }
}

void Data::set(int numb, int sum, int date, char* owner){
    std::cout << "in Data::set(...)" << std::endl;
    _numb = numb;
    _sum = sum;
    _date = date;

    if (_owner != nullptr){
        delete[] _owner;
        _owner = nullptr;
    }
    if (owner != nullptr){
        _owner = new char[strlen(owner) + 1];
        strcpy(_owner, owner);
    }
}

int Data::get_numb(){
    return _numb;
}
int Data::get_sum(){
    return _sum;
}
int Data::get_date(){
    return _date;
}
char* Data::get_owner(){
    return _owner;
}

void Data::print(){
    std::cout << _numb << " " << _sum << " " << _date;
    if (_owner != nullptr){
        std::cout << " " << _owner;
    }
    std::cout<< std::endl;
}

Data& Data::operator=(const Data &other){
    this->set(other._numb, other._sum, other._date, other._owner);
    return *this;
}
