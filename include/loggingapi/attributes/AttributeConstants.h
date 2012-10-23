//
//  AttributeConstants.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTECONSTANTS_H_
#define INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTECONSTANTS_H_

#include <string>

namespace loggingapi {
namespace attributes {

// Standard attributes names
static const std::string kMESSAGE_ATTRIBUTE_NAME = "message";
static const std::string kSEVERITY_ATTRIBUTE_NAME = "severity";
static const std::string kFILE_ATTRIBUTE_NAME = "file";
static const std::string kLINENUMBER_ATTRIBUTE_NAME = "lineNumber";

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_ATTRIBUTES_ATTRIBUTECONSTANTS_H_
