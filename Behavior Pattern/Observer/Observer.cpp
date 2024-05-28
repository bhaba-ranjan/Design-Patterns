#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class ISubscriber{
    public:
        virtual ~ISubscriber(){}
        virtual void Update(string config) =0;
};


class IPublisher{
    public:
        virtual ~IPublisher() {}
        virtual bool Subscribe(ISubscriber *subscriber) = 0;
        virtual bool UnSubscribe(ISubscriber *subscriber) = 0; 
        virtual void Notify() = 0;
};


class Publisher: public IPublisher{
    public:
        virtual ~Publisher(){}
        
        Publisher(): IPublisher(){  
            config = "Initial Config";
        }

        bool Subscribe(ISubscriber *subscriber){
            if(subscribers_.find(subscriber) != subscribers_.end()) return false;
            subscribers_[subscriber] = 1;
            // Optional: maybe update the config for the the first time when it subscribes 
            subscriber->Update(config);
            return true;
        }

        bool UnSubscribe(ISubscriber *subscriber){
            if(subscribers_.find(subscriber) == subscribers_.end()) return false;
            subscribers_.erase(subscriber);            
            return true;
        }

        void Notify(){      

            cout<< "Notifying subscribers list size: "<< subscribers_.size()<< endl;

            for(auto it = subscribers_.begin(); it != subscribers_.end(); it++){
                it->first->Update(config);
            }
            return;
        }

        void buSinessLogic(string newConfig){            
            cout<< "publisher configuration changed"<< endl;
            config = newConfig;
            Notify();
            return;
        }

    private:
        unordered_map<ISubscriber*, int> subscribers_;
        string config;

       
};

class Subscriber: ISubscriber{
    public:
        Subscriber(string name, IPublisher *publisher): ISubscriber(){
            name_ = name;
            publisher_ = publisher;
            publisher_->Subscribe(this);
            cout<< "Subscribed: "<< name<< endl;
        }

        virtual ~Subscriber(){}
        
        void Update(string newConfig){
            cout<< "Subscriber: "<< name_ << " config changed to: " <<newConfig<< endl;
            config = newConfig;
        }

        void UnSubscribe(){
            publisher_->UnSubscribe(this);
        }

        string getConfig(){
            return config;
        }
    
    private:
    // Subscriber will have a name, config and ref to Publisher
    // Publisher ref is required because it would subscribe or UNSUBSCRIBE at any time;
        string config;
        string name_;
        IPublisher *publisher_;
};

int main(){

    Publisher *pub = new Publisher();

    Subscriber *sub1 = new Subscriber("sub-1", pub);
    Subscriber *sub2 = new Subscriber("sub-2", pub);

    cout<<" Subscriber-1:" <<sub1->getConfig()<< endl;
    cout<<" Subscriber-2:" <<sub2->getConfig()<< endl;

    cout<<"PubConfig changed\n";
    pub->buSinessLogic("changed name 1st time");


    cout<<" Subscriber-1:" <<sub1->getConfig()<< endl;
    cout<<" Subscriber-2:" <<sub2->getConfig()<< endl;

    sub2->UnSubscribe();


    cout<<"PubConfig changed\n";
    pub->buSinessLogic("changed name 2nd time");
    cout<<" Subscriber-1:" <<sub1->getConfig()<< endl;
    cout<<" Subscriber-2:" <<sub2->getConfig()<< endl;
  
}