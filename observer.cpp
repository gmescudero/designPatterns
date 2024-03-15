

#include <iostream>
#include <list>

// Type definitions

typedef enum {
    HELLO,
    GOODBYE,
    NUMBER_OF_EVENTS
} EVENT_TYPE;

// Abstract interfaces 

class Observer {
protected:
    unsigned int id;
    Observer();
public:
    virtual void update(EVENT_TYPE event) = 0;
    bool operator ==(const Observer& obs);
};

class Observable {
protected:
    std::list<Observer*> observers;
public:
    virtual void attach(Observer* obs) = 0;
    virtual void detach(Observer* obs) = 0;
    void notify(EVENT_TYPE event);
};

// Concrete instances

class Subscriber: public Observer {
public:
    void update(EVENT_TYPE event);
};

class Publisher: public Observable {
public:
    void attach(Observer* obs);
    void detach(Observer* obs);
};


// Definitions

Observer::Observer() {
    static unsigned int id_counter = 0;
    id = id_counter++;
}
bool Observer::operator ==(const Observer& obs) {
    return (this->id == obs.id)?true:false;
}

void Observable::notify(EVENT_TYPE event) {
    for (Observer* obs : observers) {
        obs->update(event);
    }
}

void Publisher::attach(Observer* obs) {
    observers.push_back(obs);
}

void Publisher::detach(Observer* obs) {
    observers.remove(obs);
}

void Subscriber::update(EVENT_TYPE event) {
    std::cout << "[" << id << "] Received event code " << event << std::endl;
}


// Main function

int main(int argc, char** argv)
{  
    Publisher   pub;
    Subscriber sub1;
    Subscriber sub2;
    Subscriber sub3;

    std::cout << "Test1" << std::endl;
    pub.notify(HELLO);
    pub.notify(GOODBYE);

    std::cout << "Test2" << std::endl;
    pub.attach(&sub1);
    pub.notify(HELLO);
    pub.notify(GOODBYE);

    std::cout << "Test3" << std::endl;
    pub.attach(&sub2);
    pub.attach(&sub3);
    pub.notify(HELLO);
    pub.notify(GOODBYE);

    std::cout << "Test4" << std::endl;
    pub.detach(&sub1);
    pub.notify(HELLO);
    pub.notify(GOODBYE);

    return 0;
}