// Sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
//1.插入排序算法[数据越趋于有序效率越高]
/// 最好时间复杂度：     O(n) 已经有序
/// 最坏与平均时间复杂度：O(n^2) 
/// 空间复杂度：        O(1) ，就使用了一个辅助数组
/// 稳定性：稳定
static void InsertSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) { //O(n)
        auto val = arr[i];
        //从待排序元素的前一个位置从后往前找第一个小于等于待排序元素的元素
        int j = i - 1;
        for (; j >= 0; j--) {       //O(n)
            if (arr[j] <= val) {
                break;
            }
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = val;
    }
}
//2.折半插入排序

//3.希尔排序
/// 平均时间复杂度：依据不同的增量序列设置O(n^1.3)
/// 最坏时间复杂度：O(n^2)
/// 最好时间复杂度：O(n)
/// 空间复杂度：   O(1)
/// 稳定性：不稳定（可能会将不同的元素调整到不同的组里既不能保证元素的相对顺序）
/// 一般中等数据量的排序都用希尔排序，选择合适的增量序列，效率很不错
static void ShellSort(int arr[], int size)
{
    //确定分组
    for (int gap = size / 2; gap > 0; gap /= 2) {
        //将i指向gap处
        for (int i = gap; i < size; i++) { //O(n)
            auto val = arr[i];
            //从待排序元素的前一个位置从后往前找第一个小于等于待排序元素的元素
            int j = i - gap;
            for (; j >= 0; j-=gap) {  //同一个分组里的元素进行比较 O(n)
                if (arr[j] <= val) {
                    break;
                }
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = val;
        }
    } 
}
//*4.冒泡排序
/// 核心思想：从数组中第一个元素开始两两进行比较，大的往后放（下沉），小的往前放（上浮）
/// 冒泡排序是所有排序算法中效率最低的
/// 空间复杂度 ：O(1)
/// 时间复杂度 ：
/// 最好：O(n) ，数据已经有序，无需交换
/// 最坏：O(n^2)
/// 平均：O(n^2)
/// 稳定性：稳定
template<typename T>
static void BubbleSort(std::vector<T>& vec)
{
    //n个数要进行n - 1趟交换
    for (int i = 0; i < vec.size() - 1; i++) { //O(n)
        //j<size - 1是因为防止越界，即顶多使j指向倒数第二个位置的元素，要是能指向最后一个位置，j + 1则会指向数组外
        //-i是因为每趟比较均会去掉一个最大值不用比较
        bool flag{ false };
        for (int j = 0; j < vec.size() - 1 - i; j++) { //O(n)
            if (vec[j] > vec[j + 1]) {
                T temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
            flag = true;
        }
        if (!flag) {//如果在一趟处理中没有做任何的数据交换则说明数据已经有序
            std::cout << "数据已经有序.\n";
            return;
        }
    }
}
//**5.快速排序
/// 空间复杂度 ：O(logn) - O(n)
/// 时间复杂度 ：
/// 最好：O(nlogn) ,递归深度为logn,每趟比较n次
/// 最坏：O(n^2)
/// 平均：O(nlogn)
/// 稳定性：不稳定
namespace QuickSort {
    static int Partition(std::vector<int>& vec, int begin, int end) {
        int pivot = vec[begin];//记录基准数
        while (begin < end) {
            //在基准右边的表中利用end一直扫
            while (begin < end && vec[end] > pivot) {
                end--;
            }
            //找到了小于pivot的数
            if (begin < end) {
                vec[begin] = vec[end];
                begin++;
            }
            //在基准左边的表中利用begin一直扫
            while (begin < end && vec[begin] < pivot) {
                begin++;
            }
            //找到了大于pivot的数
            if (begin < end) {
                vec[end] = vec[begin];
                end--;
            }
        }
        //begin == end
        //即该次划分结束将最后一个比较的元素放到基准位置处
        vec[begin] = pivot;
        return begin;
    }
    static void QuickSort(std::vector<int>& vec, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int pos = Partition(vec, begin, end);
        QuickSort(vec, begin, pos - 1);
        QuickSort(vec, pos + 1, end);
    }

    static void QuickSortTest() {
        std::vector<int> arry{};
        srand(time(NULL));
        for (auto i{ 0 }; i < 10; i++) {
            arry.push_back(rand() % 100 + 1);
        }
        int n = arry.size();
        QuickSort(arry,0,n - 1);
        for (auto& item : arry) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}//namespace QuickSort
//6.选择排序
///每次在剩下的元素中选择值最小的元素和当前元素进行交换 
///空间复杂度：O(1)
///最好时间复杂度:O(n^2)
///最坏时间复杂度:O(n^2)
///平均时间复杂度:O(n^2)
///稳定性：不稳定
static void SelectionSort(std::vector<int>& array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        int minimum_index = i; //假设当前元素为最小值，记录下标
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minimum_index]) {
                minimum_index = j;
            }
        }
        //每一个趟处理后交换初始定的最小值与找到的比初始定的最小值还小的位置
        if (minimum_index != i) {//不需要与本身进行交换
            std::swap(array[i], array[minimum_index]);
        }    
    }
}
//7.二路归并排序
///也使用分治思想，即先进行序列划分再进行合并
/// 空间复杂度 ：O(n)
/// 时间复杂度 ：
/// 最好：O(nlogn) ,递归深度为logn,每趟比较n次
/// 最坏：O(nlogn)
/// 平均：O(nlogn)
/// 稳定性：稳定
namespace MergeSort {
    static void Merge(std::vector<int>& arr, int begin, int mid, int end) {
        std::vector<int> p(end - begin + 1);
        int index{};
        int left = begin;
        int right = mid + 1;
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                p[index++] = arr[left++];
            }
            else if (arr[right] <= arr[left]) {
                p[index++] = arr[right++];
            }
        }
        //处理剩余元素
        while (left <= mid) {
            p[index++] = arr[left++];
        }
        while (right <= end) {
            p[index++] = arr[right++];
        }
        //再把合并好的大段有序的结果拷贝到原始数组中
        for (left = begin, right = 0; left <= end; left++, right++) {
            arr[left] = p[right];
        }
    }
    static void MergeSort(std::vector<int>& arr,int begin,int end) {
        if (begin >= end) {
            return;
        }
        int mid = (begin + end) / 2;
        //先递归
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);
        //再归并
        //[begin,mid] [mid+1,end]把两个小段有序的序列合并成大断有序的序列
        Merge(arr, begin, mid, end);
    }
    static void MergeSort(std::vector<int>& arr,int size) {
        MergeSort(arr, 0, size - 1);
    }
    static void MergeSortTest()
    {
        std::vector<int> arr{};
        srand(time(NULL));
        for (auto i{ 0 }; i < 10; i++) {
            arr.push_back(rand() % 62 + 1);
        }
        MergeSort(arr, arr.size());
        for (auto& item : arr) {
            std::cout << item << " ";
        }
    }
}//namespace MergeSort
//8.基数排序

int main()
{
    int arr[10] = { 34,22,10,9,43,22,99,12,-98,1 };
    InsertSort(arr,10);
    for (auto& item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    ShellSort(arr, 10);
    for (auto& item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
#if 0
    std::vector<int> arrx{};
    srand(time(NULL));
    for (auto i{ 0 }; i < 10; i++) {
        arrx.push_back(rand() % 100 + 1);
    }
    for (auto & item : arrx) {
        std::cout << item << " ";
    }

    std::vector<int> arry{};
    srand(time(NULL));
    for (auto i{ 0 }; i < 10; i++) {
        arry.push_back(rand() % 100 + 1);
    }
    BubbleSort<int>(arry);
    for (auto& item : arry) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
#endif
    std::cout << "快速排序\n";
    QuickSort::QuickSortTest();
    std::cout << "简单选择排序\n";
    std::vector<int> arry{};
    srand(time(NULL));
    for (auto i{ 0 }; i < 10; i++) {
        arry.push_back(rand() % 90 + 1);
    }
    SelectionSort(arry);
    for (auto& item : arry) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << "归并排序\n";
    MergeSort::MergeSortTest();
}
#include <list>
namespace OS {

    struct PCB {
        int pid; // 进程ID
        // 其他进程相关信息
    };
    //信号量定义
    struct semaphore
    {
        int value;            //信号量值
        std::list<PCB*> list; //信号量队列指针 
    };
    //P操作
    static void P(semaphore& s){
        s.value--;
        if (s.value < 0) {
            asleep(&(s.list));
        }
    }
    //V操作
    static void V(semaphore& s) {
        s.value++;
        if (s.value <= 0) {
            awake(&(s.list));
        }
    }

    // 模拟的休眠函数
    void asleep(std::list<PCB*>* list) {
        // 模拟将当前进程加入等待队列
        PCB* current_process = new PCB(); // 这是一个示例，实际应用中需要获取当前进程
        list->push_back(current_process);
        std::cout << "Process " << current_process->pid << " is sleeping." << std::endl;
    }
    // 模拟的唤醒函数
    void awake(std::list<PCB*>* list) {
        if (!list->empty()) {
            PCB* process_to_awake = list->front();
            list->pop_front();
            std::cout << "Process " << process_to_awake->pid << " is waking up." << std::endl;
            delete process_to_awake; // 这是一个示例，实际应用中需要处理进程的恢复
        }
    }
}