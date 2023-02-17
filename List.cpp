// #include "Data.cpp"
#include <iostream>

class List{
    private:
        List *_next;
        List *_prev;
        Data _data;
        int _size;
    public:
        List();
        ~List();
        void push_back(Data data);
        void push_front(Data data);
        void insert(int pos, Data data);
        void erase(int pos);
        void erase_first();
        void erase_last();
        Data pop_back();
        Data pop_front();
        Data front();
        Data back();
        int size();
        bool empty();
        void print();
};

List::List() : _data(){
    std::cout << "in List()" << std::endl;
    _size = 0;
    _next = nullptr;
    _prev = nullptr;
}

List::~List(){
    std::cout << "in ~List()" << std::endl;
    if (_next != nullptr){
        delete _next;
    }
}

void List::push_back(Data data){
    std::cout << "in List.push_back()" << std::endl;
    _size++;
    if (_prev != nullptr){
        List *last = new List();
        last->_prev = _prev;
        _prev->_next = last;
        _prev = last;
        last->_data = data;
    }
    else{ //first
        List *last = new List();
        _next = last;
        _prev = last;
        last->_data = data;
    }
}

void List::push_front(Data data){
    std::cout << "in List.push_front()" << std::endl;
    _size++;
    if (_next != nullptr){
        List *fst = new List();
        fst->_next = _next;
        _next->_prev = fst;
        _next = fst;
        fst->_data = data;
    }
    else{ //first
        List *fst = new List();
        _next = fst;
        _prev = fst;
        fst->_data = data;
    }
}

void List::insert(int pos, Data data){
    std::cout << "in List::insert()" << std::endl;
    if (pos == 1){
        this->push_front(data);
        return;
    }
    if (pos == _size + 1){
        this->push_back(data);
        return;
    }
    if (pos > _size + 1){
        throw std::runtime_error("out of range");
        return;
    }

    _size++;
    List *next, *prev;
    next = _next;
    prev = nullptr;
    for (int i=1; i<pos; i++){
        prev = next; 
        next = next->_next;
    }

    List *node = new List();
    node->_next = next;
    node->_prev = prev;
    node->_data = data;
    if (prev != nullptr){
        prev->_next = node;
    }
    if (next != nullptr){
        next->_prev = node;
    }
}

void List::erase(int pos){
    std::cout << "in List.erase()" << std::endl;
    if (pos == 1){
        erase_first();
        return;
    }
    if (pos == _size){
        erase_last();
        return;
    }
    
    if (pos > _size || pos < 1){
        throw std::runtime_error("out of range");
        return;
    }

    _size--;
    List *target = _next;
    for (int i=1; i<pos; i++){
        target = target->_next;
    }

    List *prev, *next;
    prev = target->_prev;
    next = target->_next;
    if (prev != nullptr){
        prev->_next = next;
    }
    if (next != nullptr){
        next->_prev = prev;
    }

    target->_next = nullptr;
    target->_prev = nullptr;
    delete target;
}

void List::erase_first(){
    std::cout << "in List.erase_first()" << std::endl;
    List *node = _next;
    if (node == nullptr){
        throw std::runtime_error("list is empty");
    }
    _size--;
    _next = node->_next;
    if (_next != nullptr){
        _next->_prev = nullptr;
    }

    node->_next = nullptr;
    node->_prev = nullptr;
    delete node;
}

void List::erase_last(){
    std::cout << "in List.erase_last()" << std::endl;
    List *node = _prev;
    if (node == nullptr){
        throw std::runtime_error("list is empty");
    }

    _size--;
    _prev = node->_prev;
    if (_prev != nullptr){
        _prev->_next = nullptr;
    }

    node->_next = nullptr;
    node->_prev = nullptr;
    delete node;
}

Data List::pop_back(){
    std::cout << "in List.pop_back()" << std::endl;
    if (_prev == nullptr){
        throw std::runtime_error("list is empty");
    }

    Data ans = _prev->_data;
    erase_last();
    return ans;
}


Data List::pop_front(){
    std::cout << "in List.pop_front()" << std::endl;
    if (_next == nullptr){
        throw std::runtime_error("list is empty");
    }

    Data ans = _next->_data;
    erase_first();
    return ans;
}

Data List::front(){
    std::cout << "in List.front()" << std::endl;
    if (_next == nullptr){
        throw std::runtime_error("list is empty");
    }
    else{
        return _next->_data;
    }
}

Data List::back(){
    std::cout << "in List.back()" << std::endl;
    if (_prev == nullptr){
        throw std::runtime_error("list is empty");
    }
    else{
        return _prev->_data;
    }
}

int List::size(){
    return _size;
}

bool List::empty(){
    return _size == 0;
}

void List::print(){
    std::cout << "in List.print()" << std::endl;
    List *cur = _next;
    while (cur != nullptr){
        cur->_data.print();
        cur = cur->_next;
    }
}