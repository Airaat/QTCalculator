#ifndef CALC_H
#define CALC_H

class calc {
public:
    calc();

    bool addTrigger = false;
    bool subTrigger = false;
    bool mulTrigger = false;
    bool divTrigger = false;
    bool expTrigger = false;

    void setDefault();
    void setPlus();
    void setMinus();
    void setMult();
    void setDivide();
    void setExp();
};

#endif // CALC_H
