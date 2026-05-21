struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*> mp;
    Node *head = nullptr,*tail = nullptr;
    int capacity,n=0;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        
        if(mp[key]->prev)
            mp[key]->prev->next = mp[key]->next;
        else
            head = mp[key]->next;

        if(mp[key]->next)
            mp[key]->next->prev = mp[key]->prev;
        else
            tail = mp[key]->prev;

        mp[key]->prev = tail;
        mp[key]->next = nullptr;
        if(tail) tail->next = mp[key];
        if(!head) head = mp[key];
        tail = mp[key];
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) 
        {
            mp[key]->key = key;
            mp[key]->val = value;
            if(mp[key]->prev)
                mp[key]->prev->next = mp[key]->next;
            else
                head = mp[key]->next;

            if(mp[key]->next)
                mp[key]->next->prev = mp[key]->prev;
            else
                tail = mp[key]->prev;

            mp[key]->prev = tail;
            mp[key]->next = nullptr;
            tail->next = mp[key];
            tail = mp[key];
        }
        else
        {
            Node *x = new Node(key, value);
            mp[key] = x;

            if(!head)
            {
                head = mp[key];
                tail = mp[key];
                n++;
            }
            else
            {
                tail->next = x;
                x->prev = tail;
                tail = x;
                n++;
                if(n>capacity)
                {
                    Node* temp = head;

                    mp.erase(temp->key);

                    if(head == tail) 
                    {
                        head = tail = nullptr;
                    } 
                    else 
                    {
                        head = head->next;
                        head->prev = nullptr;
                    }

                    delete temp;
                    n--;
                }
            }
        }
    }
};
