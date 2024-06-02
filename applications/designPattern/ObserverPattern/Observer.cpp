
#include "Observer.h"

#include <algorithm>
#include <iostream>

Subject::~Subject(){
}; 

void Subject::notify()  {
        for(auto observer : _observers) {
        observer->handle();
        }
}

void Subject::subscribe(IObserver *observer)  {
    std::cout << "Subscribing observer: " << observer << '\n';
    _observers.push_back(observer);
}

void Subject::unsubscribe(IObserver * observer)  { 
    std::list<IObserver *>::iterator findObserver 
        = std::find(_observers.begin(), _observers.end(), observer);

    if(findObserver != _observers.end()) {
        std::cout << "Unsubscribing observer: " << observer << '\n';
        _observers.remove(*findObserver);
    }
}

Subscriber::Subscriber() =default;
Subscriber::Subscriber(const std::string & name): _name(name) {}

void Subscriber::handle()  {
        std::cout << "Handling of: "<< this << " " <<_name << '\n';
}
