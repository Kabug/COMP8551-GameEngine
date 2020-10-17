#pragma once


#include <string>
#include <vector>
#include "../logger.h"
#include <cstring>
#include <fstream>
#include <iostream>

#include "../CScript.h"
#include "../Components/Components.h"
#include "tinyxml2.h"

using namespace tinyxml2;
struct CustomScript
{
    public:
        CustomScript(string xmlFile) {

            doc = new TinyXMLDocument();
            XMLError xmlerr = doc->LoadFile(xmlFile.c_str());
            if (xmlerr != XML_SUCCESS)
            {
                Logger::getInstance() << "Could not read game object XML file!\n";
                return;
            }
            root = doc->FirstChildElement("root");
        }

        XMLElement* getUpdate() {
            return root->FirstChildElement("update");
        }

        ~CustomScript() {
            delete doc;
        }

    private:
        TinyXMLDocument* doc;
        XMLElement* root;
        string xml;

        // User Generated Variables <varible name, variable value>
        unordered_map<std::string, int> ints;
        unordered_map<std::string, float> floats;
        unordered_map<std::string, double> doubles;
        unordered_map<std::string, std::string> strings;
        unordered_map<std::string, bool> bools;
};
