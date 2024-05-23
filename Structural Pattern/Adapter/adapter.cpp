
// Let's say you have a legacy client: that takes XML objects and the properties is in Meter
// You want to integrate a new library that works with JSON objects and the properties should be provided in Kilo Meter
// To make this two library work with each other you need to do something
// You can create a class that follows the interface (or maybe abstract class) Defined by the LEGACY CLIENT (input: XML and Meter)
// The class should also have a reference to the New Library object (As it will interact with both of them)
// It takes the XML input -> Converts it to the format of New Library -> call service(New Library) object with processed-> hand it back.
// The class that has the above capabilities called Adapter Class and it is Known as  ADAPTER DESIGN PATTERN.


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// This is client interface 
class Xml{
    public:
        virtual string inputXML(string xmlFile) = 0;
};


class Client: public Xml{
    public:
        ~Client() = default;
        string inputXML(string xmlFile) override{
            cout<<" Type of File: Client: "<<xmlFile << endl;
            return "XML and meter unit\n";
        }
        
};

// This both of then work wih different interface 
class ThirdPartyClient{
    public:
        ~ThirdPartyClient() = default;
        string inputJSON(string jsonFile){
            cout<<" Type of File ThirdPartyClient: "<<jsonFile << endl;            
            return "JSON and Kilo Meter Format\n";
        }
};


class ThirdPartyAdapter: public Xml{
    protected:
        ThirdPartyClient *thirdParty_;
    public:
        ~ThirdPartyAdapter() = default;
        
        ThirdPartyAdapter(ThirdPartyClient *thirdParty){
            thirdParty_ = thirdParty;
        }

        string someUtilityFunction(string xmlFile){
            cout<< "Converting XML to JSON\n";
            return "JSON file";
        }

        string inputXML(string xmlFile) override {
            cout<< "Adapter received file type: "<< xmlFile << endl;
            cout<< thirdParty_->inputJSON(someUtilityFunction(xmlFile))<< endl;
            return "";
        }

        
};



int main(){

    // initially I was working with Xml object
    Xml* client = new Client();

    // I want to work with Xml object even with this third party but it is not compatable with interface
    ThirdPartyClient* thirdParty = new ThirdPartyClient();

    // write a adapter class and you can still use the Xml class and have the functionality of third party
    Xml* adapter = new ThirdPartyAdapter(thirdParty);

    
    
    // THIS WILL THROW ERROR AS INTERFACE DOES NOT DEFINE THIS FUNCTION
    // adapter->someUtilityFunction();
    
    // you will not have problems now incompatible library can work against target interface but through adapter
    adapter->inputXML("XML file");
}