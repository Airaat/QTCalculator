#ifndef CALC_H
#define CALC_H

class calc {
public:
    calc();
//    double num_first=0;
//    double num_second=0;

    bool addTrigger = false;
    bool subTrigger = false;
    bool mulTrigger = false;
    bool divTrigger = false;
    bool expTrigger = false;

    void setPlus();
    void setMinus();
    void setMult();
    void setDivide();
    void setExp();

//    double Equal();
};

#endif // CALC_H
