float medianOfArray(int arr[], int size) 
{ 
  if (size % 2 == 0) 
    return (arr[size/2] + arr[size/2 - 1])/2.0; 
  else 
    return arr[size/2]; 
} 

float median(int arr1[], int arr2[], int size)
{

  if (size == 1) 
  {
    return (arr1[0] + arr2[0])/2.0;
  }

  else if (size == 2)
  {
    return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2.0;
  }
  else
  {
    float m1 = medianOfArray(arr1,size);
    float m2 = medianOfArray(arr2,size);


    if (m1 == m2)
    {
      return m1;
    }

    if (m2 > m1)
    {
  
      if (size % 2 == 0) 
      {
        return median(arr1 + size/2 - 1, arr2, size - size/2 + 1);
      }
      else
      {
        return median(arr1 + size/2, arr2, size - size/2); 
      } 
    }
    else if (m1 > m2)
    {
      if (size % 2 == 0) 
      {
	    	return median(arr1, arr2 + size/2 - 1, size - size/2 + 1); 
      }
      else
      {
	      return median(arr1, arr2 + size/2, size - size/2); 
      }
    }
  }
}

int main()
{
  int arr1[] = {1,3,5};
  int arr2[] = {2,4,6};
  int size = sizeof(arr1)/sizeof(arr1[0]);
  float medianOfTwoArr = median(arr1, arr2, size);
  cout << "Median of the two arrays is: " << medianOfTwoArr;
  return 0;
}
