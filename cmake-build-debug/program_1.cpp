#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<ctime>
using namespace std;


static const int MAX_SPACES=40;


class MonopolySpace {
    public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        propertyName="";
        propertyColor="";
        value=0;
        rent=0;
    }
    MonopolySpace(string propertyName,string propertyColor,int value, int rent) {
        this->propertyName=propertyName;
        this->propertyColor=propertyColor;
        this->rent=rent;
        this->value=value;
    }
    bool isEqual(MonopolySpace other) {
        return propertyName==other.propertyName && propertyColor==other.propertyColor && rent==other.rent;
    }
    void print() {
        cout<<propertyName<< "|" <<propertyColor << "|$"<<value<<"| Rent $"<< rent;
    }

};
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;
    Node(T value) {
        data=value;
        nextNode=nullptr;
    }
};
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    Node<T>*playerNode;
    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode=nullptr;
        tailNode=nullptr;
        playerNode=nullptr;
        nodeCount=0;
        passGoCount=0;
    }


    bool addSpace(T value) {
        if (nodeCount==MAX_SPACES) {
            cout<<"Max space reached"<<endl;
            return false;
        }
        Node<T>* newNode = new Node<T>(value);
        if (headNode==nullptr) {
            headNode=newNode;
            tailNode=headNode;
            playerNode=newNode;
            newNode->nextNode=headNode;
        }else {
            tailNode->nextNode=newNode;
            newNode->nextNode=headNode;
            tailNode=newNode;
        }
        nodeCount++;
        return true;
    }

    int addMany(vector<T> values) {
        if (values.size()==0) {
            cout<<"Empty vector"<<endl;
        }
        int added=0;
        for (int i=0;i<values.size();i++) {
            if (!addSpace(values[i])) break;
            added++;
        }
        return added;
    }
    void movePlayer(int steps) {
        if (headNode==nullptr) {
            cout<<"movePlayer unwritten"<<endl;
            return;
        }
        for (int i=0;i<steps;i++) {
            playerNode=playerNode->nextNode;
            if (playerNode==headNode) {
                passGoCount++;
            }
        }
    }
    int getPassGoCount() {
        return passGoCount;
    }
    void printFromPlayer(int count) {
        if (playerNode==nullptr) {
            cout<<"printFromPlayer unwritten"<<endl;
            return;
        }
        int limit=(count<MAX_SPACES)?count:MAX_SPACES;
        Node<T>* currentNode=playerNode;
        for (int i=0;i<limit;i++) {
            cout<<"["<<i+1<<"]";
            currentNode->data.print();
            cout<<endl;
            currentNode=currentNode->nextNode;
        }
    }