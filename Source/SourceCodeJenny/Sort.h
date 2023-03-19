//
// Created by Bui Nguyen on 21/8/2022.
//
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int BinarySearch(int a[],int n, int data ) {//O(logn)
    int l =0, r = n- 1;
    int mid;
    while (l < r) {
        mid  = (l+r)/2;
        if (data == a[mid]) {
            return mid;
        } else if(data < a[mid]) {
            r = mid -1;
        } else if(data > a[mid]) {
            l = mid +1;
        }
    }
    return -1;
}
void display(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}

void BubbleSort(int a[], int n) {//O(n^2)
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - 1- i ; ++j) {
            if(a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void InsertionSort(int a[], int n) {//O(n^2), Best is O(n)
    int temp, i, j;
    for (i = 1; i < n; ++i) {
        temp = a[i];
//      for (j = i-1; j >=0 ; j--) {if(a[j]> temp) { a[j+1] = a[j];}}
        j = i-1;
        while (j >= 0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] =temp;
    }
}

void Selection(int a[], int n) {//O(n^2)
    int min;
    for (int i = 0; i < n-1; i++) {
        min =i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        if(min != i) { swap(&a[i], &a[min]);}
    }
}
int Partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end) {
        while (a[start] <= pivot) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}
void QuickSort(int a[], int (lb),int ub) {//O(n^2), best is O(nlogn)
    int loc;
    if(lb < ub) {
        loc = Partition(a, lb, ub);
        QuickSort(a, lb, loc-1);
        QuickSort(a, loc + 1, ub);
    }
}

void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];//tạo 2 mảng tạm thời để chứa các phần tử sau khi chia

    // Copy dữ liệu sang các mảng tạm
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // khởi tạo các giá trị ban đầu
    i = 0;
    j = 0;
    k = l;

    //gộp hai mảng tạm thời vào mảng arr
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy các phần tử còn lại của mảng L vào arr nếu có
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy các phần tử còn lại của mảng R vào arr nếu có
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp
void MergeSort(int arr[], int l, int r) //O(nlogn) Best Sort
{
    if (l < r)
    {
        int m = (l+r)/2;
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);

        Merge(arr, l, m, r);
    }
}

void InsertHeap(int a[], int n, int value) {//O(nlogn)
    n = n +1;
    a[n-1] = value;
    int i = n-1;
    int Parent = (i-1)/2;
    if(a[Parent] < a[i]) {
        swap(&a[Parent], &a[i]);
        i = Parent;
    } else return;
}
void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    while (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    while (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

void ShellSort(int a[], int n) {//O(n^2)
    for (int gap = n/2; gap >=1 ; gap/2) {
        for (int j = gap; j < n; j++) {
            for (int i = j-gap; i >= 0 ; i-gap) {
                if (a[i+gap]>a[i]) {
                    break;
                } else {
                    swap(a+i+gap, a+i);
                }
            }
        }
    }
}

void countingSort(int a[], int n, int maxVal) {//No comparition sort
    int count[maxVal+1];
    int b[n];
    for (int i = 0; i < n; i++) {
        ++count[a[i]];
    }
    for (int i = 1; i <= maxVal; i++) {
        count[i] = count[i]+count[i-1];
    }
    for (int i = n-1; i >=0 ; i--) {
           b[--count[a[i]]]=a[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

int getMax(int a[],int n)
{
    int t,i;
    t=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>t)
            t=a[i];
    }
    return(t);
}

void CountSort(int a[], int n, int pos) {
    int count[10] = {0};
    int b[n];
    for (int i = 0; i < n; ++i) {
        ++count[(a[i]/pos)%10];
    }
    for (int i = 1; i < 10; ++i) {
        count[i] = count[i]+count[i-1];
    }
    for (int i = n-1; i >=0 ; i--) {
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
    }
}
void radixSort(int a[], int n) {
    int max = getMax(a, n);
    for (int pos = 1; max/pos>0 ; pos*10) {
        CountSort(a, n, pos);
    }
}

