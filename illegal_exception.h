//
// Created by adries on 2021-04-06.
//

#ifndef MST_ILLEGAL_EXCEPTION_H
#define MST_ILLEGAL_EXCEPTION_H


#include <string>

class illegal_exception {
private:
    std::string _msg; // Message of error
public:
    illegal_exception(const std::string msg);
    std::string getMsg() const; // Return the error message
};

#endif //MST_ILLEGAL_EXCEPTION_H
