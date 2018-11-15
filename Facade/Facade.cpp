#include <iostream>

class   SubSystemOne
{
public:
    void    subOperation()
    {
        std::cout<<"SubOperation One method"<<std::endl;
    }
};

class   SubSystemTwo
{
public:
    void    subOperation()
    {
        std::cout<<"SubOperation Two method"<<std::endl;
    }
};

class   SubSystemThree
{
public:
    void    subOperation()
    {
        std::cout<<"SubOperator Three method"<<std::endl;
    }
};

class   Facade
{
private:
    SubSystemOne *      m_pSubSystemOne;
    SubSystemTwo *      m_pSubSystemTwo;
    SubSystemThree *    m_pSubSystemThree;
public:
    Facade()
    {
        m_pSubSystemOne = new SubSystemOne();
        m_pSubSystemTwo = new SubSystemTwo();
        m_pSubSystemThree = new SubSystemThree();
    }

    ~Facade()
    {
        delete m_pSubSystemOne;
        delete m_pSubSystemTwo;
        delete m_pSubSystemThree;
    }

    void    operationOne()
    {
        m_pSubSystemOne->subOperation();
        m_pSubSystemTwo->subOperation();
    }

    void    operationTwo()
    {
        m_pSubSystemOne->subOperation();
        m_pSubSystemThree->subOperation();
    }
};

int main()
{
    Facade * pFacade = new Facade();
    pFacade->operationOne();
    std::cout<<std::endl;
    pFacade->operationTwo();
    std::cout<<std::endl;
    delete pFacade;

    SubSystemOne * pSubSystemOne = new SubSystemOne();
    SubSystemTwo * pSubSystemTwo = new SubSystemTwo();
    SubSystemThree * pSubSystemThree = new SubSystemThree();
    pSubSystemOne->subOperation();
    pSubSystemTwo->subOperation();
    std::cout<<std::endl;
    pSubSystemOne->subOperation();
    pSubSystemThree->subOperation();
    delete pSubSystemOne;
    delete pSubSystemTwo;
    delete pSubSystemThree;

    return 0;

}