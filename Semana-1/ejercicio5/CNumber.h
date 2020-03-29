//
// Created by J on 29-Mar-20.
//

#ifndef TEST_CNUMBER_H
#define TEST_CNUMBER_H

template<typename T>
class CNumber
{
private:
    T value;

public:
    CNumber(T n)
    {
        value = n;
    };

    T GetValue()
    {
        return value;
    };
    void SetValue(T n)
    {
        value = n;
    }

    void operator+= (CNumber* &n)
    {
        value += n->GetValue();
    };
    void operator-= (CNumber* &n)
    {
        value -= n->GetValue();
    };
    void operator*= (CNumber* &n)
    {
        value *= n->GetValue();
    };
    void operator/= (CNumber* &n)
    {
        if(n->GetValue() == 0)
            value = 0;
        else
            value /= n->GetValue();
    };
    void operator^=(T num){
        T temp = value;
        for(int i = 1; i < num; i++)
            value = value * temp;
    };



    CNumber* operator-(CNumber* &a) {
        CNumber *tercero = new CNumber(value - a->GetValue());
        return tercero;
    };
    CNumber* operator+(CNumber* &a) {
        CNumber *tercero = new CNumber(value + a->GetValue());
        return tercero;
    };
    CNumber* operator*(CNumber* &a) {
        CNumber*tercero = new CNumber(value * a->GetValue());
        return tercero;
    };
    CNumber* operator/(CNumber* &a) {
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
    CNumber* operator^(CNumber* &a){
        T temp = value;
        for(int i = 1; i < a->GetValue(); i++){
            value = value * temp;
        }
        CNumber* tercero = new CNumber(value);
        return tercero;
    };


    bool operator>(CNumber* &n){
        return value > n->GetValue();
    }
    bool operator>=(CNumber* &n){
        return value >= n->GetValue();
    };
    bool operator<(CNumber* &n){
        return value < n->GetValue();
    };
    bool operator<=(CNumber* &n){
        return value <= n->GetValue();
    };
    bool operator!=(CNumber* &n){
        return value != n->GetValue();
    };
    bool operator==(CNumber* &n){
        return value == n->GetValue();
    }



    virtual ~CNumber() = default;;

};
#endif //TEST_CNUMBER_H
