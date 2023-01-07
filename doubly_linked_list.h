#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

template<typename E>
class DLinkedList;

template<typename E>
class DNode {
    private:
        E elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList<E>;
};

template<typename E>
class DLinkedList {
    private:
        DNode<E>* header;
        DNode<E>* trailer;
    protected:
        void add(DNode<E>* v, const E&e);
        void remove(DNode<E>* v);
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const E& front() const;
        const E& back() const;
        void addFront(const E& e);
        void addBack(const E& e);
        void removeFront();
        void removeBack();
};

template<typename E>
DLinkedList<E>::DLinkedList() {
    header = new DNode<E>;
    trailer = new DNode<E>;
    header->next = trailer;
    trailer->prev = header;
}

template<typename E>
DLinkedList<E>::~DLinkedList() {
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

template<typename E>
bool DLinkedList<E>::empty() const {
    return (header->next == trailer);
}

template<typename E>
const E& DLinkedList<E>::front() const {
    return header->next->elem;
}

template<typename E>
const E& DLinkedList<E>::back() const {
    return trailer->prev->elem;
}

template<typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e) {
    DNode<E>* u = new DNode<E>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template<typename E>
void DLinkedList<E>::addFront(const E& e) {
    add(header->next, e);
}

template<typename E>
void DLinkedList<E>::addBack(const E& e) {
    add(trailer, e);
}

template<typename E>
void DLinkedList<E>::remove(DNode<E>* v) {
    DNode<E>* w = v->next;
    DNode<E>* u = v->prev;
    u->next = w;
    w->prev = u;
    delete v;
}

template<typename E>
void DLinkedList<E>::removeFront() {
    remove(header->next);
}

template<typename E>
void DLinkedList<E>::removeBack() {
    remove(trailer->prev);
}

#endif