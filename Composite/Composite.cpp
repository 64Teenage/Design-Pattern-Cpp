#include <iostream>
#include <vector>
#include <string>

class   Component
{
public:
    virtual Component * getChild(int) {return nullptr;}
    virtual bool        add(Component *) {return false;}
    virtual bool        remove(int) {return false;}

    virtual void        print() = 0;
};

class   Leaf : public Component
{
private:
    int         m_Id;
    std::string m_strName;
public:
    Leaf(int id, std::string strWords) : m_Id(id),m_strName(strWords){}
    void    print()
    {
        std::cout<<"id:\t"<<m_Id<<"\t"<<"Name:\t"<<m_strName<<std::endl;
    }
};

class   Composite : public Component
{
private:
    std::vector<Component *> m_vecComponent;
public:
    Component * getChild(int id)
    {
        if (id>=m_vecComponent.size() || id<0)
            return nullptr;
        else
            return m_vecComponent[id];
    }
    bool        add(Component * pComponent)
    {
        m_vecComponent.push_back(pComponent);
        return true;
    }
    bool        remove(int id)
    {
        if (id>=m_vecComponent.size() || id<0)
            return false;
        m_vecComponent.erase(m_vecComponent.begin()+id);
        return true;
    }
    void        print()
    {
        for (auto pComponent : m_vecComponent)
            pComponent->print();
    }
};

int main()
{
    Composite * pComposite = new Composite();
    Composite * pSubComposite = new Composite();
    Leaf *  pLeafOne = new Leaf(1, "2008");
    Leaf *  pLeafTwo = new Leaf(2, "2012");
    Leaf *  pLeafThree = new Leaf(3, "2016");

    pSubComposite->add(pLeafOne);
    pSubComposite->add(pLeafTwo);

    pComposite->add(pSubComposite);
    pComposite->add(pLeafThree);

    pComposite->print();

    delete pLeafOne;
    delete pLeafTwo;
    delete pLeafThree;
    delete pSubComposite;
    delete pComposite;

    return 0;
}