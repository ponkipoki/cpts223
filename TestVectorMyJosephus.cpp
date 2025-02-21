#include "TestVectorMyJosephus.h"

void testJosephusVector()   //simulation for josephus vector
{
    double durationArray[TOTAL_DESTINATIONS];

    for (int i = 1; i <= TOTAL_DESTINATIONS; i++)
    { 
        ifstream inputStream("destinations.csv");

        clock_t k = clock();
        clock_t start;
        do start = clock();
        while (start == k);

        int initialDestinations = i;      //set a random n
        int eliminationInterval;
        if (i == 1)
        {
            eliminationInterval = 1;
        }
        else
        {
            eliminationInterval = (rand() % (initialDestinations - 1)) + 1;   //set a random m
        }

        VectorMyJosephus vectorSimulation(eliminationInterval, initialDestinations);

        loadDestinationsToVector(inputStream, vectorSimulation, initialDestinations);
        inputStream.close();
    
        vectorSimulation.printAllDestinations();
    
        cout << "\n";
    
        vectorSimulation.eliminateDestination();
         
        clock_t end = clock();
        double duration = (double)(end - start)/CLOCKS_PER_SEC;
        durationArray[i - 1] = duration;        //store duration into double array

        cout << "CPU elapsed time in seconds: " << duration << "\n" << endl;
    }

    printArray(durationArray, "Josephus Vector");
    printArrayToLog(durationArray, "Josephus Vector");
}