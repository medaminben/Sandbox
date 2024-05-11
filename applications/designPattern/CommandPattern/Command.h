#pragma once

#include <string>
/**
 * @brief the command interface
 * 
 */
class ICommand {
public: 
    virtual ~ICommand(){};
    virtual void execute() const = 0;
};


/**
 * @brief an naive implementation of the command interface ICommand
 * 
 */
class PrintCommand : public ICommand {  
private: 
    std::string _message; 
public:
    PrintCommand(const std::string&);
    void execute() const override;
};


/**
 * @brief the reciever is normally the consumer of the command order
 * somes call it component too 
 */
class Reciever {
public:
    void ProcessA(const std::string &);
    void ProcessB(const std::string &);
};
/**
 * @brief an implementation of the command interface ICommand
 * 
 */
class BusinessCommand : public ICommand {
private: 
    Reciever*   _reciever;
    std::string _proc_a_details;
    std::string _proc_b_details;
public:
    BusinessCommand(Reciever*, const std::string&, const std::string&);
    void execute() const override;
};



/**
 * @brief the one and only owner of the commands 
 * Normally should contains the business logic of the use of the commands
 * in this example the invoker invokes 3 commands sequentially 
 */
class Invoker {
private:
    ICommand* _startCommand = nullptr; 
    ICommand* _midCommand   = nullptr; 
    ICommand* _endCommand   = nullptr;
public:
    ~Invoker();
    void set_start_command(ICommand*);
    void set_middle_command(ICommand*);
    void set_end_command(ICommand*);
    void invoke();
};