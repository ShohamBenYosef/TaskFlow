#ifndef TASK_HPP
#define TASK_HPP

#include <string>


class Task {
    private: 
        int id;
        std::string title;
        bool completed = false;

    public:
        Task(int id, std::string title);

        int getId() const;
        std::string getTitle() const;
        bool isCompleted() const;

        void markCompleted();
        void printTask() const;
};



#endif