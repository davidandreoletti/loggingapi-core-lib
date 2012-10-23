//
//  Formatter.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include "loggingapi/formatters/Formatter.h"
#include "loggingapi/attributes/AttributeConstants.h"
#include "loggingapi/attributes/AttributeInterface.h"
#include "loggingapi/attributes/AttributeValueInterface.h"
#include "loggingapi/records/RecordInterface.h"


namespace loggingapi {
namespace formatters {

void deletePointedToObject(attributes::AttributeInterface* p) {
    delete p;
    p = NULL;
}

Formatter::~Formatter() {
    // Delete pointed-to attributes objects
    std::for_each(this->attrs_.begin(),
                  this->attrs_.end(),
                  deletePointedToObject);
}

std::string Formatter::format(const records::RecordInterface* r) const {
    if (r == NULL) {return "";}

    typedef ::loggingapi::attributes::AttributeInterface AttrI;
    typedef ::loggingapi::attributes::AttributeValueInterface AttrVI;
    namespace attributeNS = ::loggingapi::attributes;

    std::string s;
    std::vector<std::string> attrKeys;
    attrKeys.push_back(attributeNS::kFILE_ATTRIBUTE_NAME);
    attrKeys.push_back(attributeNS::kLINENUMBER_ATTRIBUTE_NAME);
    attrKeys.push_back(attributeNS::kSEVERITY_ATTRIBUTE_NAME);
    attrKeys.push_back(attributeNS::kMESSAGE_ATTRIBUTE_NAME);
    int attrKeysCount = attrKeys.size();
    for (int i = 0; i < attrKeysCount; ++i) {
        AttrI* attr = r->getAttribute(attrKeys.at(i));
        if (attr != NULL) {
            AttrVI* attrV = attr->getValue();
            if (attrV != NULL) {
                if (i > 0) {s.append(" : ");}
                s.append(attrV->getValueAsString());
            }
        }
    }
    return s;
}

}}  // namespaces
