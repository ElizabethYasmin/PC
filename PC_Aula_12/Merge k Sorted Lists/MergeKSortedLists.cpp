ListNode* mergeKLists(vector<ListNode*>& lists) {
      
        ListNode*start=NULL,*end=NULL;
        int flag=1,min=-1;
        while(flag)
        {
            flag=0;
            min=-1;
            for(int i=0;i<lists.size();i++)
            {
                if(lists[i]!=NULL)
                {
                    flag=1;
                    if(min==-1) min=i;
                    min=lists[i]->val<lists[min]->val?i:min;
                }
            }
            if(min==-1) continue;
            if(start==NULL)
            {
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
};