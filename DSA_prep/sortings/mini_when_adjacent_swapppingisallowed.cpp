//https://www.geeksforgeeks.org/number-swaps-sort-adjacent-swapping-allowed/


//Number of swaps to sort when only adjacent swapping allowed


/*
Time Complexity: O(n Log n)
Auxiliary Space: O(n)
*/

int merge(vi& arr, int temp[], int left, int mid, int right)
{
    int inv_count = 0;
    int i = left; 
    int j = mid;  
    int k = left; 
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
 
            inv_count = inv_count + (mid - i);
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
int _mergeSort(vi& arr, int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
 
        inv_count += merge(arr, temp, left, mid+1, right);
    }
 
    return inv_count;
}
 
int countSwaps(vi& arr, int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}




//// also
 
//bubble sort can be used in O(n^2) tc