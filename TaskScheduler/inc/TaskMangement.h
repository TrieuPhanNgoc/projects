#ifndef __TASK_MANAGEMENT_H__
#define __TASK_MANAGEMENT_H__

#include "common.h"

class TaskManager {
    public:
    
        enum UpdateType {
            TITLE   =   0,
            SCRIPT,
            MAX
        };

        enum Priority {
            LOW     =   0,
            MEDIUM,
            HIGH
        };

        enum Categorize {
            WORK,
            PERSONAL,
            STUDY
        };

        struct TaskInformation {
            string title_;
            string description_;
            struct tm* due_date_;
            Priority priority_;
            Categorize categorize_;
            TaskInformation(const string& title, const string& des, Priority level = Priority::LOW) 
                : title_(title), description_(des), priority_{level}, categorize_{Categorize::PERSONAL} {}
        };


        struct CRUD_UpdateHandler {
            int index_;             // <! Index of task
            std::string title_;     // <! Title for updating
            std::string scripture_; // <! Scripture of task index
            CRUD_UpdateHandler(){}
            CRUD_UpdateHandler(const int idx, const std::string& title, const std::string& script)
                : index_(idx), title_(title), scripture_(script) {}
        };

        TaskManager() {}
        TaskManager(const string& title, const string& description, Priority level = Priority::LOW);
        ~TaskManager();

    public:
        void create(const string&, const string&, Priority level = Priority::LOW);
        void read(const int index);
        void update(const int index, const UpdateType& type, const std::string& script, const std::string& script_2 = "");
        void remove(const int index);
        void filter(const Categorize&);
        void filter(const Priority&);
        void filter(const tm&);
        void showTask();

        void setCategorize(const int index, Categorize categorize);
        void setPriority(const int index, Priority level);
        void prioritySort();

    private:
        TaskInformation* m_templateHolder;
        vector<TaskInformation*> m_taskInforList;
        uint32_t m_size;
};

#endif // __TASK_MANAGEMENT_H__