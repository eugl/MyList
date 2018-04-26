#ifndef MYLIST_H
#define MYLIST_H

template <typename dType>
class MyList
{
    struct node{
        node *next;
        node *prev;
        dType val;
    };

    struct nList{
        node *head;
        node *tail;
    };

    nList *myList;
    int len;
    node *elementAt(int index);

    public:
        MyList();
        ~MyList();
        void pushFront(dType val);
        void pushBack(dType val);
        void popFront();
        void popBack();
        int length();
        dType valAt(int index);
        int indexOf(dType val);
        void insertEl(int index, dType val);
        void eraseEl(int index);
};


#endif // MYLIST_H
