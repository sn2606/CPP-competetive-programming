# Given an array nums with n integers, your task is to check if it could become 
# non-decreasing by modifying at most one element.
# We define an array is non-decreasing if nums[i] <= nums[i + 1] holds 
# for every i (0-based) such that (0 <= i <= n - 2).

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        flag = 1
        changed = 0
        n = len(nums)
        for i in range(0, n-1):
            if nums[i] > nums[i+1]:
                if changed == 1:
                    flag = 0
                    break
                else:
                    if i == n-2 or i == 0:
                        changed += 1
                        flag = 1
                    elif nums[i] <= nums[i+2] or nums[i-1] <= nums[i+1]:
                        changed += 1
                        flag = 1
                    else:
                        flag = 0
                        break
        return flag == 1