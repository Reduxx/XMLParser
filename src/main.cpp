//
// Created by Simon Sperling on 22.07.15.
//

#include <iostream>
#include "XMLClass.h"

using namespace std;


void load_users() {
}


int main() {
    cout << "Welcome to the program!\n" << endl;
    cout << "---------------------------" << endl;
    cout << "| XML Parser              |" << endl;
    cout << "| © 2015 Simon Sperling   |" << endl;
    cout << "---------------------------\n" << endl;
    string end = "<DUCKS>";
    XMLClass x;
    x.loadXML("res/xml/DUCKS.xml");
    x.changeLine(0, "<DUCKS>");
    x.helper();
    x.saveXML("res/xml/DUCKS.xml");
    //x.printXML();

    return 0;
}