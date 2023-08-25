#include "TaskMangement.h"

#define LOG_TIME(TIME) \
    cout << "Updated Time: " << asctime(TIME); \

#define LOG_LISTS(LIST) \
    for (auto& elem : LIST) { \
        cout << "Title: " << elem.title_ << endl; \
        cout << "Description: " << elem.description_ << endl; \
    } \

#define LOG_MESSAGE(MESSAGE) \
    cout << "[TaskManager]: " << MESSAGE << endl; \

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
}

void TaskManager::read(const int index) {
    if (index < 0 || index >= m_taskInforList.size()) {
        std::cout << "Could not read the invalid content" << std::endl;
        return;
    }

    std::cout << "Title: " << m_taskInforList[index]->title_ << std::endl;
    std::cout << m_taskInforList[index]->description_ << std::endl;
}

void TaskManager::update(const int index, const UpdateType& type, const std::string& script, const std::string& script_2) {
    if (index < 0 || index >= m_taskInforList.size()) {
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

void TaskManager::setCategorize(const int index, TaskManager::Categorize categorize) {
    if (index < 0 || index >= m_taskInforList.size()) {
        LOG_MESSAGE("Invalid index");
        return;
    }
    m_taskInforList[index]->categorize_ = categorize;
}

void TaskManager::setPriority(const int index, Priority level) {
    if (index < 0 || index >= m_taskInforList.size()) {
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

void TaskManager::filter(const TaskManager::Categorize& cate) {
    std::vector<TaskInformation> temp;
    for (auto elem : m_taskInforList) {
        if (elem->categorize_ == cate) {
            temp.push_back(*elem);
        }
    }
    LOG_LISTS(temp);
}

void TaskManager::filter(const TaskManager::Priority& pri) {
    std::vector<TaskInformation> temp;
    for (auto elem : m_taskInforList) {
        if (elem->priority_ == pri) {
            temp.push_back(*elem);
        }
    }
    LOG_LISTS(temp);
}

/*
* @brief this method would not be tested yet
*/
void TaskManager::filter(const tm& due_date) {
    std::vector<TaskInformation> temp;
    for (auto elem : m_taskInforList) {
        if (
            ((*elem->due_date_).tm_hour == due_date.tm_hour) 
            && ((*elem->due_date_).tm_min == due_date.tm_min) 
            && ((*elem->due_date_).tm_sec == due_date.tm_sec)
            && ((*elem->due_date_).tm_mday == due_date.tm_mday) 
            && ((*elem->due_date_).tm_mon == due_date.tm_mon)
            && ((*elem->due_date_).tm_year == due_date.tm_year) 
        )
        {
            temp.push_back(*elem);
        }
    }
    LOG_LISTS(temp);
}