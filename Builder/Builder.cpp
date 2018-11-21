#include <iostream>
#include <string>

class   Product
{
private:
    std::string     m_strKeyBoard;
    std::string     m_strMouse;
public:
    void    setKeyBoard(const std::string & strKeyBoard)
    {
        m_strKeyBoard = strKeyBoard;
    }
    void    setMouse(const std::string & strMouse)
    {
        m_strMouse = strMouse;
    }

    std::string     description()
    {
        return  m_strKeyBoard+" "+m_strMouse;
    }
};

class   Builder
{
protected:
    Product     m_Product;
public:
    virtual     ~Builder() {}
    Product     get()
    {
        return m_Product;
    }
    virtual void    makeKeyBoard() = 0;
    virtual void    makeMouse() = 0;
};

class   HpBuilder : public Builder
{
public:
    void    makeKeyBoard()
    {
        m_Product.setKeyBoard("Hp KeyBoard");
    }
    void    makeMouse()
    {
        m_Product.setMouse("Hp Mouse");
    }
};

class   DellBuilder : public Builder
{
public:
    void    makeKeyBoard()
    {
        m_Product.setKeyBoard("Dell KeyBoard");
    }
    void    makeMouse()
    {
        m_Product.setMouse("Dell Mouse");
    }
};

class   Director
{
private:
    Builder *   m_pBuilder;
public:
    Director(Builder * pBuilder = nullptr) : m_pBuilder(m_pBuilder){}
    void    setBuilder(Builder * pBuilder)
    {
        //if (m_pBuilder != nullptr)
            //delete m_pBuilder;
        m_pBuilder = pBuilder;
    }

    void    construct()
    {
        m_pBuilder->makeKeyBoard();
        m_pBuilder->makeMouse();
    }

    Product    get()
    {
        return m_pBuilder->get();
    }
};

int main()
{
    Builder *   pDellBuilder = new DellBuilder();
    Builder *   pHpBuilder = new HpBuilder();

    Director *  pDirector = new Director(pDellBuilder);
    pDirector->construct();
    Product     product = pDirector->get();
    std::cout<<product.description()<<std::endl;

    pDirector->setBuilder(pHpBuilder);
    pDirector->construct();
    product = pDirector->get();
    std::cout<<product.description()<<std::endl;

    delete  pDellBuilder;
    delete  pHpBuilder;
    delete  pDirector;

    return 0;

}
