//
// Created by Simon Sperling on 22.07.15.
//

#ifndef XMLPARSER_XMLCLASS_H
#define XMLPARSER_XMLCLASS_H

#include <array>
#include <string>
#include <vector>

class XMLClass {
public:
    XMLClass(const char* file);
    void loadXML(const char* file);
    void saveXML(const char* file);
    void changeLine(int line, std::string s);
    void createNodes();
    void printXML();
    std::string endTag(std::string s);
private:
    std::vector<std::string> xmlVector;

    class XMLNode {
        std::vector<XMLNode> children;
        std::string content;
        int startLine = 0;
        int endLine = 0;
        int depth;
        std::vector< std::vector<std::string> > params;
    public:
        XMLNode() { }
        void setStartLine(int startline);
        void setEndLine(int endline);
        int getStartLine();
        int getEndLine();
        void setDepth(int d);
        int getDepth();
    };

    class XMLNodeList {
    private:
        std::vector<XMLNode*> children;
    public:
        XMLNodeList() { }
        ~XMLNodeList() { }
        void push(XMLNode *node);

        void printList();
    };
};


#endif //XMLPARSER_XMLCLASS_H
