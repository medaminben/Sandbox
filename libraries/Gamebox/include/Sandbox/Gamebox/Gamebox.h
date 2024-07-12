#ifndef GAMEBOX_H
#define GAMEBOX_H
#include "Sandbox_Gamebox_export.h"
#include <memory>
struct BowlingSet;
namespace Sandbox { namespace Gamebox {
        
   class Bowlingbox {
        public:
            SANDBOX_GAMEBOX_API Bowlingbox();
            SANDBOX_GAMEBOX_API ~Bowlingbox();
        public:
            void SANDBOX_GAMEBOX_API roll(const int&);
            int  SANDBOX_GAMEBOX_API score();
            int* SANDBOX_GAMEBOX_API rolls();
            int* SANDBOX_GAMEBOX_API scores();
            int  SANDBOX_GAMEBOX_API pinsLeft();
            int  SANDBOX_GAMEBOX_API getFrameScore(const int&);
            void SANDBOX_GAMEBOX_API reset();
            bool SANDBOX_GAMEBOX_API isOver();
        private:
            std::unique_ptr<BowlingSet> _gameSet;
    };
}}

#endif // GAMEBOX_H
