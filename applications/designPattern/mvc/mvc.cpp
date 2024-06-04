#include <iostream>
#include <string>
/*
the mvc architure follows a layer structure as in the graph

              Vview <====> user
                |A
                ||
                V|        
            controller 
                |A
                ||
                V| 
              Model
*/
namespace View {
    class UI {
        public:
        void prompt(const std::string s) {
            std::cout << s;
        }
        void prompt(int x) {
            std::cout << x;
        }
        int get_input()  {
            int x; 
            std::cin >> x;
            return x;
        }
    };
}

namespace Model {
    class Storage {
    private:
        int _x;
    public:
        void store(int x) {
            _x =x;
        }
        int retrieve(){
            return _x;
        }
    };
}
namespace Controller {
    class Logic {
        View::UI *      _u;
        Model::Storage* _s;
    public:
        Logic(View::UI* u, Model::Storage* s): _u(u), _s(s) { 
            doLogic();
        }

        void doLogic() {
            // ask the user for an integer using the view
            _u->prompt("Enter a number: ");
            // recieve the user input from the view
            auto i = _u->get_input();
            //store the integer in the model
            _s->store(i);
            // retrieve the integer from the model
            auto x = _s->retrieve();
            _u->prompt("The input number stored is: ");
            _u->prompt(x); 
            _u->prompt("\n");
        }  
    };
}

int main(){
    View::UI u;
    Model::Storage s;
    Controller::Logic l(&u,&s);
    return 0;
}


