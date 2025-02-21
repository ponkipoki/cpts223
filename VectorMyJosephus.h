#include "Destination.h"

class VectorMyJosephus
{
    public:
        VectorMyJosephus(int m, int n):M{m}, N{n} {}      //constructor
        ~VectorMyJosephus()     //destructor
        {

        }

        void insertDestination(Destination toInsert);

        void clear();    //empties the vector
        int currentSize();      //returns total number of destinations
        bool isEmpty();     //checks if vector is empty and returns result
        void eliminateDestination();      //removes a destination based on the rules
        void printAllDestinations();        //prints destinations sorted by position

    private:
        int M;  //elimination interval
        int N;  //total initial destinations
        vector<Destination> josephusVector;
};

void loadDestinationsToVector(ifstream &infile, VectorMyJosephus &insertInto, int n);     //inserts n amount of destinations from an infile to a vector