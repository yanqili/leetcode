/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (25.43%)
 * Total Accepted:    319.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 'capacity' );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */
class LRUCache {
private:
    struct Node{
        int key;
        int value;

        Node* last;
        Node* next;
        Node(int k, int v):key(k),value(v),last(NULL),next(NULL){}
    };
    class DoubleLinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        DoubleLinkedList(){
            head = NULL;
            tail = NULL;
        }
        void mv_node_to_tail(Node* node){
            if(tail == node){
                return;
            }
            if(head == node){
                node->next->last = NULL;
                head = node->next;            
            }
            else{
                node->next->last = node->last;
                node->last->next = node->next;
            }
            node->next = NULL;
            node->last = tail;
            tail->next = node;
            tail = node;
            return;
        }
        void add_node(Node* node){
            if(head==NULL){
                head = node;
                tail = node;
            }
            else{
                tail->next = node;
                node->last = tail;
                tail = node;
            }
            return;
        }
        Node* rm_head_node(){
            if(head == tail){  // 只有一个node时
                head = NULL;
                tail = NULL;
                return head;
            }
            else{
                Node* node = head;
                node->next->last = NULL;
                head = node->next;
                node->next = NULL;
                return node;
            }
            
        }

    };
public:
    unordered_map<int, Node*> ump;
    DoubleLinkedList* dlist;
    int size;
    LRUCache(int capacity) {
        size = capacity;
        dlist = new DoubleLinkedList();
    }
    
    int get(int key) {
        unordered_map<int, Node*>::iterator itr = ump.find(key);
        if(itr == ump.end())  // not find
        {
            return -1;
        }
        else{
            dlist->mv_node_to_tail(ump[key]);
            return ump[key]->value;
        }
        
    }
    
    void put(int key, int value) {
        //Node* new_node = new Node(key, value);
        //cout<<"put "<<key<<" : "<<value<<endl;
        unordered_map<int, Node*>::iterator itr = ump.find(key);
        if(itr == ump.end())  // not find
        {       
            Node* new_node = new Node(key, value);
            ump[key] = new_node;
            dlist->add_node(ump[key]);  // 新node直接放到tail
        }
        else{
            ump[key]->value = value;
            dlist->mv_node_to_tail(ump[key]);  // 已有node移到tail
        }
        //dlist->add_node(ump[key]);
        if(ump.size() > size){
            Node* rm_node = dlist->rm_head_node();
            ump.erase(rm_node->key);
            delete rm_node;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

