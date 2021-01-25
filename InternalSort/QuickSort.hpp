namespace InternalSort
{
    template <class IteratorType>
    void doQuick(IteratorType begin, IteratorType end, bool (&comparisonMethod)(IteratorType, IteratorType))
    {
        if (begin < end)
        {
            IteratorType part = Partition(begin, end, comparisonMethod);
            doQuick(begin, part - 1, comparisonMethod);
            doQuick(part + 1, end, comparisonMethod);
        }
    }

    template <class IteratorType>
    void Quick(IteratorType begin, IteratorType end, bool (&comparisonMethod)(IteratorType, IteratorType))
    {
        doQuick(begin, end - 1, comparisonMethod);
    }
} // namespace InternalSort
