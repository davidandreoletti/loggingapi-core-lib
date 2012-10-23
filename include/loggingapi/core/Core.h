//
//  Core.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_CORE_CORE_H_
#define INCLUDE_LOGGINGAPI_CORE_CORE_H_

#include <vector>
#include <string>

namespace loggingapi {
namespace loggers {class LoggerInterface;}

namespace core {

    /**
     * Wrapper containing loggers
     * Created only to ease memory management
     */
class LoggersContainerWrapper {
 public:
   /**
    * Destructor
    */
    ~LoggersContainerWrapper();

    /**
     * Registered loggers
     */
    std::vector<loggers::LoggerInterface*> loggers_;
};

/**
 *  Logging Core
 */
class Core {
 public:
    /**
     * Destructor
     */
    ~Core();

    /**
     * See LoggingAPI::getLogger(const std::string&)
     */
    static loggers::LoggerInterface* getLogger(const std::string& name);
    /**
     * See LoggingAPI::addLogger(LoggerInterface&)
     */
    static bool addLogger(loggers::LoggerInterface* logger);
    /**
     * See LoggingAPI::removeLogger(const std::string&)
     */
    static loggers::LoggerInterface* removeLogger(const std::string& name);

 private:
    /**
     * Registered loggers
     */
    static LoggersContainerWrapper loggersW_;
};



}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_CORE_CORE_H_
