#ifndef __TASK_MANAGEMENT_H__
#define __TASK_MANAGEMENT_H__

#include "common.h"

class CRUD {
    public:
        virtual void create(const string&, const string&) = 0;
        virtual void read() = 0;
        virtual void update() = 0;
        virtual void remove() = 0;
};

class TaskManager : public CRUD {
    public:
        struct TaskInformation {
            string title_;
            string description_;
            struct tm* due_date_;
            uint32_t priority;
            TaskInformation(const string& title, const string& des) : title_(title), description_(des) {}
        };
        TaskManager() {}
        TaskManager(const string& title, const string& description);
        ~TaskManager();

        void create(const string&, const string&) override;
        void read() override;
        void update() override;
        void remove() override;

    private:
        vector<TaskInformation*> m_taskInforList;
        uint32_t m_size;
};

#endif // __TASK_MANAGEMENT_H__