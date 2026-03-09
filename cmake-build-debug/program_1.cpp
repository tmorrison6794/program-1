#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
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
        for (int i=0;i<(int)values.size();i++) {
            if (!addSpace(values[i])) break;
            added++;
        }
        return added;
    }
    void movePlayer(int steps) {
        if (headNode==nullptr) {
            cout<<"Empty Board"<<endl;
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
            cout<<"Empty Board"<<endl;
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
    bool removeByName(string name) {
        if (headNode==nullptr) {
            cout<<"Empty Board"<<endl;
            return false;
        }
        if (headNode==tailNode) {
            if (headNode->data.propertyName==name) {
                delete headNode;
                headNode=nullptr;
                tailNode=nullptr;
                playerNode=nullptr;
                nodeCount--;
                return true;
            }
            return false;
        }
        if (headNode->data.propertyName==name) {
            Node<T>* currentNode=headNode;
            headNode=headNode->nextNode;
            tailNode->nextNode=headNode;
            if (playerNode==currentNode) playerNode=headNode;
            delete currentNode;
            nodeCount--;
            return true;
        }
        Node<T>* prev=headNode;
        Node<T>* currentNode=prev->nextNode;
        while (currentNode!=headNode) {
            if (currentNode->data.propertyName==name) {
                prev->nextNode=currentNode->nextNode;
                if (currentNode==tailNode) tailNode=prev;
                if (playerNode==currentNode) playerNode=prev->nextNode;
                delete currentNode;
                nodeCount--;
                return true;
            }
            prev=currentNode;
            currentNode=currentNode->nextNode;
        }
        return false;
    }
    vector<string> findByColor(string color) {
        vector<string> matches;
        if (headNode==nullptr) {
            return matches;
        }
        Node<T>* currentNode=headNode;
        do {
            if (currentNode->data.propertyColor==color) {
                matches.push_back(currentNode->data.propertyName);
            }
            currentNode=currentNode->nextNode;
        }while (currentNode!=headNode);
        return matches;
    }
    int countSpaces() {
        if (headNode==nullptr) {
            return 0;
        }
        int count=0;
        Node<T>* currentNode=headNode;
        do {
            count++; currentNode=currentNode->nextNode;
        }
        while(currentNode!=headNode);
        return count;
    }
    void clear() {
        if (tailNode!=nullptr){
            tailNode->nextNode=nullptr;
        }
        Node<T>* currentNode=headNode;
        while (currentNode!=nullptr) {
            Node<T>* nextNode=currentNode->nextNode;
            delete currentNode;
            currentNode=nextNode;
        }
        headNode=nullptr;
        tailNode=nullptr;
        playerNode=nullptr;
        nodeCount=0;
        passGoCount=0;
    }
};
int rollDice2to12() {
    return(rand()%6+1)+(rand()%6+1);
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    CircularLinkedList<MonopolySpace> board;
    vector<MonopolySpace> spaces;
    spaces.push_back(MonopolySpace("GO", "NONE", 0,0));
    spaces.push_back(MonopolySpace("MEDITERRANEAN AVE", "BROWN", 60,2));
    spaces.push_back(MonopolySpace("COMMUNITY CHEST", "NONE", 0,0));
    spaces.push_back(MonopolySpace("BALTIC AVE","BROWN",60,4));
    spaces.push_back(MonopolySpace("INCOME TAX", "NONE",0,200));
    spaces.push_back(MonopolySpace("READING RAILROAD", "RAILROAD",200,0));
    spaces.push_back(MonopolySpace("ORIENTAL AVE","LIGHTBLUE",100,6));
    spaces.push_back(MonopolySpace("CHANCE","NONE",0,0));
    spaces.push_back(MonopolySpace("VERMONT AVE","LIGHTBLUE",100,6));
    spaces.push_back(MonopolySpace("CONNECTICUT AVE","LIGHTBLUE",120,8));
    spaces.push_back(MonopolySpace("IN JAIL/JUST VISITING","NONE",0,0));
    spaces.push_back(MonopolySpace("ST. CHARLES PLACE","PINK",140,10));
    spaces.push_back(MonopolySpace("ELECTRIC COMPANY","UTILITY",150,0));
    spaces.push_back(MonopolySpace("STATES AVE","PINK",140,10));
    spaces.push_back(MonopolySpace("VIRGINIA AVE","PINK",160,12));
    spaces.push_back(MonopolySpace("PENNSYLVANIA RAILROAD","RAILROAD",200,0));
    spaces.push_back(MonopolySpace("ST. JAMES PLACE","ORANGE",180,14));
    spaces.push_back(MonopolySpace("COMMUNITY CHEST","NONE",0,0));
    spaces.push_back(MonopolySpace("TENNESSEE AVE","ORANGE",180,14));
    spaces.push_back(MonopolySpace("NEW YORK AVE","ORANGE",200,16));
    spaces.push_back(MonopolySpace("FREE PARKING", "NONE",0,0));
    spaces.push_back(MonopolySpace("KENTUCKY AVE","RED",220,18));
    spaces.push_back(MonopolySpace("CHANCE","NONE",0,0));
    spaces.push_back(MonopolySpace("INDIANA AVE","RED",220,18));
    spaces.push_back(MonopolySpace("ILLINOIS AVE","RED",240,20));
    spaces.push_back(MonopolySpace("B&O RAILROAD","RAILROAD",200,0));
    spaces.push_back(MonopolySpace("ATLANTIC AVE", "YELLOW", 260, 22));
    spaces.push_back(MonopolySpace("VENTNOR AVE","YELLOW",260,22));
    spaces.push_back(MonopolySpace("WATER WORKS","UTILITY",150,0));
    spaces.push_back(MonopolySpace("MARVIN GARDENS","YELLOW",280,24));
    spaces.push_back(MonopolySpace("GO TO JAIL", "NONE",0,0));
    spaces.push_back(MonopolySpace("PACIFIC AVE","GREEN",300,26));
    spaces.push_back(MonopolySpace("NORTH CAROLINA AVE","GREEN",300,26));
    spaces.push_back(MonopolySpace("COMMUNITY CHEST","NONE",0,0));
    spaces.push_back(MonopolySpace("PENNSYLVANIA AVE","GREEN",320,28));
    spaces.push_back(MonopolySpace("SHORT LINE","RAILROAD",200,0));
    spaces.push_back(MonopolySpace("CHANCE","NONE",0,0));
    spaces.push_back(MonopolySpace("PARK PL","BLUE",350,35));
    spaces.push_back(MonopolySpace("LUXURY TAX","NONE",0,100));
    spaces.push_back(MonopolySpace("BOARDWALK","BLUE",400,50));
    board.addMany(spaces);
    for (int turn=1;turn<=10;turn++) {
        int roll=rollDice2to12();
        cout<<"\nTurn "<<turn<<" | Rolled: "<<roll<<endl;
        board.movePlayer(roll);
        cout<<"Board view from player (next 5 spaces):" <<endl;
        board.printFromPlayer(5);
        cout<<"Times passed GO so far:"<<board.getPassGoCount()<<endl;
    }
    board.removeByName("MEDITERRANEAN AVE");
    vector<string> pinkProps=board.findByColor("PINK");
    cout<<"\nPink properties:"<<endl;
    for (int i=0;i<(int)pinkProps.size();i++) {
        cout<<" -"<<pinkProps[i]<<endl;

    }
    return 0;
}







