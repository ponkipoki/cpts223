#include "TestListMyJosephus.h"

void testJosephusList()   //simulation for josephus list
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

        ListMyJosephus listSimulation(eliminationInterval, initialDestinations);
        loadDestinationsToList(inputStream, listSimulation, initialDestinations);
    
        listSimulation.printAllDestinations();
    
        cout << "\n";
    
        listSimulation.eliminateDestination();
         
        clock_t end = clock();
        double duration = (double)(end - start)/CLOCKS_PER_SEC;
        durationArray[i - 1] = duration;        //store duration into double array

        cout << "CPU elapsed time in seconds: " << duration << "\n" << endl;
        
        inputStream.close();
    }

    printArray(durationArray, "Josephus List");
    printArrayToLog(durationArray, "Josephus List");
}