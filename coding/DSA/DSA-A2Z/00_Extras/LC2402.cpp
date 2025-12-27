#include<bits/stdc++.h>
using namespace std;

/*
my Algo: 

1. sort meetings
2. lookup Table [n,INF]
3. value[n,0] indicating the number of meetings in the ith room
4. priorityQueue< { key , meeting } >   
        with priority : 
            { 
                2 level - if 1st tie then 2nd
                        - 1st : meeting endtime i.e. meeting[idx][1] for some idx
                        - 2nd : key of the meeting (indicating the room number)
            }
5. for( i=0 to meetings)
    {   
        if( pq.size < n ) :
            int k=0;
            search look-up table for 1st empty k for which the value is INF i.e. empty room
            lookup[k] = meetings[i][1] // end time
            pq.push( k , meetings[i] )
            value[k]++;

        else :
            endT = pq.top.meeting.endtime
            k = pq.top.key
            pq.extractMin() // pop()
            lookup[k] = meetings[i][1] // endtime
            pq.push( k , meetings[i] );
            value[k]++;
            
    }

*/


// ------------------------------------------------------------------------------------------------ //

/*
chatGPT modified algo : 

1. sort meetings by start time

2. lookup Table [n] initialized with -1
   // lookup[i] = end time of room i, -1 means free

3. value[n] = {0}   // number of meetings handled by each room

4. priorityQueue pq  (min heap)
   stores:
        { endTime , roomIndex }
   priority:
        1) smaller endTime
        2) smaller room index

5. for each meeting i in sorted order:

    // STEP 1: free rooms that have completed before this meeting starts
    while pq not empty AND pq.top().endTime <= meetings[i][0]:
        room = pq.top().roomIndex
        pop pq
        lookup[room] = -1   // mark room free

    // STEP 2: if there is a free room
    if (exists room k where lookup[k] == -1):
        pick smallest such k
        lookup[k] = meetings[i][1]
        pq.push( {meetings[i][1], k} )
        value[k]++

    // STEP 3: all rooms are busy → delay meeting
    else:
        top = pq.top()
        pop pq

        k = top.roomIndex
        endT = top.endTime

        duration = meetings[i][1] - meetings[i][0]
        newEnd = endT + duration

        lookup[k] = newEnd
        pq.push( {newEnd, k} )
        value[k]++

6. answer = index with maximum value[]
   if tie → smallest index
*/

#define ll long long

class Solution {
public:

    struct cmp {
        bool operator()( const pair< ll , ll >& a , const pair< ll , ll >& b ) const {
            // a = {endTime , room}
            // min-heap behavior:
            if (a.first == b.first)
                return a.second > b.second;  // smaller room index first
            return a.first > b.first;        // smaller endTime first
        }
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        // 1
        sort( meetings.begin() , meetings.end() );

        // 2 
        vector<ll> lookup(n,-1);

        // 3
        vector<ll> value(n,0);

        // 4
        priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, cmp > pq; // { endTime , roomKey }

        // 5
        for( ll i=0 ; i<meetings.size() ; i++ ) {

            // 5.1
            while( !pq.empty() && pq.top().first <= meetings[i][0] ) {
                ll key = pq.top().second;
                pq.pop();
                lookup[key] = -1;
            }

            // 5.2
            ll k=0 ;
            for ( ; k<n ; k++ ){
                if ( lookup[k] == -1 ) {
                    lookup[k] = meetings[i][1];
                    pq.push( { meetings[i][1] , k } );
                    value[k]++;
                    break;
                }
            }

            // 5.3
            if( k==n ) {
                auto top = pq.top();
                pq.pop();

                k = top.second;
                ll endT = top.first;

                ll duration = meetings[i][1] - meetings[i][0];
                ll newEnd = endT + duration;

                lookup[k] = newEnd;
                pq.push( { newEnd , k } );
                value[k]++;

            }

        }

        ll idx = 0;
        ll maxi = -1;
        for(ll i=0 ; i<n ; i++){
            if( value[i] > maxi ){
                maxi = value[i];
                idx = i;
            }
        }

        return idx;

    }
};

// ------------------------------------------------------------------------------------------------ //