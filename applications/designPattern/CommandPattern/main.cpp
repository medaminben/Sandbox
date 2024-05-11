#include "Command.h"

int main () {
    auto invoker       = new Invoker();

    auto firstCommand  = new PrintCommand("first Command");
    auto secondCommand = new BusinessCommand(new Reciever(), "second Command", "Reciever Call");
    auto thirdCommand  = new PrintCommand("third Command");
    
    invoker->set_start_command(firstCommand);
    invoker->set_middle_command(secondCommand);
    invoker->set_end_command(thirdCommand);
    
    invoker->invoke();
    
    delete invoker;
    return 0;
}