#include <iostream>

class   Strategy
{
public:  
    virtual ~Strategy(){}
    virtual void    algorithmInterface()=0;
};

class   ConcreteStrategyOne : public Strategy
{
public:
    ~ConcreteStrategyOne(){}
    void    algorithmInterface()
    {
        std::cout<<"I am Strategy One!"<<std::endl;
    }
};

class   ConcreteStrategyTwo : public Strategy
{
public:
    ~ConcreteStrategyTwo(){}
    void    algorithmInterface()
    {
        std::cout<<"I am Strategy Two!"<<std::endl;
    }
};

class   Contex
{
private:
    Strategy    *m_Strategy;
public:
    Contex(Strategy * s) : m_Strategy(s){}
    ~Contex()
    {
        delete  m_Strategy;
    }

    void    display()
    {
        m_Strategy->algorithmInterface();
    }
};


int main()
{
    ConcreteStrategyOne *CSOne = new ConcreteStrategyOne();
    Contex  contex(CSOne);
    contex.display();

    ConcreteStrategyTwo *CSTwo = new ConcreteStrategyTwo();
    Contex  comtex(CSTwo);
    comtex.display();

    return 0;
}