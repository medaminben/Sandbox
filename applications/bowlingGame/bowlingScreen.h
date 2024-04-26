#ifndef BOWLING_SCREEN_H
#define BOWLING_SCREEN_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#ifdef WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#endif
#include <unistd.h>
#include <memory>


#include <Sandbox/Gamebox/Gamebox.h>

using namespace Sandbox::Gamebox;
using namespace std;
typedef std::vector<std::vector<std::string>> StringTable;
namespace Console{

    class Frame{
        public:
            enum class Type{
                Regular = 0,
                Last = 1
            };
            enum class Bonus{
                None= -3,
                Strike = -2,
                Spare = -1
            };
            enum class Order{
                First = 1,
                Second = 2,
                Last
            };
            Frame(Type type = Type::Regular);
        public:
            void setRoll(const Order&, const int&);
            void setScore(const int&);
        public:
            void updateRolls();
            void updateScore();
            void resetFrame();
            std::vector<std::string> getFrame() const;
            void setFrame(const int& frame_score,
                          const int& first_roll, 
                          const int& second_roll, 
                          const int& last_roll = (int)Bonus::None
                          );
        protected:
            Type type = Type::Regular;

            std::string _firstRoll{"   "};
            std::string _secondRoll{"   "};
            std::string _framescore{"   "};
            std::string _lastRoll{"   "};
            std::vector<std::string> _frame{};
    };


    class Screen {  
        enum class Status {
            FristStart   = 0,
            TryStart     = 1,
            Running      = 2,
            End          = 3,
            Quit         = 4,
            Typo         = 5
        };
        public:
            Screen(std::shared_ptr<Bowlingbox>);
        
            bool clearScreen();
            int  getConsoleWidth();
            void updateGrid();
            void plotIntro();
            void plotGrid();
            void start();
            void resetGame();
            void evaluate(const std::string& choice);
            void plotMenu();

        protected:
            bool isExit();
            bool isEndGame();
            bool isRunning();
            bool isTryStart();
            bool isFirstStart();
            bool isTypo();
        private:
            std::shared_ptr<Bowlingbox> game;
            std::vector<Frame> frames{};
            Status status = Status::FristStart;


        private: 
    };
}

#endif // BOWLING_SCREEN_H