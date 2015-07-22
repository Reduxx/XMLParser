//
// Created by Simon Sperling on 22.07.15.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "XMLClass.h"


XMLClass::XMLClass(const char* file) {
    loadXML(file);
    createNodes();

}

void XMLClass::loadXML(const char* file) {
    // create input stream for file or load file
    std::ifstream d_file(file);
    // define a string for current line
    std::string line;

    // as long as the end of the file isn't reached, the next line will be copied in line
    while( std::getline( d_file, line ) ) {
        // line is pushed to our vector
        this->xmlVector.push_back( line );
    }

// d_file closes automatically if the function is left
}


void XMLClass::saveXML(const char* file) {
    std::ofstream output_file(file);
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(this->xmlVector.begin(), this->xmlVector.end(), output_iterator);
}

void XMLClass::printXML() {
    // get line count from vector size
    std::size_t line_count = this->xmlVector.size();
    //iterate over the vector lines and cout them
    for( std::size_t i = 0; i < line_count; ++i ) {
        std::cout << i << "    " << this->xmlVector[i] << std::endl;
    }
}

void XMLClass::changeLine(int line, std::string s) {
    this->xmlVector[line] = s;
}

void XMLClass::createNodes() {

    std::vector<std::vector<std::string>> test;
    std::string tempOuter, tempInner;
    std::string endTagString;
    int depth = 0;
    XMLNode* node;
    node = new XMLNode;
    XMLNodeList* nodeList = new XMLNodeList;

    // get line count from vector size
    std::size_t line_count = this->xmlVector.size();
    //iterate over the vector lines and cout them
    for( std::size_t i = 0; i < line_count; ++i ) {
        if(node->getEndLine() > (int) i) {
            node->setDepth(depth++);
        }
        node = new XMLNode;
        tempOuter = this->xmlVector[i];
        // skip if is closing tag
        if(tempOuter.substr(0,5).find("/") != std::string::npos) {
            continue;
        }
        //this->xmlVector[i] = std::regex_replace(this->xmlVector[i], std::regex("^ +| +$|( ) +"), "$1");
        std::cout << i << ": " << tempOuter << std::endl;
        node->setStartLine((int) i);
        endTagString = endTag(tempOuter).substr(0,5);
        for( std::size_t j = i; j < line_count; ++j ) {
            tempInner = this->xmlVector[j];
            if(tempInner.find(endTagString) != std::string::npos) {
                std::cout << j << ": " << tempInner << std::endl;
                node->setEndLine((int) j);
                depth--;
                break;
            }
        }
        nodeList->push(node);
    }
    nodeList->printList();
}

std::string XMLClass::endTag(std::string s) {
    std::string endTagString;
    endTagString = std::regex_replace(s, std::regex("<"), "</");
    return endTagString;
}

void XMLClass::XMLNode::setStartLine(int startline) {
    this->startLine = startline;
}

void XMLClass::XMLNode::setEndLine(int endline) {
    this->endLine = endline;
}

void XMLClass::XMLNodeList::push(XMLClass::XMLNode *node) {
    this->children.push_back(node);
}

void XMLClass::XMLNodeList::printList() {
    std::size_t line_count = this->children.size();
    //iterate over the vector lines and cout them
    for( std::size_t i = 0; i < line_count; ++i ) {
        std::cout << "S-line: " << this->children[i]->getStartLine() << std::endl;
        std::cout << "E-line: " << this->children[i]->getEndLine() << std::endl;
        std::cout << "Depth : " << this->children[i]->getDepth() << std::endl;
    }
}

int XMLClass::XMLNode::getEndLine() {
    return this->endLine;
}

int XMLClass::XMLNode::getStartLine() {
    return this->startLine;
}

void XMLClass::XMLNode::setDepth(int d) {
    this->depth = d;
}

int XMLClass::XMLNode::getDepth() {
    return this->depth;
}
