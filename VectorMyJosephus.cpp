#include "VectorMyJosephus.h"

void VectorMyJosephus::insertDestination(Destination toInsert)    //inserts new destination to VectorMyJosephus vector
{
    this->josephusVector.push_back(toInsert);
}

void VectorMyJosephus::clear()    //empties the vector
{
    this->josephusVector.clear();
}

int VectorMyJosephus::currentSize()     //returns total number of destinations
{
    return this->josephusVector.size();
}

bool VectorMyJosephus::isEmpty()    //checks if vector is empty and returns result
{
    bool result = (this->josephusVector.empty()) ? true : false;
    return result;
}

void VectorMyJosephus::printAllDestinations()       //prints destinations sorted by position
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        for (int i = 0; i < (int)this->josephusVector.size(); i++)
        {
            cout << josephusVector[i];
            
            if (i != (int)this->josephusVector.size() - 1)
            {
                cout << " - ";
            }
        }
    }
}

void VectorMyJosephus::eliminateDestination()      //removes a destination based on the rules
{
    if (josephusVector.size() == 1)
    {
        cout << "Last Destination - " << josephusVector.front() << endl;      //print out last destination if vector is size 1
        return;
    }

    int moveCount = 0;
    static int currentVectorPosition = 0;
    int vectorPositionToDelete = 0;
    Destination i = this->josephusVector[currentVectorPosition];
    Destination end = this->josephusVector[josephusVector.size() - 1];

    while (moveCount != this->M)
    {
        if (i.returnPosition() == end.returnPosition() && moveCount != this->M - 1)
        {
            i = josephusVector[0];
        }
        else
        {
            i = josephusVector[currentVectorPosition + 1];
        }

        moveCount++;
        currentVectorPosition++;

        if (currentVectorPosition == (int)josephusVector.size())
        {
            currentVectorPosition = 0;
            i = josephusVector[currentVectorPosition];
        }
        
    }

    cout << "To remove - " << i << endl;
    vectorPositionToDelete = currentVectorPosition;
    if (currentVectorPosition == (int)josephusVector.size() - 1)        //change currentVectorPosition to start at first element 
    {
        currentVectorPosition = 0;
    }

    josephusVector.erase(josephusVector.begin() + (vectorPositionToDelete));

    cout << "\n";
    this->printAllDestinations();
    cout << "\n";

    this->eliminateDestination();
}

void loadDestinationsToVector(ifstream &infile, VectorMyJosephus &insertInto, int n)     //inserts n amount of destinations from an infile to a vector
{
    int destinationCount = 0;
    string fileRead;		//stores data read from file

    if (infile.is_open())
    {       
        getline(infile, fileRead);    //read line from file and store to fileRead
        char fileReadChar[fileRead.length()] = {'\0'};
        strcpy(fileReadChar, fileRead.c_str());         //make string into char *

        char* token = strtok(fileReadChar, ";");
    
        while (n != 0)
        {   
            destinationCount++;
            Destination tempDestination(0, "");      //stores destination data read from infile
            
            tempDestination.setDestinationName(token);
            tempDestination.setPosition(destinationCount);  //set data into temp destination class
            insertInto.insertDestination(tempDestination);  //add temp destination to vector

            token = strtok(NULL, ";");     
            n--;
        }
    }
}