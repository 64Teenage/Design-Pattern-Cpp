#include <iostream>

class   Subject
{
public:
    virtual     ~Subject(){}
    virtual void    request() = 0;
};


class   RealSubject : public Subject
{
public:
    void    request()
    {
        std::cout<<"We have got your message"<<std::endl;
    }
};


class   Proxy : public Subject
{
private:
    Subject *   m_pSubject;
public:
    Proxy()
    {
        m_pSubject = new RealSubject();
    }

    ~Proxy()
    {
        delete m_pSubject;
    }

    void    request()
    {
        m_pSubject->request();
    }
};

int main()
{
    Proxy * pProxy = new Proxy();
    pProxy->request();

    delete pProxy;
    return 0;
}