#include <iostream>
#include <string>

class   Implementor
{
public:
    virtual std::string     action() = 0;
};

class   RedImplementor : public Implementor
{
public:
    std::string     action()
    {
        return std::string("red");
    }
};

class   BlackImplementor : public Implementor
{
public:
    std::string     action()
    {
        return std::string("black");
    }
};

class   Abstraction
{
public:
    virtual void    operation() = 0;
};

class   SonyAbstraction : public Abstraction
{
private:
    Implementor *   m_pImplementor;
public:
    SonyAbstraction(Implementor * pImplementor) : m_pImplementor(pImplementor){}
    void    operation()
    {
        std::cout<<"Sony "<<m_pImplementor->action()<<" TV"<<std::endl;
    }
    void    setImplementor(Implementor * pImplementor)
    {
        m_pImplementor = pImplementor;
    }
};

class   HpAbstraction : public Abstraction
{
private:
    Implementor *   m_pImplementor;
public:
    HpAbstraction(Implementor * pImplementor) : m_pImplementor(pImplementor) {}
    void    operation()
    {
        std::cout<<"Hp "<<m_pImplementor->action()<<" TV"<<std::endl;
    }
    void    setImplementor(Implementor * pImplementor)
    {
        m_pImplementor = pImplementor;
    }
};


int main()
{
    Implementor * pRedImplementor = new RedImplementor();
    Implementor * pBlackImplementor = new BlackImplementor();

    Abstraction * pSonyAbstraction = new SonyAbstraction(pRedImplementor);
    Abstraction * pHpAbstraction = new HpAbstraction(pBlackImplementor);
    pSonyAbstraction->operation();
    pHpAbstraction->operation();


    delete pRedImplementor;
    delete pBlackImplementor;
    delete pSonyAbstraction;
    delete pHpAbstraction;

    return 0;
}