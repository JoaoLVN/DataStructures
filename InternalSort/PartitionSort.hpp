namespace InternalSort
{
    template <class IteratorType>
    IteratorType Partition(IteratorType begin, IteratorType end, bool (&comparisonMethod)(IteratorType, IteratorType))
    {
        IteratorType pivot = end;
        IteratorType smaller = begin - 1;
        for (IteratorType j = begin; j != end; ++j)
        {
            if (comparisonMethod(j, pivot))
            {
                smaller++;
                Swap(*smaller, *j);
            }
        }
        IteratorType plusOne = smaller + 1;
        Swap(*plusOne, *end);
        return plusOne;
    }

} // namespace InternalSort
