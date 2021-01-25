namespace InternalSort
{
    template <class IteratorType>
    void Insertion(IteratorType begin, IteratorType end, bool (&comparisonMethod)(IteratorType, IteratorType))
    {
        for (IteratorType a = begin + 1; a != end; ++a)
        {
            IteratorType selected = a;
            for (IteratorType b = a - 1; b != begin - 1; --b)
            {
                if (comparisonMethod(selected, b))
                {
                    Swap(*selected, *b);
                    selected = b;
                }
                else
                    break;
            }
        }
    }
} // namespace InternalSort