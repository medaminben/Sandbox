#ifndef GAMEBOX_IMPL_H
#define GAMEBOX_IMPL_H

namespace Sandbox {
    namespace Gamebox {
         enum class  Status {
            None   = -3,
            Strike = -2,
            Spare  = -1
        };
        struct BowlingSet {
            //setters
            void roll(const int&);
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
            int  frameScore(const int&);
            bool  managePins(const int&);
            int  validateRoll(const int&);
            //states
        private:
            int _rolls[21];
            int _rollIndex = 0;
            int _pinsLeft  =10;
        };

    }
}

#endif //GAMEBOX_IMPL_H