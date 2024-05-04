// #include <myproject/xyz/header.h>
// Include local private headers using quotes and path relative to the
// current file
#include "Gamebox_impl.h"
// Include public headers of the current or other target within this
// project with path relative to the "include" directory
#include <Sandbox/Gamebox/Gamebox.h>

// Include 3rd party headers with brackets
// #include <xyz>

// Include standard headers with brackets
#include <iostream>


namespace Sandbox {

    namespace Gamebox {



        /**
         * @brief Constructs a new Bowlingbox instance.
         *
         * This constructor initializes a unique pointer to a BowlingSet object,
         * which is used to store the game states.
         */
        Bowlingbox::Bowlingbox() {
            // Initialize a unique pointer to a BowlingSet object
            _gameSet = std::make_unique<BowlingSet>();
        }

        Bowlingbox::~Bowlingbox(){
        }

        /**
         * @brief Rolls a number of pins in the bowling game.
         *
         * This function takes an integer representing the number of pins rolled and 
         * passes it to the BowlingSet object to update the game state.
         *
         * @param pins The number of pins rolled in the current turn.
         */
        void Bowlingbox::roll(const int& pins){
            // Pass the number of pins rolled to the BowlingSet object to update the game state
            _gameSet->roll(pins);
        }

        /**
         * @brief Retrieves the current score of the bowling game.
         *
         * This function calls the `score()` method of the `BowlingSet` object,
         * which returns the current score of the game.
         *
         * @return The current score of the bowling game.
         */
        int Bowlingbox::score(){
            // Call the `score()` method of the `BowlingSet` object and return the result
            return _gameSet->score();
        }
         
        int* Bowlingbox::rolls() {
            return _gameSet->rolls();
        }

        int* Bowlingbox::scores(){
            return _gameSet->scores();
        }

        int Bowlingbox::pinsLeft()
        {
            return _gameSet->pinsLeft();
        }
        int Bowlingbox::getFrameScore(const int &frameIndex)
        {
            return _gameSet->frameScore(frameIndex);
        }
        /**
         * @brief Resets the bowling game to its initial state.
         *
         * This function calls the `reset()` method of the `BowlingSet` object,
         * which resets the game state to its initial state.
         */
        void Bowlingbox::reset(){
            // Call the `reset()` method of the `BowlingSet` object to reset the game state
            _gameSet->reset();
        }
        
        bool Bowlingbox::isOver()
        {
            return _gameSet->isOver();
        }

        bool Bowlingbox::isStrike(const int & index)
        {
            return _gameSet->isStrike(index);
        }
        bool Bowlingbox::isSpare(const int & index) {
            return _gameSet->isStrike(index);        
        }
    }
}
