#include <iostream>

class   Task
{
public:
    virtual void    request() = 0;
};

class   Adaptee
{
public:
    void    specialRequest()
    {
        std::cout<<"I am Adaptee"<<std::endl;
    }
};

class   Adapter : public Task
{
private:
    Adaptee *   m_pAdaptee;
public:
    Adapter() 
    {
        m_pAdaptee = new Adaptee();
    }

    ~Adapter()
    {
        delete m_pAdaptee;
    }

    void    request()
    {
        m_pAdaptee->specialRequest();
    }
};

int main()
{
    Task * pTask = new Adapter();
    pTask->request();

    delete pTask;
    return 0;
}