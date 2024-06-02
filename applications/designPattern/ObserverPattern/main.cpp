#include "Observer.h"

#include <iostream>

int main () {
    Subject aSubject= Subject();
    Subscriber* sub0 = new Subscriber;
    Subscriber* sub1 = new Subscriber("first Subscriber");
    Subscriber* sub2 = new Subscriber("Second Subscriber");
    aSubject.subscribe(sub0);
    aSubject.subscribe(sub1);
    aSubject.subscribe(sub2);

    aSubject.notify();

    aSubject.unsubscribe(sub0);
    aSubject.unsubscribe(sub1);
    aSubject.unsubscribe(sub2);

    int x; std::cin >> x; 
    return 0;
}