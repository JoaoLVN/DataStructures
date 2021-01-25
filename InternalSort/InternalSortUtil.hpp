namespace InternalSort
{
    bool StringComparisonMethod(char a[], char b[])
    {
        int i = 0;
        while (a[i] != '\0' && a[i] == b[i])
            i++;
        if (a[i] == '\0')
            return false;
        return (a[i] <= b[i]);
    }

    template <class IteratorType>
    bool LessThan(IteratorType a, IteratorType b)
    {
        return *a < *b;
    }

    template <class IteratorType>
    bool GreaterThan(IteratorType a, IteratorType b)
    {
        return *a <= *b;
    }

    template <class IteratorType>
    bool GreaterOrEqual(IteratorType a, IteratorType b)
    {
        return *a >= *b;
    }

    template <class IteratorType>
    bool LessOrEqual(IteratorType a, IteratorType b)
    {
        return *a <= *b;
    }

} // namespace InternalSort
