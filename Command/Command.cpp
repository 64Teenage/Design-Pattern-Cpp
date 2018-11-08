#include <iostream>

class   Receiver
{
public:
    virtual void    on()=0;
    virtual void    off()=0;
};

class   DellReceiver : public Receiver
{
public:
    void    on()
    {
        std::cout<<"Dell Open"<<std::endl;
    }
    void    off()
    {
        std::cout<<"Dell Close"<<std::endl;
    }
};

class   HpReceiver : public Receiver
{
public:
    void    on()
    {
        std::cout<<"Hp Open"<<std::endl;
    }
    void    off()
    {
        std::cout<<"Hp Close"<<std::endl;
    }
};

class   Command
{
public:
    virtual void    execute()=0;
    virtual void    undo()=0;
};

class   OnCommand : public Command
{
private:
    Receiver * m_pReceiver;
public:
    OnCommand(Receiver * pReceiver) : m_pReceiver(pReceiver){}

    void    execute()
    {
        m_pReceiver->on();
    }
    void    undo()
    {
        m_pReceiver->off();
    }
};

class   OffCommand : public Command
{
private:
    Receiver * m_pReceiver;
public:
    OffCommand(Receiver * pReceiver) : m_pReceiver(pReceiver){}

    void    execute()
    {
        m_pReceiver->off();
    }
    void    undo()
    {
        m_pReceiver->on();
    }
};

class   Invoker
{
private:
    Command *   m_pCommand;
    Command *   m_pUndoCommand;
public:
    Invoker() : m_pCommand(nullptr),m_pUndoCommand(nullptr){}
    void    setCommand(Command * pCommand)
    {
        m_pCommand = pCommand;
        m_pUndoCommand = pCommand;
    }

    void    confirm()
    {
        if (m_pCommand)
            m_pCommand->execute();
    }

    void    revoke()
    {
        if (m_pUndoCommand)
            m_pUndoCommand->undo();
    }
};

int main()
{
    DellReceiver    dellReceiver = DellReceiver();
    HpReceiver      hpReceiver = HpReceiver();

    OnCommand   dellOnCommand = OnCommand(&dellReceiver);
    OnCommand   hpOnCommand = OnCommand(&hpReceiver);

    Invoker remoteControl = Invoker();
    remoteControl.setCommand(&dellOnCommand);
    remoteControl.confirm();
    remoteControl.setCommand(&hpOnCommand);
    remoteControl.confirm();
    remoteControl.revoke();
    
    OffCommand  dellOffCommand = OffCommand(&dellReceiver);
    remoteControl.setCommand(&dellOffCommand);
    remoteControl.confirm();

    return 0;
}