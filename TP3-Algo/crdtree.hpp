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
    void Show(const std::shared_ptr<CNode<T>> Racine);
};

template <typename T>
std::shared_ptr<CNode<T> > CRDTree::GetRacine() const
{
    return m_Racine;
}

void CRDTree::setRacine(const std::shared_ptr<CNode<T> > &Racine)
{
    m_Racine = Racine;
}

CRDTree<T>::CRDTree(const T & val) : m_Racine(new CNode<T>(val, nullptr, nullptr)){}

template <typename T>
CRDTree<T>::Show(const std::shared_ptr<CNode<T>> Racine)
{
    if (m_Racine->GetLC())
        EditerArbre (m_Racine->GetGauche());

    cout << m_Racine->GetData();

    if (Racine->GetRC())
        EditerArbre (m_Racine->GetRC());
}











































































#endif // CRDTREE_HPP
