#include <iostream>

int* merge_arrays(int* arr1, int size1, int* arr2, int size2, int size3);
void print_arr(int* arr, int size);

int main()
{
    int first_arr[] = {1, 3, 5, 7};
    int second_arr[] = {2, 4, 6, 8};
    int size1 = sizeof(first_arr) / sizeof(first_arr[0]);
    int size2 = sizeof(second_arr) / sizeof(second_arr[0]);
    int size3 = size2 + size1;
    int* third_arr = merge_arrays(first_arr, size1, second_arr, size2, size3);
    print_arr(third_arr, size3);
    
    delete [] third_arr;
    
    
}

int* merge_arrays(int* arr1, int size1, int* arr2, int size2, int size3)
{
    int* arr3 = new int[size3];
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            ++i;
        } else {
            arr3[k] = arr2[j];
            ++j;
        }
        ++k;
    }
    while(i < size1)
    {
        arr3[k] = arr1[i];
        ++k;
        ++i;
    }
    while(j < size2)
    {
        arr3[k] = arr2[j];
        ++k;
        ++j;
    }
  
    return arr3;
}

void print_arr(int* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


    

