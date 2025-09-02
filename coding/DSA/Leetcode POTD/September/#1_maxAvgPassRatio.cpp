#include<bits/stdc++.h>
using namespace std;


// try 1

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> passRatio(n);

        double sum = 0;

        for(int i=0 ; i<n ; i++){
            passRatio[i] = (double)(classes[i][0]/classes[i][1]);
            sum += passRatio[i];
        }

        for(int i = 0 ; i < extraStudents ; i++){
            double currMaxSum = sum;
            for(int i=0 ; i<n ; i++){
                double a = classes[i][0] , b = classes[i][1];
                // currMaxSum = max(currMaxSum , sum + ( (double)(classes[i][1]-classes[i][0])/(double)(classes[i][1]*(classes[i][1]+1)) ));
                currMaxSum = max(currMaxSum , sum - (a/b) + (a+1/b+1));
            }
            sum = currMaxSum;
        }

        return (double)(sum/(n+extraStudents));

    }
};

// try 2


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> passRatio(n);

        double sum = 0; // sum of passRatios

        for(int i=0 ; i<n ; i++){
            passRatio[i] = (double)((double)classes[i][0]/classes[i][1]);
            sum += passRatio[i];
        }

        for(int i = 0 ; i < extraStudents ; i++){
            // double currMaxSum = 0;
            for(int i=0 ; i<n ; i++){
                double a = classes[i][0] , b = classes[i][1];
                // currMaxSum = max(currMaxSum , sum + ( (double)(classes[i][1]-classes[i][0])/(double)(classes[i][1]*(classes[i][1]+1)) ));
                sum = max(sum , sum - (double)(a/b) + (double)((a+1)/(b+1)));
            }
            // sum = currMaxSum;
        }

        return (double)(sum)/n;

    }
};


// brute sol updated (chat GPT) - TLE

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        for (int k = 0; k < extraStudents; k++) {
            int bestIdx = -1;
            double bestGain = -1.0;

            for (int i = 0; i < n; i++) {
                double a = classes[i][0], b = classes[i][1];
                double gain = (a + 1) / (b + 1) - (a / b);

                if (gain > bestGain) {
                    bestGain = gain;
                    bestIdx = i;
                }
            }

            // Assign one student to the best class
            classes[bestIdx][0]++;
            classes[bestIdx][1]++;
        }

        // Compute final average
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (double)classes[i][0] / classes[i][1];
        }

        return sum / n;
    }
};


// optimal code using maxHeap by chatGPT :

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int,int>>> pq; // maxHeap of < gain , < pass , total > >
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto [g, p] = pq.top(); // g = gain , p = <pass,total>
            pq.pop();
            int pass = p.first, total = p.second;
            pass++, total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        double sum = 0;
        while (!pq.empty()) {
            auto [g, p] = pq.top(); pq.pop();
            sum += (double)p.first / p.second;
        }

        return sum / n;
    }
};