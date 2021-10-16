// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the sum of a
// triplet which is closest to x
int solution(vector<int>& arr, int x)
{

    // Sort the array
    sort(arr.begin(), arr.end());

    // To store the closest sum
  //not using INT_MAX to avoid overflowing condition 
    int closestSum = 1000000000;

    // Fix the smallest number among
    // the three integers
    for (int i = 0; i < arr.size() - 2; i++) {

        // Two pointers initially pointing at
        // the last and the element
        // next to the fixed element
        int ptr1 = i + 1, ptr2 = arr.size() - 1;

        // While there could be more pairs to check
        while (ptr1 < ptr2) {

            // Calculate the sum of the current triplet
            int sum = arr[i] + arr[ptr1] + arr[ptr2];

            // If the sum is more closer than
            // the current closest sum
            if (abs(1LL*x - sum) < abs(1LL*x - closestSum)) {
                closestSum = sum;
            }

            // If sum is greater then x then decrement
            // the second pointer to get a smaller sum
            if (sum > x) {
                ptr2--;
            }

            // Else increment the first pointer
            // to get a larger sum
            else {
                ptr1++;
            }
        }
    }

    // Return the closest sum found
    return closestSum;
}

// Driver code
int main()
{
    vector<int> arr = { -1, 2, 1, -4 };
    int x = 1;
    cout << solution(arr, x);

    return 0;
}
