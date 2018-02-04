#include"../head.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //其实这道题目还挺难想的 希望下次做的时候可以不看参考独立做出来。
    //https://www.cnblogs.com/grandyang/p/4280120.html
    int maxPathSum(TreeNode* root) {
        int maxpath=INT_MIN;
        sumpath(root,maxpath);
        return maxpath;
    }
    
    int sumpath(TreeNode* root,int &maxpath){
        if(!root) return 0;
        int left=max(sumpath(root->left,maxpath),0);//如果还小于0呢 那宁可不要这些子节点了，所以先进行预处理一下。
        int right=max(sumpath(root->right,maxpath),0);
        maxpath=max(maxpath,root->val+left+right);//看看当前根结点代表的子树是不是就是最大路径了
        return root->val+max(left,right);//只选择一边：左子树或右子树
    }
};