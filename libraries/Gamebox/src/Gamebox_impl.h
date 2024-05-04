#ifndef GAMEBOX_IMPL_H
#define GAMEBOX_IMPL_H

namespace Sandbox {
    namespace Gamebox {
         enum class  Status {
            Empty  = -4,
            None   = -3,
            Strike = -2,
            Spare  = -1,
            Miss   =  0
        };
        struct BowlingSet {
            //setters
            bool roll(const int&);
            void reset();
            //getters
            int* rolls();
            int* scores();
            int  pinsLeft();
            int  score();
            bool isOver(); 
            //helpers
            bool isStrike(const int&);
            bool isSpare(const int&);
            bool isEmpty(const int &);
            bool isMiss(const int &);
            bool isNone(const int &);
            int  frameScore(const int &);
            bool managePins(const int&);
            int  manageCursor();
            int  validateRoll(const int &);
            //states
        private:
            int _rolls[21];
            int _rollIndex = 0;
            int _pinsLeft  =10;
            int _cursor    = 0; 
        };

    }
}

#endif //GAMEBOX_IMPL_H