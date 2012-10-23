//
//  Logger.h
//  libloggingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_LOGGERS_LOGGER_H_
#define INCLUDE_LOGGINGAPI_LOGGERS_LOGGER_H_
#include <string>
#include <vector>
#include "loggingapi/loggers/LoggerInterface.h"
#include "loggingapi/criteria/CriteriaChecker.h"

namespace loggingapi {
namespace attributes { class AttributeInterface; }
namespace sinks { class SinkInterface; }

class RecordInterface;

namespace loggers {

/**
 *  A logger
 */
class Logger : public LoggerInterface {
 public:
    // Inherited from LoggerInterface
    virtual std::string getName() const;
    virtual void setName(std::string name);
    virtual attributes::AttributeInterface* getFilter(const std::string& name) const;  // NOLINT(whitespace/line_length)
    virtual bool addFilter(attributes::AttributeInterface* filter);
    virtual attributes::AttributeInterface* removeFilter(const std::string& name);  // NOLINT(whitespace/line_length)
    virtual void log(const records::RecordInterface* record);

    /**
     * Adds a sink
     * @param s Sink to add. SInk not added if logger already contains this sink. Caller does NOT own the pointer if successfully added.
     * @return True if sink is added
     */
    virtual bool addSink(sinks::SinkInterface* s);

    /**
     * Gets a sink
     * @param name Sink name to retrieve. Caller does NOT own the pointer
     * @return Sink
     */
    virtual sinks::SinkInterface* getSink(const std::string& name) const;  // NOLINT(whitespace/line_length)

    /**
     *  Destructor
     */
    ~Logger();

 private:
    /**
     *  Check if record's values pass are equal or higher than expected values
     *  \param expectedFilters Filters containing expected values
     *  \param recordFilters Record filters
     *  \return True if for each filter key 
     *          (defined as loggingapi::attributes::AttributeInterface::getKey()) 
     *          in expectedFilters there is a matching filter key in 
     *          recordFilters AND expected filter value is lower or equal to 
     *          the record filter value (defined as loggingapi::attributes::
     *          AttributeValue::compare(const AttributeValueInterface &a) const)
     */
    bool passFilters(const std::vector<attributes::AttributeInterface*>& expectedFilters,  // NOLINT(whitespace/line_length)
                            const std::vector<attributes::AttributeInterface*>& recordFilters);    // NOLINT(whitespace/line_length)

    /**
     * Logger Name
     */
    std::string name_;

    /**
     *  Logger's filters
     */
    std::vector<attributes::AttributeInterface*> filters_;

    /**
     *  Logger's sinks
     */
    std::vector<sinks::SinkInterface*> sinks_;

    /**
     *  Logger''s record criteria checker
     */
    criteria::CriteriaChecker criteriaChecker_;
};

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_LOGGERS_LOGGER_H_
