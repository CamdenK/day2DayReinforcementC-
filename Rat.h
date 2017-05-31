// Rat.h
// author: camdenko
// camdenko@gmail.com
// Description: rat object

#ifndef DAY2DAYREINFORCEMENTC_RAT_H
#define DAY2DAYREINFORCEMENTC_RAT_H

#endif //DAY2DAYREINFORCEMENTC_RAT_H

#include <cstddef>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Rat{
private:
    size_t experimentLength;
    int openDay;
    std::vector <int> openTimes;
    std::string condition;

    void setOpenDay();
public:
    //default ctor
    Rat();

    //constructor with condition
    Rat(std::string condition);

    //constructor with all fields. string must be delimted by commas for openTimes
    Rat(size_t expLength, std::string cond, std::string time);

    //returns whether or not the rat is an opener
    bool isOpener() const;

    //get number of consecutive openings
    size_t consecutiveOpenings();

    //sets the experiment length
    void setExperimentLength(size_t newLength);

    //get number of openings
    size_t numOpenings();

    //set the openTimes from a comma delimited string
    void setOpenTimesFromString(std::string in);

    //set openTimes from a vector of ints
    void setOpenTimesFromVect(std::vector<int> in);

    //sets the condition for the rat
    void setCondition(string cond);

    //gets the condition for the rat
    string getCondition(){return condition;};

    //copy ctor
    Rat(const Rat &rhs);
};