#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"
#include <memory>

template <typename T>
class CList
{
private:
    std::shared_ptr<CNode<T>> m_fictionaHead;
    std::shared_ptr<CNode<T>> m_realTail;

public:
    CList ();
    //~CList ();
    void push_front (const T & val);
    void Show () const;
    std::shared_ptr<CNode<T>> Find (const T & val) /*const*/;
    //void Add (const T & val, std::shared_ptr<CNode<T>>);
    void Delete (std::shared_ptr<CNode<T>>);
    //void push_back (const T & val);
    std::shared_ptr<CNode<T>> Begin () const;
    //void AddAfter (std::shared_ptr<CNode<T>>, const T & val);
    //void AddBefore (const std::shared_ptr<CNode<T>>, const T & val);
};

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Begin () const
{
    return m_fictionaHead;
}

//template <typename T>
/*void CList<T>::AddAfter (std::shared_ptr<CNode<T>> ptr, const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T>(val, ptr-> GetNextNode()));
    ptr -> GetNextNode() -> setPrev(tmp);
    ptr -> SetNextNode (tmp);
    tmp -> setPrev(ptr);

    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

template <typename T>
void CList<T>::Add (const T & val, std::shared_ptr<CNode<T>> ptr)
{
    std::shared_ptr<CNode<T>> ptrTmp = new CNode<T> (val, ptr -> GetNextNode ());
    ptr -> SetNextNode (ptrTmp);
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

Ptr_t AjoutApres (Ptr_t Tete, int NewVal, Ptr_t PtrElem)
{
    if (! PtrElem) PtrElem = Tete;

    PtrElem->SetSuivant
           (new C1Link (NewVal, PtrElem->GetSuivant()));

    return PtrElem->GetSuivant();

} // AjoutApres()
*/

template <typename T>
CList<T>::CList () : m_fictionaHead (new CNode<T> ()), m_realTail (m_fictionaHead) {}

//template <typename T>
//CList<T>::~CList () {
//    delete m_fictionaHead;
//}

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Find (const T & val) //const
{
    std::shared_ptr<CNode<T>> Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());
    Ptr->GetPrev()->SetNextNode(Ptr->GetNextNode());//1st etape

    if(Ptr != m_realTail)
        Ptr->GetNextNode()->setPrev(Ptr->GetPrev());//2nd etape
    else
        m_realTail = Ptr->GetPrev();

    Ptr->setPrev(m_fictionaHead);//etape 3
    Ptr->SetNextNode(m_fictionaHead -> GetNextNode());//etape4
    Ptr->GetNextNode()->setPrev(Ptr);//etape5
    m_fictionaHead->SetNextNode(Ptr);//etape6


    return Ptr;
}



/*template <typename T>
void CList<T>::push_front (const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T> (val, m_fictionaHead->GetNextNode ()));
    m_fictionaHead->SetNextNode (tmp);
    if (m_realTail == m_fictionaHead) m_realTail = m_fictionaHead->GetNextNode ();
}*/

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (std::shared_ptr<CNode<T>> Ptr (m_fictionaHead -> GetNextNode()); Ptr; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T>> pDelete)
{
    std::shared_ptr<CNode<T>> pFind (m_fictionaHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());

    pFind -> SetNextNode (pDelete -> GetNextNode ());
    pDelete -> GetNextNode() ->setPrev(pFind);
    if (pDelete == m_realTail) m_realTail = pFind;
    pDelete -> SetNextNode (nullptr);
    pDelete -> setPrev(nullptr);

 //   delete pDelete;
}

/*template <typename T>
void CList<T>::push_back (const T & val)
{
    std::shared_ptr<CNode<T>> pTmp (new CNode<T> (val, NULL));
    m_realTail -> SetNextNode (pTmp);
    m_realTail = pTmp;
}

template <typename T>
void CList<T>::AddBefore (const std::shared_ptr<CNode<T>> ptr, const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T>(val, ptr -> GetPrev()));
    ptr ->GetPrev() ->SetNextNode(tmp);
    tmp ->SetNextNode(ptr);
    ptr ->setPrev(tmp);

    if(ptr == m_fictionaHead) m_fictionaHead = ptr ->GetPrev();

}*/

#endif // LIST_HPP
