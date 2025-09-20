#include<bits/stdc++.h>
using namespace std;



// try 1

class Router {
public:
    struct packet{
        int source;
        int destination;
        int timestamp;
    };

    queue<packet> q;
    int limit;
    unordered_map<packet , int> mpp;
    unordered_map<int , unordered_set<int> > dest_time; // dest-> set<time>

    Router(int memoryLimit) {
        queue<packet> temp;
        q.swap(temp);
        mpp.clear();
        dest_time.clear();
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {

        if(q.size() == limit){
            return false;
        }

        packet temp;
        temp.source = source;
        temp.destination = destination;
        temp.timestamp = timestamp;

        mpp[temp]++;
        dest_time[destination].insert(timestamp);

        return true;

    }
    
    vector<int> forwardPacket() {

        if(q.empty()){
            return {};
        }

        packet temp = q.front();
        q.pop();

        int source = temp.source;
        int destination = temp.destination;
        int timestamp = temp.timestamp;

        mpp.erase(temp);
        dest_time[destination].erase(timestamp);

        return {source , destination , timestamp};

    }
    
    int getCount(int destination, int startTime, int endTime) {

        int count = 0;
        unordered_set<int> times = dest_time[destination];
        
        for(int time : times){
            if(startTime<=time && time<=endTime) count++;
        }

        return count;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */



// try 2 : wrong


class Router {
public:
    // Packet struct
    struct packet {
        int source;
        int destination;
        int timestamp;
    };

    queue<packet> q;
    int limit;

    // Change: unordered_map with tuple key instead of packet to avoid hash issues
    unordered_map<tuple<int,int,int>, int> mpp; // removed: unordered_map<packet,int> mpp;
    
    // Change: use multiset for efficient range counting
    unordered_map<int, multiset<int>> dest_time; // removed: unordered_map<int, unordered_set<int>>

    Router(int memoryLimit) {
        // Removed unnecessary clearing of queue and maps
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> p = {source,destination,timestamp};

        // Change: check for duplicate
        if(mpp[p] > 0) return false;

        // Change: handle memory limit FIFO eviction
        if(q.size() == limit){
            packet old = q.front();
            q.pop();
            tuple<int,int,int> old_p = {old.source, old.destination, old.timestamp};
            mpp.erase(old_p);
            // dest_time[old.destination].erase(dest_time[old.destination].find(old.timestamp)); // short cut
            auto& timestamps = dest_time[old.destination]; // get reference to multiset
            auto it = timestamps.find(old.timestamp);      // find one occurrence
            if(it != timestamps.end()) {
                timestamps.erase(it);                      // erase that one occurrence
            }
        }

        // Create new packet
        packet temp = {source, destination, timestamp};

        // Add to queue
        q.push(temp); // Added: previously missing

        // Add to map
        mpp[p] = 1; // Added: duplicate count management

        // Add timestamp to destination multiset
        dest_time[destination].insert(timestamp); // Modified: multiset insert

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }

        packet temp = q.front();
        q.pop();

        tuple<int,int,int> p = {temp.source, temp.destination, temp.timestamp};

        // Remove from map
        mpp.erase(p);

        // Remove timestamp from multiset
        dest_time[temp.destination].erase(dest_time[temp.destination].find(temp.timestamp));

        return {temp.source, temp.destination, temp.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        // Efficient range query using multiset
        auto& times = dest_time[destination]; // times multi_set
        auto it1 = times.lower_bound(startTime);
        auto it2 = times.upper_bound(endTime);
        count = distance(it1, it2);

        return count;
    }
};



// try 3: accepted but TLE

class Router {
public:
    // Packet struct
    struct packet {
        int source;
        int destination;
        int timestamp;
    };

    // Custom key for unordered_map
    struct PacketKey {
        int source, destination, timestamp;
        bool operator==(const PacketKey& other) const {
            return source == other.source && destination == other.destination && timestamp == other.timestamp;
        }
    };

    // Hash function for PacketKey
    struct PacketKeyHash {
        size_t operator()(const PacketKey& p) const {
            return hash<int>()(p.source) ^ (hash<int>()(p.destination) << 1) ^ (hash<int>()(p.timestamp) << 2);
        }
    };

    queue<packet> q; // FIFO queue for packets
    int limit;

    // Map to track duplicates
    unordered_map<PacketKey, int, PacketKeyHash> mpp; 
    
    // Map destination -> multiset of timestamps for range queries
    unordered_map<int, multiset<int>> dest_time; 

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        PacketKey key{source, destination, timestamp};

        // Check for duplicate
        if(mpp[key] > 0) return false;

        // Handle FIFO eviction if memory limit reached
        if(q.size() == limit){
            packet old = q.front();
            q.pop();
            PacketKey oldKey{old.source, old.destination, old.timestamp};
            mpp.erase(oldKey);

            auto& timestamps = dest_time[old.destination];
            auto it = timestamps.find(old.timestamp);
            if(it != timestamps.end()) timestamps.erase(it);
        }

        // Add new packet
        packet temp{source, destination, timestamp};
        q.push(temp);
        mpp[key] = 1;
        dest_time[destination].insert(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};

        packet temp = q.front();
        q.pop();

        PacketKey key{temp.source, temp.destination, temp.timestamp};
        mpp.erase(key);

        auto& timestamps = dest_time[temp.destination];
        auto it = timestamps.find(temp.timestamp);
        if(it != timestamps.end()) timestamps.erase(it);

        return {temp.source, temp.destination, temp.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& times = dest_time[destination];
        auto it1 = times.lower_bound(startTime);
        auto it2 = times.upper_bound(endTime);
        return distance(it1, it2);
    }
};


// try 4 : TLE


class Router {
public:
    // Packet struct
    struct packet {
        int source;
        int destination;
        int timestamp;
    };

    // Custom key for unordered_map to check duplicates
    struct PacketKey {
        int source, destination, timestamp;
        bool operator==(const PacketKey& other) const {
            return source == other.source && destination == other.destination && timestamp == other.timestamp;
        }
    };

    struct PacketKeyHash {
        size_t operator()(const PacketKey& p) const {
            return hash<int>()(p.source) ^ (hash<int>()(p.destination) << 1) ^ (hash<int>()(p.timestamp) << 2);
        }
    };

    queue<packet> q; // FIFO queue
    int limit;

    unordered_map<PacketKey, int, PacketKeyHash> mpp; // check duplicates
    unordered_map<int, map<int,int>> dest_time;        // destination -> timestamp -> count

    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        PacketKey key{source, destination, timestamp};

        // Duplicate check
        if(mpp[key] > 0) return false;

        // FIFO eviction if memory limit reached
        if(q.size() == limit){
            packet old = q.front();
            q.pop();
            PacketKey oldKey{old.source, old.destination, old.timestamp};
            mpp.erase(oldKey);

            auto& ts_map = dest_time[old.destination];
            ts_map[old.timestamp]--;
            if(ts_map[old.timestamp] == 0) ts_map.erase(old.timestamp);
        }

        // Add new packet
        packet temp{source, destination, timestamp};
        q.push(temp);
        mpp[key] = 1;
        dest_time[destination][timestamp]++; // increment count

        return true;
    }

    vector<int> forwardPacket() {
        if(q.empty()) return {};

        packet temp = q.front();
        q.pop();

        PacketKey key{temp.source, temp.destination, temp.timestamp};
        mpp.erase(key);

        auto& ts_map = dest_time[temp.destination];
        ts_map[temp.timestamp]--;
        if(ts_map[temp.timestamp] == 0) ts_map.erase(temp.timestamp);

        return {temp.source, temp.destination, temp.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        auto& ts_map = dest_time[destination];
        auto it1 = ts_map.lower_bound(startTime);
        auto it2 = ts_map.upper_bound(endTime);
        for(auto it = it1; it != it2; ++it){
            count += it->second;
        }
        return count;
    }
};



// solution section - 1

class Router {
public:
    map<vector<int>, int> mpp; // to track duplicates
    queue<vector<int>> queue; // to store packets in FIFO order
    unordered_map<int, vector<int>> timestamps; // for timestamps tracking
    unordered_map<int, int> st; 
    int maxSize = 0; // maxSize allowed

    Router(int memoryLimit) { 
        maxSize = memoryLimit; 
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        // checking for duplicate
        if (mpp.count(packet))
            return false;
        if (queue.size() == maxSize) { // remove the first element if queue is full
            vector<int> res = queue.front();
            mpp.erase(res);
            int temp = res[1];
            st[temp]++;  
            queue.pop();
        }
        queue.push(packet);
        mpp[packet]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(queue.empty()) return {};
        vector<int> res = queue.front();
        queue.pop();
        mpp.erase(res);
        int temp = res[1];
        st[temp]++;
        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        if(timestamps.find(destination) == timestamps.end())
            return 0;
        auto &p = timestamps[destination];
        int temp = st[destination];
        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);
        return int(left - right);
    }
};

