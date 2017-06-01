// Rat.h
// author: camdenko
// camdenko@gmail.com
// Description: rat object

#ifndef DAY2DAYREINFORCEMENTC_RAT_H
#define DAY2DAYREINFORCEMENTC_RAT_H

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

    //copy ctor
    Rat(const Rat &rhs);

    //accessors:
    //gets the condition for the rat
    string getCondition(){return condition;};

    //gets openDay
    int getOpenDay(){return openDay;};

    //get openTimes
    vector<int> getOpenTimes(){return openTimes;};

    //mutators:
    //sets the experiment length
    void setExperimentLength(size_t newLength);

    //set the openTimes from a comma delimited string
    void setOpenTimes(std::string in);

    //set openTimes from a vector of ints
    void setOpenTimes(std::vector<int> in);

    //sets the condition for the rat
    void setCondition(string cond);



    //returns whether or not the rat is an opener
    bool isOpener() const;

    //get number of consecutive openings
    size_t numConsecutiveOpenings();

    //get number of openings
    size_t numOpenings();

    //returns if rat opens on specific day of trial
    bool opensOnDate(size_t day);
};

#endif