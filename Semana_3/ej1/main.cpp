#include <iostream>
#include <random>
using namespace std;

template <typename  T>
T rand_integral(T start, T end)
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<T>dis(start, end);
    return dis(eng);
}

template <typename T>
vector<T>generate_repeated(size_t n)
{
    vector<T> source(n);
    for(T& elem:source)
        elem = rand_integral(1, 10);
    cout << "Vec original:" << endl;
    for(T& elem:source)
        cout << elem << " ";

    cout << endl <<  "_____"<<endl;

    vector<T> target;
    for(const T& elem:source){
        auto start = target.size();
        target.resize(target.size() + elem);
        fill(begin(target) + start, end(target), elem);
    }
    return target;
}



int main() {
    for(const auto& item:generate_repeated<int>(10)){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
