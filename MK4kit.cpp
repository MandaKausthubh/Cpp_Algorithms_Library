#include<bits/stdc++.h>
using namespace :: std;


template <typename T>
//Linked Lists
class Linked_List{
    T Data ;
    Linked_List* PointerNext;
    Linked_List* PointerPrevious;
    int size;

    private:
        bool StandardComparator(T a, T b){return a < b;}

        void mergeSort(T arr[], int l, int r, bool (*func)(T, T) = StandardComparator)
        {
            int mid = (l + r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);

            //Merging the two parts
            int k = 0, temp_l = l, temp_r = r;
            int temporary_array[l-r+1];
            while(temp_l < mid+1 && temp_r < r+1)
            {
                if(func(arr[temp_l], arr[temp_r])) temporary_array[k++] = arr[temp_l++];
                else temporary_array[k++] = arr[temp_r++];
            }
            while(temp_l < mid+1) temporary_array[k++] = arr[temp_l++];
            while(temp_r < r+1) temporary_array[k++] = arr[temp_r++];
        }

    public:
        Linked_List(int val) {
            data = val;
            PointerNext = NULL;
            PointerPrevious = NULL;
        }

        void InsertFront(int val)
        {
            Linked_List Temp = *this;
            while(this.PointerNext){
                Temp = Temp.PointerNext;
            }
            Temp.PointerNext = new Linked_List(val);
            Temp.PointerNext.PointerPrevious = Temp;
        }

        void InsertBack(int val)
        {
            this.PointerPrevious = new Linked_List(val);
            this.PointerPrevious.PointerNext = this;
            this = this.PointerPrevious;
        }

        void PopFront(){
            Linked_List old = *this;
            this = this.PointerNext;
            delete(old);
        }

        void PopBack(){
            Linked_List Temp = *this;
            while(Temp.PointerNext){
                Temp = Temp.PointerNext;
            }
            if(Temp == *this){
                this = NULL;
            }
            delete(Temp);
        }

        T ValueAt(int target){
            if(target >= size) return NULL;
            Linked_List Temp = *this;
            for(int index = 0; index < target; index++)
            {
                Temp = Temp.PointerNext;
            }
            return Temp.Data;
        }

        void Sort(int leftPtr = 0, int rightPtr = size - 1, bool (*func)(T, T) = StandardComparator){
            //mergeSort applied
            if(leftPtr < rightPtr)
            {
                Linked_List Temp = *this;
                T arr[rightPtr - leftPtr + 1];
                for(int i = 0; i < rightPtr - leftPtr + 1; i++){arr[i] = Temp.Data; Temp = Temp.PointerNext;}
                mergeSort(arr, 0, rightPtr - leftPtr, func);
                for(int i = 0; i < rightPtr - leftPtr + 1; i++){Temp.Data = arr[i]; Temp = Temp.PointerNext;}
            }

        }
};

int main(void)
{
    return 0;
}
