// List.cpp (implementation file for the List)
// Originally written by Malik 7th ed.  Commented by Jeff G.
#include "List.h"

// default constructor
template <class Type>
List<Type>::List()
{
    first = nullptr;            // set pointers to null
    last = nullptr;             //  "      "     "   "
    count = 0;                  // zero the count
}

// destructor destroys all nodes that were allocated
template <class Type>
List<Type>::~List()
{
   destroyList();               // call the private destroyList function
   cout << "List is destroyed...." << endl << endl; // demonstration only
}//end destructor



template <class Type>
void List<Type>::print() const
{
    nodeType<Type> *current;    //pointer to traverse the list

    current = first;            //set current so that it points to first node
    while (current != nullptr)  //while more data to print
    {
        cout << current->info << " ";   //view the data
        current = current->link;// advance current pointer
    }
    cout << endl;
}//end print

// length gets the lengto of the list
template <class Type>
int List<Type>::length() const
{
    return count;               // returns the # of nodes in the list
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
void List<Type>::insertFirst(const Type& item)  // building the list "backwards"
{
    nodeType<Type> *newNode;    //pointer to declare the new node

    newNode = new nodeType<Type>;   //create (allocate) new node

    newNode->info = item;       //assign item into info
    newNode->link = first;      //assign old first pointer to the newNode's link
    first = newNode;            //assign first to point to the new first node
    count++;                    //increment count
}//end insertFirst



template <class Type>
void List<Type>::insertLast(const Type& item) // building the list "forwards"
{
    nodeType<Type> *newNode;    //pointer to create the new node

    newNode = new nodeType<Type>;   //create the new node

    newNode->info = item;       //store the new item in the node
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
void List<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;            //pointer to traverse the list
    nodeType<Type> *trailCurrent;       //pointer just before current
    bool found;

    if (first == nullptr)               //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem)  //Case 2
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)       //the list has only one node
                last = nullptr;
            delete current;
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
                if (current->info != deleteItem)
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
