#include <iostream>

class   Element;
class   KeyBoardElement;
class   MouseElement;

class   Visitor
{
public:
    virtual void    visit(KeyBoardElement * pElement) = 0;
    virtual void    visit(MouseElement * pElement) = 0;
};

class   Element 
{
public:
    virtual void    accept(Visitor * pVisitor) = 0;
};

class   MouseElement : public Element
{
public:
    void    accept(Visitor * pVisitor)
    {
        pVisitor->visit(this);
    }
};

class   KeyBoardElement : public Element
{
public:
    void    accept(Visitor * pVisitor)
    {
        pVisitor->visit(this);
    }
};

class   DellVisitor : public Visitor
{
public:
    void    visit(KeyBoardElement * pElement)
    {
        std::cout<<"Dell search keyboard"<<std::endl;
    }
    void    visit(MouseElement * pElement)
    {
        std::cout<<"Dell search mouse"<<std::endl;
    }
};

class   HpVisitor : public Visitor
{
public:
    void    visit(KeyBoardElement * pElement)
    {
        std::cout<<"Hp search keyboard"<<std::endl;
    }
    void    visit(MouseElement * pElement)
    {
        std::cout<<"Hp search mouse"<<std::endl;
    }
};

int main()
{
    DellVisitor * pDellVisitor = new DellVisitor();
    HpVisitor * pHpVisitor = new HpVisitor();

    KeyBoardElement keyBoard = KeyBoardElement();
    MouseElement    mouse = MouseElement();
    keyBoard.accept(pDellVisitor);
    keyBoard.accept(pHpVisitor);

    mouse.accept(pDellVisitor);
    mouse.accept(pHpVisitor);

    delete pDellVisitor;
    delete pHpVisitor;

    return 0;
}