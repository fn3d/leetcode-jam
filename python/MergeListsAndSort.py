"""
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

 

Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109

 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
"""

from typing import List

temp_list = []
nums2_merged_items = []
last_add_was_num1 = False

class Solution:
    def merge1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        nums2_counter = 0
        for i in range(len(nums1)):
            if (len(nums2) > 0):
                if ((nums2[nums2_counter] >= nums1[i] or (nums1[i]==0)) and 
                    ((nums2[nums2_counter] < nums1[i+1])) or (nums1[i+1]==0)):
                    if ((last_add_was_num1 == False) and (nums1[i] != 0)):
                        temp_list.append(nums1[i])
                    temp_list.append(nums2[nums2_counter])
                    nums2_merged_items.append(nums2[nums2_counter])
                    nums2_counter += 1
                    last_add_was_num1 = False
                else:
                    temp_list.append(nums1[i])
                    temp_list.append(nums1[i+1])
                    last_add_was_num1 = True
                    print(temp_list)
                    print(nums2_merged_items)
                    print("-------------")
                if (len(temp_list) == (m + n)):
                    break
            
    def merge2(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = 0
        j = 0
        nums1_temp = nums1
        nums1 = []
        while (len(temp_list) < m + n):
            print("{" + str(i) + ", " + str(j) + "}")
            if (len(nums2) > 0):
                if (nums2[j] > nums1_temp[i]):
                    if ((len(temp_list) != 0) and nums1_temp[i] != 0):
                        if (nums1_temp[i] < temp_list[len(temp_list)-1]):
                            temp_val = temp_list[len(temp_list)-1]
                            temp_list[len(temp_list)-1] = nums1_temp[i]
                            temp_list.append(temp_val)
                            nums1.append(temp_val)
                        else:
                            temp_list.append(nums1_temp[i])
                            nums1.append(nums1_temp[i])
                    else:
                        (temp_list.append(nums1_temp[i]) if nums1_temp[i] != 0 else None)
                        (nums1.append(nums1_temp[i]) if nums1_temp[i] != 0 else None)
                    i += 1
                    temp_list.append(nums2[j])
                    nums1.append(nums2[j])
                    j += 1
                else:
                    temp_list.append(nums2[j])
                    nums1.append(nums2[j])
                    j += 1
            else:
                temp_list.extend(nums1_temp)
                nums1.extend(nums1_temp)
                break
        nums1.extend(temp_list)

if __name__ == "__main__":
    obj = Solution()

    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    m = 3
    n = 3

    """nums1 = [1]
    nums2 = []
    m = 1
    n = 0"""

    """nums1 = [0]
    nums2 = [1]
    m = 0
    n = 1"""

    """nums1 = [7,8,8,11,0,0,0,0]
    nums2 = [2,6,9,10]
    m = 4
    n = 4"""

    obj.merge2(nums1, m, nums2, n)
    print(temp_list)
    print("------------")
    