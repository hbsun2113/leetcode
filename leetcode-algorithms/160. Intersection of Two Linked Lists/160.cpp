//
// Created by Mac on 2018/2/4.
//
#include "../head.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //https://www.cnblogs.com/grandyang/p/4128461.html
    //这道题目没思路，看了别人的解题报告，其实突破点很简单，现在第一种解法算是想得比较清楚了。
    //如果两个链表长度相等，并且有交集，那么不相等的部分肯定也是长度对应相等的，所以只要对应位置进行判断就可以了。
    //如果长度不相等，假设A更长，并且有交集，那么不相等的部分肯定也是len(A)-len(B)，所以就先让headA移动len(A)-len(B)个距离，这样就转化为第一种情况(两个链表长度相等)，后续操作是一样的。
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        int lenA=0,lenB=0;
        ListNode * preA=headA;
        ListNode * preB=headB;
        while(headA->next!=NULL){
            lenA+=1;
            headA=headA->next;
        }
        while(headB->next!=NULL){
            lenB+=1;
            headB=headB->next;
        }
        headA=preA;
        headB=preB;
        if(lenA==lenB){
            while(headA!=headB && headA!=NULL){
                headA=headA->next;
                headB=headB->next;
            }
            return headA;
        }
        if(lenA>lenB){
            int diff=lenA-lenB;
            int time=0;
            while(time<diff){
                time+=1;
                headA=headA->next;
            }
            while(headA!=headB && headA!=NULL){
                headA=headA->next;
                headB=headB->next;
            }
            return headA;
        }
        if(lenA<lenB){
            int diff=lenB-lenA;
            int time=0;
            while(time<diff){
                time+=1;
                headB=headB->next;
            }
            while(headA!=headB && headB!=NULL){
                headA=headA->next;
                headB=headB->next;
            }
            return headA;
        }
    }

    //第二种解法相对更巧妙一些。是将A的尾链到B的头，B的尾链到A的头。
    //若len(A)==len(B)就没啥好说的了。
    //考虑两个链表有重合部分。假设还是A比较长，"A的指针第一次遍历完A"和"B的指针第一次遍历完B"时，二者肯定不能在重合起始位置相遇，因为差了len(A)-len(B)步，现在把A指针链到B头部，把B指针链到A头部，这样在第一遍历时的差异正好反了过来，即消除了两个指针在第一次遍历时的差异,这样同步的结果就是二者一定会在重合的起始位置相遇。
    //换种说法，第一次遍历时，A指针差了len(A)-len(B)步追赶到B指针--和B指针在重合的起始位置相遇，第二次遍历开始时，就把这差的步数消了回来。画个图可能更好一些，假设A中不同部分长度为a,B中不同部分长度为b,二者重合部分长度为c，则当两指针同时走过了a+b+c个步时，二者在重合起始位置相遇。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode * preA=headA;
        ListNode * preB=headB;
        while(headA!=headB){
            headA= headA!=NULL ? headA->next : preA;
            headB= headB!=NULL ? headB->next : preB;
        }
        return headA;
    }
};