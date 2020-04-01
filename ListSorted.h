// ListSorted.h class header file (specification).
// Version 1.0 by Mr. Jeff Goldstein, TCC Adjunct Professor, Virginia Beach Campus
#ifndef H_List_Sorted
#define H_List_Sorted

template <class Type>
class ListSorted : public List<Type>
{
  public:
    void sortLinkedList(string field);                  // optimized bubble sort on one field

  private:
    bool swapData(Type &, Type & );                     // swaps records for sorting
};
#endif
