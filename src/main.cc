#include <iostream>
#include "../include/DLinkedlist.h"

int interface()
{
    char choix;
    std::cout << "Menu Double liste chainée" << std::endl;
    std::cout << "Veuillez entrez une option" << std::endl;
    std::cout << "[1] Insérer une valeur dans la liste" << std::endl;
    std::cout << "[2] Supprimer une valeur de la liste" << std::endl;
    std::cout << "[3] Lister les valeurs contenues dans la liste" << std::endl;
    std::cout << "[4] Lancer la compaction" << std::endl;
    do
    {
        std::cin >> choix;
    } while (choix > '4' || choix < '1');
    return choix;
}

int main()
{
    char choix;
    int valeur;
    DLinkedlist d_linked_list;
    while (true)
    {
        choix = interface();
        switch (choix)
        {
        case '1':
            std::cout << "Entrez la valeur à ajouter" << std::endl;
            std::cin >> valeur;
            d_linked_list.add_node(valeur);
            break;
        case '2':
        {
            std::cout << "Entrez la valeur à supprimer" << std::endl;
            std::cin >> valeur;
            Iterator tmp;
            tmp = d_linked_list.find_node(valeur);
            d_linked_list.delete_node(tmp);
            break;
        }
        case '3':
            d_linked_list.visit_list();
            break;
        case '4':
            d_linked_list.compact_list();
            break;
        default:
            return 0;
        }
        std::cout << std::endl;
    }
    return 0;
}