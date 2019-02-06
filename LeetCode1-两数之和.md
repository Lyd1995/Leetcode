# LeetCode1-两数之和

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

## 一、思路

#### 1、相加求和再判断是否等于目标值
使用双重循环：
- 外层循环遍历第一个数的所有可能的取值，复杂度：$O(n)$
- 内层循环遍历第二个数的所有可能的取值，因为不能重复，因此复杂度为：$O(n-1)、O(n-2)、O(n-3)........O(1)$
内层的平均时间复杂度为：$O(n/2)$

总的时间复杂度为： $O(\frac {n^2}{2})$

#### 2、哈希表
使用两次循环：
- 第一次：建立哈希表，时间复杂度为：$O(n)$

例如：给定 nums = [2, 7, 11, 15]， target = 9
map[n]=target - n

map[2]=7
map[7]=2
map[11]=-2
map[15]=-6
- 第二次查找哈希表，平均时间复杂度：$O(n/2)$

总的时间复杂度：$O(n)$

系数约为：$\frac{3}{2}$

C++代码如下：
```
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> hashmap;
		int j;
		vector<int> result;
		// 建立哈希表
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			j = target - *it;
			hashmap.insert(map<int, int>::value_type (*it, j));
		}
		// 在哈希表中寻找匹配的value
		for (map<int, int>::iterator it = hashmap.begin(); it != hashmap.end(); it++) {
			// 找到对应的数
			if (hashmap.count(it->second) != 0) {
				for (int a = 0; a < nums.size(); a++) {
					if (nums[a] == it->first) {
						result.push_back(a);
						continue;
					}
						
					if (nums[a] == it->second) {
						result.push_back(a);
						continue;
					}
						
				}
				break;
			}
		}
		return result;
	}
};
```
执行效率：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190206230948203.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x5ZDE5OTU=,size_16,color_FFFFFF,t_70)


#### 3、改进的哈希表
实际上，可以使用一次循环来解决这个问题。
之前考虑先建立哈希表，再在哈希表中进行查找，实际上，在建立哈希表时就可以一边建立，一边查找。
例子：给定 nums = [2, 8, 11, 15, 7]， target = 9
map[2]=7
查找哈希表中的关键字7，不存在
map[8]=1
查找哈希表中的关键字1，不存在
map[11]=-2
查找哈希表中的关键字-2，不存在
map[15]=-6
查找哈希表中的关键字-6，不存在
map[7]=2
查找哈希表中的关键字2，存在
因为相加的两个数实际是等价的。这个方法的时间复杂度取决于相加的两个数中，排在后面的那个数的位置，平均时间复杂度：$O(n/2)$

C++代码如下：
```
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> hashmap;
		int j;
		vector<int> result;
		// 建立哈希表
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			j = target - *it;
			hashmap.insert(map<int, int>::value_type (*it, j));
			if (hashmap.count(j) != 0) {
				for (int a = 0; a < nums.size(); a++) {
					if (nums[a] == *it) {
						result.push_back(a);
						continue;
					}
					if (nums[a] == j) {
						result.push_back(a);
						continue;
					}
				}
				if (result.size() != 2) {
					result.clear();
				}
				else
					break;
				
			}
		}
		return result;
	}
};
```
执行效率：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190206231025937.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x5ZDE5OTU=,size_16,color_FFFFFF,t_70)
