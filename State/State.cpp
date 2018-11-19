#include <iostream>

class   State
{
public:
    virtual     ~State() {}
    virtual void    buttonOn() = 0;
    virtual void    buttonOff() = 0;
};

class   TV;

class   TvOnState : public State
{
private:
    TV &    m_TvState;
public:
    TvOnState(TV & TvState) : m_TvState(TvState){}
    void    buttonOn()
    {
        std::cout<<"You have open tv!"<<std::endl;
    }
    void    buttonOff();
};
class   TvOffState : public State
{
private:
    TV &    m_TvState;
public:
    TvOffState(TV & TvState) : m_TvState(TvState){}
    void    buttonOn();
    void    buttonOff()
    {
        std::cout<<"Oop, please open tv first."<<std::endl;
    }
};

class   TV 
{
private:
    State *     m_pOnState;
    State *     m_pOffState;
    State *     m_pState;

public:
    TV()
    {
        m_pOnState = new TvOnState(*this);
        m_pOffState = new TvOffState(*this);
        m_pState = m_pOffState;
    }

    void    startTv()
    {
        m_pState->buttonOn();
    }
    void    closeTv()
    {
        m_pState->buttonOff();
    }
    void    setState(State * pState)
    {
        this->m_pState = pState;
    }

    State * getTvOffState()
    {
        return m_pOffState;
    }

    State * getTvOnState()
    {
        return m_pOnState;
    }

    ~TV()
    {
        delete  m_pOffState;
        delete  m_pOnState;
    }
};

void    TvOnState::buttonOff()
{
    m_TvState.setState(m_TvState.getTvOffState());
    std::cout<<"Good bye."<<std::endl;
}
void    TvOffState::buttonOn()
{
    std::cout<<"TV On, enjoy yourself!"<<std::endl;
    m_TvState.setState(m_TvState.getTvOnState());
}
int main()
{
    TV *    pTv = new TV();
    pTv->startTv();
    pTv->startTv();
    pTv->closeTv();
    pTv->closeTv();

    delete pTv;

    return 0;
}