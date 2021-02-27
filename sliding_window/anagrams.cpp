#include <iostream>
#include <unordered_map>
using namespace std;

typedef unordered_map<int,int> maptype;

maptype mapping(string s){
    maptype mp;
    for(int i=0; i<s.length(); i++)
        mp[s[i]]++;
    return mp;
}

maptype new_mapping(maptype &mp, char c_add, char c_minus){
    if(c_minus!=' '){
        mp[c_add]++;
        mp[c_minus]--;
    }
    else{
        mp[c_add]++;
    }
    return mp;
}

int compare (maptype mp_norm, maptype mp_anag){
    int flag = 1;
    for(auto i=mp_anag.begin(); i!=mp_anag.end(); i++){
        if(i->second!=mp_norm[i->first]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){

    cout<<"Enter the string : "<<endl;
    string s_major;
    // getline(cin, s_major);
    cin>>s_major;
    
    cout<<"Enter the anagram string : "<<endl;
    string anag;
    cin>>anag; 

    maptype mp_anag;
    maptype mp_norm;
    int flag;
    string s3;
    s3 = "";

    mp_anag = mapping(anag);
    int start = 0;
    int count = 0;

    cout<<"Anagram length : "<<anag.length()<<endl;
    cout<<"Actual string length : "<<s_major.length()<<endl;

    for(int end =0; end<s_major.length(); end++){
        s3 += s_major[end];
        
        cout<<end-start+1<<endl;
        if((end-start+1)!=anag.length()){
            new_mapping(mp_norm, s_major[end], ' ');
            cout<<"in the first loop : "<<endl;
            cout<<"added  : "<<s_major[end]<<endl;
        }
        else if(end-start+1==anag.length()){
            if(start == 0){
                new_mapping(mp_norm, s_major[end], ' ');
                cout<<"in the second loop : "<<endl;
                cout<<"start: "<<start<<"end : "<<end<<endl;
                cout<<"s3 : "<<s3<<endl;
                cout<<"added  : "<<s_major[end]<<endl;
                flag = compare(mp_norm, mp_anag);
                count = count + flag;
                s3.erase(s3.begin()+0);
            }
            else{
            cout<<"in the second loop : "<<endl;
            cout<<"start: "<<start<<"end : "<<end<<endl;
            cout<<"s3 : "<<s3<<endl;
            cout<<"added  : "<<s_major[end]<<endl;
            cout<<"removed  : "<<s_major[start-1]<<endl;
            new_mapping(mp_norm, s_major[end], s_major[start-1]);
            flag = compare(mp_norm, mp_anag);
            count = count + flag;
            cout<<"\ncounting: ----  "<<count<<endl;
            s3.erase(s3.begin()+0);
            }
            start++;
            
        }
    }
    cout<<"count of anagrams : "<<count;
    return 0;
}
