//
//  Logger.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "./loggingapi/loggers/Logger.h"
#include "./loggingapi/attributes/AttributeInterface.h"
#include "./loggingapi/sinks/SinkInterface.h"
#include "./loggingapi/records/RecordInterface.h"
#include "./loggingapi/criteria/CriteriaChecker.h"

namespace loggingapi {
namespace loggers {

std::string Logger::getName() const {
    return this->name_;
}

void Logger::setName(std::string name) {
    this->name_ = name;
}

typedef records::RecordInterface RecordI;
typedef attributes::AttributeInterface AttrI;
typedef attributes::AttributeValueInterface AttrVI;
typedef sinks::SinkInterface SinkI;

/**
 * Function object to find a filter with requested name
 */
struct GetFilterByName : public std::binary_function<AttrI*, std::string, bool> {  // NOLINT(whitespace/line_length)
    /**
 * Finds Filter with requested name
 * @param a Filter
 * @param name Requested Filter name
 * @return True if filter has same name as the requested name
 */
    bool operator()(AttrI* a, const std::string name) const {
        return name.compare(a->getKey()) == 0;
    }
};

AttrI* Logger::getFilter(const std::string& name) const {
    std::vector<AttrI*>::const_iterator it;
    it = std::find_if(this->filters_.begin(),
                      this->filters_.end(),
                      std::bind2nd(GetFilterByName(), name));
    return (it != this->filters_.end()) ? *it : NULL;
}

bool Logger::addFilter(AttrI* filter) {
    if (filter == NULL) {return false;}
    if (this->getFilter(filter->getKey()) != NULL) {return false;}
    this->filters_.push_back(filter);
    return true;
}

attributes::AttributeInterface* Logger::removeFilter(const std::string& name) {
    std::vector<AttrI*>::iterator it;
    // Search for filter with requested name
    it = std::find_if(this->filters_.begin(),
                      this->filters_.end(),
                      std::bind2nd(GetFilterByName(), name));
    if (it != this->filters_.end()) {
        // Filter found, remove it from filters
        this->filters_.erase(it);
        return *it;
    }
    return NULL;
}

/**
 * Function object to log a record to a sink
 */
struct LogRecordToSink : public std::binary_function<SinkI*, RecordI*, void> {  // NOLINT(whitespace/line_length)
    /**
     * Logs a record to a sink
     * @param s Sink to log to
     * @param r Record to log
     */
    void operator()(SinkI* s, RecordI* r) const {
        s->log(r);
    }
};

void Logger::log(const records::RecordInterface* record) {
    const std::vector<loggingapi::attributes::AttributeInterface*> recordAttributes(record->getAttributes().begin(), record->getAttributes().end());  // NOLINT(whitespace/line_length)
    if (this->criteriaChecker_.pass(this->filters_, recordAttributes)) {
        std::for_each(this->sinks_.begin(),
                this->sinks_.end(),
                std::bind2nd(LogRecordToSink(), record));
    }
    delete record;
}

void deletePointedToFilterObject(AttrI* p) {
    delete p;
    p = NULL;
}

void deletePointedToSinkObject(SinkI* p) {
    delete p;
    p = NULL;
}

Logger::~Logger() {
    // Delete pointed-to filters object
    std::for_each(this->filters_.begin(),
                  this->filters_.end(),
                  deletePointedToFilterObject);
    // Delete pointed-to sinks object
    std::for_each(this->sinks_.begin(),
                  this->sinks_.end(),
                  deletePointedToSinkObject);
    // vector object is deleted when it goes out of scope
}

/**
 * Function object to find a sink with requested name
 */
struct GetSinkByName : public std::binary_function<SinkI*, std::string, bool> {
    /**
 * Finds Sink with requested name
 * @param a Sink
 * @param name Requested Sink name
 * @return True if sink has same name as the requested name
 */
    bool operator()(SinkI* a, const std::string name) const {
        return name.compare(a->getName()) == 0;
    }
};

SinkI* Logger::getSink(const std::string& name) const {
    std::vector<SinkI*>::const_iterator it;
    it = std::find_if(this->sinks_.begin(),
                      this->sinks_.end(),
                      std::bind2nd(GetSinkByName(), name));
    return (it != this->sinks_.end()) ? *it : NULL;
}

bool Logger::addSink(SinkI* s) {
    if (this->getSink(s->getName()) == NULL) {
        this->sinks_.push_back(s);
        return true;
    }
    return false;
}

}}  // namespaces
