//
//  Core.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "loggingapi/core/Core.h"
#include "loggingapi/loggers/LoggerInterface.h"

namespace loggingapi {
namespace core {

void deletePointedToLoggerObject(loggers::LoggerInterface* p) {
    delete p;
    p = NULL;
}

LoggersContainerWrapper::~LoggersContainerWrapper() {
    // Delete pointed-to filters object
    std::for_each(this->loggers_.begin(),
                  this->loggers_.end(),
                  deletePointedToLoggerObject);
}

LoggersContainerWrapper Core::loggersW_;

/**
 * Function object to find a logger with requested name
 */
struct FindLoggerWithName : public std::binary_function<loggers::LoggerInterface*,  // NOLINT(whitespace/line_length)
                                                        std::string&, bool> {
    /**
         * Finds a logger with requested name
         * @param a Logger instance 
         * @param name Requested name
         * @return True if logger has requested name
         */
    bool operator()(loggers::LoggerInterface* a, const std::string& name) const {  // NOLINT(whitespace/line_length)
       return name.compare(a->getName()) == 0;
    }
};

loggers::LoggerInterface* Core::getLogger(const std::string& name) {
    std::vector<loggers::LoggerInterface*>::iterator it;
    it = std::find_if(Core::loggersW_.loggers_.begin(),
                      Core::loggersW_.loggers_.end(),
                      std::bind2nd(FindLoggerWithName(), name));
    if (it != Core::loggersW_.loggers_.end()) {
        return *it;
    }
    return NULL;
}

bool Core::addLogger(loggers::LoggerInterface* logger) {
    if (logger == NULL) {return false;}
    std::vector<loggers::LoggerInterface*>::iterator it;
    it = std::find_if(Core::loggersW_.loggers_.begin(),
                      Core::loggersW_.loggers_.end(),
                      std::bind2nd(FindLoggerWithName(), logger->getName()));
    if (it == Core::loggersW_.loggers_.end()) {
        Core::loggersW_.loggers_.push_back(logger);
        return true;
    }
    return false;
}

loggers::LoggerInterface* Core::removeLogger(const std::string& name) {
    std::vector<loggers::LoggerInterface*>::iterator it;
    it = std::find_if(Core::loggersW_.loggers_.begin(),
                      Core::loggersW_.loggers_.end(),
                      std::bind2nd(FindLoggerWithName(), name));
    if (it != Core::loggersW_.loggers_.end()) {
        Core::loggersW_.loggers_.erase(it);
        return *it;
    }
    return NULL;
}

}}  // namespaces
