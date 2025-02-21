#include "Destination.h"

void Destination::printPosition()  //prints destination position
{
    cout << "Position: " << position << endl;
}

void Destination::printDestinationName()  //prints destination name
{
    cout << "Destination: " << name << endl;
}

int Destination::returnPosition()    //returns the value of the destination's position
{
    return this->position;
}

void Destination::setPosition(int position)     //set destination position to parameter
{
    this->position = position;
}

void Destination::setDestinationName(string name)      //set destination name to parameter
{
    this->name = name;
}

void printArray(double array[], const string josephusType)     //prints duration array to console
{
    double sum = 0;

    for (int i = 0; i < TOTAL_DESTINATIONS; i++)
    {
        sum += array[i];
        cout << array[i] << " ";
    }

    cout << "\nAverage CPU time duration for " << josephusType << " in seconds: " << sum / TOTAL_DESTINATIONS << "\n" << endl;
}

void printArrayToLog(double array[], const string josephusType)    //prints duration array to results.log and its average
{
    double sum = 0;
    ofstream outputStream("results.log", std::fstream::app);

    for (int i = 0; i < TOTAL_DESTINATIONS; i++)
    {
        sum += array[i];
        outputStream << array[i] << " ";
    }

    outputStream << "\nAverage CPU time duration for " << josephusType << " in seconds: " << sum / TOTAL_DESTINATIONS << "\n" << endl;

    outputStream.close();
}