// Singleton exercise
/*

Exercise 1 - singleton
Create a singleton Servers of lazy type. This singleton stores the list of servers (as String). Implement the following functionalities:
- adding a server to the list
    - a method adding the server to the list should return boolean (true if the server has been added to the list, false if it's otherwise)
    - adding is possible, if its name starts from http or https
    - adding a duplicated name is impossible.
- downloading a list of servers, that names start from http.
- downloading a list of servers, that names start from https.
*/

#include <iostream>
#include <list>

#define HTTP_STR "http://"
#define HTTPS_STR "https://"

// This class is a singleton with eager instantiation
class Servers {
private:
    std::list<std::string> servers;

    Servers();
public:
    // Retrieve singleton isntance
    static Servers& Instance();
    
    // Add server to the list
    bool AddServer(std::string name) {
        if ((0 != name.rfind(HTTP_STR,0)) && (0 != name.rfind(HTTPS_STR,0))) {
            return false;
        }
        for (auto srv : servers) {
            if (0 == srv.compare(name)) {
                return false;
            }
        }

        servers.push_back(name);
        return true;
    }

    // Get all the HTTP servers
    std::list<std::string> GetHttpServers() {
        std::list<std::string> slice;
        for (auto srv : servers) {
            if (0 == srv.rfind(HTTP_STR,0)) {
                slice.push_back(srv);
            }
        }
        return slice;
    }

    // Get all the HTTPS servers
    std::list<std::string> GetHttpsServers() {
        std::list<std::string> slice;
        for (auto srv : servers) {
            if (0 == srv.rfind(HTTPS_STR,0)) {
                slice.push_back(srv);
            }
        }
        return slice;
    }
};

Servers::Servers(){}
Servers& Servers::Instance() {
    static Servers* _instance = new Servers;
    return *_instance;
}


int main (int argc, char** argv)
{
    std::cout << "Test1" << std::endl;

    std::cout <<  Servers::Instance().AddServer("https://homeworks.java.en.sdacademy.pro/design_pattern_and_good_practices/exercises/") << std::endl;
    std::cout <<  Servers::Instance().AddServer("https://homeworks.java.en.sdacademy.pro/design_pattern_and_good_practices/exercises/") << std::endl;
    std::cout <<  Servers::Instance().AddServer("https://www.youtube.com/watch?v=eLAvry56vLU&list=PLvv0ScY6vfd9wBflF0f6ynlDQuaeKYzyc&index=2") << std::endl;
    std::cout <<  Servers::Instance().AddServer("https://www.cs.utexas.edu/users/flame/laff/alaff/chapter10-10-most-important-algorithms.html") << std::endl;
    std::cout <<  Servers::Instance().AddServer("http://www.google.es") << std::endl;
    std::cout <<  Servers::Instance().AddServer("www.google.es") << std::endl;

    std::cout << "Test2" << std::endl;

    std::list<std::string>  slice = Servers::Instance().GetHttpsServers();
    std::cout << slice.size() << std::endl;
    std::cout << slice.front() << std::endl;
    
    std::cout << "Test3" << std::endl;

    slice = Servers::Instance().GetHttpServers();
    std::cout << slice.size() << std::endl;
    std::cout << slice.front() << std::endl;

    return 0;
}
