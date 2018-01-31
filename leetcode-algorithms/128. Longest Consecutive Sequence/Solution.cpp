class Solution {
public:
    //由于我先进行了排序 因此不符合O(n)的要求 此解法无效(虽然可以AC)
    // {0,1,2,1}返回3
    int longestConsecutive1(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int result=1;
        unordered_map<int,int> length;
        length[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            if(length.find(nums[i]-1)!=length.end()) 
                length[nums[i]]=length[nums[i]-1]+1;
            else 
                length[nums[i]]=1;
            result=max(result,length[nums[i]]);
        }
        return result;
        
    }
    
    
    //https://leetcode.com/problems/longest-consecutive-sequence/discuss/41055/
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int result=1;
        unordered_map<int,int> length;
        int left,right,sum;
        for(auto n:nums){
            //for(auto l:length) cout<<"length "<<l.first<<":"<<l.second<<endl;
            if(length.find(n)==length.end()){
                //注意这两行不可以替换成left=length[n-1],因为这样的话如果n-1不存在length里面，就会新创建一个{n-1:0}，而这不是我们希望的。我们希望，如果n-1不存在length里面，直接返回0就好了，不会对length进行改动。
                left=length.find(n-1)==length.end()?0:length[n-1];
                right=length.find(n+1)==length.end()?0:length[n+1];
                

                sum=left+right+1;
                
                //只要改变边界就好了，中间的值不用care，反正不会是最大值。
                //要改变这个是考虑到只有增加边界扩展的时候才能改变最大值。
                length[n-left]=sum;
                length[n+right]=sum;
                result=max(result,sum);
                
                length[n]=sum;//这行必须要加，是因为避免有重复值出现，然后重复加和。
                
                
            }
            // else{
            //     cout<<n<<" "<<length[n]<<endl;
            // }
        }
        return result;
    }
};