#ifndef TASK_FACTORY_HPP
#define TASK_FACTORY_HPP

#include "Task.hpp"
#include "BasicTask.hpp"
#include "DeadlineTask.hpp"
#include "RecurringTask.hpp"

#include <memory>
#include <vector>
#include <string>


class TaskFactory {
    public:
        static std::unique_ptr<Task> createTask(const std::vector<std::string>& parts);
};




#endif // TASK_FACTORY_HPP