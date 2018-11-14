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

class   Adapter : public Task, public Adaptee
{
    void    request()
    {
        specialRequest();
    }
};

int main()
{
    Task * pTask = new Adapter();
    pTask->request();

    delete pTask;
    return 0;
}