
#include "HeapSort.hpp"
#include "InternalSortUtil.hpp"
#include "iostream"
#include <cstring>

struct Node
{
    int Value;
    char Name[21];

    inline bool operator<(Node a)
    {
        return Value < a.Value;
    }
    inline bool operator>(Node a)
    {
        return Value > a.Value;
    }
    inline bool operator>=(Node a)
    {
        return Value >= a.Value;
    }
    inline bool operator<=(Node a)
    {
        return Value <= a.Value;
    }
};

int main()
{
    int nodeCount = 0;
    std::cin >> nodeCount;
    Node nodes[nodeCount];
    for (size_t i = 0; i < nodeCount; i++)
    {
        std::cin >> nodes[i].Name >> nodes[i].Value;
    }
    std::vector<Node> nodeVec(nodes, nodes + nodeCount);

    DataStructures::Heap<Node> heap;
    heap.Array = nodeVec;
    heap.Construct();
    InternalSort::HeapSort(heap, heap.Array.begin(), heap.Array.end(), InternalSort::LessThan);

    for (size_t i = 0; i < nodeCount; i++)
    {
        std::cout << heap.Array[i].Name << "\n";
    }
    return 0;
}