#include <iostream>
#include <fstream>
#include "Rat.h"
std::string getFileName();

int main() {
    string fileName = getFileName();
    ifstream input;
    string numIterations;

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


