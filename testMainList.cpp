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
    cout << "Length of list: "// This program tests various operation of a linked list
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
void title();// displays title 


ifstream fin ("listIn.txt");
ofstream fout("listOut.txt");

int main()
{
	title();// calls title function 
	
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
    fout << endl;
    cout << "Length of list: "
         << list.length() << endl << endl;
    fout << "exiting process function\n" << endl;
    fout << "Length of list: "
         << list.length() << endl << endl;
    fout << "exiting process function\n" << endl;

}

void title()// formatted tile function to be called by main and displayed 
{ 
	cout << setw(40) << " L I N K E D  L I S T  G P A  R E P O R T "
	     << endl << endl;
	cout << setw(6)  << " " << "Current Date: April 08, 2020"<< endl<< endl; 
	cout << setw(19) << " " << "by" << endl<< endl;
	cout << setw(2)  << " " << "Kendra Schall and Jordan Summer, TCC"<< endl << endl;
	
	cout << setw(15) << "LastName, First" << setw(7) <<" " 
		 << setw(7)  << "ZipCode" << setw(2) << " " 
		 << setw(3)	 << "Sex" << setw(3) << " "<< setw(3) <<"GPA"<< endl;
	cout << setw(15) << "---------------" << setw(7) << " "
		 << setw(7)  << "-------" << setw(2) << " "
		 << setw(3)  << "---" << setw(3) << " "<< setw(3) <<"---"<< endl; 
	cout << "(Unsorted)" << endl;
	cout << "----------------------------------------" << endl;
	// need to repeat 95-100 for every report set 
	// cout << "(GPA sorted)" << endl;
	// cout << "----------------------------------------" << endl;
	
	// cout << "(Name sorted)" << endl;
	// cout << "----------------------------------------" << endl;
	
	// cout << "(Original main list2)" << endl;
	// cout << "----------------------------------------" << endl;
	
	// cout << "(Original main list1)" << endl;
	// cout << "----------------------------------------" << endl;
	
	// cout << "(Original main list0)" << endl;
	// cout << "----------------------------------------" << endl;
	
	fout << setw(40) << " L I N K E D  L I S T  G P A  R E P O R T "
	     << endl << endl;
	fout << setw(6)  << " " << "Current Date: April 08, 2020"<< endl<< endl; 
	fout << setw(19) << " " << "by" << endl<< endl;
	fout << setw(2)  << " " << "Kendra Schall and Jordan Summer, TCC"<< endl << endl;
	
	fout << setw(15) << "LastName, First" << setw(7) <<" " 
		 << setw(7)  << "ZipCode" << setw(2) << " " 
		 << setw(3)	 << "Sex" << setw(3) << " "<< setw(3) <<"GPA"<< endl;
	fout << setw(15) << "---------------" << setw(7) << " "
		 << setw(7)  << "-------" << setw(2) << " "
		 << setw(3)  << "---" << setw(3) << " "<< setw(3) <<"---"<< endl; 
	fout << "(Unsorted)" << endl;
	fout << "----------------------------------------" << endl;
}



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


