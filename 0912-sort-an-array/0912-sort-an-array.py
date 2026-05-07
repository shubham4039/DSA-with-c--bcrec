class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        if n <= 1:
            return nums

        mid = n//2
        left_half = self.sortArray(nums[:mid])
        right_half = self.sortArray(nums[mid:])

        def merge(left, right):
            l = len(left) + len(right)
            result = []
            i = j = 0

            for val in range(l):
                if left[i] <= right[j]:
                    result.append(left[i])
                    i += 1
                    if i == len(left):
                        result.extend(right[j:])
                        break
                else:
                    result.append(right[j])
                    j += 1
                    if j == len(right):
                        result.extend(left[i:])
                        break
            
            return result


        return merge(left_half, right_half)