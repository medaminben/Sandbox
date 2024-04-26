#include "Gamebox_impl.h"
#include <iostream>

namespace {
/* 
 * print
 * This function prints a message to the standard output.
 * @param message The message to be printed.
 */
void print(std::string message){
    std::cout << message << std::endl;
}
}
namespace Sandbox {
    namespace Gamebox {
        /**
         * @brief Rolls a number of pins in the bowling game.
         * This function takes an integer representing the number of pins rolled and
         * updates the game state accordingly. If the game is over, a message is
         * printed and the function returns.
         * @param pins The number of pins rolled in the current turn.
         * @throws None.
         */
        void BowlingSet::roll(const int& pins){
            // Check if the game is over
            if (isOver()) {
                // Print message if the game is over
                print("Game is over");
                return;
            }
            auto is_valide_roll = managePins(pins);
            // entry guard, not valide pins number return 
            if(!is_valide_roll) return;
            // Update the pins array with the number of pins rolled
            _rolls[_rollIndex++] = pins;
            
            // Check if the frame is not the last one
            if(_rollIndex < 18) {
                // Check if the pins rolled is a strike, if so, skip the frame
                if(pins == 10){ 
                    // If the pins rolled is a strike and the current roll index is odd, skip the next pin
                    if(_rollIndex % 2 == 1){
                        _rolls[_rollIndex++] = 0;
                    }
                }
            }
        }

       
        /**
         * @brief Calculates the total score of the bowling game.
         * 
         * This function calculates the total score of the bowling game
         * by calling the `frameScore` function for the 9th frame.
         * 
         * @return The total score of the bowling game.
         * 
         * @see BowlingSet::frameScore()
         */
        int BowlingSet::score()
        {
           return frameScore(9); 
        }

        /**
         * @brief Resets the bowling game by setting all pins to 0 and resetting the roll index.
         */
        void BowlingSet::reset(){
            for(int& pins : _rolls){ 
                pins = (int)Status::None; 
            } 
            _rollIndex = 0; 
            _pinsLeft = 10;
        }

        bool BowlingSet::managePins(const int &pins){
            if(_pinsLeft >=  pins) {
                   _pinsLeft -= pins;
            } else return false;

            if (_rollIndex % 2 == 1 
             || _pinsLeft == 0) {
                    _pinsLeft = 10;
            }
            return true;

        }

        int BowlingSet::validateRoll(const int & value)
        {
            if ((int) Status::None == value) return 0;
            return value;
        }

        int *BowlingSet::rolls() 
        {
            static int rolls[21]; 
            for(int i = 0; i< 21; i++) {
               if(i < _rollIndex)
                    if(isStrike(i)) 
                        rolls[i] = (int)Status::Strike;
                    else if(isSpare(i))
                        rolls[i] = (int)Status::Spare;
                    else
                    rolls[i] = _rolls[i];
               else 
                rolls[i] = (int) Status::None;
            }
            return rolls; 
        }

        int *BowlingSet::scores() 
        {
            static int scores[10]; 

            for(int i = 0; i< 10; i++) 
                scores[i] = (i <= (_rollIndex / 2))
                    ? frameScore(i) :(int) Status::None;

            return scores; 
        }

        int BowlingSet::pinsLeft()
        {
            return _pinsLeft;
        }

        /**
         * @brief Checks if the bowling game is over.
         *
         * This function checks if the bowling game is over by verifying if the
         * roll index is greater than or equal to 21. If it is, the function
         * returns true indicating that the game is over. If the roll index is 20,
         * the function checks if the pins in the 19th and 20th frame are at least 10,
         * if they are, it returns false indicating that the game is not over.
         * Otherwise, it returns false indicating that the game is not over.
         *
         * @return True if the bowling game is over, false otherwise.
         */
        bool BowlingSet::isOver() {
            // Check if the roll index is greater than or equal to 21
            if (_rollIndex >= 21) {
                 return  true;
            }
               
            
            // If the roll index is 20, check if the pins in the 19th and 20th frame are at least 10
            if(_rollIndex == 20){
                // Check if the sum of pins in the 19th and 20th frame is at least 10
                return ! (_rolls[18] + _rolls[19] >= 10);
                // Return false if the sum of pins is at least 10, indicating that the game is not over
            }
            // Return false indicating that the game is not over
            return false;
        }

      /**
       * @brief Checks if the frame at the given index is a strike.
       *
       * This function checks if the frame at the given index is a strike by verifying
       * if the pin count in the frame is 10. If the index is less than 19, it checks
       * if the pin count in the frame is 10 and if the index is even. If the index
       * is 19 or greater, it simply checks if the pin count is 10.
       *
       * @param index The index of the frame to check.
       *
       * @return True if the frame is a strike, false otherwise.
       */
      bool BowlingSet::isStrike(const int& index)
      {
        
          if (index < 19)
              if (index % 2 == 0)
               return _rolls[index] == 10;
              else
                return false;
          else 
            return _rolls[index] == 10;
          
      }
      /**
       * @brief Checks if the frame at the given index is a spare.
       *
       * This function checks if the frame at the given index is a spare by verifying
       * if the sum of pins in the previous and current frame is 10 and if the pin
       * count in the previous frame is not 10. If these conditions are met, the
       * function returns true indicating that the frame is a spare. Otherwise, it
       * returns false.
       *
       * @param index The index of the frame to check.
       * @return True if the frame is a spare, false otherwise.
       */
      bool BowlingSet::isSpare(const int& index)
      { 
          // Check if the index is valid and if it is an odd frame
          if(index < 20 && index % 2 == 1){
               
              // Check if the sum of pins in the previous and current frame is 10
              // and if the pin count in the previous frame is not 10
              return _rolls[index-1] + _rolls[index] == 10 
                  && _rolls[index-1] != 10;
          }
           
          // If the index is not valid or it is not an odd frame, return false
          return false;
      }
      /// @brief 
      /// @param frameIndex 
      /// @return 
      int BowlingSet::frameScore(const int& frameIndex)
      {
        if(frameIndex >= 10) return (int)Status::None;
        // convert the frame index to a limit of iteration 
        // each frame has 2 rolls but the last one (number 9) has 3.
        auto limit  = (2 * frameIndex);
        if(frameIndex == 9) {
            limit+=2;
        }else {
            if(limit >= _rollIndex) 
                return (int)Status::None;
            limit++;
        }

        int score =0;
        // Iterate over the pins array
        for(auto i=0; i<= limit; i++) {
            // Check if the frame is a strike
            if(i % 2 == 0) {
                auto roll_i = validateRoll(_rolls[i]);
                auto roll_i1 = validateRoll(_rolls[i+1]);
                // Check if the pins in the current and next frame are 10
                if(roll_i + roll_i1 == 10 ){
                    auto roll_i2 = validateRoll(_rolls[i+2]);
                    // Add the score of the frame after the strike
                    score +=  roll_i2;
                    // If the current frame is a strike and not the last frame,
                    // add the score of the frame after the next strike
                    if(roll_i== 10){
                    
                        auto roll_i3 = validateRoll(_rolls[i+3]);
                        auto roll_i4 = validateRoll(_rolls[i+4]);
                        score += (roll_i2 == 10 
                                    && i != 18) //not the last frame
                                    ? roll_i4 : roll_i3;
                    }
                }
            }
            // Add the score of the current frame to the total score
            score += validateRoll(_rolls[i]);
        }
        return score;
      }
    }
}