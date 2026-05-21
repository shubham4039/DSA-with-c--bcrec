class Solution {
    public int[] asteroidCollision(int[] asteroids) {
      Stack<Integer> space = new Stack<>();

      for(int CurrentAsteroid : asteroids)
      {
        boolean Destroyed = false;
        while(!space.isEmpty() &&
               CurrentAsteroid < 0 &&
               space.peek()> 0
               ){
                if(Math.abs(CurrentAsteroid) > space.peek())
                {
                    space.pop();
                    continue;
                }
                if(Math.abs(CurrentAsteroid) == space.peek())
                {
                    space.pop();
                }
                Destroyed = true;
                break;
               }
               if(!Destroyed)
               {
                space.push(CurrentAsteroid);
               }
      }
      int[]FinalAsteroidsInSpace = new int[space.size()];
      for(int i =  FinalAsteroidsInSpace.length-1 ; i>=0 ; --i)
      {
        FinalAsteroidsInSpace[i] = space.pop();
      }
      return FinalAsteroidsInSpace;
    }
      }
               
                
               
       
    
