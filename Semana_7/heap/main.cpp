#include "heap.h"

//#define max_heap_int
//#define show_cout_int

//#define max_heap_char
//#define show_cout_char

//#define max_secuancia
#define max_secuancia2
int main() {

    string heap_;

#ifdef max_heap_int
    max_heap<int> heap_int(10);

    // Push
    heap_int.push(20);
    heap_int.push(5);
    heap_int.push(12);
    heap_int.push(24);
    heap_int.push(52);
    heap_int.push(18);
    heap_int.push(2);
    heap_int.push(15);

    heap_ = heap_int.get_heap();
    assert(heap_ == "52 20 24 15 12 5 18 2 10 ");

#ifdef show_cout_int
    cout << heap_ << endl;
#endif

    // Size & empty & find
    assert(heap_int.is_empty() == 0);
    assert(heap_int.size() == 9);
    assert(heap_int.find_value(4) == 12);
#ifdef show_cout_int
    cout << heap_int.find_value(4) << endl;
    cout << heap_int.is_empty() << endl;
    cout << heap_int.size() << endl;
#endif

    // Remove
    heap_int.remove(5);
    heap_ = heap_int.get_heap();
    assert(heap_ == "52 20 24 15 12 10 18 2 ");
#ifdef show_cout_int
    cout << heap_ << endl;
#endif

    // Top
    heap_int.top();
    heap_ = heap_int.get_heap();
    assert(heap_ == "24 20 18 15 12 10 2 ");
#ifdef show_cout_int
    cout << heap_ << endl;
#endif

    // Pop
    heap_int.pop();
    heap_ = heap_int.get_heap();
    assert(heap_ == "24 20 18 15 12 10 ");
#ifdef show_cout_int
    cout << heap_ << endl;
#endif

#endif


    // ----------------------------------//
    //               CHAR               //
    // ----------------------------------//

#ifdef max_heap_char
    max_heap<char> heap_char('a');

    // Push
    heap_char.push('c');
    heap_char.push('d');
    heap_char.push('o');
    heap_char.push('b');
    heap_char.push('p');
    heap_char.push('n');
    heap_char.push('k');
    heap_char.push('e');

    heap_ = heap_char.get_heap();
    assert(heap_ == "p k o e b c n a d ");
#ifdef show_cout_char
    cout << heap_ << endl;
#endif
    // Size & empty & find
    assert(heap_char.is_empty() == 0);
    assert(heap_char.size() == 9);
    assert(heap_char.find_value(4) == 'b');
#ifdef show_cout_char
    cout << heap_char.find_value(4) << endl;
    cout << heap_char.is_empty() << endl;
    cout << heap_char.size() << endl;
#endif

    // Remove
    heap_char.remove(5);
    heap_ = heap_char.get_heap();
    assert(heap_ == "p k o e b d n a ");
#ifdef show_cout_char
    cout << heap_ << endl;
#endif

    // Top
    heap_char.top();
    heap_ = heap_char.get_heap();
    assert(heap_ == "o k n e b d a ");
#ifdef show_cout_char
    cout << heap_ << endl;
#endif

    // Pop
    heap_char.pop();
    heap_ = heap_char.get_heap();
    assert(heap_ == "o k n e b d ");
#ifdef show_cout_char
    cout << heap_ << endl;
#endif

#endif


#ifdef max_secuancia
    max_heap<double> secint;
    for (int i = 0; i < 20; ++i)
        secint.push(i);

    secint.print();

    cout <<  endl << secint.remove_sequence("PRIO*R**I*T*Y***QUE***U*E");
    secint.print();
#endif

#ifdef max_secuancia2
   max_heap<char>char_heap;
    cout <<  endl << char_heap.remove_star("PRIO*R**I*T*Y***QUE***U*E") << endl;
    char_heap.print();
#endif

    return 0;
}