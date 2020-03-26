//***************************************************************
// Program #1a Random Number Generator
// Name: Ben Diekhoff
// CMPS 5243 Algorithms
// Dr. Halverson
// Date: 03/24/2020
//***************************************************************
/*
This program generates 500 random numbers ranging from 0 to 4999.
These numbers are stored in an output file named "datafile.txt". The output file
is not allowed to contain duplicate numbers.
/******************************************************************/

#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    ofstream datafile("datafile.txt");
    const int max = 5000; // random numbers will be 0 to max -1
    int dupTable[max] = {0}; //Acts like a direct mapped hash table that keeps 
                             // track of which numbers have already been used 
    int data;
    srand(time(NULL));

    // Generate 500 random numbers
    for (int i = 0; i < 500; i++) {
        data = rand() % max;

        //check for and prevent duplicates
        while (dupTable[data] == 1) {
            data = rand() % max;
        }
        dupTable[data] = 1;

        //print to datafile
        datafile << setw(8) << data;
        if (i % 10 == 9)
            datafile << "\n";
    }
    datafile.close();
    return 0;
}