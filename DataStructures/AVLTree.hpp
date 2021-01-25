#include "BinaryTree.hpp"

namespace DataStructures
{
    template <class KeyT, class ValueT>
    class AVLTree : public BinaryTree<KeyT, ValueT>
    {
    public:
        int Fb(Node<KeyT, ValueT> *node);

        bool IsAvl(Node<KeyT, ValueT> *node);

        void BalanceTree(Node<KeyT, ValueT> *&node);

        void BalanceNode(Node<KeyT, ValueT> *&node);

        void RR(Node<KeyT, ValueT> *&node);

        void RL(Node<KeyT, ValueT> *&node);

        void LR(Node<KeyT, ValueT> *&node);

        void LL(Node<KeyT, ValueT> *&node);

        virtual Node<KeyT, ValueT> *Add(Node<KeyT, ValueT> *&node, KeyT key, ValueT value);

        virtual Node<KeyT, ValueT> *Remove(Node<KeyT, ValueT> *&node, KeyT key);
    };

    template <class KeyT, class ValueT>
    int AVLTree<KeyT, ValueT>::Fb(Node<KeyT, ValueT> *node)
    {
        if (node == NULL)
            return 0;
        int left = this->Height(node->Left);
        int right = this->Height(node->Right);
        return left - right;
    }

    template <class KeyT, class ValueT>
    bool AVLTree<KeyT, ValueT>::IsAvl(Node<KeyT, ValueT> *node)
    {
        int fb = Fb(node);
        return (fb >= 0 ? fb : -fb) <= 1;
    }

    template <class KeyT, class ValueT>
    void AVLTree<KeyT, ValueT>::BalanceTree(Node<KeyT, ValueT> *&node)
    {
        if (node == NULL)
            return;
        BalanceTree((*node).Left);
        BalanceTree((*node).Right);
        BalanceNode(node);
    }

    template <class KeyT, class ValueT>
    void AVLTree<KeyT, ValueT>::BalanceNode(Node<KeyT, ValueT> *&node)
    {
        if (node == NULL)
            return;
        if (!IsAvl(node))
        {
            int fb = Fb(node);
            if (fb > 1)
            {
                if (Fb((*node).Left) < 0)
                {
                    LR(node);
                }
                else if (Fb((*node).Left) > 0)
                {
                    LL(node);
                }
            }
            else if (fb < -1)
            {
                if (Fb((*node).Right) > 0)
                {
                    RL(node);
                }
                else if (Fb((*node).Right) < 0)
                {
                    RR(node);
                }
            }
        }
    }

    template <class KeyT, class ValueT>
    Node<KeyT, ValueT> *AVLTree<KeyT, ValueT>::Add(Node<KeyT, ValueT> *&node, KeyT key, ValueT value)
    {
        if (node == NULL)
        {
            node = new Node<KeyT, ValueT>(key, value);
            return node;
        }
        Node<KeyT, ValueT> *created;
        if (key < node->Key)
        {
            created = Add(node->Left, key, value);
        }
        else if (key > node->Key)
        {
            created = Add(node->Right, key, value);
        }
        BalanceNode(node);
        return created;
    }

    template <class KeyT, class ValueT>
    Node<KeyT, ValueT> *AVLTree<KeyT, ValueT>::Remove(Node<KeyT, ValueT> *&node, KeyT key)
    {
        if (node == NULL)
            return NULL;

        Node<KeyT, ValueT> *removed = NULL;
        if (key < node->Key)
        {
            removed = Remove(node->Left, key);
        }
        else if (key > node->Key)
        {
            removed = Remove(node->Right, key);
        }
        else
        {
            if (node->Left == NULL || node->Right == NULL)
            {
                Node<KeyT, ValueT> *aux = node->Left;
                if (node->Right != NULL)
                    aux = node->Right;
                removed = node;
                node = aux;
            }
            else
            {
                Node<KeyT, ValueT> *successor = node->Right;
                while (successor->Left != NULL)
                    successor = successor->Left;
                removed = new Node<KeyT, ValueT>(node->Key, node->Value);
                node->Key = successor->Key;
                node->Value = successor->Value;
                Remove(node->Right, successor->Key);
            }
            BalanceNode(node);
        }

        return removed;
    }


    template <class KeyT, class ValueT>
    void AVLTree<KeyT, ValueT>::RR(Node<KeyT, ValueT> *&node)
    {
        Node<KeyT, ValueT> *pb = (*node).Right;
        (*node).Right = pb->Left;
        pb->Left = node;
        node = pb;
    }

    template <class KeyT, class ValueT>
    void AVLTree<KeyT, ValueT>::RL(Node<KeyT, ValueT> *&node)
    {
        Node<KeyT, ValueT> *pb = (*node).Right;
        Node<KeyT, ValueT> *pc = pb->Left;
        pb->Left = pc->Right;
        pc->Right = pb;
        (*node).Right = pc->Left;
        pc->Left = node;
        node = pc;
    }

    template <class KeyT, class ValueT>
    void AVLTree<KeyT, ValueT>::LL(Node<KeyT, ValueT> *&node)
    {
        Node<KeyT, ValueT> *pb = (*node).Left;
        (*node).Left = pb->Right;
        pb->Right = node;
        node = pb;
    }

    template <class KeyT, class ValueT>
    void AVLTree<KeyT, ValueT>::LR(Node<KeyT, ValueT> *&node)
    {
        Node<KeyT, ValueT> *pb = (*node).Left;
        Node<KeyT, ValueT> *pc = pb->Right;
        pb->Right = pc->Left;
        pc->Left = pb;
        (*node).Left = pc->Right;
        pc->Right = node;
        node = pc;
    }

} // namespace DataStructures
