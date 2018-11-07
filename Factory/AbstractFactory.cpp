#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class MouseProduct
{
public:
    virtual string  getName()=0;
};

class KeyBoardProduct
{
public:
    virtual string  getName()=0;
};

class DellMouseProduct : public MouseProduct
{
public:
    string      getName()
    {
        return string("Dell Mouse");
    }
};

class HpMouseProduct : public MouseProduct
{
public:
    string      getName()
    {
        return string("Hp Mouse");
    }
};

class DellKeyBoardProduct : public KeyBoardProduct
{
public:
    string      getName()
    {
        return string("Dell KeyBoard");
    }
};

class HpKeyBoardProduct : public KeyBoardProduct
{
public:
    string  getName()
    {
        return string("Hp KeyBoard");
    }
};

class   AbstractFactory
{
public:
    virtual MouseProduct * createMouse()=0;
    virtual KeyBoardProduct * createKeyBoard()=0;
};

class   DellFactory : public AbstractFactory
{
public:
    MouseProduct * createMouse()
    {
        return new DellMouseProduct();
    }
    KeyBoardProduct * createKeyBoard()
    {
        return new DellKeyBoardProduct();
    }
};

class   HpFactory : public AbstractFactory
{
public:
    MouseProduct * createMouse()
    {
        return new HpMouseProduct();
    }
    KeyBoardProduct * createKeyBoard()
    {
        return new HpKeyBoardProduct();
    }
};

int main()
{
    AbstractFactory * pFactory = new DellFactory();
    MouseProduct * pMouseProduct = pFactory->createMouse();
    KeyBoardProduct * pKeyBoardProduct  = pFactory->createKeyBoard();
    std::cout<<pMouseProduct->getName()<<std::endl;
    std::cout<<pKeyBoardProduct->getName()<<std::endl;

    delete pFactory;
    delete pMouseProduct;
    delete pKeyBoardProduct;

    pFactory = new HpFactory();
    pMouseProduct = pFactory->createMouse();
    pKeyBoardProduct = pFactory->createKeyBoard();
    std::cout<<pMouseProduct->getName()<<std::endl;
    std::cout<<pKeyBoardProduct->getName()<<std::endl;

    delete pFactory;
    delete pMouseProduct;
    delete pKeyBoardProduct;

    return 0;
}