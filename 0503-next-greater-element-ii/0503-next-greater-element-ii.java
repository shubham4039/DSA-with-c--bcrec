class Solution {
    public int[] nextGreaterElements(int[] nums) {
      int N                 = nums.length;
      int[] Result           = new int[N];
      Arrays.fill(Result,-1);
      Stack<Integer> stack = new Stack<>();
      for(int i = (N*2)-1 ;  i>=0 ; --i)
      {
        int CurrentIndex      =i % N;

        while(! stack.isEmpty() && stack.peek() <= nums[CurrentIndex])
        {
            stack.pop();
        }
        if(!stack.isEmpty() && i< N){
            Result[CurrentIndex] = stack.peek();
        }
        stack.push(nums[CurrentIndex]);
      }
      return Result;
    }
        }