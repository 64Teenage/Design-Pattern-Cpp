#include <iostream>
#include <mutex>

std::mutex mtx;

class Singleton
{
private:
    static Singleton * m_pSingleInstance;
    Singleton(){}
    Singleton(const Singleton &){}
    Singleton *     operator=(const Singleton &){}
public:
    static Singleton *      getInstance()
    {
        if (m_pSingleInstance==NULL)
            m_pSingleInstance = new Singleton();
        return m_pSingleInstance;
    }

    void    showInstance()
    {
        std::cout<<"I am Singleton"<<std::endl;
    }
};

Singleton * Singleton::m_pSingleInstance = nullptr;

class Singleton_thread
{
private:
    static Singleton_thread * m_pSingleInstance;
    Singleton_thread(){}
    Singleton_thread(const Singleton_thread &){}
    Singleton_thread *     operator=(const Singleton_thread &){}
public:
    static Singleton_thread *      getInstance()
    {
        if (m_pSingleInstance==NULL)
        {
            mtx.lock();
            if (m_pSingleInstance==NULL)
                m_pSingleInstance = new Singleton_thread();
            mtx.unlock();
        }
        return m_pSingleInstance;
    }

    void    showInstance()
    {
        std::cout<<"I am Singleton"<<std::endl;
    }
};

int main()
{
    Singleton * pSingletonOne = Singleton::getInstance();
    Singleton * pSingletonTwo = Singleton::getInstance();
    pSingletonOne->showInstance();

    std::cout<<pSingletonOne<<std::endl;
    std::cout<<pSingletonTwo<<std::endl;
    return 0;
}
