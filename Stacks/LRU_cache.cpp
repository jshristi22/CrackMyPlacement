// leetcode
// https://leetcode.com/problems/lru-cache/

#include<unordered_map>
using namespace std;

class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k, val = v;
            // next = NULL;
            // prev = NULL;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> umap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;        
    }

    void deleteNode(Node* n){
        Node* delPrev = n->prev;
        Node* delNext = n->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addNode(Node* n){
        auto headNext = head->next;
        // next
        head->next = n;
        n->next = headNext;
        // prev
        headNext->prev = n;
        n->prev = head;

    }
    
    int get(int key) {
        if(umap.find(key) != umap.end())    {
            Node* n = umap[key];
            int value = n->val;
            umap.erase(key);
            deleteNode(n); // unlink from the current position
            addNode(n); // links to next of head(recently used)
            umap[key] = head->next;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if we find the key
        if(umap.find(key) != umap.end()){
            Node* n = umap[key];
            umap.erase(key); // deletes the current key & value
            deleteNode(n); //unlink the node;
        }
        // if the capacity is full
        if(umap.size() == cap){
            // delete the last node
            Node* n = tail->prev;
            umap.erase(tail->prev->key);
            deleteNode(n);
        }

        // if we dont find the key
        addNode(new Node(key, value));
        umap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */