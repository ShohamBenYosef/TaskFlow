#include "TaskFactory.hpp"


#include <memory>
#include <vector>
#include <string>

std::unique_ptr<Task> TaskFactory::createTask(const std::vector<std::string>& parts) {
    if (parts.empty()) {
        return nullptr;
    }

    if (parts[0] == "BASIC" && parts.size() == 4) {
        return std::make_unique<BasicTask>(std::stoi(parts[1]), parts[2]);
    }

    else if (parts[0] == "DEADLINE" && parts.size() == 5) {
        return std::make_unique<DeadLineTask>(std::stoi(parts[1]), parts[2], parts[4]);
    }

    else if (parts[0] == "RECURRING" && parts.size() == 5) {
        return std::make_unique<RecurringTask>(std::stoi(parts[1]), parts[2], parts[4]);
    }

    return nullptr;
}