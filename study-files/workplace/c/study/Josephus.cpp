#include "stdio.h"

/* solution 1 : using circular list*/
struct ListNode
{
    int num;
    ListNode* next;
    ListNode(int n = 0, ListNode* p = NULL){
        num = n;
        next = p;
    }
};

int JosephusProblem_Solution1(int n, int m) {
    if (n<1 || m<1)
        return -1;

    ListNode* pHead = new ListNode();
    ListNode* pCurrentNode = pHead;
    ListNode* pLastNode = NULL;

    int i;
    for (i=1; i<n; ++i) { // create a circular list
        pCurrentNode->next = new ListNode(i);
        pCurrentNode = pCurrentNode->next;
    }
    pCurrentNode->next = pHead;
    pLastNode = pCurrentNode;
    pCurrentNode = pHead;

    while (pCurrentNode->next != pCurrentNode) {
        for (i=0; i<m-1; ++i) { // goto the first m
            pLastNode = pCurrentNode;
            pCurrentNode = pCurrentNode->next;
        }
        pLastNode->next = pCurrentNode->next; // delete current node
        delete pCurrentNode;
        pCurrentNode = pLastNode->next;
    }

    int result = pCurrentNode->num;
    delete pCurrentNode;

    return result;
}
/*
// using standard library
int JosephusProblem_Solution2(int n, int m) {
    if (n<1 || m<1)
        return -1;

    list<int> listInt;
    int i;
    for (i=0; i<n; ++i)
        listInt.push_back(i);

    list<int>::iterator iterCurrent = listInt.begin();

    while (listInt.size()>1) {
        for (i=0; i<m; ++i)
            if (++iterCurrent == listInt.end())
                iterCurrent = listInt.begin();
        list<int>::iterator iterDel = iterCurrent;
        if (++iterCurrent == listInt.end())
            iterCurrent = listInt.begin();
        listInt.erase(iterDel);
    }
    return *iterCurrent;
}
*/
int JosephusProblem_Solution3(int n, int m) {
    if (n<1 || m<1)
        return -1;
    int i;
    int* f = new int[n+1];
    f[1] = 0;

    for (i=2; i<=n; ++i)
        f[i] = (f[i-1] + m) % i;

    int result = f[n];
    delete []f;

    return result;
}

int main(int argc, char *argv[])
{
    int m = 3, n = 10;
    int result = 0;
    result = JosephusProblem_Solution1(n, m+1);
    printf("The result is %d\n", result);
    
    result = JosephusProblem_Solution3(n, m+1);
    printf("The result is %d\n", result);
    
    return 0;
}
