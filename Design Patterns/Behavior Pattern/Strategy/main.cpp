#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class IPaymentStrategy{
    public:
        IPaymentStrategy(){}
        virtual bool pay(int amount) =0;
};


class DebitCardPayment: public IPaymentStrategy{
private:
    string name;
    string cardNumber;
    string cvv;
public:
    DebitCardPayment(string name, string cardNumber, string cvv){
        this->name = name;
        this->cardNumber = cardNumber;
        this->cvv = cvv;
    }

    bool pay(int amount) {
        cout<< "DEBIT CARD:paying the amount to the dealer\n";
        return true;
    }
};


class CreditCardPayment: public IPaymentStrategy{
private:
    string name;
    string cardNumber;
    string cvv;
public:
    CreditCardPayment(string name, string cardNumber, string cvv){
        this->name = name;
        this->cardNumber = cardNumber;
        this->cvv = cvv;
    }
    bool pay(int amount) {
        cout<< "CREDIT CARD: paying the amount to the dealer\n";
    }
};


class MakePaymentStrategy {
private:
    IPaymentStrategy *paymentMethod;
public:
    
    MakePaymentStrategy(){
        this->paymentMethod = nullptr;
    }

    void setPaymentType(IPaymentStrategy *payment){
        this->paymentMethod = payment;
    }

    bool pay(int amount){
        bool x = this->paymentMethod->pay(amount);
        return x;
    }
};


int main(){

    MakePaymentStrategy *paymetGateWay = new MakePaymentStrategy();

    IPaymentStrategy *debit = new DebitCardPayment("Sibu","amex", "233");
    paymetGateWay->setPaymentType(debit);
    paymetGateWay->pay(100);

    IPaymentStrategy *credit = new CreditCardPayment("Sibu","amex", "233");
    paymetGateWay->setPaymentType(credit);
    paymetGateWay->pay(100);
    

}