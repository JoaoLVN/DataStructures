template <class IteratorType>
void Swap(IteratorType &a, IteratorType &b)
{
    IteratorType aux = a;
    a = b;
    b = aux;
}
