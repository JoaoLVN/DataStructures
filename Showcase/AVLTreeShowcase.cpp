#include "AVLTree.hpp"

int main()
{
    DataStructures::AVLTree<int, int> avlTree;

    int nodeCount;
    std::cin >> nodeCount;
    while (nodeCount-- > 0)
    {
        int currentNode;
        std::cin >> currentNode;
        avlTree.Add(avlTree.Root, currentNode, currentNode);
    }

    int elementToRemove;
    std::cin >> elementToRemove;
    avlTree.Remove(avlTree.Root, elementToRemove);
    
    avlTree.PrintTree(avlTree.Root);
    return 0;
}
