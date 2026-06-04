#ifndef DEADLINE_TASK_HPP
#define DEADLINE_TASK_HPP

#include "Task.hpp"
#include <string>

class DeadLineTask : public Task {
private:
    std::string deadline;

public:
    DeadLineTask(int id, std::string title, std::string deadline);

    void printTask() const override;
    std::string serialize() const override;
};

#endif