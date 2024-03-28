#ifndef SESSION_HPP
#define SESSION_HPP

/* C/C++ Libs */
#include <string>

class Session {
public:
    Session(std::string sessionId) : _sessionId(sessionId) {}
    ~Session();

    void setName(std::string name) { _name = name;}
    void setAge(std::string age) { _age = age;}
    void setHeight(std::string height) { _height = height;}
    void setWeight(std::string weight) { _weight = weight;}

    std::string getName() { return _name;}
    std::string getAge() { return _age;}
    std::string getHeight() { return _height;}
    std::string getWeight() { return _weight;}

private:
    std::string _sessionId;
    std::string _name, _age, _height, _weight;
};

#endif
