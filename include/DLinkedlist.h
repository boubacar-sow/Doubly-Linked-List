/* ---------------------------------------------------------
   Implémentation d'une liste doublement chainée avec un
   itérateur.
   Fichier de définitions de classes et types utiles.
   ---------------------------------------------------------
   09/03/22	BOubacar SOW	création
   ---------------------------------------------------------
*/
#pragma once

/*Structure réprésentant un noeud*/
typedef struct node
{
    int value;
    struct node *previous;
    struct node *next;
    bool marked;
} s_node;

/*Classe utilitaire qui réprésente un itérateur*/
class Iterator
{
private:
    s_node *elm;
    friend class DLinkedlist;

public:
    typedef Iterator iter;
    Iterator(); // Constructeur de la classe Itérateur
    int get();
    iter operator++(); // Méthode pour incrémenter l'itérateur
    iter operator++(int);
    iter operator--(); // Méthode pour décrémenter l'itérateur
    iter operator--(int);
    bool operator==(const iter &) const; // Surcharge de l'opérateur == pour comparer l'itérateur
    bool operator!=(const iter &) const; // Surcharge de l'opérateur != pour comparer l'itérateur
};

//objet static qui permet de retourner un itérateur. Son attribut
static Iterator cur; 
/*Classe qui représente une liste doublement chainée*/
class DLinkedlist
{

private:
    s_node *head;  // Pointeur sur la tête de la liste
    s_node *queue; // Pointeur sur la fin de la liste
    friend class Iterator;

public:
    /*Constructeur de la liste doublement chainée*/
    DLinkedlist();

    /*
    Ajout d'une valeur dans la liste. Un noeud sera inséré
    soit au premier noeud marqué libre ou alors à la fin (au début si elle vide)
    de la liste
    */
    void add_node(int value);

    /*
    Recherche d'un noeud dans la liste, renvoie un itérateur sur le
    noeud trouvé
    */
    Iterator find_node(int value);

    /*
    Suppression d'un noeud de la liste. Le oeud ne sera pas libéré
    Il sera juste marqué comme libre et sera donc utilisé pour une
    prochaine insertion dans liste
    */
    void delete_node(Iterator &);

    /*
    Compactage de la liste. Tous les noeuds marqués libres seront alors libérés.
    La prochaine insertion se fera à la fin de la liste.
    */
    void compact_list();

    /*
    Parcours de la liste grace à un itérateur. Les noeuds marqués comme libre
    pourront étre sautés.
    */
    void visit_list();

    /*
    Méthode qui initialise l'itérateur sur la liste
    */
    Iterator begin();

    /*
    Méthode qui permet d'arréter l'itérateur lorsqu'il sera égal à la valeur
    retournée par elle
    */
    Iterator end();
};