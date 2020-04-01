// uses an "Optimized" Bubble Sort technique sort the data within
// the list, rather than modify link structure.
#include "listsorted .h 

template <class Type>
void List<Type>::sortLinkedList(string field)
{
    nodeType<Type> *curr;               // local current pointer
	nodeType<Type> *next;               // local pointer always previous to curr
    bool swapped = true;                // assume swapped is true to enter the outer loop
    for(int i = 0; swapped && i < count; i++)  /// SOMETHING 2 X SPECIAL HERE!
    {
    	// keeps track of current pointer and the next adjacent pointer
        curr = first;                   // assigns first to local curr pointer
        next = first->link;             // next is the pointer after curr
    	swapped = false;                // reset flag to assume no swaps will happen
        for(int j = 0; j < count - i - 1; j++)  // optimized inner loop
        {
            if(field == "GPA")          // if the key field was GPA
            {
                // check to see if a smaller gpa comes before a larger gpa (wrong order)
                if (curr->stuRecord.fGpa < next->stuRecord.fGpa) // GPA's descending
                    swapped = swapData(curr->stuRecord, next->stuRecord);   // swap data
            }
            else                        // the name field should be sorted in ascending order
            {
                // if structure checks for names ascending order
                // same swap as in line 20 above
            }
            curr = curr->link;          // advance curr ptr
            next = next->link;          // advance next ptr
        }   // inner loop
    }   // outer loop
}   //SortLinkedList

// swapData used to exchange all data between nodes
template <class Type>
bool List<Type>::swapData(Type & currRec, Type & prevRec)
{
    Type tempRec = currRec;             // save current record
    currRec = prevRec;                  // assign previous record to currRec
    prevRec = tempRec;                  // assign saved temp record to previous rec
    return true;                        // yes, we did swap data
}
