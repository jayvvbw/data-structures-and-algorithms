class Solution {
public:
    struct node
    {
        int val;
        node* next;
        node(int v): val(v),next(nullptr) {}
    };  

    node* hash[10] = {nullptr};

    int hashfunc(int v)
    {
        int sum=0;
        while(v>0)
        {
            sum=sum+v%10;
            v=v/10;
        }
        return sum%10;
    }

    void add(int v)
    {
        node* current = new node(v);
        int bucket = hashfunc(v);
        if(hash[bucket]==nullptr)
        {
            hash[bucket] = current;
        }
        else
        {
            node* temp = hash[bucket];
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next = current;
        }
    }

    bool search(int v)
    {
        int bucket = hashfunc(v);
        node* current = hash[bucket];
        while(current!=nullptr)
        {
            if(current->val == v)
            {
                return true;
            }
            current=current->next;
        }
        return false;
    }

    int index(vector<int>& arr,int value)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<10;i++)
        {
            node* current = hash[i];
            if(current!=nullptr)
            {
                node* nextnode = current->next;
                delete current;
                current = nextnode;
            }
            hash[i] = nullptr;
        }

        for(int i=0;i<nums.size();i++)
        {
            int complement = target-nums[i];
            if(search(complement))
            {
                return {i,index(nums,complement)};
            }
            add(nums[i]);
        } 
        return {};
    }
};