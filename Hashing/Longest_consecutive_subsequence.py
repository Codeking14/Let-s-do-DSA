def findLongestConseqSubseq(arr, n):
	
	ans = 0
	count = 0

		arr.sort()

	v = []

	v.append(arr[0])

	for i in range(1, n):
		if (arr[i] != arr[i - 1]):
			v.append(arr[i])

	for i in range(len(v)):

		if (i > 0 and v[i] == v[i - 1] + 1):
			count += 1
			
		else:
			count = 1
			
		ans = max(ans, count)
		
	return ans

arr = [ 1, 2, 2, 3 ]
n = len(arr)

print("Length of the Longest contiguous subsequence is",
	findLongestConseqSubseq(arr, n))
