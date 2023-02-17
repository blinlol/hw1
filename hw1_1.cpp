#include "Data.cpp"
#include "List.cpp"
#include <iostream>

int main(){
    char name1[6]="fedya";
    Data d0, d00 = d0, d1(1, 100, 2003, name1), d2(-1, -1, 5, "Vasiliy");
    // d0.print();
    // d1.print();
    // d2.print();
    // char *a = d2.get_owner();
    // std::cout<<a<<std::endl;

    // List lst;
    // lst.print();
    // lst.push_back(d0);
    // d0 = lst.pop_back();
    // lst.push_back(d0);
    // lst.push_back(d1);
    // lst.front().print();
    // lst.back().print();
    // lst.push_front(d1);
    // Data dpop1 = lst.pop_front();
    // lst.push_back(d1);
    // lst.push_back(d1);
    // lst.print();
    // Data dpop2 = lst.pop_back();     // утекает память при вызове pop_back
    // lst.print();

    List lst2;
    lst2.push_back(d2);
    lst2.insert(1, d0);
    lst2.insert(3, d1);
    lst2.insert(2, d1);
    // lst2.front().print();
    // lst2.print();
    // lst2.erase(2);
    // lst2.print();
    // lst2.push_back(d2);
    // lst2.push_back(d2);
    Data d3 = lst2.pop_front();
    lst2.print();
    // d3 = lst2.pop_front();
    // Data d5 = lst2.pop_front();

}