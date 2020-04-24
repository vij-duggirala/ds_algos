class LRUCache {
    list <int> q;
    unordered_map <int , list<int>::iterator> m;
    unordered_map<int , int> mm;
    int cap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key)==0)
                return -1;
        else
        {
            q.erase(m[key]);
            q.push_front(key);
            m[key] = q.begin();
            return mm[key];
        }
        
    }
    
    void put(int key, int value) {
        if(!m.count(key)){
        if(q.size() == cap)
        {
            int  l = q.back();
            q.pop_back();
            m.erase(l);
            mm.erase(l);
        }
        q.push_front(key);
        m[key] = q.begin();
        mm[key] = value;
        }
        else
        {
         q.erase(m[key]);
        q.push_front(key);
        m[key] = q.begin();
        mm[key] = value;
        }
    }
};