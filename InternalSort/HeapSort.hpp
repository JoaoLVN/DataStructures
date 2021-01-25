#include "Heap.hpp"
#include "Helpers.hpp"

namespace InternalSort
{
    template <class IteratorType, class HeapType>
    void HeapSort(DataStructures::Heap<HeapType> heap, IteratorType begin, IteratorType end,
                  bool (&comparisonMethod)(IteratorType, IteratorType))
    {
        for (IteratorType a = begin; a != end; ++a)
        {
            IteratorType selected = a;
            for (IteratorType b = a; b != end; ++b)
            {
                if (comparisonMethod(b, selected))
                {
                    selected = b;
                }
            }
            Swap(*a, *selected);
            heap.Rebuild(0);
        }
    }
} // namespace InternalSort
