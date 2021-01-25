#include <vector>

namespace DataStructures
{
    template <class T>
    class Heap
    {
    public:
        Heap();

        std::vector<T> Array;

        void Construct();

        void Rebuild(int i);
    };

    template <class T>
    Heap<T>::Heap()
    {
    }

    template <class T>
    void Heap<T>::Rebuild(int i)
    {
        while (i < Array.size())
        {
            if ((2 * i) < Array.size() && (2 * i + 1) < Array.size())
            {
                if (Array[2 * i] < Array[2 * i + 1] && Array[i] < Array[2 * i + 1])
                {
                    Swap(Array[2 * i + 1], Array[i]);
                    i = 2 * i + 1;
                }
                else if (Array[i] < Array[2 * i])
                {
                    Swap(Array[2 * i], Array[i]);
                    i = 2 * i;
                }
                else
                    break;
            }
            else if ((2 * i) < Array.size() && (2 * i + 1) > Array.size())
            {
                if (Array[i] < Array[2 * i])
                {
                    Swap(Array[2 * i], Array[i]);
                    i = 2 * i;
                }
                else
                    break;
            }
            else
                break;
        }
    }

    template <class T>
    void Heap<T>::Construct()
    {
        int i = (Array.size() - 1) / 2 + 1;
        while (--i >= 0)
        {
            Rebuild(i);
        }
    }
} // namespace DataStructures
