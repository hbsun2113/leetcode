#include"../head.h"
//
// Created by Mac on 2018/2/4.
//

class MinStack {
public:
    /** initialize your data structure here. */

    vector<int> array;
    vector<int> min_array;
    int minvalue=INT_MAX;
    MinStack() {
        //int min_index=0;
        array.push_back(minvalue);
        min_array.push_back(0);
    }

    void push(int x) {
        array.push_back(x);
        if(x<minvalue){
            minvalue=x;
            min_array.push_back(array.size()-1);
        }
        else{
            min_array.push_back(min_array[min_array.size()-1]);
        }
    }

    void pop() {
        array.pop_back();
        min_array.pop_back();
    }

    int top() {
        return array[array.size()];
    }

    int getMin() {
        return array[min_array.size()-1];
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