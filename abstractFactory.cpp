

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>


class Coin {
private: 
    int value;
public:
    Coin():value(10){
        std::cout << "Created default coin, value: " << value << std::endl;
    }
};

class Block {
private: 
    bool isRed;
public:
    Block():isRed(false){
        std::cout << "Created default non-red block" << std::endl;
    }
    Block(bool red):isRed(red){
        std::cout << "Created " << (red?"red":"non-red") << " block" << std::endl;
    }
};

class AbstractFactory {
protected:
    AbstractFactory(){}
public:
    virtual Coin* CreateCoin() = 0;
    virtual Block* CreateBlock() = 0;
};

class DefaultFactory: public AbstractFactory {
public:
    Coin* CreateCoin() {
        return new Coin;
    }
    Block* CreateBlock() {
        return new Block;
    }
};


class RedBlockFactory: public AbstractFactory {
public:
    Coin* CreateCoin() {
        return new Coin;
    }
    Block* CreateBlock() {
        return new Block(true);
    }
};

int main(int argc, char** argv) 
{
    AbstractFactory* factory = new DefaultFactory;

    Block* b = factory->CreateBlock();
    Coin* c  = factory->CreateCoin();

    delete b;
    delete c;

    return 0;
}