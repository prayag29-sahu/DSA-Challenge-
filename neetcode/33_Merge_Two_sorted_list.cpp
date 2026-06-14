#include<iostream>
using namespace std;

struct list{
    int val;
    list *next;
    list() : val(0),next(nullptr) {}
    list(int val): val(val), next(nullptr){}
    list(int val, list *next) : val(val), next(next){}
};

list *mergeSortedList(list * l1, list * l2){
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    list ans(0);
    list *temp = &ans;
    while(l1 && l2){
        if(l1->val <= l2->val){
            temp->next = l1;
            l1 = l1->next;
        }else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1){
        temp->next = l1;
    }
    if(l2){
        temp->next = l2;
    }
    return ans.next;
}

    int main()
{
    list *l1 = new list(1);
    l1->next = new list(2);
    l1->next->next = new list(4);   

    list *l2 = new list(1);
    l2->next = new list(3);
    l2->next->next = new list(4);

    list *ans = mergeSortedList(l1, l2);
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}