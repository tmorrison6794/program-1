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

};