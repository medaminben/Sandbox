#include "Command.h"

#include <iostream>

 PrintCommand::PrintCommand(const std::string& data) : _message(data) {

 }
void PrintCommand::execute() const {
    std::cout << "command to print: " << _message << '\n';
}



void Receiver::ProcessA(const std::string &proc_a_stuff) {
    std::cout << "Receiver is A working on: " << proc_a_stuff << '\n';
}
void Receiver::ProcessB(const std::string &proc_b_stuff) {
    std::cout << "Receiver is B working on: " << proc_b_stuff << '\n';
}

BusinessCommand::BusinessCommand(Receiver*   reciever, 
                                  const std::string& a, 
                                  const std::string& b) :
                 _reciever(reciever), _proc_a_details(a), 
                 _proc_b_details(b) {

}
void BusinessCommand::execute() const  {
    _reciever->ProcessA(_proc_a_details);
    _reciever->ProcessB(_proc_b_details);
}


Invoker::~Invoker(){
    if(_startCommand) 
        delete _startCommand;
    if(_midCommand) 
        delete _midCommand;
    if(_endCommand) 
        delete _endCommand;
}
void Invoker::set_start_command(ICommand*  sc) {
    _startCommand = sc; 
}
void Invoker::set_middle_command(ICommand* mc) {
    _midCommand   = mc;
}
void Invoker::set_end_command(ICommand* ec) {
    _endCommand   = ec;
}
void Invoker::invoke() {
    if(_startCommand) 
        _startCommand->execute();
    if(_midCommand) 
        _midCommand->execute();
    if(_endCommand) 
        _endCommand->execute();
}