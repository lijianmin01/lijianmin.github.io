#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int swap(int* arr,int i,int j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int partition(int *arr,int low,int high){
    while(low<high){
        //右边的元素大于左边的元素
        while(low<high && arr[low]<arr[high]){
            //箭头左移
            high--;
        }
        if (low<high)
        {
            swap(arr,low,high);
            //左边的元素右移
            low++;
        }
        while (low<high && arr[low]<=arr[high])
        {
            low++;
        }
        if(low<high){
            swap(arr,low,high);
            high--;
        }
        
    }
    return low;
}

void quitSort1(int* arr,int left,int right){
    //用递归的方法实现快排
    //首先是递归的终止条件
    if(left>=right){
        return;
    }
    int mid = partition(arr,left,right);
    quitSort1(arr,0,mid-1);
    quitSort1(arr,mid+1,right);
}

//快速排序包装
void quitSort(int* arr){
    quitSort1(arr,0,8);
}


int main(){
    int arr[]={5,1,7,8,9,2,0,10,3,10};
    cout<<"排序之前的数组：";
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<< endl;
    quitSort(arr);
    cout<<"排序之后的数组：";
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}