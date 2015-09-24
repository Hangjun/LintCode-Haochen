/*
134. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Have you met this question in a real interview?
Example
*/

// Hashmap and doubly linked list.
#include <unordered_map>
using namespace std;

typedef struct DoublyListNode {
    int key;
    int val;
    struct DoublyListNode *left;
    struct DoublyListNode *right;
    DoublyListNode(int key = 0, int val = 0): key(key), val(val) {
        left = right = NULL;
    }
} DLN;

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = tail = NULL;
    }
   
    // @return an integer
    int get(int key) {
        if (um.find(key) == um.end()) {
            return DEFAULT_VALUE;
        }
        moveToFront(key);
        return um[key]->val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        DLN *p;
        if (um.find(key) == um.end()) {
            if (size == cap) {
                p = tail;
                um.erase(tail->key);
                tail->key = key;
                tail->val = value;
            } else {
                p = new DLN(key, value);
                if (head == NULL) {
                    head = tail = p;
                } else {
                    p->right = head;
                    head->left = p;
                    head = p;
                }
                ++size;
            }
            um[key] = p;
        } else {
            p = um[key];
            p->val = value;
        }
        moveToFront(key);
    }
private:
    static const int DEFAULT_VALUE = -1;
    unordered_map<int, DLN *> um;
    int cap;
    int size;
    DLN *head, *tail;
   
    void moveToFront(int key) {
        if (um.find(key) == um.end()) {
            return;
        }
        DLN *p = um[key];
        if (p == head) {
            return;
        }
        
        if (p == tail) {
            tail = tail->left;
            tail->right = NULL;
        } else {
            p->left->right = p->right;
            p->right->left = p->left;
        }
        p->left = NULL;
        p->right = head;
        head->left = p;
        head = p;
    }
};
