namespace InternalSort
{
    template <class IteratorType>
    void Bubble(IteratorType begin, IteratorType end, bool (&comparisonMethod)(IteratorType, IteratorType))
    {
        for (IteratorType a = begin; a != end; ++a)
        {
            for (IteratorType b = begin; b != end - 1; ++b)
            {
                if (comparisonMethod(a, a + 1))
                    Swap(*a, *(a + 1));
            }
        }
    }
} // namespace InternalSort
