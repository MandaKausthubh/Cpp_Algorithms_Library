#include<bits/stdc++.h>
using namespace :: std;


template <typename T>
//Linked Lists
class Linked_List{
    T Data ;
    Linked_List* PointerNext;
    Linked_List* PointerPrevious;
    int size;

    public:
        Linked_List(int val) {
            data = val;
            PointerNext = NULL;
            PointerPrevious = NULL;
        }

        void InsertFront(int val)
        {
            Linked_List* Temp = this;
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
            Linked_List* old = this;
            this = this.PointerNext;
            delete(old);
        }

        void PopBack(){
            Linked_List* Temp = this;
            while(Temp.PointerNext){
                Temp = Temp.PointerNext;
            }
            if(Temp == this){
                this = NULL;
                delete(Temp);
            }
        }

        // int ValueAt(int target){
        //     if(target > size-1) return NULL;
        //     for(int index = 0; index < target; index++){
        //         if(index == target) return 
        //     }
        // }
};

int main(void)
{
    return 0;
}
