namespace InternalSort
{
    int GetDigitCount(int a)
    {
        int lengthCount = 0;
        for (; a != 0; a /= 10, lengthCount++)
            ;
        return lengthCount;
    }

    int GetDigit(int a, int digit)
    {
        return (a / (int)std::pow(10, digit)) % 10;
    }

    template <class IteratorType>
    void Radix(IteratorType begin, IteratorType end, int (&getKeyMethod)(IteratorType, int))
    {
        IteratorType max = begin;
        for (IteratorType a = begin + 1; a != end; ++a)
            if (*a > *max)
                max = a;
        int digitCount = GetDigitCount(getKeyMethod(max, -1));
        for (int i = 0; i < digitCount; ++i)
            Counting(begin, end, 10, i, getKeyMethod);
    }
} // namespace InternalSort
