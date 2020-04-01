// linkedList.cpp (implementation file for the linkedList)
// What this implementation file does...............March 30th
// Written by ...............................................
// Date: ....................................................

#include "List.h"

///Public Functions

// default constructor
template <class Type>
List<Type>::List()
{
    first = nullptr;            // set pointers to nullptr
    last  = nullptr;            //  "      "     "   "
    count = 0;                  // zero the count
}

// destructor destroys all nodes that were allocated
template <class Type>
List<Type>::~List()
{
   destroyList();           // calls protected destroyList function
   cout << setw(32) << "List is destroyed..." << endl << endl; // demonstration only
}//end destructor


// copy constructor creates a "deep copy" of the other list
template <class Type>
List<Type>::List(const List<Type>& otherList)
{
   	first = nullptr;            // set first pointer to nullptr
    copyList(otherList);        // deep copy the other list
}//end copy constructor


//overload the assignment operator
template <class Type>
const List<Type>& List<Type>::operator=
                      (const List<Type>& otherList)
{
    if (this != &otherList)     //avoid self-copy
    {
        copyList(otherList);    // simply call the copyList function
    }
     return *this;              // now, left side has the assigned list
}

template <class Type>
void List<Type>::initializeList()
{
	destroyList();              //if the list has any nodes, delete them
}

template <class Type>
bool List<Type>::isEmptyList() const
{
    return(first == nullptr);   //checks empty list from initial pointer
}

// length gets the length of the list
template <class Type>
int List<Type>::length() const
{
    return count;                       // returns the # of records in the list
}  //end length

template <class Type>
Type List<Type>::front() const
{
    assert(first != nullptr);

    return first->info;         //return the info of the first node
}//end front

template <class Type>
Type List<Type>::back() const
{
    assert(last != nullptr);

    return last->info;          //return the info of the last node
}//end back

template <class Type>
void List<Type>::insertFirst(const Type& record)  // building the list "backwards"
{
    nodeType<Type> *newNode;        //pointer to declare the new node

    newNode = new nodeType<Type>;   //create (allocate) new node

    newNode->stuRecord = record;    //assign record into list
    newNode->link = first;          //assign old first pointer to the newNode's link
    first = newNode;                //assign first to point to the new first node
    count++;                        //increment count
}//end insertFirst

template <class Type>
void List<Type>::insertLast(const Type& record) // building the list "forwards"
{
    nodeType<Type> *newNode;        //pointer to create the new node

    newNode = new nodeType<Type>;   //create the new node

    newNode->stuRecord = record;    //store the new item in the node
    newNode->link = nullptr;    //set the link field of newNode to nullptr

    if (first == nullptr)       //if list is empty, newNode is both first & last node
    {
        first = newNode;        //assign the new node pointer to first
        last = newNode;         //assign the new node pointer to last
    }
    else                        //list is not empty, insert newNode after last
    {
        last->link = newNode;   //insert newNode after last
        last = newNode;         //make last point to actual last node in the list
    }
    count++;                    // increment count
}//end insertLast

template <class Type>
bool List<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;            //pointer to traverse the list
    nodeType<Type> *trailCurrent;       //pointer just before current
    bool found;

    if (first == nullptr)               //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->stuRecord.name == deleteItem.name)  //Case 2
        {
            current = first;            // Save the first pointer to curr
            first = first->link;        // adv. 1st ptr to next node
            count--;                    // decrement count
            if (first == nullptr)       //the list has only one node
                last = nullptr;         // assign nullptr to last
            delete current;             // deallocate first node
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;       //set trailCurrent to point
                                        //to the first node
            current = first->link;      //set current to point to
                                        //the second node

            while (current != nullptr && !found)
            {
                if (current->stuRecord != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)     //node to be deleted
                                         //was the last node
                    last = trailCurrent; //update the value
                                         //of last
                delete current;          //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

///Protected Functions

template <class Type>
void List<Type>::copyList(const List<Type>& otherList)
{
    nodeType<Type> *newNode;    //local pointer to create a node
    nodeType<Type> *current;    //local pointer to traverse the list

    if (first != nullptr)       //if the list is not empty
       destroyList();           //then, make it empty

    if (otherList.first == nullptr)  //otherList is empty
    {
        first = nullptr;        //reset pointers
        last = nullptr;         //  "      "
        count = 0;              // zero the count
    }
    else                        //the other list must have data
    {
        current = otherList.first;  //current points to the list to be copied
        count = otherList.count;

        //this section copies only the first node
        first = new nodeType<Type>;     //create (allocate) the node

        first->stuRecord = current->stuRecord;    //copy the stuRecord
        first->link = nullptr;          //set the link field of the node to nullptr
        last = first;                   //make last point to the first node
        current = current->link;        //make current point to the next node

        //copy the remaining list
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;   //create (allocate) the node
            newNode->stuRecord = current->stuRecord;  //copy the stuRecord
            newNode->link = nullptr;           //set the link of newNode to nullptr
            last->link = newNode;           //attach newNode after last
            last = newNode;                 //make last point to the actual last node
            current = current->link;        //make current point to the next node
        }//end while
    }//end else
}//end copyList

template <class Type>
void List<Type>::destroyList()
{
    nodeType<Type> *temp;       //pointer to deallocate the memory occupied by node
    while (first != nullptr)    //while there are nodes in the list
    {
        temp = first;           //set temp to the current node
        first = first->link;    //advance first to the next node
        delete temp;            //deallocate the memory occupied by temp
        cout << "Node destroyed." << endl;
    }
    last = nullptr;             //initialize last to nullptr; first has already
                                //been set to nullptr by the while loop
    count = 0;                  // zero the count
}

/// Friend Functions

template <class Type>
istream & operator>> (istream & infile, List<Type> & obj)
{
    Type stuRec;                        // declare local student record
    string lname, fname, name, zip;     // declare string variables
    char sex;                           // declare char
    float gpa;                          // declare gpa
    infile >> lname >> fname >> zip >> sex >> gpa;  // priming read entire line
    while (!infile.eof())
    {
        name = lname + ", " + fname;    // concatenate name last, first

        stuRec.name    = name;          // assign each input to the correct field
        stuRec.zipCode = zip;           //   "     "     "    "  "      "     "
        stuRec.gender  = sex;
        stuRec.fGpa    = gpa;
        obj.insertLast(stuRec);         // add this record to the end of the list
        infile >> lname >> fname >> zip >> sex >> gpa;  // read entire line
    }
    return infile;                      // return to the data stream
}

template <class Type>
ostream & operator<< (ostream & outfile, const List<Type> & obj)
{
    nodeType<Type> *curr;                       // declare pointer to traverse list
    curr = obj.first;                           // set curr to point to first node
    outfile << fixed << setprecision(2);        // format the output for 2 decimal places
    while (curr != nullptr)
    {
        outfile << left << setw(23);
        outfile << curr->stuRecord.name;    // output the name (hint) left justified
        // right justify the rest of the data
        outfile << right;
        outfile << curr->stuRecord.zipCode << "\t"; // output the zipCode
        outfile << curr->stuRecord.gender << "\t";  // output the gender
        outfile << curr->stuRecord.fGpa   << "\t";  // output the gpa
        outfile << endl;                            // end of line after this record
        curr = curr->link;
    }
    return outfile;                                 // return to the data stream
}



