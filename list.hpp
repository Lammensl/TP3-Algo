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
    std::shared_ptr<CNode<T>> tmp (new CNode<T>(val, ptr-> GetRC()));
    ptr -> GetRC() -> setLC(tmp);
    ptr -> SetRC (tmp);
    tmp -> setLC(ptr);

    if (ptr == m_realTail) m_realTail = ptr->GetRC ();
}

template <typename T>
void CList<T>::Add (const T & val, std::shared_ptr<CNode<T>> ptr)
{
    std::shared_ptr<CNode<T>> ptrTmp = new CNode<T> (val, ptr -> GetRC ());
    ptr -> SetRC (ptrTmp);
    if (ptr == m_realTail) m_realTail = ptr->GetRC ();
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
    std::shared_ptr<CNode<T>> Ptr (m_fictionaHead->GetRC ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetRC ());
    Ptr->GetLC()->SetRC(Ptr->GetRC());//1st etape

    if(Ptr != m_realTail)
        Ptr->GetRC()->setLC(Ptr->GetLC());//2nd etape
    else
        m_realTail = Ptr->GetLC();

    Ptr->setLC(m_fictionaHead);//etape 3
    Ptr->SetRC(m_fictionaHead -> GetRC());//etape4
    Ptr->GetRC()->setLC(Ptr);//etape5
    m_fictionaHead->SetRC(Ptr);//etape6


    return Ptr;
}



/*template <typename T>
void CList<T>::push_front (const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T> (val, m_fictionaHead->GetRC ()));
    m_fictionaHead->SetRC (tmp);
    if (m_realTail == m_fictionaHead) m_realTail = m_fictionaHead->GetRC ();
}*/

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (std::shared_ptr<CNode<T>> Ptr (m_fictionaHead -> GetRC()); Ptr; Ptr = Ptr->GetRC ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T>> pDelete)
{
    std::shared_ptr<CNode<T>> pFind (m_fictionaHead);
    for ( ; pFind -> GetRC () != pDelete ; pFind = pFind -> GetRC ());

    pFind -> SetRC (pDelete -> GetRC ());
    pDelete -> GetRC() ->setLC(pFind);
    if (pDelete == m_realTail) m_realTail = pFind;
    pDelete -> SetRC (nullptr);
    pDelete -> setLC(nullptr);

 //   delete pDelete;
}

/*template <typename T>
void CList<T>::push_back (const T & val)
{
    std::shared_ptr<CNode<T>> pTmp (new CNode<T> (val, NULL));
    m_realTail -> SetRC (pTmp);
    m_realTail = pTmp;
}

template <typename T>
void CList<T>::AddBefore (const std::shared_ptr<CNode<T>> ptr, const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T>(val, ptr -> GetLC()));
    ptr ->GetLC() ->SetRC(tmp);
    tmp ->SetRC(ptr);
    ptr ->setLC(tmp);

    if(ptr == m_fictionaHead) m_fictionaHead = ptr ->GetLC();

}*/

#endif // LIST_HPP
