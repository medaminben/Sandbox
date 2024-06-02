#pragma once
/**
 * @brief the State interface
 * 
 */
class IState {
public: 
    virtual ~IState(){};

    virtual void enter()  =0;
    virtual void update() =0;
    virtual void leave()  =0;

    static IState * currentState;
    static IState * mainState, * optionalState;
};

/**
 * @brief an implementation of the State interface IState
 * 
 */
class MainState : public IState {  
public:
    virtual void enter() ;
    virtual void update();
    virtual void leave() ;
};

/**
 * @brief an implementation of the State interface IState
 * 
 */
class OptionalState : public IState { 
public:
    virtual void enter() ;
    virtual void update();
    virtual void leave() ;
};

