#include "bowlingScreen.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
namespace dbg {
    auto print(std::string message) -> void {std::cout << message <<"\n";}
}
namespace {
    /// @brief  convert int to a 3 chars string 
    /// @param i int to convert, pins number or score
    /// @return 
    std::string toConsole(const int& i){
        //convert to string
        auto i_str = std::to_string(i);
        // format to 3 chars string
        switch (i_str.length())
        {
            // one digit number
            case 1:  return " " + i_str + " "; 
            case 2:  return " " + i_str; 
            default: return       i_str;
        }
    }
    /// @brief convert value to string for console
    /// @param value eather pins number, bonus case or score. 
    /// the game states are tolerates as negative numbers see
    /// @enum Gamebox::Bowlingbox::Bonus
    /// @return a 3 chars string of the value 
    std::string valueToConsole(const int& value){
        // the highest number is equal to the
        // maximum score that can be achieved
        // which is 300, so any higher number
        // is wrong input
        if(value / 1000 > 1) return "   ";
        // extract corner caeses: game states
        switch (value)
        {
        case -3: // not set
            return "   ";
        case -2: // strike
            return " X " ;
        case -1: // spare
            return " / ";        
        default:// numbers call toConsole
            return toConsole(value);
        }
    }
    std::string generateBar(const int& length, const std::string& stone, bool with_return = true) {
        std::string bar = "";
        for (int i = 0; i < length-1; i++)
                bar += stone;
        if (with_return)
            return bar + "\n";
        return bar;
    }
    std::string formatTitle(const int& length, const std::string& title) {
        std::string space = " ",new_line = "\n" ,colomn = "|";

        int space_length =  (length - title.length() -1) / 2;
        std::string spacer = generateBar(space_length,space,false);
        return  spacer + title + spacer + new_line;
    }
    std::string giveAbout(std::string author_name){
        std::string about = "=About=\n Made by: "; 
        return about + author_name + "\n";
    }
    
    /// @brief check if string contains only digits
    /// @param str the string
    /// @return true if the string contains only digits
    bool isNumber(const std::string& str) {
        // fast return if empty
        if(str.empty()) return false;
        // check if all digits
        return std::find_if( 
            str.begin(), str.end(), [](unsigned char c) {
                                return !std::isdigit(c);} ) == str.end();
    }
}

////////////////////////////////////////////////////////////////
// Screen class implementation
////////////////////////////////////////////////////////////////
Console::Screen::Screen(std::shared_ptr<Bowlingbox> g) { 
    game   = g;
    //frames = std::vector<Frame>(10);
    for(auto i = 0; i < 9; i++) {
        frames.push_back(Frame());
    }
    frames.push_back(Frame(Frame::Type::Last));
}

bool Console::Screen::clearScreen()
{
#ifdef _WIN32
     // Clear the console screen
    system("cls"); // For Windows
#elif 
     // Clear the console screen
    system("clear"); // For Linux/Mac
#endif// WIN32
    return true;
}

int Console::Screen::getConsoleWidth(){
#ifdef WIN32
    // Get the width of the console screen
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_col;
#endif // WIN32
}

void Console::Screen::updateGrid() {
    auto rolls  = game->rolls();
    auto scores = game->scores();

    int first,second,score,last =(int)Frame::Bonus::None;

    for (auto frame_index = 0; 
              frame_index < 10; frame_index+=1) {
        first   = rolls[2*frame_index];
        second  = rolls[2*frame_index + 1];
        score   = scores[frame_index];
        if(frame_index == 9) 
             last    = rolls[2*frame_index + 2];

        frames[frame_index].setFrame(score, 
                         first, second, last);  
    }
}

void Console::Screen::plotIntro(){
   if(clearScreen()){
        std::string hash_stone = "#",
                    wave_stone = "~",
                    spacer     = " ", 
                    new_line   = "\n";

        int width = Screen::getConsoleWidth();
        
        std::string title = formatTitle(width, 
                    "Execution of BowlingGame from Gamebox Library");

        std::string introduction = 
            "This console game is an interface to the bowling game implemented under the Gamebox library.";
        
        std::string about = giveAbout("github.com/medaminben");

        // create a bars
        std::string hash_bar = generateBar(width, hash_stone);
        std::string wave_bar = generateBar(width, wave_stone);
        // bundle all together in a banner
        std::string banner = 
            hash_bar + title + hash_bar + introduction 
            + new_line + about + wave_bar + new_line;
        // print the banner
        std::cout << banner;
    }
}

void Console::Screen::plotGrid() {
    //refresh data
    updateGrid() ;
    auto spacer     =  " "; 
    //first we need to know the width of the screen
    int width       = getConsoleWidth();
    //then we need to know the number of frames to be plotted
    int frameSize   = frames.size();
    int frameHeight = frames[0].getFrame().size();
    //fix the index of the last frame just for readability proposal
    int lastIndex   = frameSize - 1;
    // then we need to know the width of each frame
    int last_width  = frames[lastIndex].getFrame()[0].length();
    int unit_width  = frames[0].getFrame()[0].length() + 1; // plus 1 for the spacer;

    //then we need to know the number of regular units can be plotted 
    // in the screen at the same line other than the last frame.
    int regular_width = width - last_width + 1;
    // here we add 1 for the last frame
    int units         = ((regular_width+2)  / (unit_width+1)) + 1; 

    //find the best unit width
    if(units < frameSize){ // else all the frames in one row
        if(units >= 5) // 5 frames can be plotted in one row
           units = 5;  // 5 frames is a good choice in that way we 2 similar rows in the screen
        else // if the screen is smaller than 5 frames 2 frames can be plotted in one row
            if(units >= 2) 
                 units = 2; // 2 frames is a good choice in that way we 5 similar rows in the screen
            else units = 1; // the minimum number of frames can be plotted in one row
                            // else an exception should be thrown, something wrong 
    }

    // findout if an extra row is needed
    int rest        = (frameSize % units == 0) ? 0 : 1;
    // a stack is a alligned group of frames in the screen
    int rows         =  (frameSize / units) + rest;
    // plot the frames    
    int frameIndex  = 0; // frame index
    ///load the frames to the rows
    for(auto i = 0; i < rows; i++) { 
        //check the remaining to avoid the overflow
        auto remain = frameSize - (i * units);
        int  stop   = (remain < units) ? remain : units;
        if(stop <= 0) return;
        // the row is constituted by the frames external vector size.
        //(frames are vector of vector of strings)
        auto lines  = std::vector<std::string>(frameHeight);
        //initialize the lines
        for(auto& line : lines) 
                line    = std::string("");
        //load the frames line by line,       
        for(auto  j = 0; j < stop; j++) {
             for(auto k = 0; k < frameHeight; k++) 
                lines[k] += spacer + frames[frameIndex].getFrame()[k];
            //increase the index to move to the next frame
            frameIndex++;
        }   
       // print the row in the screen line by line 
        for(auto line : lines) {
            std::cout << line << "\n";
        }     
    }   
}
void Console::Screen::start(){
    while(status != Status::Quit) {
        // output
        plotIntro();

        plotGrid();

        plotMenu();
        // input
        std::string choice{};
        std::getline(std::cin, choice);
        evaluate(choice); 
        
        if(isExit() || isRunning()) continue;
        dbg::print("Enter any key to continue...\n");
        std::getline(std::cin, choice);
        // if q close the program
    }
}
void Console::Screen::resetGame()
{
    for (auto& frame : frames) 
        frame.resetFrame();
    game->reset();
}
void Console::Screen::evaluate(const std::string& choice)
{
    auto message     = std::string();   
    auto maxPins     = game->pinsLeft();
    auto beforeStart = isTryStart();
    auto running     = isRunning() || isTypo();
    auto play        = beforeStart ? "p" :"r";
 

    auto messageBeforeStart ="Invalid starting choice: " + choice 
                                + "\nPlease select a letter (q to exit or "+ play +" to play) to continue\n";
   
    auto messageRollingError = "Invalid rolling choice: " + choice  
                                + "\nPlease select a number between 0 and" + std::to_string(maxPins) + "\n";

    auto messageAfterStartError = messageRollingError + ", or a letter (q to exit or "+ play +" to play\n";

    if(isFirstStart()) return; // error evaluate should not be called if is first start but try start

    if(choice == "q") {
        status = Status::Quit;
        return;    
    } else 
    if(choice == play) {
        if(running)
            resetGame();
        dbg::print("reset");
        status = Status::Running;
        return;
    }

    if(!beforeStart){
        if (isNumber(choice) ) {
            int pins = std::stoi(choice);
            if(pins >= 0 && pins <= maxPins) {
                game->roll(pins);
                status  = Status::Running;
                return;
            } else {
                message = messageRollingError;
                status  = Status::Typo;
            }
        } else {
                message = messageAfterStartError;
                status  = Status::Typo;
            }
    } else {
        message = messageBeforeStart;
        status  = Status::TryStart;
    }
    dbg::print(message);
}
void Console::Screen::plotMenu(){
    std::string spacer = " ";
    std::string message= "";
    auto gameOver = game->isOver();
    
    if(gameOver) {
        status  = Status::End;
        message = "Game Over!\n You have scored: "
                + std::to_string(game->get_score()) +"\n";
    }
    if(isRunning()){
         message = "You have scored: "
                + std::to_string(game->get_score()) +"\n";
    }

    auto no_play = isEndGame() || isFirstStart();
    auto beforeStart = no_play || isTryStart();
    
    // add static choices
    std::vector<std::string> choices = {"q - quit"};
    // add the dynamic choices
    choices.push_back(beforeStart ? "p - play" : "r - restart");
    
    // start the select menu
    message += "Select a choice:\n";
    // append the choices
    for(auto choice: choices) { 
        message += spacer + choice;
    }
    if(!beforeStart) {
        message += spacer + "or enter a number between 0 and " 
                           + std::to_string(game->pinsLeft());
    }
    dbg::print(message);
    if(isFirstStart())
        status = Status::TryStart;
}

bool Console::Screen::isEndGame()
{
    return Status::End == status;
}
bool Console::Screen::isExit() {
    return Status::Quit == status;
}

bool Console::Screen::isRunning()
{
    return Status::Running == status;
}

bool Console::Screen::isTryStart()
{
    return Status::TryStart == status;
}

bool Console::Screen::isFirstStart()
{
    return Status::FristStart == status;
}

bool Console::Screen::isTypo()
{
    return Status::Typo == status;
}

////////////////////////////////////////////////////////////////
// Frame struct implementation
////////////////////////////////////////////////////////////////
Console::Frame::Frame(Type t): type(t) {
    _frame = std::vector<std::string>(5, "   ");
    resetFrame();
}

void Console::Frame::setRoll(const Order& position, const int& value) {
    std::string value_str = valueToConsole(value);
    switch (position)
    {
        case Order::First:  _firstRoll  = value_str; break;
        case Order::Second: _secondRoll = value_str; break;
        case Order::Last:   _lastRoll   = value_str; break;
    }
    updateRolls();
}

void Console::Frame::setScore(const int & score) {
    _framescore = valueToConsole(score);
    updateScore();
}

 std::vector<std::string> Console::Frame::getFrame() const {
    return _frame;
}

void Console::Frame::updateRolls() {
    std::string leftEdge   =  "| ", 
                rightEdge  = " |", 
                middleEdge = " | ";
    // reset the frame line with fiest roll first
    _frame[1] = leftEdge + _firstRoll;
    // prepare the right side of the frame by the second roll
    auto rightSide  = middleEdge + _secondRoll;
    // evaluate if it is the last frame then support a 3rd roll
    if(type == Type::Last)
         rightSide += middleEdge + _lastRoll;
    //append the right side and the edge to the frame line
    _frame[1] +=  rightSide + rightEdge;
}

void Console::Frame::updateScore() {
    std::string leftedge  = "|    ", 
                rightedge = "    |";

    if(type == Type::Last) { 
        //inlarge the edges for the last frame 
        leftedge += "   " ; 
        rightedge = "   " + rightedge;
    }

    _frame[3] = leftedge + _framescore + rightedge;
}

void Console::Frame::resetFrame() {
    _firstRoll  ="   ";
    _secondRoll ="   ";
    _lastRoll   ="   ";
    _framescore ="   ";
    switch (type)
    {
    case Type::Regular: {
        //regular frame
        _frame[0]     = ".-----------.";
        _frame[1]     = "|     |     |";
        _frame[2]     = "|     '-----|";
        _frame[3]     = "|           |";
        _frame[4]     = "'-----------'";
    }
        break;
    case Type::Last: {
        //last frame
        _frame[0] = ".-----------------.";
        _frame[1] = "|     |     |     |";
        _frame[2] = "|     '-----'-----|";
        _frame[3] = "|                 |";
        _frame[4] = "'-----------------'";
    }
        break;
    }
}

void Console::Frame::setFrame(const int& frame_score,
                              const int& first_roll, 
                              const int& second_roll, 
                              const int& last_roll){
    setRoll(Order::First, first_roll);
    setRoll(Order::Second, second_roll);
    setRoll(Order::Last, last_roll);
    setScore(frame_score);
}







