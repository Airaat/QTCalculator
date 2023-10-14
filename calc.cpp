#include "calc.h"

calc::calc()
{

}

void calc::setPlus()
{
    addTrigger = true;
    subTrigger = false;
    mulTrigger = false;
    divTrigger = false;
    expTrigger = false;
}

void calc::setMinus()
{
    addTrigger = false;
    subTrigger = true;
    mulTrigger = false;
    divTrigger = false;
    expTrigger = false;
}

void calc::setMult()
{
    addTrigger = false;
    subTrigger = false;
    mulTrigger = true;
    divTrigger = false;
    expTrigger = false;
}

void calc::setDivide()
{
    addTrigger = false;
    subTrigger = false;
    mulTrigger = false;
    divTrigger = true;
    expTrigger = false;
}

void calc::setExp()
{
    addTrigger = false;
    subTrigger = false;
    mulTrigger = false;
    divTrigger = false;
    expTrigger = true;
}

