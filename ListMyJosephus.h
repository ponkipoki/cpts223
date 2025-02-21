#include "Destination.h"

class ListMyJosephus
{
    public:
        ListMyJosephus(int m, int n):M{m}, N{n} {}      //constructor
        ~ListMyJosephus()     //destructor
        {

        }

        void insertDestination(Destination toInsert);

        void clear();    //empties the list
        int currentSize();      //returns total number of destinations
        bool isEmpty();     //checks if list is empty and returns result
        void eliminateDestination();      //removes a destination based on the rules
        void printAllDestinations();        //prints destinations sorted by position

    private:
        int M;  //elimination interval
        int N;  //total initial destinations
        list<Destination> josephusList;
};

void loadDestinationsToList(ifstream &infile, ListMyJosephus &insertInto, int n);     //inserts n amount of destinations from an infile to a list