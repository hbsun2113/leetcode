#include"../head.h"
//
// Created by Mac on 2018/2/4.
//

class MinStack {
public:
    /** initialize your data structure here. */
    //水题还做了将近一个小时，主要是忘了更新minvalue。貌似大家用的数据结构是栈，只有我用的是vector？下次再做的时候可以换一下栈。
    vector<int> array;
    vector<int> min_array;
    int minvalue=INT_MAX;


    MinStack() {
        array.push_back(minvalue);
        min_array.push_back(0);
    }

    void push(int x) {
        cout<<"push:"<<x<<endl;
        array.push_back(x);
        if(x<=minvalue){
            minvalue=x;
            min_array.push_back(array.size()-1);
        }
        else{
            int end=min_array.back();
            min_array.push_back(end);
        }
    }

    void pop() {
        cout<<"pop"<<endl;
        if(array.size()==1) return;
        array.pop_back();
        min_array.pop_back();
        minvalue=array[min_array.back()];//这个别忘了 但是就是忘了更新这个 调试了蛮久的时间。
    }

    int top() {
        cout<<"top"<<endl;
        return array.back();
    }

    int getMin() {
        cout<<"getMin"<<endl;
        return array[min_array.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */