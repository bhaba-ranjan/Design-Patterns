#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Factory method is used when we don't know what kind of object is going to be created
// This objects are created for a purpose (eg: logistic can Create ship and Truck object (called product) [goal is to deliver])
// eg: A pizza store can create different pizza objects (NY style  / chicago style (product) [Goal is that it will be ordered])
// if you see these objects have same goal to Deliver or to Order (Of course products are created with some intention )
// Factory methods passes the object creating logic(through virtual function/abstract class) to subclass and only calls the Goal method inside it.


class Product{
    public:
        virtual ~Product() {};
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void pack() = 0;
};

// WARNING: don't use a string type to choose between product [enum Enforces type safety (can't pass a product that does not exist)]
enum PizzaType {NY=0, CA=1}; 

class FactoryCreator {
    public:
        virtual ~FactoryCreator(){};
        // We will instantiate object in the subclass
        virtual Product* createProduct(PizzaType type) = 0;

        void orderPizza(PizzaType specificPizzaType){
            Product* pizza= this->createProduct(specificPizzaType);
            pizza->bake();
            pizza->cut();
            pizza->pack();            
        }

};

// These are Concrete Product classes
// Concrete Creator will decide which one will be created
class NewYorkCheesePizza: public Product{
    public:
        virtual ~NewYorkCheesePizza(){};
        virtual void bake()  {
            cout<< "Baking NewYorkCheesePizza"<< endl;
        }

        virtual void cut()  {
            cout<< "Cutting NewYorkCheesePizza"<< endl;
        }

        virtual void pack()  {
            cout<< "Packing NewYorkCheesePizza"<< endl;
        }
        
};

class CaliforniaThinCrustPizza: public Product{
    public:
        virtual ~CaliforniaThinCrustPizza(){}
        virtual void bake()  {
            cout<< "Baking CaliforniaThinCrustPizza"<< endl;
        }

        virtual void cut()  {
            cout<< "Cutting CaliforniaThinCrustPizza"<< endl;
        }

        virtual void pack()  {
            cout<< "Packing CaliforniaThinCrustPizza"<< endl;
        }
        
};


// Concrete Creator
class DominosGMU: public FactoryCreator{
    public:
        virtual ~DominosGMU(){}
        // Offloading the creating logic to subclass
        Product* createProduct(PizzaType type)  {
            if(type == NY) return new NewYorkCheesePizza();
            if(type == CA) return new CaliforniaThinCrustPizza();  
            return NULL;          
        }
};

int main(){
    DominosGMU* dominosGMU = new DominosGMU();
    dominosGMU->orderPizza(NY);
    dominosGMU->orderPizza(CA);
    return 0;
}