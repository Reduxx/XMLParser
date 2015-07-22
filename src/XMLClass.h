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
    void loadXML(const char* file);
    void saveXML(const char* file);
    void changeLine(int line, std::string s);
    std::string endTag(std::string s);
    void helper();
    void printXML();
private:
    std::vector<std::string> xmlVector;

    class XMLNode {
    private:
    public:
        int startTag;
        int endTag;
        XMLNode();

    private:
        std::string content;
        std::vector< std::vector<std::string> > params;
    };
};


#endif //XMLPARSER_XMLCLASS_H
