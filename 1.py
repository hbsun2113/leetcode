#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 11 21:33:52 2017

@author: mac
"""


import math
import functools
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result=[]
        now=[]
        for c in candidates:
            self.recursive(candidates,target,now,result)
        return result
    
    def recursive(self,nums,target,now,result):
        if target==0:
            result.append(now)
            #print(result) 
        for num in nums:
            if target>=num:
                #print ([num]+now)
                self.recursive(nums,target-num,[num]+now,result)
            


if __name__ == "__main__":
    s=Solution()
    print (s.combinationSum([2,3,6,7],7))
