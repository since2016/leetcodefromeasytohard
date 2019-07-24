// 二分查找 递归与非递归
int BinarySearch(int arr[], int value, int low, int high){
    if (low>high)
    {
        return -1;
    }
    int mid = low+(high-low)/2;
    if (arr[mid]==value)
    {
        return mid;
    }
    if (arr[mid]>value)
    {
        return BinarySearch(arr, value, low, mid-1);
    }
    if (arr[mid]<value)
    {
        return BinarySearch(arr, value, mid+1, high);
    }
    
}

int BinarySearch(int arr[], int value, int n){
    int low, high, mid;
    low = 0, high = n -1;
    while (low<=high)
    {
        mid = low+(high-low)/2;
        if (arr[mid]==value)
        {
            return mid;
        }
        if (arr[mid]>value)
        {
            high = mid - 1;

        }if (arr[mid]<value)
        {
            low = mid + 1;
        }
    }
    return -1;
    
}

void BubbleSort(int arr[]){
    int len = arr.size();
    bool flag;
    for (int i = 0; i < len-1; i++)
    {
        flag = false;
        for (int j = len-1; j > i; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j], arr[j-1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        } 
    }
}

/** 快排 **/
int partition(int arr[], int l, int r){
    int key = arr[l];
    int index = l;
    while (l<r)
    {
        while(l<r&&arr[r]>=key)
            r--;
        // 改进
        arr[l] = arr[r];
        while (l<r&&arr[l]<=key)
        {
            l--;
        }
        //改进
        arr[r] = arr[l];

        swap(arr[l], arr[r]);
        
    }
    swap(arr[l], arr[index]);
    return l;
}

void quicksort(int arr[], int l, int r){
    if (l>=r)
    {
        return;
    }
    int pos = partition(arr, l, r);
    quicksort(arr, l , pos - 1);
    quicksort(arr, pos+1, r);
    
}