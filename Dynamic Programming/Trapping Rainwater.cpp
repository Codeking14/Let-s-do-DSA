/*Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.*/

/*Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9
*/

/*Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

/* Algorithm

->Find maximum height of bar from the left end upto an index i in the array left_max.
->Find maximum height of bar from the right end upto an index i in the array right_max.
->Iterate over the height array and update ans:
  -Add min(left_max[i],right_max[i]) - height[i]min(left_max[i],right_max[i])−height[i] to ans*/


int trapRainwater(vector<int>& height)
{
    if(height.empty())
        return 0;
    int answer = 0;
    int size = height.size();
    vector<int> left(size), right(size);
    left[0] = height[0];
    for (int i = 1; i < size; i++) {
        left[i] = max(height[i], left[i - 1]);
    }
    right[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right[i] = max(height[i], right[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        answer += min(left[i], right[i]) - height[i];
    }
    return answer;
}