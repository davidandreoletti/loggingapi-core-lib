//
//  FileSink.h
//  libloggingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_SINKS_FILESINK_H_
#define INCLUDE_LOGGINGAPI_SINKS_FILESINK_H_

#include <string>
#include <fstream>  //  NOLINT(readability/streams)
#include "loggingapi/sinks/SinkInterface.h"

namespace loggingapi {
namespace sinks {

/**
 *  A sink to file
 */
class FileSink : public sinks::SinkInterface {
 public:
     // Inherits from SinkInterface
    virtual void log(records::RecordInterface* r);
    virtual std::string getName();
    virtual void setName(std::string name);
    virtual void setFormatter(formatters::FormatterInterface* f);

    /**
     *  Constructor. Opens files in std::ios::out | std::ios::ate mode.
     *  \param fPath File path. File path validaity is NOT checked
     */
    explicit FileSink(const std::string fPath);

    /**
     *  Destructor
     */
    virtual ~FileSink();

 private:
     /**
      * File path to write logs to
      */
    std::string filePath_;

     /**
      * File object for filePath_
      */
    std::ofstream file_;

    /**
     Sink name*/
    std::string name_;

    /**
     * SInk record formatter
     */
    formatters::FormatterInterface* formatter_;
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_SINKS_FILESINK_H_
