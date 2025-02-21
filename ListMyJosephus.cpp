#include "ListMyJosephus.h"

void ListMyJosephus::insertDestination(Destination toInsert)    //inserts new destination to ListMyJosephus list
{
    this->josephusList.push_back(toInsert);
}

void ListMyJosephus::clear()    //empties the list
{
    this->josephusList.clear();
}

int ListMyJosephus::currentSize()     //returns total number of destinations
{
    return this->josephusList.size();
}

bool ListMyJosephus::isEmpty()    //checks if list is empty and returns result
{
    bool result = (this->josephusList.empty()) ? true : false;
    return result;
}

void ListMyJosephus::printAllDestinations()       //prints destinations sorted by position
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        for (auto i = this->josephusList.begin(); i != this->josephusList.end(); i++)
        {
            cout << *i;

            if (i != --this->josephusList.end())
            {
                cout << " - ";
            }
        }
    }
}

void ListMyJosephus::eliminateDestination()      //removes a destination based on the rules
{
    if (josephusList.size() == 1)
    {
        cout << "Last Destination - " << josephusList.front() << endl;      //print out last destination if list is size 1
        return;
    }

    int moveCount = 0;
    static int currentVectorPosition = 0;
    auto i = this->josephusList.begin();

    for (int j = 0; j < currentVectorPosition; j++)
    {
        i++;        //traverse to currentVectorPosition in list
    }

    while (moveCount != this->M)
    {
        if (i == --josephusList.end() && moveCount != this->M - 1)
        {
            i = josephusList.begin();
        }
        else
        {
            i++;
        }

        moveCount++;
        currentVectorPosition++;

        if (currentVectorPosition == (int)josephusList.size())
        {
            currentVectorPosition = 0;
            i = josephusList.begin();
        }
        
    }

    cout << "To remove - " << *i << endl;

    if (currentVectorPosition == (int)josephusList.size() - 1)        //change currentVectorPosition to start at first element 
    {
        currentVectorPosition = 0;
    }

    josephusList.erase(i);

    cout << "\n";
    this->printAllDestinations();
    cout << "\n";

    this->eliminateDestination();
}

void loadDestinationsToList(ifstream &infile, ListMyJosephus &insertInto, int n)     //inserts n amount of destinations from an infile to a list
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
            insertInto.insertDestination(tempDestination);  //add temp destination to list

            token = strtok(NULL, ";");     
            n--;
        }
    }
}