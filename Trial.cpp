//
// Created by masonlab on 5/31/2017.
//

#include "Trial.h"
Trial::Trial():numRats(16),experimentLength(12),condition("") {

}

Trial::Trial(size_t length, string input):experimentLength(length),condition(""){
    setRats(input);
}

size_t Trial::totalConsecutiveOpenings() {
    size_t out = 0;
    for(size_t index = 0; index < rats.size();index++)
    {
        out += rats[index]->consecutiveOpenings();
    }
    return out;
}

size_t Trial::totalOpenings() {
    size_t out = 0;
    for(size_t index = 0; index < rats.size(); index++)
    {
        out += rats[index]->numOpenings();
    }
    return out;
}

size_t Trial::numOpeners() {
    size_t out = 0;
    for(size_t index = 0; index < rats.size(); index++)
    {

        if(rats[index]->isOpener())
        {
            out++;
        }
    }
    return out;
}

void Trial::setCondition(string cond) {
    condition = cond;
    for(size_t index =0; index < rats.size(); index++)
    {
        rats[index]->setCondition(cond);
    }
}

void Trial::setRats(string input) {
    string temp;
    std::istringstream inputStream(input);
    while(getline(inputStream,temp))
    {
        rats.push_back(new Rat(experimentLength,condition,temp));
    }
    numRats = rats.size();
}

Trial::Trial(const Trial&rhs): numRats(rhs.numRats),experimentLength(rhs.experimentLength),
                                condition(rhs.condition)
{
    for(size_t index =0 ; index < rhs.numRats;index++)
    {
        rats.push_back(new Rat(*rhs.rats[index]));
    }
}

Trial::~Trial() {
    for(size_t index = 0; index < rats.size(); index++)
    {
        delete rats[index];
    }
}

