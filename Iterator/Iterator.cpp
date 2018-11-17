#include <iostream>
#include <vector>

template <class Item>
class   Iterator;

template <class Item>
class Agregate
{
  public:
    virtual Iterator<Item> *createIterator() = 0;
    virtual ~Agregate() {}
};

template <class Item>
class ConcreteAgregate;

template <class Item>
class Iterator 
{
  private:
    Item *m_pConcreteAgregate;
    size_t m_iPosition;

  public:
    Iterator(Item *pConcreteAgregate) : m_pConcreteAgregate(pConcreteAgregate), m_iPosition(0)
    {
    }

    Item &operator*()
    {
        return *m_pConcreteAgregate;
    }

    Item *operator->()
    {
        return m_pConcreteAgregate;
    }

    Iterator & operator++()
    {
        ++m_pConcreteAgregate;
        return *this;
    }
    Iterator operator++(int)
    {
        Iterator temp = *this;
        ++*this;
        return temp;
    }
    bool operator==(const Iterator & concreteIterator) const
    {
        return m_pConcreteAgregate == concreteIterator.m_pConcreteAgregate;
    }
    bool operator!=(const Iterator & concreteIterator) const
    {
        return m_pConcreteAgregate != concreteIterator.m_pConcreteAgregate;
    }
};

template <class Item>
class ConcreteAgregate : public Agregate<Item>
{
  private:
    std::vector<Item> m_vecArray;
    //typedef Iterator<Item>  iterator;
    
  public:
    using iterator = Iterator<Item>;
    void addItem(const Item &item)
    {
        m_vecArray.push_back(item);
    }

    iterator begin()
    {
        return iterator(&(m_vecArray[0]));
    }

    iterator end()
    {
        return iterator(&(m_vecArray[0]) + m_vecArray.size());
    }

    iterator *createIterator()
    {
        return new iterator(&m_vecArray[0]);
    }
};

int main()
{
    ConcreteAgregate<int> * pConcreteAgregate = new ConcreteAgregate<int>();
    for (int pos=0; pos<10; ++pos)
        pConcreteAgregate->addItem(pos+1);
    
    for (ConcreteAgregate<int>::iterator it = pConcreteAgregate->begin(); it!=pConcreteAgregate->end(); ++it)
        std::cout<<*it<<std::endl;

    return 0;

}