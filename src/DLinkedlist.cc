#include <iostream>
#include <cstdlib>
#include "../include/DLinkedlist.h"

DLinkedlist::DLinkedlist()
{
    head = nullptr;
    queue = nullptr;
}

void DLinkedlist::add_node(int value)
{

    s_node *new_node = new s_node;
    new_node->value = value;
    new_node->marked = false;
    if (!head)
    {
        new_node->next = nullptr;
        new_node->previous = nullptr;
        head = queue = new_node;
        std::cout << "tete: " << head->value << std::endl;
    }
    else
    {
        s_node *tmp = head;
        while (tmp->marked == false && tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        if (tmp == queue)
        {
            tmp = new_node;
            tmp->previous = queue;
            tmp->next = nullptr;
            queue->next = tmp;
            queue = tmp;
        }
        else
        {
            tmp->value = value;
            tmp->marked = false;
        }
    }
}

Iterator DLinkedlist::find_node(int value)
{
    s_node *tmp = nullptr;
    Iterator it;
    if (!head)
        return it;
    tmp = head;
    while (tmp)
    {
        if (tmp->value == value)
            break;
        tmp = tmp->next;
    }
    it.elm = tmp;
    return it;
}

void DLinkedlist::delete_node(Iterator &it)
{
    if (it.elm == nullptr)
        return;
    it.elm->marked = true;
}

void DLinkedlist::compact_list()
{
    if (!head)
        return;
    s_node *tmp = head;
    s_node *pt = head;
    while (pt)
    {
        pt = tmp->next;
        if (tmp->marked == true)
        {
            if (tmp == head && tmp == queue)
            {
                head = nullptr;
                queue = nullptr;
                delete (tmp);
                delete (pt);
                return;
            }
            if (tmp == head)
            {
                tmp = head->next;
                head = tmp;
                head->previous = nullptr;
            }
            else if (tmp == queue)
            {
                queue = tmp->previous;
                queue->next = nullptr;
            }
            else
            {
                if (tmp->next && tmp->previous)
                {
                    tmp->previous->next = tmp->next;
                    tmp->next->previous = tmp->previous;
                }
            }
        }
        tmp = pt;
    }
    delete (tmp);
    delete (pt);
}

void DLinkedlist::visit_list()
{
    std::cout << "[";
    for (Iterator it = DLinkedlist::begin(); it != DLinkedlist::end(); ++it)
    {
        std::cout << "(";
        it.get();
        std::cout << ") ";
    }
    std::cout << "]";
}

Iterator DLinkedlist::begin()
{
    cur.elm = head;

    /*À décommenter si on ne veut pas du tout afficher la tête si elle est marquée. On sautera alors l'élement marqué.
       Ceci a été commenté pour pouvoir prendre en charge l'affichage des éléments marqués avec une tête de mort.
    if (cur.elm->marked == true)
    {
        while (cur.elm->marked == true and cur.elm)
        {
            cur.elm = cur.elm->next;
        }
    }*/
    return cur;
}

Iterator DLinkedlist::end()
{
    Iterator it;
    return it;
}

bool Iterator::operator==(const Iterator &source) const
{
    if (elm == source.elm)
        return 1;
    return 0;
}

bool Iterator::operator!=(const Iterator &source) const
{
    if (elm != source.elm)
        return 1;
    return 0;
}

Iterator Iterator::operator++()
{
    if (!elm)
        return *this;
    elm = elm->next;
    /*Éventuellement si on ne veut pas du tout afficher les éléments marqués. On sautera alors les éléments marqués.
      Ceci a été commenté pour pouvoir prendre en charge l'affichage des éléments marqués avec une tête de mort.
    if (elm)
    {
        if (elm->marked == true)
        {
            if (elm->next)
            {
                while (elm->marked == true and elm)
                {
                    elm = elm->next;
                }
            }
            else
            {
                elm = elm->next;
            }
        }
    }
    */
    cur.elm = elm;
    return cur;
}

Iterator Iterator::operator++(int)
{
    if (!elm)
        return *this;
    elm = elm->next;
    /*À décommenter si on ne veut pas du tout afficher les éléments marqués. On sautera alors les éléments marqués.
      Ceci a été commenté pour pouvoir prendre en charge l'affichage des éléments marqués avec une tête de mort.
    if (elm)
    {
        if (elm->marked == true)
        {
            if (elm->next)
            {
                while (elm->marked == true and elm)
                {
                    elm = elm->next;
                }
            }
            else
            {
                elm = elm->next;
            }
        }
    }
    */
    cur.elm = elm;
    return cur;
}

Iterator Iterator::operator--()
{
    if (!elm)
        return *this;
    elm = elm->next;
    /*À décommenter si on ne veut pas du tout afficher les éléments marqués. On sautera alors les éléments marqués.
      Ceci a été commenté pour pouvoir prendre en charge l'affichage des éléments marqués avec une tête de mort.
    if (elm)
    {
        if (elm->marked == true)
        {
            if (elm->next)
            {
                while (elm->marked == true and elm)
                {
                    elm = elm->previous;
                }
            }
            else
            {
                elm = elm->previous;
            }
        }
    }
    */
    cur.elm = elm;
    return cur;
}

Iterator Iterator::operator--(int)
{
    if (!elm)
        return *this;
    elm = elm->next;
    /*À décommenter si on ne veut pas du tout afficher les éléments marqués. On sautera alors les éléments marqués.
      Ceci a été commenté pour pouvoir prendre en charge l'affichage des éléments marqués avec une tête de mort.
    if (elm)
    {
        if (elm->marked == true)
        {
            if (elm->next)
            {
                while (elm->marked == true and elm)
                {
                    elm = elm->previous;
                }
            }
            else
            {
                elm = elm->previous;
            }
        }
    }
    */
    cur.elm = elm;
    return cur;
}

int Iterator::get()
{
    std::cout << cur.elm->value;
    if (cur.elm)
    {
        if (cur.elm->marked)
        {
            std::cout << "☠";
        }
        else
        {
            std::cout << "😀";
        }
    }
    return -1;
}

Iterator::Iterator() : elm(nullptr) { ; }
