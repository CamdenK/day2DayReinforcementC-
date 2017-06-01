//
// Created by masonlab on 5/31/2017.
//

#include <array>

#ifndef DAY2DAYREINFORCEMENTC_TRIAL_H
#define DAY2DAYREINFORCEMENTC_TRIAL_H

#endif //DAY2DAYREINFORCEMENTC_TRIAL_H
#include <cstddef>
#include <iostream>
#include<string>
#include <sstream>
#include "Rat.h"

using namespace std;

class Trial{
private:
    size_t numRats;
    size_t experimentLength;
    std::vector<Rat*> rats;
    string condition;
public:
    //default ctor
    Trial();

    //ctor with string of input of comma delimted values
    Trial(size_t length, string input);

    //copy ctor
    Trial(const Trial&rhs);

    //default dtor
    ~Trial();

    //assignment operator
    const Trial& operator = (const Trial& rhs);

    //ACCESSORS:
    //gets numRats
    size_t getNumRats();

    //gets experimentLength
    size_t getExperimentLength();

    //gets condition
    string getCondition(){return condition;};

    //gets vector of rats
    vector<Rat*> getRats(){return rats;};

    //MUTATORS:
    //sets rats with comma delimited information
    void setRats(string input);

    //add a rat
    void addRat(string data);

    //sets condition of trial and changes condition for all rats
    void setCondition(string cond);

    //sets the experimentLength
    void setExperimentLength(size_t length){experimentLength = length;};

    //OTHER:
    //gets the total number of consecutive openings for all rats
    size_t totalConsecutiveOpenings();

    //gets the total number of openings for all rats
    size_t totalNumOpenings();

    //gets number of openers for rats
    size_t numOpeners();

    //returns number of openings in one day
    size_t numOpensInDay(size_t day);

    //returns number of times one rat opens
    size_t totalOpensByOneRat(size_t rat);
};