#ifndef __AST_LOGICAL_EXPRESSION_HPP__
#define __AST_LOGICAL_EXPRESSION_HPP__

#include "AST.hpp"

class LogicalExpression : public AST {
public:
    LogicalExpression() {
    }
    ~LogicalExpression() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "LogicalExpression:" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
    }
};

#endif /* END __AST_LOGICAL_EXPRESSION_HPP__ */