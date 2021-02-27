// Given two strings s1 and s2
// Find the length of minimum window from string s1 which contains all the characters from string s2 in equal amount.
#include <iostream>
#include <unordered_map>
using namespace std;
class min_window{
    private:
    string s1;
    string s2;
    unordered_map<int, int> s2_mp;
    public:
    min_window();
    unordered_map<int, int> get_s2_counts(string s2);
    void solve(string s1, unordered_map<int, int> s2_mp);
};

unordered_map<int, int> min_window :: get_s2_counts(string s2){
    unordered_map<int, int> mp;
    for(char c:s2){
        mp[c]++;
    }
    return mp;
}

void min_window :: solve(string s1, unordered_map<int, int> s2_mp){
    int w=1;
    int ans=INT_MAX;
    unordered_map<int, int> s1_mp;
    for(char c:s1){
        if(s2_mp.find(c)==s2_mp.end()){
            w++;
        }
        else{
            s1_mp[c]++;
            if(s1_mp[c]==s2_mp[c]){
                ans = min(w, ans);
            }
            else if(s1_mp[c]<s2_mp[c]){
                w++;
            }
            else{

            }


        }
}

min_window :: min_window(){
    cout<<"\nEnter the string s1 : "<<endl;
    cin>>s1;
    cout<<"\nEnter the string s2 : "<<endl;
    cin>>s2;
    s2_mp = get_s2_counts(s2);
    solve(s1, s2_mp);
}

int main(){
    min_window m1[1];
    return 0;
}