class EventManager {
public:
    // creating map for accessing old priority
    unordered_map<int,int> mpp ;

    // using set of accesing highest priority 
    set<pair<int,int>> st ;

    EventManager(vector<vector<int>>& events) {

        for ( auto it : events ) {

            int id = it[0] ;
            int priority = it[1] ;

            mpp[-id] = priority ;
            st.insert( { priority , -id } ) ;

        }
        
    }
    
    void updatePriority(int eventId, int newPriority) {

        // getting old priority of that event
        int old_priority = mpp[-eventId] ;

        // deleting old priority from set
        st.erase( { old_priority , -eventId } ) ;

        // inserting new priority of that event in set
        st.insert( { newPriority , -eventId } ) ;

        // updating map
        mpp[-eventId] = newPriority ;
        
    }
    
    int pollHighest() {

        if ( st.empty() ) return -1 ;

        auto it = st.rbegin() ;

        int event = it->second ;
        int priority = it->first ;

        st.erase( *it ) ;
        mpp.erase( event ) ;

        return -event ;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */