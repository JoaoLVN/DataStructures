#include "Dictionary.hpp"

namespace InternalSearch
{
    template <class KeyT, class ValueT>
    int Sequential(DataStructures::Dictionary<KeyT, ValueT> dictionary, KeyT searchItem)
    {
        for (int i = 0; i < dictionary.items.size(); ++i)
        {
            if (dictionary.items[i].key == searchItem)
            {
                return i;
            }
        }
        return -1;
    }
}