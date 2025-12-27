#include<bits/stdc++.h>
using namespace std;

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