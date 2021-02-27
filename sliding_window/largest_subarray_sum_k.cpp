// Given an array, find the subarray with largest length with given sum
#include <iostream>
using namespace std;

class subarray_sum{
    private:
    int size, end, sum, s, start, max_l, flag;
    public:
    subarray_sum();
    void solve(int arr[]);
};

void subarray_sum :: solve(int arr[]){
    start = 0;
    end = 0;
    sum = 0;
    max_l = 0;
    flag = 1;
    
    while(end<size){
        cout<<"---------------------"<<endl;
        //1 3 9 13 12 1 2 3 4 3
        if(flag != 0 ){
            sum = sum + arr[end];
        }
        cout<<start<<" "<<end<<"  "<<max_l<<"  "<<sum<<"  "<<size<<" "<<flag<<endl;
        if(sum < s){
            flag = 1;
            end++;
            continue;
        }
        if(sum == s){
            flag = 1;
            if(max_l < end - start + 1){
                max_l = end - start + 1;
            }
            end++;
        }
        else if(sum > s){
            sum = sum - arr[start];
            start++;
            flag = 0;
        }
        
    }
    cout<<"Max length subarray : "<<max_l;
}

subarray_sum :: subarray_sum(){
    cout<<"\n\nEnter the size of the array : "<<endl;
    cin>>size;
    cout<<"Enter the array elements: ";
    int arr[size];
    for(int i =0; i<size ; i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the sum for which you are searching the longest length of the array  : "<<endl;
    cin>>s;
    solve(arr);

}

int main(){
    subarray_sum s1, s2;

    return 0;
}