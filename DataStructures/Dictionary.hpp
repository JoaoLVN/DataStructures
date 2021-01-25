namespace DataStructures
{
    template <class KeyT, class ValueT>
    class Dictionary
    {

        struct DictionaryItem
        {
            KeyT key;
            ValueT value;

            DictionaryItem(KeyT key, ValueT value)
            {
                this->key = key;
                this->value = value;
            }
        };

    public:
        explicit Dictionary(int (&searchMethod)(DataStructures::Dictionary<KeyT, ValueT>, KeyT));

        typedef int (*SearchMethod)(DataStructures::Dictionary<KeyT, ValueT>, KeyT);

        std::vector<DictionaryItem> items;

        int length;

        ValueT &operator[](KeyT key);

        bool Contais(KeyT key);

        bool Add(KeyT key, ValueT value);

        bool Remove(KeyT key, ValueT &out);

    private:
        SearchMethod Search;
    };

    template <class KeyT, class ValueT>
    ValueT &Dictionary<KeyT, ValueT>::operator[](KeyT key)
    {
        int i = Search(*this, key);
        if (i == -1)
            return 0;
        return items[i].value;
    }

    template <class KeyT, class ValueT>
    bool Dictionary<KeyT, ValueT>::Contais(KeyT key)
    {
        int i = Search(*this, key);
        return (i != -1);
    }

    template <class KeyT, class ValueT>
    bool Dictionary<KeyT, ValueT>::Add(KeyT key, ValueT value)
    {
        for (int i = 0; i < items.size(); ++i)
        {
            if (items[i].key == key)
            {
                items[i].value = value;
                return false;
            }
            else if (items[i].key > key)
            {
                items.push_back(items[items.size() - 1]);
                for (int j = items.size() - 2; j != i; --j)
                {
                    items[j] = items[j - 1];
                }
                DictionaryItem item(key, value);
                items[i] = item;
                length++;
                return true;
            }
        }
        length++;
        DictionaryItem item(key, value);
        items.push_back(item);
        return true;
    }

    template <class KeyT, class ValueT>
    Dictionary<KeyT, ValueT>::Dictionary(int (&searchMethod)(DataStructures::Dictionary<KeyT, ValueT>, KeyT))
    {
        Search = searchMethod;
        length = 0;
    }

    template <class KeyT, class ValueT>
    bool Dictionary<KeyT, ValueT>::Remove(KeyT key, ValueT &out)
    {
        int i = Search(*this, key);
        if (i == -1)
            return false;
        DictionaryItem item = items[i];
        for (int j = i; j < items.size() - 1; ++j)
        {
            items[j] = items[j + 1];
        }
        items.pop_back();
        length--;
        out = item.value;
        return true;
    }

} // namespace DataStructures
