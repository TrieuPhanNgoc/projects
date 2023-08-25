#include <iostream>
#include "TaskMangement.h"
#include "UserAuthentication.h"

int main() {
    TaskManager m_taskMan;
    m_taskMan.create("Noting", "This is using for update task!");
    m_taskMan.create("Noting 2", "This is using for update task!!!!!");
    m_taskMan.create("Noting 3", "This is using for update task!!!!!!!");
    m_taskMan.create("Noting 4", "This is using for update task!!!!!!!!");
    // m_taskMan.showTask();
    // m_taskMan.remove(1);
    m_taskMan.update(0, TaskManager::UpdateType::TITLE, "Program");
    m_taskMan.update(0, TaskManager::UpdateType::SCRIPT, "This task to write down ideas for program");
    // m_taskMan.showTask();
    m_taskMan.setCategorize(1, TaskManager::Categorize::WORK);
    m_taskMan.setCategorize(3, TaskManager::Categorize::WORK);
    m_taskMan.filter(TaskManager::Categorize::WORK);

    // Authentication authen;
    // authen.setPassword("Hello World!", sizeof("Hello World!"));
    // if (authen.verifyPassword("Hello World!", sizeof("Hello World!")) == Authentication::AuthenRetCode::SUCCESS) {
    //     printf("Unlock Password Successful\n");
    // }
    // else {
    //     printf("Unlock Password Failed\n");
    // }
    return 0;
}