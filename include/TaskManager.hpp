#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include "Task.hpp"
#include "RecurringTask.hpp"

#include <vector>
#include <string>
#include <memory>



class TaskManager {
    private:
        std::vector<std::unique_ptr<Task>> tasks;
        int nextId;
        
    public:
        TaskManager();

        void addTask(const std::string& title);
        void addDeadlineTask(const std::string& title, const std::string& deadline);
        void addRecurringTask(const std::string& title, const std::string& frequency);

        void printAllTasks() const;
        bool markTaskCompleted(int id);

        void saveToFile(const std::string& filename) const;

};

#endif


