#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Component
{
public:
    virtual string  getDescription() = 0;
};

class ConcreteComponent : public Component
{
private:
    string  m_strDescription;
public:
    ConcreteComponent(string strDescription) : m_strDescription(strDescription){}
    string  getDescription()
    {
        return m_strDescription;
    }
};

class Decorator : public Component
{
protected:
    Component * m_pComponent;
public:
    Decorator(Component * component) : m_pComponent(component){}
    virtual string  getDescription() = 0;
};

class ConcreteDecoratorOne : public Decorator
{
public:
    ConcreteDecoratorOne(Component * component) : Decorator(component){}
    string  getDescription()
    {
        return m_pComponent->getDescription() + " ConcreteDecoratorOne ";
    }
};

class ConcreteDecoratorTwo : public Decorator
{
public:
    ConcreteDecoratorTwo(Component * component) : Decorator(component){}
    string  getDescription()
    {
        return m_pComponent->getDescription() + " ConcreteDecoratorTwo ";
    }
};

int main()
{
    Component * pComponent = new ConcreteComponent("Conponent");
    std::cout<<pComponent->getDescription()<<std::endl;

    Component * pComponentOne = new ConcreteDecoratorOne(pComponent);
    std::cout<<pComponentOne->getDescription()<<std::endl;

    Component * pComponentTwo = new ConcreteDecoratorTwo(pComponentOne);
    std::cout<<pComponentTwo->getDescription()<<std::endl;

    delete pComponentTwo;
    delete pComponentOne;
    delete pComponent;

    return 0;
}