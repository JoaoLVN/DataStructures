namespace InternalSort
{
    template <class IteratorType>
    void Counting(IteratorType begin, IteratorType end, int collectionKeysLength, int digit,
                  int (&getKeyMethod)(IteratorType, int))
    {
        int C[collectionKeysLength];

        for (int i = 0; i < collectionKeysLength; ++i)
            C[i] = 0;

        for (IteratorType a = begin; a != end; ++a)
            C[getKeyMethod(a, digit)]++;
        for (int i = 1; i < collectionKeysLength; ++i)
            C[i] += C[i - 1];

        typeof(*begin) B[end - begin];

        for (IteratorType k = end - 1; k != begin - 1; --k)
            B[--C[getKeyMethod(k, digit)]] = *k;

        for (IteratorType a = begin; a != end; ++a)
            *a = B[std::distance(begin, a)];
    }
} // namespace InternalSort
