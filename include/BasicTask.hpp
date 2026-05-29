#ifndef BASIC_TASK_HPP
#define BASIC_TASK_HPP

#include "Task.hpp"
#include <string>

class BasicTask : public Task {
public:
    BasicTask(int id, std::string title);

    void printTask() const override;
};

#endif