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
    void Show(const std::shared_ptr<CNode<T>> &) const;
public:
    CRDTree(const T &  val = T());
    void Show();
    void Add(const T & val, std::shared_ptr<CNode<T>> tmp);
};


template<typename T>
void CRDTree<T>::Add(const T &val, std::shared_ptr<CNode<T>> tmp)
{
    if (val < tmp->GetData ()){
        if (tmp->GetLC () == nullptr)
            tmp->SetLC (std::shared_ptr<CNode<T>> (new CNode<T>(val)));
        else
            Add(val, tmp ->GetLC());
    }

    else if (val > tmp->GetData()){
        if (tmp->GetRC() == nullptr)
            tmp->SetRC(std::shared_ptr<CNode<T>> (new CNode<T>(val)));
        else
                Add(val, tmp ->GetRC());
    }


}

template <typename T>
CRDTree<T>::CRDTree(const T & val) : m_Racine(new CNode<T>(val)){}

template <typename T>
void CRDTree<T>::Show(const std::shared_ptr<CNode<T>> & ) const
{
    if (m_Racine->GetLC())
        Show (m_Racine->GetLC());

    std::cout << m_Racine->GetData();

    if (m_Racine->GetRC())
        Show (m_Racine->GetRC());
}

template <typename T>
void CRDTree<T>::Show(){
    Show(m_Racine);
}









































































#endif // CRDTREE_HPP
