#include "TaskMangement.h"

#define LOG_TIME(TIME) \
    cout << "Timer of action: " << asctime(TIME) << endl; \

TaskManager::TaskManager(const string& title, const string& description) : m_size(0)
{ 
    this->create(title, description);
}

TaskManager::~TaskManager() {
}

void TaskManager::create(const string& title, const string& description) {
    TaskInformation* newTask = new TaskInformation(title, description);
    time_t now;
    time(&now);
    newTask->due_date_ = localtime(&now);
    
    LOG_TIME(newTask->due_date_);

    m_taskInforList.push_back(newTask);
    m_size++;
}

void TaskManager::read() {}
void TaskManager::update() {}
void TaskManager::remove() {}