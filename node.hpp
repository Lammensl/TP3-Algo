#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode> m_RC;
    std::shared_ptr<CNode> m_LC;

public:
    //constructor
    CNode (const T &  val = T(), std::shared_ptr<CNode> ptr = nullptr, std::shared_ptr<CNode> Pptr = nullptr);
    //destructor
   // ~CNode ();

    //getter / setter
    const T &GetData () const;
    std::shared_ptr<CNode> GetRC () const;
    void SetData (const T & val);
    void SetRC (std::shared_ptr<CNode>);
    std::shared_ptr<CNode> GetLC() const;
    void SetLC(const std::shared_ptr<CNode> &LC);
};


template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetLC() const
{
    return m_LC;
}

template <typename T>
void CNode<T>::SetLC(const std::shared_ptr<CNode<T>> &LC)
{
    m_LC = LC;
}

template <typename T>
CNode<T>::CNode (const T & val/* = T()*/, std::shared_ptr<CNode> ptr/* = nullptr*/, std::shared_ptr<CNode> Pptr/* =nullptr*/ ) : m_Data (val), m_RC (ptr), m_LC (Pptr)
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
std::shared_ptr<CNode<T>> CNode<T>::GetRC () const
{
    return m_RC;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetRC (std::shared_ptr<CNode> ANode)
{
    m_RC = ANode;
}

#endif // NODE_HPP
