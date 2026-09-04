class Solution {
public:
    int secondsBetweenTimes(string st, string et) {

        int hr1 = stoi( st.substr(0,2) ) * 60 * 60 ;
        int hr2 = stoi( et.substr(0,2) ) * 60 * 60 ;
        int min1 = stoi( st.substr(3,2) ) * 60 ;
        int min2 = stoi( et.substr(3,2) ) * 60 ;
        int sec1 = stoi( st.substr(6,2) ) ;
        int sec2 = stoi( et.substr(6,2) ) ;

        return hr2+min2+sec2 - hr1-min1-sec1 ;
        
    }
};