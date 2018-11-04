#include <iostream>
#include <list>

using namespace std;

class Subject;

class Observer
{
  public:
    virtual int getState() = 0;
    virtual void update(Subject *object) = 0;
};

class ConcreteOberverOne : public Observer
{
  private:
    int m_observerState;

  public:
    ConcreteOberverOne(int iObserverState) : m_observerState(iObserverState){}
    int getState()
    {
        return m_observerState;
    }
    void    update(Subject *);
};

class Subject
{
  private:
    std::list<Observer *> m_pObserverNode;

  public:
    void registerObserver(Observer *object)
    {
        m_pObserverNode.push_back(object);
    }

    void removeObserver(Observer *object)
    {
        m_pObserverNode.remove(object);
    }

    void notifyObserver()
    {
        for (list<Observer *>::iterator it = m_pObserverNode.begin(); it != m_pObserverNode.end(); ++it)
        {
            (*it)->update(this);
        }
    }

    virtual int getState() = 0;
    virtual void setState(int iState) = 0;
};

class ConcreteSubject : public Subject
{
  private:
    int m_iSubjectState;

  public:
    int getState()
    {
        return m_iSubjectState;
    }
    void setState(int iState)
    {
        m_iSubjectState = iState;
    }
    ConcreteSubject(int iState) : m_iSubjectState(iState) {}
    ConcreteSubject() {}
};

void ConcreteOberverOne::update(Subject *object)
{
    m_observerState = object->getState();
    std::cout << m_observerState << std::endl;
}

int main()
{
    ConcreteOberverOne ObserverOne(1);
    ConcreteOberverOne ObserverTwo(2);

    Subject *subject = new ConcreteSubject();
    subject->registerObserver(&ObserverOne);
    subject->registerObserver(&ObserverTwo);

    subject->setState(10);
    subject->notifyObserver();

    subject->removeObserver(&ObserverOne);
    subject->removeObserver(&ObserverTwo);

    delete subject;

    return 0;
}