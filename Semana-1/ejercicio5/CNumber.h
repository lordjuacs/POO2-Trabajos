//
// Created by J on 29-Mar-20.
//

#ifndef TEST_CNUMBER_H
#define TEST_CNUMBER_H

//declaration
template<typename T>
class CNumber {
private:
    T value;

public:
    CNumber();
    CNumber(T n);

    T GetValue();

    void SetValue(T n);

    void operator+=(CNumber *&n);
    void operator-=(CNumber *&n);
    void operator*= (CNumber* &n);
    void operator/= (CNumber* &n);
    void operator^=(T num);


    auto* operator-(CNumber* &a);
    auto* operator+(CNumber* &a);
    auto* operator*(CNumber* &a);
    auto* operator/(CNumber* &a);
    auto* operator^(CNumber* &a);

    bool operator>(CNumber* &n);
    bool operator>=(CNumber* &n);
    bool operator<(CNumber* &n);
    bool operator<=(CNumber* &n);
    bool operator!=(CNumber* &n);
    bool operator==(CNumber* &n);

    virtual ~CNumber();

};

//definition

template<typename T>CNumber<T>::CNumber() {
    value = 0;
}
template <typename T>CNumber<T>::CNumber(T n){
    value = n;
};
template <typename T> T CNumber<T>::GetValue()
{
    return value;
};
template <typename T>void CNumber<T>::SetValue(T n)
{
    value = n;
}
template <typename T> void CNumber<T>::operator+= (CNumber* &n)
{
    value += n->GetValue();
};

template <typename T>void CNumber<T>::operator-= (CNumber* &n)
{
    value -= n->GetValue();
};
template <typename T> void CNumber<T>::operator*= (CNumber* &n)
{
    value *= n->GetValue();
};
template <typename T>void CNumber<T>::operator/= (CNumber* &n)
{
    if(n->GetValue() == 0)
        value = 0;
    else
        value /= n->GetValue();
};
template <typename T>void CNumber<T>:: operator^=(T num){
    T temp = value;
    for(int i = 1; i < num; i++)
        value = value * temp;
};
template <typename T>auto* CNumber<T>::operator-(CNumber* &a) {
    CNumber *tercero = new CNumber(value - a->GetValue());
    return tercero;
};
template <typename T>auto* CNumber<T>::operator+(CNumber* &a) {
    CNumber *tercero = new CNumber(value + a->GetValue());
    return tercero;
};
template <typename T>auto* CNumber<T>::operator*(CNumber* &a) {
    CNumber*tercero = new CNumber(value * a->GetValue());
    return tercero;
};
template <typename T>auto* CNumber<T>::operator/(CNumber* &a) {
    if(a->GetValue()==0){
        CNumber*tercero = new CNumber(0);
        cerr << "Indeterminado" << endl;
        return tercero;
    }
    else{
        CNumber*tercero = new CNumber(value / a->GetValue());
        return tercero;

    }
};
template <typename T>auto* CNumber<T>::operator^(CNumber* &a){
    T temp = value;
    for(int i = 1; i < a->GetValue(); i++){
        value = value * temp;
    }
    CNumber* tercero = new CNumber(value);
    return tercero;
};


template <typename T>bool CNumber<T>::operator>(CNumber* &n){
    return value > n->GetValue();
}
template <typename T>bool CNumber<T>::operator>=(CNumber* &n){
    return value >= n->GetValue();
};
template <typename T>bool CNumber<T>::operator<(CNumber* &n){
    return value < n->GetValue();
};
template <typename T>bool CNumber<T>::operator<=(CNumber* &n){
    return value <= n->GetValue();
};
template <typename T>bool CNumber<T>::operator!=(CNumber* &n){
    return value != n->GetValue();
};
template <typename T>bool CNumber<T>::operator==(CNumber* &n){
    return value == n->GetValue();
}


template<typename T>CNumber<T>::~CNumber() = default;




#endif //TEST_CNUMBER_H
