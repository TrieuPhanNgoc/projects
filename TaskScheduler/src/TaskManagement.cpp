#include "TaskMangement.h"

#define LOG_TIME(TIME) \
    cout << "Updated Time: " << asctime(TIME); \

TaskManager::TaskManager(const string& title, const string& description, Priority level) 
    : 
    m_templateHolder{nullptr},
    m_size{0}
{ 
    this->create(title, description);
}

TaskManager::~TaskManager() {
}

void TaskManager::create(const string& title, const string& description, Priority level) {
    if (m_templateHolder == nullptr) {
        return;
    }
    time_t now;
    time(&now);
    m_templateHolder = new TaskInformation(title, description, level);
    m_templateHolder->due_date_ = localtime(&now);
    LOG_TIME(m_templateHolder->due_date_);
    m_taskInforList.push_back(m_templateHolder);
    m_size++;
}

void TaskManager::read(const int index) {
    if (index < 0 || index >= m_size) {
        std::cout << "Could not read the invalid content" << std::endl;
        return;
    }

    std::cout << "Title: " << m_taskInforList[index]->title_ << std::endl;
    std::cout << m_taskInforList[index]->description_ << std::endl;
}

void TaskManager::update(const int index, const UpdateType& type, const std::string& script, const std::string& script_2) {
    if (index < 0 || index >= m_size) {
        return;
    }

    switch (type)
    {
        case UpdateType::TITLE: {
            m_taskInforList[index]->title_ = script;
            break;
        }

        case UpdateType::SCRIPT: {
            m_taskInforList[index]->description_ = script;
            break;
        }

        case UpdateType::MAX: {
            m_taskInforList[index]->title_ = script;
            m_taskInforList[index]->description_ = script_2;
            break;
        }

        default: {
            break;
        }
    }
}

void TaskManager::remove(const int index) {
    if (index < 0 || index >= m_size) {
        return;
    }
    m_taskInforList.erase(m_taskInforList.begin() + index);
}

void TaskManager::showTask() {
    for (int idx = 0; idx < m_taskInforList.size(); ++idx) {
        std::cout << "***********************************************" << std::endl;
        this->read(idx);
        std::cout << "***********************************************" << std::endl;
    }
}

void TaskManager::setPriority(const int index, Priority level) {
    if (index < 0 || index > m_size) {
        return;
    }

    m_taskInforList[index]->priority_ = level;
}

void TaskManager::prioritySort() {
    std::vector<TaskInformation*> temp;
    for (auto elem : m_taskInforList) {
        if (elem->priority_ == Priority::LOW) {
            temp.push_back(elem);
        }
    }

    for (auto elem : m_taskInforList) {
        if (elem->priority_ == Priority::MEDIUM) {
            temp.push_back(elem);
        }
    }

    for (auto elem : m_taskInforList) {
        if (elem->priority_ == Priority::HIGH) {
            temp.push_back(elem);
        }
    }

    m_taskInforList = temp;
}   

void TaskManager::filter(const Categorize&) {

}