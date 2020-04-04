//
// Created by J on 29-Mar-20.
//

#ifndef TEST_CINTEGER_H
#define TEST_CINTEGER_H


class CInteger
{
private:
    int value;

public:
    CInteger(int n)
    {
        value = n;
    };


    int GetValue()
    {
        return value;
    };
    void SetValue(int n)
    {
        value = n;
    }

    void operator+= (CInteger* &n)
    {
        value += n->GetValue();
    };
    void operator-= (CInteger* &n)
    {
        value -= n->GetValue();
    };
    void operator*= (CInteger* &n)
    {
        value *= n->GetValue();
    };
    void operator/= (CInteger* &n)
    {
        if(n->GetValue() == 0)
            value = 0;
        else
            value /= n->GetValue();
    };
    void operator^=(int num){
        int temp = value;
        for(int i = 1; i < num; i++)
            value = value * temp;
    };



    CInteger* operator-(CInteger* &a) {
        CInteger *tercero = new CInteger(value - a->GetValue());
        return tercero;
    };
    CInteger* operator+(CInteger* &a) {
        CInteger *tercero = new CInteger(value + a->GetValue());
        return tercero;
    };
    CInteger* operator*(CInteger* &a) {
        CInteger *tercero = new CInteger(value * a->GetValue());
        return tercero;
    };
    CInteger* operator/(CInteger* &a) {
        if(a->GetValue()==0){
            CInteger *tercero = new CInteger(0);
            cerr << "Indeterminado" << endl;
            return tercero;
        }
        else{
            CInteger *tercero = new CInteger(value / a->GetValue());
            return tercero;

        }
    };
    CInteger* operator^(CInteger* &a){
        int temp = value;
        for(int i = 1; i < a->GetValue(); i++){
            value = value * temp;
        }
        CInteger* tercero = new CInteger(value);
        return tercero;
    };


    bool operator>(CInteger* &n){
        return value > n->GetValue();
    }
    bool operator>=(CInteger* &n){
        return value >= n->GetValue();
    };
    bool operator<(CInteger* &n){
        return value < n->GetValue();
    };
    bool operator<=(CInteger* &n){
        return value <= n->GetValue();
    };
    bool operator!=(CInteger* &n){
        return value != n->GetValue();
    };
    bool operator==(CInteger* &n){
        return value == n->GetValue();
    }




    virtual ~CInteger() = default;;

};
#endif //TEST_CINTEGER_H
