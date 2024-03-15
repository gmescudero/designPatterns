
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

// General Entity abstract class
class Entity {
protected:
    Entity(){}
public:
    virtual void update() = 0;
};

// Concrete Enemy clases
class Boo: public Entity {
public:
    Boo(){
        std::cout << "Boo created" << std::endl;
    }
    void update(){
        std::cout << "Boo update" << std::endl;
    }
};

class Koopa: public Entity {
public:
    Koopa(){
        std::cout << "Koopa created" << std::endl;
    }
    void update(){
        std::cout << "Koopa update" << std::endl;
    }

};

class Goomba: public Entity {
public:
    Goomba(){
        std::cout << "Goomba created" << std::endl;
    }
    void update(){
        std::cout << "Goomba update" << std::endl;
    }

};



// General Factory abstract class
class EnemyFactory {
private:

protected:
    enum {
        BOO = 0,
        KOOPA,
        GOOMBA,
        NUMBER_OF_ENEMIES
    } TYPES_OF_ENEMIES;
    std::list<Entity*> enemies;
    EnemyFactory(){}
public:
    ~EnemyFactory() {
        for (Entity* e : enemies) {
            delete e;
        }
    }
    virtual void AddEnemy() = 0;
};

// Concrete Factory class adding random enemies
class RandomEnemyFactory: public EnemyFactory {
public:
    RandomEnemyFactory() {
        std::srand(std::time(nullptr));
    }

    void AddEnemy() {
        int randomValue = std::rand() % NUMBER_OF_ENEMIES;

        switch (randomValue) {
            case BOO: // Boo
                enemies.push_back(new Boo);
                break;
            case KOOPA: // Koopa
                enemies.push_back(new Koopa);
                break;
            case GOOMBA: // Boo
                enemies.push_back(new Goomba);
                break;
            default: 
                std::cout << "Error" << std::endl;
        }

    }
};



int main(int argc, char** argv)
{
    std::cout << "Test1" << std::endl;

    Entity* g = new Koopa;
    
    g->update();

    delete g;

    std::cout << "Test2" << std::endl;

    RandomEnemyFactory factory;

    factory.AddEnemy();
    factory.AddEnemy();
    factory.AddEnemy();
    factory.AddEnemy();

    return 0;
}