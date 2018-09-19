#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode> m_Next;
    std::shared_ptr<CNode> m_Prev;

public:
    //constructor
    CNode (const T &  val = T(), std::shared_ptr<CNode> ptr = nullptr, std::shared_ptr<CNode> Pptr = nullptr);
    //destructor
   // ~CNode ();

    //getter / setter
    const T &GetData () const;
    std::shared_ptr<CNode> GetNextNode () const;
    void SetData (const T & val);
    void SetNextNode (std::shared_ptr<CNode>);
    std::shared_ptr<CNode> GetPrev() const;
    void setPrev(const std::shared_ptr<CNode> &Prev);
};


template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetPrev() const
{
    return m_Prev;
}

template <typename T>
void CNode<T>::setPrev(const std::shared_ptr<CNode<T>> &Prev)
{
    m_Prev = Prev;
}

template <typename T>
CNode<T>::CNode (const T & val/* = T()*/, std::shared_ptr<CNode> ptr/* = nullptr*/, std::shared_ptr<CNode> Pptr/* =nullptr*/ ) : m_Data (val), m_Next (ptr), m_Prev (Pptr)
{
}

//template <typename T>
//CNode<T>::~CNode ()
//{
//    delete m_Next;
    //cout << m_Data << endl;
//}

template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetNextNode () const
{
    return m_Next;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetNextNode (std::shared_ptr<CNode> ANode)
{
    m_Next = ANode;
}

#endif // NODE_HPP
