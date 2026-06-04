#ifndef RECURRING_TASK_HPP
#define RECURRING_TASK_HPP

#include "Task.hpp"
#include <string>


class RecurringTask : public Task {
    private:
        std::string frequency;
    public:
        RecurringTask(int id, std::string title, std::string frequency);

        void printTask() const override;
        std::string serialize() const override;
};


#endif