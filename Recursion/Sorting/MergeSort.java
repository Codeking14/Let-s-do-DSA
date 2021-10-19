package recursion;

public class MergeSort {

    public static int[] Mergesort(int arr[], int low, int high) {

        if(low==high){
            int[] br=new int[1];
            br[0]=arr[low];
            return br;
        }
        int mid = (low + high) / 2;

        int[] ls = Mergesort(arr, low, mid);
        int[] rs = Mergesort(arr, mid + 1, high);
        
        int result[]= mergetwosorted(ls,rs);
        
        
        return result;

    }

    public static int[] mergetwosorted(int arr1[], int arr2[]) {

        int result[] = new int[arr1.length + arr2.length];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < arr1.length && j < arr2.length) {

            if (arr1[i] < arr2[j]) {
                result[k] = arr1[i];
                i++;
                k++;
            } else {
                result[k] = arr2[j];
                j++;
                k++;
            }
        }

        if (i == arr1.length) {
            while (j < arr2.length) {
                result[k] = arr2[j];
                j++;
                k++;
            }
        }

        if (j == arr2.length) {
            while (i < arr1.length) {
                result[k] = arr1[i];
                i++;
                k++;
            }
        }
        return result;
    }

    public static void main(String[] args) {
//      
//        int arr1[]={2,3,7,8,9};
////        int arr2[]={5,6,20,33,89};
//        int arr[]=mergetwosorted(arr1,arr2);
//        

        int arr1[] = {3, 6, 2, 7, 33, 8, 98};
        int arr[] = Mergesort(arr1, 0, arr1.length - 1);
        for (int i : arr) {
            System.out.println(i);
        }

    }

}
