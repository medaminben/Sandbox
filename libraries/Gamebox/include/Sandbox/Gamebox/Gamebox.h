#ifndef GAMEBOX_H
#define GAMEBOX_H
#include "Sandbox_export.h"
#include <memory>
struct BowlingSet;
namespace Sandbox {
    namespace Gamebox {
        
        class Bowlingbox {
            public:
                SANDBOX_API Bowlingbox();
                SANDBOX_API ~Bowlingbox();
            public:
                void SANDBOX_API roll(const int&);
                int  SANDBOX_API score();
                int* SANDBOX_API rolls();
                int* SANDBOX_API scores();
                int  SANDBOX_API pinsLeft();
                int  SANDBOX_API getFrameScore(const int&);
                void SANDBOX_API reset();
                bool SANDBOX_API isOver();
            private:
                std::unique_ptr<BowlingSet> _gameSet;
        };
    }
}

#endif // GAMEBOX_H
