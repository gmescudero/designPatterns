
#include <iostream>
#include <list>

class Dog {
private:
    std::string name;
    std::string type;
    int age;
    std::list<std::string> toys;

protected:
    Dog(std::string nameIn, std::string typeIn, int ageIn, std::list<std::string> toysIn){
        name = nameIn;
        type = typeIn;
        age  = ageIn;
        toys = toysIn;
    }
public:
    virtual Dog build();
};

class AwesomeBuilder: Dog{

public:
    bool BuildPart() {
        std::cout << "This is an awesome builder" << std::endl;
        return true;
    }


};


int main (int argc, char** argv)
{

    return 0;
}