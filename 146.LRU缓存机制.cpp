//146. LRU 缓存机制
//运用你所掌握的数据结构，设计和实现一个  LRU(最近最少使用) 缓存机制 。
//实现 LRUCache 类：
//
//LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
//int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 - 1 。
//void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字 - 值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//
//
//进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
//
//
//
//示例：
//
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
//
//
//提示：
//
//1 <= capacity <= 3000
//0 <= key <= 3000
//0 <= value <= 104
//最多调用 3 * 104 次 get 和 put
//
//0 <= value <= 104
//最多调用 3 * 104 次 get 和 put
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/lru-cache
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解题思路：

//用哈希表来确认是否缓存命中及修改，但是LRU替换访问最少如何完成？
//无需排序计数，我们只需要一个用的最少的位置就行，用的多的放在头，少的放在尾巴。
//用链表来完成，因为需要频繁的删除和插入，用vector会导致挪动数据。增大时间复杂度。


//list：存<key,value>;   ;
//map存<key,list的迭代器>     key用来查找在不在，但是存迭代器是为了什么？

//每进行get，和put都将访问的节点放在头部，这样尾部就是访问次数最少的，   (即：用链表从头到尾顺序==key访问次数从多到少)

//当put满了需要进行LRU替换时，我们把list尾部的key_value替换，

//回答上面的问题，存迭代器为了什么？
//如果不存，每次根据存在的key去修改value时，都要根据key在list里遍历查找存储位置，好把它放到头部，时间复杂度：O（N）

//存了迭代器，直接根据迭代器，得到位置，删除再头插

class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		if (um.find(key) == um.end())
		{
			return -1;
		}
		else
		{
			//先插再删，不然还要备份key_value
			lp.push_front(make_pair(key, um[key]->second));
			lp.erase(um[key]);
			um[key] = lp.begin();
			return um[key]->second;
		}
	}

	void put(int key, int value) {

		//key是否已经存在？
		//if(存在)
		// {
		//     //直接替换，不用管满没满
		// }
		// else  
		// {
		//     if（满）
		//     {
		//         //不存在且已满，LRU替换
		//     }
		//     else
		//     {
		//         //不存在且未满，插入即可
		//     }
		// }

		unordered_map<int, list<pair<int, int>>::iterator>::iterator it = um.find(key);
		if (it != um.end())  
		{
			//key存在，即使满了，删掉原来的，再头插新数据，然后更改um[key]返回的迭代器为头部迭代器
			lp.erase(it->second);                      //这一行最体现存迭代器的意义
			lp.push_front(make_pair(key, value));
			um[key] = lp.begin();
		}
		//上面7行代码就体现了存迭代器的意义

		else
		{
			if (lp.size() >= _capacity)
			{
				//已经达到最大容量且key不存在，再put数据需要进行LRU替换。lp删掉不常用的尾部，再头插。
				um.erase(um.find((--lp.end())->first));
				lp.pop_back();
				lp.push_front(make_pair(key, value));
				um.insert(make_pair(key, lp.begin()));
			}
			else
			{
				//未达到最大容量且不存在，lp直接头插。
				lp.push_front(make_pair(key, value));

				//um中直接插入key，和刚才lp尾巴插入确定的迭代器
				um.insert(make_pair(key, lp.begin()));
			}
		}
	}

private:
	unordered_map<int, list<pair<int, int>>::iterator> um;
	int _capacity;
	list<pair<int, int>> lp;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

