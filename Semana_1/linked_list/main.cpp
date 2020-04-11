#include <iostream>
#include <cassert>
#include <string>
#include "linked_list.h"
using namespace std;

int main() {
    utec::linked_list_t ll;

    //test push_front;
    for(int i = 0; i < 10; ++i){
        ll.push_front(i);
    }


    //verify size
    assert(ll.size() == 10);

    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }

    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    //test pop_front;





    for(int i = 0; i < ll.size(); i++) {
        ll.pop_front();
    }

    //verify size
    assert(ll.size() == 5);

    for (int i = 0; i < 5; ++i) {
        ll.pop_front();
    }

    //verify size
    assert(ll.size() == 0);



    cout << "Success!" << endl;

    return 0;
}
