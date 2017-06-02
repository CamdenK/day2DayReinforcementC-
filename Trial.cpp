//
// Created by masonlab on 5/31/2017.
//

#include "Trial.h"
Trial::Trial():numRats(0),experimentLength(12),condition("") {

}

Trial::Trial(size_t length, string input):experimentLength(length),condition(""){
    setRats(input);
}

size_t Trial::totalConsecutiveOpenings() {
    size_t out = 0;
    for(size_t index = 0; index < rats.size();index++)
    {
        out += rats[index]->numConsecutiveOpenings();
    }
    return out;
}

size_t Trial::totalNumOpenings() {
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

size_t Trial::getNumRats() {
    return numRats;
}

void Trial::addRat(string data){
    rats.push_back(new Rat(experimentLength,condition,data));
    numRats = rats.size();
}

size_t Trial::getExperimentLength() {
    return experimentLength;
}

size_t Trial::numOpensInDay(size_t day) {
    size_t out = 0;
    for(size_t rat = 0; rat < numRats;rat++)
    {
        if(rats[rat]->opensOnDate(day))
        {
            out++;
        }
    }
    return out;
}

size_t Trial::totalOpensByOneRat(size_t rat) {
    return rats[rat]->numOpenings();
}

vector<size_t> Trial::getOpenerDates(){
    vector<size_t> out;
    for(size_t rat = 0; rat<numRats; rat++)
    {
        out.push_back(rats[rat]->getOpenDay());
    }
    return out;
}

Rat Trial::getRat(size_t ratNum) {
    return *rats[ratNum];
}