/* 设计一个数据结构实现LRU:Least Recently Used cache.
 * 支持get(int key) 和 push(int key, int val)两种操作
 * Solution:push的时候注意，先检测该key在前文是否出现，有的话，调整其到队尾
 * 再检测是否超过capacity，超过则pop_front().
 * 使用双向队列实现。
 */
#include <iostream>
#include <deque>
#include <utility>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        int ret(-1);
        int i = search(key);
        if(i != -1){
            //find this index in pre
            ret = pages[i].second;//save ret.
            adjust(i, pages);            
        }
        return ret;         
    }
    
    void put(int key, int value) {
        int i = search(key);
        int size = pages.size();
        if(i != -1){ //FOUND
            pages[i].second = value;
            adjust(i, pages);
        } else {
            if(size == cap) pages.pop_front();    
            pages.push_back({key, value});
        }
    }

    int search(int key){
        int i(0), size(pages.size());
        for( ; i<size; ++i){
            if(pages[i].first == key) break;
        }
        return (i == size)? -1 : i;
    }
    //when get, put the key existed, the order needer to adjust to keep LRU.
    void adjust(int index, deque<pair<int,int>> &pages){
        auto tmp = pages[index];
        int size = pages.size();
        for(; index<size-1; ++index) pages[index] = pages[index+1];
        pages[size-1] = tmp;
    }

    void print(){
        for(auto i : pages) cout << i.first << "," << i.second << "   ";
        cout << endl;
    }
private:
    deque<pair<int,int>> pages;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(){
    LRUCache obj(2);
    obj.put(2,1);
    obj.print();
    obj.put(1,1);
    obj.print();
    obj.put(2,3);
    obj.print();
    obj.put(4,1);
    obj.print();
    cout << obj.get(1) << endl;
    obj.print();
    cout << obj.get(2) << endl;
    obj.print();
}
