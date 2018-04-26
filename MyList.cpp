#include "MyList.h"
#include <stddef.h>
#include <iostream>
#include <string>

using namespace std;

//constructor
template <typename dType>
MyList<dType>::MyList()
{
    myList = new nList;
    myList->head = NULL;
    myList->tail = NULL;
    len = 0;
}

//destructor
template <typename dType>
MyList<dType>::~MyList()
{
    while (myList->head!=NULL){
        popFront();
    }
    delete myList;
}

//get element from list
template <typename dType>
typename MyList<dType>::node *MyList<dType>::elementAt(int index)
{
    if (index>=len || index<0){
        cout << "Index out of range!";
        throw NULL;
    }
    if (index<len/2){
        node *temp = myList->head;
        int i=0;
        while(i<index){
            temp = temp->next;
            i++;
        };
        return temp;
    } else {
        node *temp = myList->tail;
        int i=len-1;
        while(i>index){
            temp = temp->prev;
            i--;
        };
        return temp;
    }
}

//add element on front of the list
template <typename dType>
void MyList<dType>::pushFront(dType val)
{
    if (myList->head == NULL){
        myList->head = new node;
        myList->tail = myList->head;
        myList->head->prev = NULL;
        myList->head->next = NULL;
        myList->head->val = val;
    } else{
        myList->tail->next = new node;
        node *temp = myList->tail;
        myList->tail = myList->tail->next;
        myList->tail->prev = temp;
        myList->tail->next = NULL;
        myList->tail->val = val;
    }
    len++;
}

//add element to the end of list
template <typename dType>
void MyList<dType>::pushBack(dType val)
{
    if (myList->head == NULL){
        myList->head = new node;
        myList->tail = myList->head;
        myList->head->prev = NULL;
        myList->head->next = NULL;
        myList->head->val = val;
    } else{
        myList->head->prev = new node;
        node *temp = myList->head;
        myList->head = myList->head->prev;
        myList->head->next = temp;
        myList->head->prev = NULL;
        myList->head->val = val;
    }
    len++;
}

//delete element from the front of list
template <typename dType>
void MyList<dType>::popFront()
{
    if (myList->head==NULL){
        return;
    }
    if (myList->head==myList->tail){
        delete myList->head;
        myList->head = myList->tail = NULL;
        len--;
        return;
    }
    myList->head = myList->head->next;
    delete myList->head->prev;
    myList->head->prev = NULL;
    len--;
}

//delete element from end of the list
template <typename dType>
void MyList<dType>::popBack()
{
    if (myList->head==NULL){
        return;
    }
        if (myList->head==myList->tail){
        delete myList->head;
        myList->head = myList->tail = NULL;
        len--;
        return;
    }
    myList->tail = myList->tail->prev;
    delete myList->tail->next;
    myList->tail->next = NULL;
    len--;
}

//return list length
template <typename dType>
int MyList<dType>::length()
{
    return len;
}


//return value of element
template <typename dType>
dType MyList<dType>::valAt(int index)
{
    node *temp = elementAt(index);
    return temp->val;
}


//insert element before element number index
template <typename dType>
void MyList<dType>::insertEl(int index, dType val)
{
    if (index==0){
        pushFront(val);
        return;
    }
    if (index==len+1){
        pushBack(val);
        return;
    }
    node *temp = elementAt(index);
    node *tempPrev = temp->prev;
    tempPrev->next = new node;
    tempPrev->next->val = val;
    temp->prev = tempPrev->next;
    tempPrev->next->next = temp;
    tempPrev->next->prev = tempPrev;
    len++;
}

//erase element
template <typename dType>
void MyList<dType>::eraseEl(int index)
{
    node *temp = elementAt(index);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    len--;
}



template class MyList<int>;
template class MyList<float>;
template class MyList<double>;
template class MyList<string>;
template class MyList<char>;

