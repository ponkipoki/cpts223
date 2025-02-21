#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstring>
#include <list>
#include <vector>
using std::string;
using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::ifstream;
using std::ofstream;

#define TOTAL_DESTINATIONS 957

class Destination
{
    public:
        Destination(int pos, string n):position{pos}, name{n} {}    //constructor
        // ~Destination()      //destructor
        // {
        //     delete this;
        // }     

        friend ostream &operator << (ostream &os, const Destination &destination)
        {
            os << "Position: " << destination.position << ", Name: " << destination.name;
            fflush(stdout);
            return os;
        }

        void printPosition();
        void printDestinationName();
        int returnPosition();

        void setPosition(int position);
        void setDestinationName(string name);

    private:
        int position;
        string name;


};

void printArray(double array[], const string josephusType);     //prints duration array to console
void printArrayToLog(double array[], const string josephusType);  //prints duration array to results.log and its average