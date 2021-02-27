#include <iostream>
#include <unordered_map>
using namespace std;

class unique_char{
    private:
    string s;
    int size, k, start, end, max_l, flag;
    unordered_map<int, int> mp;

    public:
    unique_char();
    void solve(string s);

};

void unique_char :: solve(string s){
    start = 0;
    end = 0;
    max_l = 0;
    flag = 1;
    while(end<size){
        if(flag != 0){
            mp[s[end]]++;
        }
        cout<<start<<" "<<end<<" "<<max_l<<" "<<mp.size()<<" "<<flag<<endl;
        if(mp.size()<k){
            flag = 1;
            end++;
            continue;
        }
        if(mp.size()==k){
            flag = 1;
            if(max_l<end-start+1){
                max_l = end-start+1;
            }
            end++;
        }
        if(mp.size()>k){
            mp[s[start]]--;
            if(mp[s[start]]==0){
                mp.erase(s[start]);
            }
            start++;
            flag = 0;
        }
    }
    cout<<"Maximum length of the substring : "<<max_l<<endl;
}

unique_char :: unique_char(){
    cout<<"\n\nEnter the string : "<<endl;
    cin>>s;
    size = s.length();
    cout<<"Enter the number of unique characters, depending on which you are trying to find the longest substribg length : "<<endl;
    cin>>k;

    solve(s);
}

int main(){
    unique_char u1, u2;

    return 0;
}