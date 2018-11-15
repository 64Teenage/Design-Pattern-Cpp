#include <iostream>

class   BaseAlgorithm
{
public:
    void    AlgorithmFrame()
    {
        boilWater();
        addMaterial();
        makeCup();
        drink();
    }

    void    boilWater()
    {
        std::cout<<"Boil Water"<<std::endl;
    }

    virtual void    addMaterial() = 0;
    virtual void    makeCup() = 0;

    void    drink()
    {
        std::cout<<"Drink"<<std::endl;
    }
};

class   Tea : public BaseAlgorithm
{
public:
    void    addMaterial()
    {
        std::cout<<"Add Surger"<<std::endl;
    }

    void    makeCup()
    {
        std::cout<<"Make Tea"<<std::endl;
    }
};

class   Coffee : public BaseAlgorithm
{
public:
    void    addMaterial()
    {
        std::cout<<"Add Salt"<<std::endl;
    }

    void    makeCup()
    {
        std::cout<<"Make Coffee"<<std::endl;
    }
};

int main()
{
    BaseAlgorithm * pBaseAlgorithm = new Tea();
    pBaseAlgorithm->AlgorithmFrame();
    delete pBaseAlgorithm;

    pBaseAlgorithm = new Coffee();
    pBaseAlgorithm->AlgorithmFrame();
    delete pBaseAlgorithm;

    return 0;
}