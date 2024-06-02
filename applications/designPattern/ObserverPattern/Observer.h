#pragma once

class IObserver{
public:
     virtual void handle() =0;
};

class IObservable {
public:
    virtual ~IObservable(){}; 

    virtual void notify()                 =0;

    virtual void subscribe(IObserver *)   =0;
    virtual void unsubscribe(IObserver *) =0;
};


#include <list>
#include <string>
class Subject: public IObservable {
public:
    ~Subject(); 

    void notify() override ;

    void subscribe(IObserver *observer) override ;

    void unsubscribe(IObserver * observer) override ;

    std::list<IObserver *> _observers{};
};

class Subscriber: public IObserver {
public:
    Subscriber();
    Subscriber(const std::string & name);

    void handle() override ;

protected: 
    std::string _name{"default Subscriber"};
};
