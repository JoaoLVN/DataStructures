
namespace InternalSort
{
    template <class IteratorType>
    void Selection(IteratorType begin, IteratorType end, bool (&comparisonMethod)(IteratorType, IteratorType))
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
        }
    }
} // namespace InternalSort
