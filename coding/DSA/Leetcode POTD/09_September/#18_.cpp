#include<bits/stdc++.h>
using namespace std;


class TaskManager {
public:

    unordered_map< int , map<int , set<int> > > userPriorTask; 
    // map < user -> map < prior -> ordered_set<tasks> > >

    unordered_map<int , int> taskUser; // task -> user
    unordered_map<int , int> taskPrior; // task -> prior
    map<int , int> userPrior; // user -> prior

    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int> task : tasks ){
            userPriorTask[task[0]][task[1]].insert(task[2]);
            taskUser[task[1]]=task[0];
            taskPrior[task[1]]=task[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        userPriorTask[userId][taskId].insert(priority);
        taskUser[taskId]=userId;
        taskPrior[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        int oldPrior = taskPrior[taskId];
        int userId = taskUser[oldPrior];
        userPriorTask[userId][oldPrior].erase(taskId);
        userPriorTask[userId][newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        int priorityId = taskPrior[taskId];
        int userId = taskUser[taskId];
        userPriorTask[userId][priorityId].erase(taskId);
    }
    
    int execTop() {
        int taskId;
        // vector<int> highestTasks;
        int maxPrior = 0;
        for(auto it : userPriorTask){
            // map<int, int> mp = it.second;
            // maxPrior = max(maxPrior ,  );
            // create a list of tasks with higehest priority and the rmv(taskId)
        }
    }

};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */


     // auto lastPair = prev(myMap.end());
    // cout << "Last element key: " << lastPair->first << ", value: " << lastPair->second << endl;



// ----------------------------------------------------------------------------------------------------------- //


class TaskManager {
public:
    // Heap element: {priority, taskId, userId}
    priority_queue<tuple<int,int,int>> pq;

    // taskId -> {priority, userId}
    unordered_map<int, pair<int,int>> taskInfo;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskInfo[taskId] = {priority, userId};
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {priority, userId};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto [oldPriority, userId] = taskInfo[taskId];
        taskInfo[taskId] = {newPriority, userId};
        pq.push({newPriority, taskId, userId}); // push new version
    }

    void rmv(int taskId) {
        taskInfo.erase(taskId); // lazy removal (old entry in heap ignored later)
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            pq.pop();

            // check if still valid
            if (taskInfo.count(taskId) && taskInfo[taskId].first == priority) {
                taskInfo.erase(taskId); // remove after execution
                return userId;
            }
        }
        return -1; // no tasks
    }
};


// ---------------------------------------------------- //
// produces TLE


class TaskManager {
public:
    // user -> priority -> {tasks}
    unordered_map<int, map<int, set<int>>> userPriorTask;

    // taskId -> userId
    unordered_map<int, int> taskUser;

    // taskId -> priority
    unordered_map<int, int> taskPrior;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            userPriorTask[userId][priority].insert(taskId);
            taskUser[taskId] = userId;
            taskPrior[taskId] = priority;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        userPriorTask[userId][priority].insert(taskId);
        taskUser[taskId] = userId;
        taskPrior[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int oldPrior = taskPrior[taskId];
        int userId = taskUser[taskId];

        // remove from old bucket
        userPriorTask[userId][oldPrior].erase(taskId);
        if (userPriorTask[userId][oldPrior].empty()) {
            userPriorTask[userId].erase(oldPrior);
        }

        // add to new bucket
        userPriorTask[userId][newPriority].insert(taskId);
        taskPrior[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priorityId = taskPrior[taskId];
        int userId = taskUser[taskId];

        userPriorTask[userId][priorityId].erase(taskId);
        if (userPriorTask[userId][priorityId].empty()) {
            userPriorTask[userId].erase(priorityId);
        }

        taskUser.erase(taskId);
        taskPrior.erase(taskId);
    }
    
    int execTop() {
        int bestUser = -1;
        int bestTask = -1;
        int bestPrior = -1;

        for (auto &u : userPriorTask) {
            int userId = u.first;
            if (u.second.empty()) continue;

            auto it = prev(u.second.end()); // max priority
            int priority = it->first;
            int taskId = *prev(it->second.end()); // max taskId in that priority

            if (priority > bestPrior || (priority == bestPrior && taskId > bestTask)) {
                bestPrior = priority;
                bestTask = taskId;
                bestUser = userId;
            }
        }

        if (bestUser == -1) return -1; // no tasks

        // remove chosen task
        userPriorTask[bestUser][bestPrior].erase(bestTask);
        if (userPriorTask[bestUser][bestPrior].empty()) {
            userPriorTask[bestUser].erase(bestPrior);
        }
        taskUser.erase(bestTask);
        taskPrior.erase(bestTask);

        return bestUser;
    }
};
