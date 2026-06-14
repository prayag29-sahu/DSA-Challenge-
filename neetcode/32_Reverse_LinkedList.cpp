#include <iostream>
using namespace std;

struct list
{
    int val;
    list *next;
    list() : val(0), next(nullptr) {}
    list(int val) : val(val), next(nullptr) {}
    list(int val, list *next) : val(val), next(next) {}
};

list *reverse(list *l1){
    if (!l1 || !l1->next)
    {
        return l1;
    }
    list *prev = nullptr;
    list *curr = l1;
    while (curr)
    {
        list *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    list *l = new list(1);
    l->next = new list(2);
    l->next->next = new  list(3);
    l->next->next->next = new list(4);
    l->next->next->next->next = new list(5);
    l = reverse(l);
    while(l != nullptr){
        cout<<l->val<<" ";
        l = l->next;
    }

}