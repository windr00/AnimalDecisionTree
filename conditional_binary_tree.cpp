//
// Created by 冉惟之 on 20/11/2017.
//

#include <cstdlib>
#include <iostream>
#include "conditional_binary_tree.h"

#define ANSWER_LENGTH 4
#define MESSAGE_ON_ILLEGAL_INPUT "Please input \"yes\" or \"no\""

conditional_binary_tree::conditional_binary_tree() = default;

conditional_binary_tree::conditional_binary_tree(const char *condition, conditional_binary_tree *yes_child,
                                                 conditional_binary_tree *no_child) {
    this->_condition = condition;
    this->_yes_child = yes_child;
    this->_no_child = no_child;
}

conditional_binary_tree *conditional_binary_tree::set_condition(const char *condition) {
    this->_condition = condition;
    return this;
}

conditional_binary_tree *conditional_binary_tree::create_yes_child() {
    this->_yes_child = new conditional_binary_tree();
    this->_is_yes_child_created = true;
    return _yes_child;
}

conditional_binary_tree *conditional_binary_tree::create_no_child() {
    this->_no_child = new conditional_binary_tree();
    this->_is_no_child_created = true;
    return _no_child;
}

conditional_binary_tree *conditional_binary_tree::try_match_condition() {
    while (true) {
        std::cout << this->_condition << std::endl;
        char result[ANSWER_LENGTH] = {0};
        std::cin >> result;
        result[3] = 0;
        if (strcmp(result, "yes") == 0) {
            return this->_yes_child;
        } else if (strcmp(result, "no") == 0) {
            return this->_no_child;
        } else {
            std::cout << MESSAGE_ON_ILLEGAL_INPUT << std::endl;
        }
    }
}

conditional_binary_tree::~conditional_binary_tree() {
    if (_is_yes_child_created) {
        delete _yes_child;
    }
    if (_is_no_child_created) {
        delete _no_child;
    }
}