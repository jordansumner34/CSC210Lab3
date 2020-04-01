// This program tests various operation of a linked list
// Originally written by author: Malik, but did not work
// Severely modified by Jeff Goldstein, TCC Adjunct Professor, VB Campus
// "... a good start!"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "List.cpp"
#include "ListSorted.cpp"

void process(ListSorted<stuRecord>);  // pass by value

ifstream fin ("listIn.txt");
ofstream fout("listOut.txt");

int main()
{
    List<stuRecord> list0;      // create object list0 with no stuRecords
    ListSorted<stuRecord> list1;
    ListSorted<stuRecord> list2;

    fin >> list2;           // extraction operator overloaded works fine.
    fin.close();            // close the input file

    cout << list2;          // insertion operator is crippled, but works
    fout << list2;

    list0 = list1 = list2;   // overload operator = chained.

    process(list2);          // call process

    cout << list2;
    fout << list2;
    cout << endl;
    cout << "Length of list: "
         << list2.length() << endl << endl;



    return 0;
}

// process funtion passes a deep copy of list 2 in.
void process(ListSorted<stuRecord> list)
{

    /// call a funtion instead of these liones
    /// deleteStudent (list, "Close, Soo");
    stuRecord local;
    local.name = "Wallace, Mike";

    cout << "\n I'm in the process function\n" << endl;
    if(list.deleteNode(local))
    {
        cout << local.name << " was deleted" << endl;
    }
    else
    {
        cout << local.name << " could not be found" << endl;
    }

    /// addStudent function
    local.name = "Dawg, Top";
    local.fGpa = 4.0;
    local.zipCode = "23405";
    local.gender = 'M';

    list.insertLast(local);
    list.sortLinkedList("Name");

    cout << list;
    fout << list;
    cout << endl;
    cout << "Length of list: "
         << list.length() << endl << endl;
    cout << "exiting process function\n" << endl;

}


