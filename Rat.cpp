// Rat.cpp
// author: camdenko
// camdenko@gmail.com
// Description: rat object

#include "Rat.h"

//default ctor
Rat::Rat(): experimentLength(40), openDay(0), condition("control")
{

}

//ctor with condition
Rat::Rat(std::string in): experimentLength(40), openDay(0), condition(in)
{

}

//ctor with all fields
Rat::Rat(size_t expLength, std::string cond, std::string time): experimentLength(expLength),condition(cond)
{
    setOpenTimesFromString(time);
}

bool Rat::isOpener() const {
    if(openDay == 0)
    {
        return false;
    }
    return true;
}

size_t Rat::consecutiveOpenings()  {
    size_t num = 0;
    for(std::vector<int>::iterator it = openTimes.begin(); it +1 != openTimes.end(); it++)
    {
        if(*it != experimentLength)
        {
            if(*(it+1) != experimentLength)
            {
                num++;
            }
        }
    }

    return num;
}

void Rat::setExperimentLength(size_t newLength) {
    experimentLength = newLength;
}

size_t Rat::numOpenings() {
    size_t num = 0;
    for(std::vector<int>::iterator it = openTimes.begin(); it != openTimes.end(); it++)
    {
        if(*it != experimentLength)
        {
            num++;
        }
    }
    return num;
}

void Rat::setOpenTimesFromString(std::string in) {
    std::replace(in.begin(),in.end(),',',' ');
    std::stringstream inStream(in);
    int i;

    while(inStream >> i)
    {
        openTimes.push_back(i);
    }
    setOpenDay();
}

void Rat::setOpenTimesFromVect(std::vector<int> in) {
    for(size_t index = 0; index < in.size();index++)
    {
        openTimes.push_back(in[index]);
    }
    setOpenDay();
}

void Rat::setOpenDay() {
    for(size_t index = 0; index < openTimes.size() -2; index++)
    {
        if(openTimes[index] != experimentLength)
        {
            if(openTimes[index+1] != experimentLength)
            {
                if(openTimes[index+2] != experimentLength)
                {
                    openDay = index +1;
                    break;
                }
            }
        }
    }
}

void Rat::setCondition(string cond) {
    condition = cond;
}

Rat::Rat(const Rat &rhs):experimentLength(rhs.experimentLength),openDay(rhs.openDay),condition(rhs.condition) {
    for(size_t index = 0; index < rhs.openTimes.size();index++)
    {
        openTimes.push_back(rhs.openTimes[index]);
    }
}