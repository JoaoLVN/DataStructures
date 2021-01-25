#include "Dictionary.hpp"

namespace InternalSearch
{
    template <class KeyT, class ValueT>
    int Binary(DataStructures::Dictionary<KeyT, ValueT> dictionary, KeyT searchItem)
    {
        int esq = 0, dir = dictionary.items.size() - 1;
        int mid;
        while (esq <= dir)
        {
            mid = (dir + esq) / 2;
            if (searchItem < dictionary.items[mid].key)
                dir = mid - 1;
            else if (searchItem > dictionary.items[mid].key)
                esq = mid + 1;
            else
                return mid;
        }
        return -1;
    }
} // namespace InternalSearch