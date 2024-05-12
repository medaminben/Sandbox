#include "State.h"
#include <iostream>
void MainState::enter()  {
     std::cout << "Now MainState is Started!"  << '\n';
}

void MainState::update(){
    std::cout << "Mainstate updating..."  << '\n';

    char context[] = "Select a choice \n -> 1 for Options -> 2 for exit\n";
    int choice; 
    while(true) {
        std::cout << context; std::cin >> choice;
        switch(choice){
            case 1: leave(); currentState = optionalState; return;
            case 2: exit(0);  
        }
    }
}
void MainState::leave()  {
    std::cout << "Leaving MainState"  << '\n';
}

void OptionalState::enter()  {
    std::cout << "Now OptionalState is Started!"  << '\n';
}
void OptionalState::update(){
    std::cout << "OptionalState updating..."  << '\n';
    char context[] = "Select a choice \n -> 1 for Main -> 2 for exit\n";
    int choice; 
    while(true) {
       std::cout << context; std::cin >> choice;
        switch(choice){
            case 1: leave(); currentState = mainState; return;
            case 2: exit(0);  
        }
    }
}
void OptionalState::leave()  {
     std::cout << "Leaving OptionalState"  << '\n';
}