#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Rat.h"
#include "Trial.h"

std::string getFileName();
Trial readInput(Trial orig, std::ifstream file);

//for each iteration returns a double of probability of sequential opening
double iteration(vector<double> dayDifference, vector<double> ratDifference, Trial run);

int main() {
    string fileName = getFileName();
    ifstream input;
    size_t numIterations;

    cout<<"How many iterations?";
    cin>>numIterations;
    Trial run;
    run = readInput(run,input);

    vector<double> dayDifference;
    vector<double> ratDifference;
    vector<double> iterationProbability;

    for(size_t index = 0; index < run.getExperimentLength();index++)
    {
        dayDifference.push_back(double(run.numOpensInDay(index))/ run.totalNumOpenings());
    }
    for(size_t rat = 0; rat < run.getNumRats();rat++)
    {
        ratDifference.push_back(double(run.totalOpensByOneRat(rat))/ run.totalNumOpenings());
    }

    for(size_t iter = 0; iter < numIterations; iter++)
    {
        iterationProbability.push_back(iteration(dayDifference,ratDifference,run));
    }
}

std::string getFileName()
{
    ifstream input;
    string fileName;
    cout<<"Enter file name:";
    cin>>fileName;
    input.open(fileName.c_str());
    if(input.fail())
    {
        cout<<"File could not be found";
        return getFileName();
    }

    return fileName;
}

Trial readInput(Trial orig, std::ifstream file)
{
    string line;
    while(file>>line)
    {
        orig.addRat(line);
    }
    return orig;
}

double iteration(vector<double> dayDifference, vector<double> ratDifference, Trial run)
{
    size_t numOpens = 0;
    size_t sequetialOpens = 0;
    vector<int> randomRat;

    for(size_t rat = 0; rat < ratDifference.size(); rat++)
    {
        for(size_t day = 0; day < dayDifference.size(); day++)
        {
            if((double)rand() / RAND_MAX >= dayDifference[day] * ratDifference[rat] * run.totalNumOpenings())
            {
                randomRat.push_back(0);
            }
            else
            {
                randomRat.push_back(1);
            }
        }

        for(size_t day = 0; day < dayDifference.size(); day++)
        {
            
        }
    }
}

