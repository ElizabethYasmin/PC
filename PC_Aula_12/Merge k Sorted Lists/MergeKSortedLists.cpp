
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*start=NULL,*end=NULL;
        int flag=1,min=-1;
        while(flag){
            flag=0;
            min=-1;
            for(int i=0;i<lists.size();i++){
                if(lists[i]!=NULL){
                    flag=1;
                    if(min==-1) min=i;
                    min=lists[i]->val<lists[min]->val?i:min;
                }
            }
            if(min==-1) continue;
            if(start==NULL){
                start=new ListNode(lists[min]->val);
                end=start;
            }
            else{
                end->next=new ListNode(lists[min]->val);
                end=end->next;
            }
            lists[min]=lists[min]->next;
        }
        return start;
    }

int main(){

    //vector<int> l = {{1,4,5},{1,3,4},{2,6}};
    //vector<list<ListNode>> lists;

    //lists.push_back(list<ListNode>{ 1, 4, 5 });
    //lists.push_back(list<ListNode>{}); // Empty
    //lists.push_back(list<ListNode>{ 1, 3, 4 });
    //lists.push_back(list<ListNode>{ 2, 6 });

    //list<ListNode> onelist(mergeKLists(lists));
    ListNode* n3 = new ListNode(5,nullptr);
    ListNode* n2 = new ListNode(4,n3);
    ListNode* n1 = new ListNode(1,n2);
//-------------------------------------------
    ListNode* m3 = new ListNode(4,nullptr);
    ListNode* m2 = new ListNode(3,m3);
    ListNode* m1 = new ListNode(1,m2);
//------------------------------------------
    ListNode* o2 = new ListNode(6,nullptr);
    ListNode* o1 = new ListNode(2,o2);
//-----------------------------------------
    vector<ListNode*> lists;
    lists.push_back(n1);
    lists.push_back(m1);
    lists.push_back(o1);

    ListNode* head = mergeKLists(lists);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
}