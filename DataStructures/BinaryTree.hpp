#include <cstddef>
#include "iostream"

namespace DataStructures
{
    template <class KeyT, class ValueT>
    struct Node
    {
       public:
        KeyT Key;
        ValueT Value;
        Node *Left, *Right, *Parent;
        char Color;

        Node() {}

        Node(KeyT key, ValueT value)
        {
            Key = key;
            Value = value;
            Left = NULL;
            Right = NULL;
        }

        bool operator<(Node &a)
        {
            return Key < a.Key;
        }

        bool operator>(Node &a)
        {
            return Key > a.Key;
        }
    };

    template <class KeyT, class ValueT>
    class BinaryTree
    {
    public:
        BinaryTree();

        Node<KeyT, ValueT> *Root;

        int Count();

        int Height(Node<KeyT, ValueT> *node);

        int Count(Node<KeyT, ValueT> *node);

        virtual Node<KeyT, ValueT> *Add(KeyT key, ValueT value);

        virtual Node<KeyT, ValueT> *Remove(KeyT key);

        Node<KeyT, ValueT> *Find(KeyT key);

        virtual void PrintTree(Node<KeyT, ValueT> *node);
    };

    template <class KeyT, class ValueT>
    BinaryTree<KeyT, ValueT>::BinaryTree()
    {
        Root = NULL;
    }

    template <class KeyT, class ValueT>
    Node<KeyT, ValueT> *BinaryTree<KeyT, ValueT>::Add(KeyT key, ValueT value)
    {
        Node<KeyT, ValueT> *node = new Node<KeyT, ValueT>(key, value);
        Node<KeyT, ValueT> *current = Root;
        if (Root == NULL)
        {
            Root = node;
            return node;
        }
        while (true)
        {
            if (*node < *current)
            {
                if (current->Left == NULL)
                {
                    current->Left = node;
                    return node;
                }
                current = current->Left;
            }
            else if (*node > *current)
            {
                if (current->Right == NULL)
                {
                    current->Right = node;
                    return node;
                }
                current = current->Right;
            }
        }
    }

    template <class KeyT, class ValueT>
    void BinaryTree<KeyT, ValueT>::PrintTree(Node<KeyT, ValueT> *node)
    {
        if (node == NULL)
        {
            std::cout << "()";
            return;
        }
        std::cout << "(C" << node->Key;
        PrintTree(node->Left);
        PrintTree(node->Right);
        std::cout << ")";
    }

    template <class KeyT, class ValueT>
    Node<KeyT, ValueT> *BinaryTree<KeyT, ValueT>::Find(KeyT key)
    {
        Node<KeyT, ValueT> *current = Root;
        while (true)
        {
            if (current == NULL)
                return NULL;
            if (key < current->Key)
                current = current->Left;
            else if (key > current->Key)
                current = current->Right;
            else
                return current;
        }
    }

    template <class KeyT, class ValueT>
    Node<KeyT, ValueT> *BinaryTree<KeyT, ValueT>::Remove(KeyT key)
    {
        Node<KeyT, ValueT> *parent = NULL;
        Node<KeyT, ValueT> *current = Root;
        while (true)
        {
            if (current == NULL)
                return NULL;
            if (key < current->Key)
            {
                parent = current;
                current = current->Left;
            }
            else if (key > current->Key)
            {
                parent = current;
                current = current->Right;
            }
            else
            {
                if (current->Left == NULL || current->Right == NULL)
                {
                    Node<KeyT, ValueT> *aux = current->Left;
                    if (current->Right != NULL)
                        aux = current->Right;
                    if (parent != NULL)
                    {
                        if (parent->Left == current)
                        {
                            parent->Left = aux;
                        }
                        else
                        {
                            parent->Right = aux;
                        }
                    }
                    else
                    {
                        Root = aux;
                    }
                }
                else
                {
                    Node<KeyT, ValueT> *successor = current->Right;
                    while (successor->Left != NULL)
                        successor = successor->Left;
                    Remove(successor->Key);
                    if (parent != NULL)
                    {
                        if (parent->Left == current)
                        {
                            parent->Left->Key = successor->Key;
                            parent->Left->Value = successor->Value;
                        }
                        else
                        {
                            parent->Right->Key = successor->Key;
                            parent->Right->Value = successor->Value;
                        }
                    }
                    else
                    {
                        Root = successor;
                    }
                }
                return current;
            }
        }
    }

    template <class KeyT, class ValueT>
    int BinaryTree<KeyT, ValueT>::Count()
    {
        return Count(Root);
    }

    template <class KeyT, class ValueT>
    int BinaryTree<KeyT, ValueT>::Count(Node<KeyT, ValueT> *node)
    {
        if (node == NULL)
            return 0;
        return 1 + Count(node->Left) + Count(node->Right);
    }

    template <class KeyT, class ValueT>
    int BinaryTree<KeyT, ValueT>::Height(Node<KeyT, ValueT> *node)
    {
        if (node == NULL)
            return 0;
        int left = Height(node->Left);
        int right = Height(node->Right);

        return (right > left ? right : left) + (node == Root ? 0 : 1);
    }

} // namespace DataStructures
