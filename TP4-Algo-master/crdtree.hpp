#ifndef CRDTREE_HPP
#define CRDTREE_HPP
#include <iostream>
#include "node.hpp"
#include <memory>

template <typename T>
class CRDTree
{
private:
    std::shared_ptr<CNode<T>> m_Racine;
public:
    CRDTree(const T &  val = T());
    std::shared_ptr<CNode<T> > GetRacine() const;
    void setRacine(const std::shared_ptr<CNode<T> > &Racine);
    void Show(const std::shared_ptr<CNode<T>> &) const;
    void Add(const T & val, std::shared_ptr<CNode<T>> & tmp);
};

template <typename T>
std::shared_ptr<CNode<T> > CRDTree<T>::GetRacine() const
{
    return m_Racine;
}

template <typename T>
void CRDTree<T>::setRacine(const std::shared_ptr<CNode<T> > &Racine)
{
    m_Racine = Racine;
}

template<typename T>
void CRDTree<T>::Add(const T &val, std::shared_ptr<CNode<T>> & tmp)
{
    tmp = m_Racine;

    if (! tmp->GetLC())
    {
      tmp->setLC(std::shared_ptr<CNode<T>>(new CNode (val)));
      return;
    }

    else if(! tmp->GetRC())
    {
       tmp->setRC(std::shared_ptr<CNode<T>>(new CNode (val)));
       return;
    }

    else
    {
        int i = (rand() %2);
        if (i == 0)
        {
            Add(val ,tmp->GetLC());
        }
        else
        {
            Add(val ,tmp->GetRC());
        }
    }
}

template <typename T>
CRDTree<T>::CRDTree(const T & val) : m_Racine(new CNode<T>(val, nullptr, nullptr)){}

template <typename T>
CRDTree<T>::Show(const std::shared_ptr<CNode<T>> & Racine) const
{
    if (m_Racine->GetLC())
        Show (m_Racine->GetLC());

    cout << m_Racine->GetData();

    if (Racine->GetRC())
        Show (m_Racine->GetRC());
}











































































#endif // CRDTREE_HPP
