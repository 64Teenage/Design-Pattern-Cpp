#include <iostream>
#include <string>

using std::string;

class Product
{
public:
    virtual string  getName()=0;
};


class ConcreteProductOne : public Product
{
public:
    string  getName()
    {
        return string("Concrete Product One");
    }
};

class ConcreteProductTwo : public Product
{
public:
    string  getName()
    {
        return string("Concrete Product Two");
    }
};

class Factory
{
public:
    virtual Product * createProduct() = 0;
};

class ConcreteFactoryOne : public Factory
{
public:
    Product *   createProduct()
    {
        return (new ConcreteProductOne());
    }
};

class ConcreteFactoryTwo : public Factory
{
public:
    Product *   createProduct()
    {
        return new ConcreteProductTwo();
    }
};

int main()
{
    Factory *   pFactory = new ConcreteFactoryOne();
    Product *   pProduct = pFactory->createProduct();
    std::cout<<pProduct->getName()<<std::endl;
    delete pFactory;
    delete pProduct;

    pFactory = new ConcreteFactoryTwo();
    pProduct = pFactory->createProduct();
    std::cout<<pProduct->getName()<<std::endl;
    delete pFactory;
    delete pProduct;

    return 0;
}