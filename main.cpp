#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Rat.h"
#include "Trial.h"

std::string getFileName();
Trial readInput(Trial orig, std::ifstream file);

//for each iteration returns a double of probability of sequential opening
vector<double> iteration(vector<double> dayDifference, vector<double> ratDifference, Trial run, size_t numIterations);

//calculate sequential open probability for data of 1's and 0's where 1 is open, 0 is non open
double sequentialOpeningProb(vector<int> openData);

int main() {
    string fileName = getFileName();
    ifstream input;
    size_t numIterations;

    cout<<"How many iterations?";
    cin>>numIterations;
    Trial temp;
    Trial run = readInput(temp,input);

    vector<double> dayDifference;
    vector<double> ratDifference;

    for(size_t index = 0; index < run.getExperimentLength();index++)
    {
        dayDifference.push_back(double(run.numOpensInDay(index))/ run.totalNumOpenings());
    }
    for(size_t rat = 0; rat < run.getNumRats();rat++)
    {
        ratDifference.push_back(double(run.totalOpensByOneRat(rat))/ run.totalNumOpenings());
    }

    vector<double> iterationProbability =(iteration(dayDifference,ratDifference,run,numIterations));

    double origProb = run.totalConsecutiveOpenings()/run.totalNumOpenings();
    double averageItProb = accumulate(iterationProbability.begin(), iterationProbability.end(), 0.0) / iterationProbability.size();

    cout<<"Probability of sequential opening for original data: " << origProb <<endl;
    cout<<"Probability of sequential opening based off of simulation: " << averageItProb << endl;

    //calculate extreme values
    size_t numExtreme = 0;
    for(size_t iter = 0; iter < numIterations; iter++)
    {
        if(abs(iterationProbability[iter] - averageItProb) >= abs(origProb - averageItProb))
        {
            numExtreme++;
        }
    }

    cout<<"P - value:"<<(double) numExtreme / numIterations<<endl;
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

vector<double> iteration(vector<double> dayDifference, vector<double> ratDifference, Trial run,size_t numIterations)
{
    vector<int> randomRat;
    vector<double> out;

    for(size_t iter = 0; iter < numIterations; iter++) {
        for (size_t rat = 0; rat < ratDifference.size(); rat++) {
            randomRat.clear();
            for (size_t day = 0; day < dayDifference.size(); day++) {
                if ((double) rand() / RAND_MAX >= dayDifference[day] * ratDifference[rat] * run.totalNumOpenings()) {
                    randomRat.push_back(0);
                } else {
                    randomRat.push_back(1);
                }
            }
            out.push_back(sequentialOpeningProb(randomRat));
        }
    }

    return out;
}

double sequentialOpeningProb(vector<int> openData)
{
    size_t numOpens = 0;
    size_t sequentialOpens = 0;
    for(size_t day = 0; day < openData.size()-1; day++)
    {
        if(openData[day] == 1)
        {
            numOpens++;
            if(openData[day +1] == 1)
            {
                sequentialOpens++;
            }
        }
    }
    if(openData[openData.size()-1] == 1)
    {
        numOpens++;
    }
    return (double)numOpens/sequentialOpens;
}