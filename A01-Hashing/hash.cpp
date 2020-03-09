//***************************************************************
// Program #1 Hashing Expirement
// Name: Ben Diekhoff
// CMPS 5243 Algorithms
// Dr. Halverson
// Date: 03/10/2020
//***************************************************************
/*
This program takes a set of keys, hashes them using linear probing and double
hashing, and returns the complete hash tables for each CRP as well as the 
average number of probes for each method.
/******************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ofstream outfile("output.txt");

class HASH {
private:
    int* table;                             // the hash table
    void Clean_Table(int);
    int Lin_Probe(int, int, int);
    int Double_Probe(int, int, int);
    void Print_Table(int);
public:
    HASH(int);                                // constructor
    ~HASH();                                  // destructor
    int Mod_Hash(int, int);
    void Clean_Table_Pub(int);                // caller function
    int Lin_Probe_Pub(int, int, int);         // caller function
    int Double_Probe_Pub(int, int, int);      // caller function
    void Print_Table_Pub(int);                // caller function

};


/**********************************************************************
    Clean_Table
	Parameters: One int
    
    Sets every value in the dyanimcally allocated table to -9999.
***********************************************************************/
void HASH::Clean_Table(int table_size) {
    for (int i = 0; i < table_size; i++) {
        table[i] = -9999;
    }
}


/**********************************************************************
    Lin_Probe
	Parameters: Three ints

    Inserts a key into an "empty" slot in the table (orig_loc by default), 
    where -9999 is considered empty. If the orig_loc isn't empty, it increments
    through the table one index at a time (mod table_size) until an empty slot 
    is found. It returns the number of probes it takes for successful insertion.
***********************************************************************/
int HASH::Lin_Probe(int key, int orig_loc, int table_size) {
    int count = 1;

    while (table[orig_loc] != -9999) {
        count++;
        orig_loc = (orig_loc + 1) % table_size;
    }
    table[orig_loc] = key;
    return count;
}


/**********************************************************************
    Double_Probe
	Parameters: Three ints

    Inserts a key into an "empty" slot in the table (orig_loc by default), 
    where -9999 is considered empty. If the orig_loc isn't empty, it increments
    through the table based on the last digit of the key + 1. When it finds an
    empty slot the key is inserted. It returns the number of probes it takes 
    for successful insertion.
***********************************************************************/
int HASH::Double_Probe(int key, int orig_loc, int table_size) {
    int increment = (key % 10) + 1;
    int count = 1;

    while (table[orig_loc] != -9999) {
        count++;
        orig_loc = (orig_loc + increment) % table_size;
    }
    table[orig_loc] = key;
    return count;
}


/**********************************************************************
    Print_Table
	Parameters: One int

    Prints the table in a nice, readable format to a .txt file.
***********************************************************************/
void HASH::Print_Table(int table_size) {
    int key;
    outfile << setw(12) << left << "LOCATION" << "KEY\n";

    for (int loc = 0; loc < table_size; loc++) {
        key = table[loc];
        outfile << setw(12) << loc << key << "\n";
    }
}


//////////////////////////////////////////////////////////////////////////
////////////////////////////                  ////////////////////////////
//////////////////////////// PUBLIC FUCNTIONS ////////////////////////////
////////////////////////////                  ////////////////////////////
//////////////////////////////////////////////////////////////////////////


/**********************************************************************
    HASH
	Parameters: One int

    Constructor for the HASH class.
***********************************************************************/
HASH::HASH(int table_size) {
    table = new int[table_size];
}


/**********************************************************************
    HASH
	Parameters: None

    Destructor for the HASH class.
***********************************************************************/
HASH::~HASH() {
    delete[] table;
    table = nullptr;
}


/**********************************************************************
    Mod_Hash
	Parameters: Two ints

    Calculates and returns the initial hash location for a given key. 
***********************************************************************/
int HASH::Mod_Hash(int key, int table_size) {
    return (key % table_size);
}


/**********************************************************************
    Clean_Table_Pub
	Parameters: Three ints

    Caller function for Clean_Table, which:
    Sets every value in the dyanimcally allocated table to -9999.
***********************************************************************/
void HASH::Clean_Table_Pub(int table_size) {
    Clean_Table(table_size);
}


/**********************************************************************
    Lin_Probe_Pub
	Parameters: Three ints

    Caller function for Lin_Probe, which:
    Inserts a key into an "empty" slot in the table (orig_loc by default), 
    where -9999 is considered empty. If the orig_loc isn't empty, it increments
    through the table one index at a time (mod table_size) until an empty slot 
    is found. It returns the number of probes it takes for successful insertion.
***********************************************************************/
int HASH::Lin_Probe_Pub(int key, int orig_loc, int table_size) {
    return Lin_Probe(key, orig_loc, table_size);
}


/**********************************************************************
    Double_Probe_Pub
	Parameters: Three ints

    Caller function for Double_Probe, which:
    Inserts a key into an "empty" slot in the table (orig_loc by default), 
    where -9999 is considered empty. If the orig_loc isn't empty, it increments
    through the table based on the last digit of the key + 1. When it finds an
    empty slot the key is inserted. It returns the number of probes it takes 
    for successful insertion.
***********************************************************************/
int HASH::Double_Probe_Pub(int key, int orig_loc, int table_size) {
    return Double_Probe(key, orig_loc, table_size);
}


/**********************************************************************
    Print_Table_Pub
	Parameters: One int

    Caller function for Print_Table, which:
    Prints the table in a nice, readable format to a .txt file.
***********************************************************************/
void HASH::Print_Table_Pub(int table_size) {
    Print_Table(table_size);
}

//////////////////////////////////////////////////////////////////////////
////////////////////////////                  ////////////////////////////
////////////////////////////   MAIN FUCNTION  ////////////////////////////
////////////////////////////                  ////////////////////////////
//////////////////////////////////////////////////////////////////////////

int main() {
    const int table_size = 31;
    int probe_count = 0;  // 0 is a sentinel value
    int orig_loc = -1;  // Location a key is initially hashed toS
    int data[] = { 3,9,44,123,99,332,69,97,33,22,52,569,873,773,987,35,14,89,
        339,42 };  // Data to be inserted into the hash table
    double n = sizeof(data) / sizeof(data[0]);  // number of items to insert
    double alpha = n / table_size;  // Load factor
    double avg_probes = -1.1; // Avg number of probes for inserting into a table

    HASH h(table_size);

    for (int i = 0; i < 2; i++) {
        probe_count = 0;

        h.Clean_Table_Pub(table_size); // Set all values in h.table to -9999

        if (i == 0) {
            for (auto key : data) {
                // determines hash location for key
                orig_loc = h.Mod_Hash(key, table_size); 
                // accumulator for the number of probes required to insert
                // all values into the table
                probe_count += h.Lin_Probe_Pub(key, orig_loc, table_size);
            }
            outfile << "LINEAR PROBE\n================\n";
        }

        else if (i == 1) {
            for (auto key : data) {
                // determines hash location for key
                orig_loc = h.Mod_Hash(key, table_size);
                // accumulator for the number of probes required to insert
                // all values into the table
                probe_count += h.Double_Probe_Pub(key, orig_loc, table_size);
            }
            outfile << "DOUBLE HASH\n================\n";
        }
        avg_probes = probe_count / n;
        outfile << "Average number of probes: " << fixed << setprecision(3) 
            << avg_probes << "\n";
        h.Print_Table_Pub(table_size);
        outfile << "\n\n";
    }

    outfile.close();
    return 0;
}

// cout << "key\torigloc\tactloc\tprobes\n";

// for (auto key : data) {
//     cout << key << "\t";
//     orig_loc = h.Mod_Hash(key, table_size); // determines hash location for key
//     cout << orig_loc << "\t";
//     linearProbeCount = h.Lin_Probe(key, orig_loc, table_size);
//     act_loc = (orig_loc + linearProbeCount - 1) % table_size;
//     cout << act_loc << "\t";
//     cout << linearProbeCount << "\n";
// }

// // reset the table
// for (int i = 0; i < table_size; i++) {
//     h.table[i] = -9999;
// }
// cout << "\n\nDOUBLE HASHING\n";
// cout << "key\torigloc\tactloc\tprobes\n";
// for (auto key : data) {
//     cout << key << "\t";
//     orig_loc = h.Mod_Hash(key, table_size); // determines hash location for key
//     cout << orig_loc << "\t";
//     doubleProbeCount = h.Double_Probe(key, orig_loc, table_size);
//     act_loc = orig_loc;
//     cout << act_loc << "\t";
//     cout << doubleProbeCount << "\n";
// }

