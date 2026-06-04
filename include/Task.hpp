#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
protected:
    int id;
    std::string title;
    bool completed;

public:
    Task(int id, std::string title);
    virtual ~Task() = default;

    int getId() const;
    std::string getTitle() const;
    bool isCompleted() const;

    void markCompleted();

    virtual void printTask() const = 0;
    virtual std::string serialize() const = 0;
};

#endif