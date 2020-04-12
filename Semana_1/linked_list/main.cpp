
#include "linked_list.h"
using namespace std;

int main() {
    cout << "Testing linked_list_t:" << endl << endl;
    //Testing functions
    cout << "Functions:" << endl;
    //__________________________________________________
    //test push_front;
    utec::linked_list_t ll;

    for(int i = 0; i < 10; ++i){
        ll.push_front(i);
    }
    //verify size
    assert(ll.size() == 10);
    string result;
    for (int i = 0; i < ll.size(); ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");
    cout << "push_front = :)" << endl;
    //__________________________________________________
    //test pop_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    //verify size
    assert(ll.size() == 5);
    for (int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    //verify size
    assert(ll.size() == 0);
    cout << "pop_front = :)" << endl;
    //__________________________________________________
    //test push_back;
    for(int i = 0; i < 10; i++)
        ll.push_back(i);
    //verify size
    assert(ll.size() == 10);
    string result2;
    for (int i = 0; i < ll.size(); ++i) {
        result2 += to_string(ll.item(i)) + " ";
    }
    assert(result2 == "0 1 2 3 4 5 6 7 8 9 ");
    cout << "push_back = :)" << endl;
    //__________________________________________________
    //test pop_back
    for(int i = 0; i < 10; i++)
        ll.pop_back();
    //verify size
    assert(ll.size() == 0);
    cout << "pop_back = :)" << endl;
    //__________________________________________________
    //test insert
    utec::linked_list_t vacio;
    vacio.insert(0, 1);
    vacio.insert(0,3);
    string result3;
    for (int i = 0; i < vacio.size(); ++i) {
        result3 += to_string(vacio.item(i)) + " ";
    }
    assert(result3 == "3 1 ");
    cout << "insert = :)" << endl;
    //__________________________________________________
    //test erase
    vacio.push_back(2);
    vacio.push_front(4);
    vacio.erase(1);
    vacio.erase(0);
    string result4;
    for (int i = 0; i < vacio.size(); ++i) {
        result4 += to_string(vacio.item(i)) + " ";
    }
    assert(result4 == "1 2 ");
    cout << "erase = :)" << endl;

    //Testing constructors
    cout << endl << "Constructors" << endl;
    //__________________________________________________
    //test copy 100% new list constructor
    utec::linked_list_t l2;
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);

    utec::linked_list_t l3(l2);
    string result5;
    for(int i = 0; i < l3.size(); ++i)
        result5 += to_string(l2.item(i)) + " ";
    assert(l3.size() == 3);
    assert(result5 == "3 4 5 ");
    cout << "copy 100% new <<linked_list_t(const linked_list_t& other)>> = :)" << endl;

    //__________________________________________________
    //test copy already existing list constructor
    utec::linked_list_t l4;
    l4.push_back(50);
    l4.push_back(60);
    utec::linked_list_t l5;
    l5.push_back(1);
    l5 = l4;
    string result6;
    for(int i = 0; i < l5.size(); ++i)
        result6 += to_string(l5.item(i)) + " ";
    assert(l5.size() == 2);
    assert(result6 == "50 60 ");
    cout << "copy already existing <<linked_list_t&operator=(const linked_list_t& other)>> = :)" << endl;
    //__________________________________________________
    //test move 100% new list constructor
    utec::linked_list_t l6;
    l6.push_back(3);
    l6.push_back(4);
    l6.push_back(5);

    utec::linked_list_t l7(l6);
    string result7;
    for(int i = 0; i < l7.size(); ++i)
        result7 += to_string(l7.item(i)) + " ";
    assert(l7.size() == 3);
    assert(result7 == "3 4 5 ");
    cout << "move 100% new <<linked_list_t(linked_list_t&& other) noexcept>> = :)" << endl;
    //__________________________________________________
    //test move already existing list constructor
    utec::linked_list_t l8;
    l8.push_back(50);
    l8.push_back(60);
    utec::linked_list_t l9;
    l9.push_back(1);
    l9 = l8;
    string result8;
    for(int i = 0; i < l9.size(); ++i)
        result8 += to_string(l9.item(i)) + " ";
    assert(l9.size() == 2);
    assert(result8 == "50 60 ");
    cout << "move already existing <<llinked_list_t&operator=(linked_list_t&& other) noexcept>> = :)" << endl;

    cout << endl << "Success!" << endl;




    for(int i = 0; i < 10; ++i)
        cout << endl;
    cout << "By: Joaquin Ramirez" << endl;


    return 0;
}
