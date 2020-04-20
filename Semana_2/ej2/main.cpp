#include <iostream>
#include <vector>
using namespace std;
template <class InputIt1, class InputIt2, class OutputIt>
    OutputIt merge(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first){
    while (true) {
        if (first1==last1)
            return copy(first2,last2,d_first);
        if (first2==last2)
            return copy(first1,last1,d_first);
        *d_first++ = (*first2 < *first1)? *first2++ : *first1++;
    }

}
int main() {

    int first[] = {1,1,1,1,1};
    int second[] = {2,2,2,2,2};
    vector<int>v1(10);
    merge(first, first + 5, second, second + 5, v1.begin());
    for(auto element:v1)
        cout << element << endl;
    return 0;
}
