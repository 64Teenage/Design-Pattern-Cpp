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
    Product *   createProduct(const int id)
    {
        switch(id)
        {
            case 1:
            return new ConcreteProductOne();
            break;
            case 2:
            return new ConcreteProductTwo();
            break;
            default:
            return nullptr;
            break;
        }
    }
};


int main()
{
    Factory factory;

    Product * product = factory.createProduct(1);
    std::cout<<product->getName()<<std::endl;
    delete product;

    product = factory.createProduct(2);
    std::cout<<product->getName()<<std::endl;
    delete product;

    return 0;

}
