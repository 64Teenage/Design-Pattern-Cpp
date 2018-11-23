#include <iostream>
#include <unordered_map>

class   Flyweight
{
public:
    virtual ~Flyweight() {}
    virtual void    operation() = 0;
};

class   ShareFlyweight : public Flyweight
{
private:
    int     m_iStatusCode;
public:
    ShareFlyweight(int iCode) : m_iStatusCode(iCode){}
    void    operation()
    {
        std::cout<<"Share Flyweight with code "<<m_iStatusCode<<std::endl;
    }
};

class   MonopolyFlyweight : public Flyweight
{
private:
    int     m_iStatusCode;
public:
    MonopolyFlyweight(int iCode) : m_iStatusCode(iCode){}
    void    operation()
    {
        std::cout<<"Monopoly Flyweight with code "<<m_iStatusCode<<std::endl;
    }
};

class   FlyweightFactory
{
private:
    std::unordered_map<int, Flyweight*> m_mapGraph;
public:
    ~FlyweightFactory()
    {
        for (auto it=m_mapGraph.begin(); it!=m_mapGraph.end(); ++it)
            delete it->second;
    }
    Flyweight *     getFlyweight(int iCode)
    {
        auto it = m_mapGraph.find(iCode);
        if (it!=m_mapGraph.end())
        {
            std::cout<<iCode<<" Flyweight already exist."<<std::endl;
            return it->second;
        }
        else
        {
            Flyweight * pFlyweight = new ShareFlyweight(iCode);
            m_mapGraph.insert(std::pair<int,Flyweight *>(iCode, pFlyweight));
            return pFlyweight;
        }
    }
};

int main()
{
    FlyweightFactory * pFlyweightFactory = new FlyweightFactory();
    Flyweight * pFlyweight = pFlyweightFactory->getFlyweight(1);
    pFlyweight->operation();
    pFlyweight = pFlyweightFactory->getFlyweight(2);
    pFlyweight->operation();
    pFlyweight = pFlyweightFactory->getFlyweight(1);
    pFlyweight->operation();

    delete pFlyweightFactory;
    return 0;
}