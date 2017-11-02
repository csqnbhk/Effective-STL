/**************************************************************
           function:第一章"容器"使用建议
           ★:全部内容来自"Effective STL"该书
	   author:Demon
	   Time:2017/11/2
**************************************************************/

#include<iostream>
#include<list>
#include<fstream>
#include<iterator>
using namespace std;
//int test(int(temp))
//{
//	return temp;
//}
int main()
{


	//★1.慎重选择容器类型

	 /*
	  ■标准STL序列容器：vector，string，deque,list

	  ■标准STL关联容器：set，multiset，map，multimap

	  ■非标准序列容器：slist,rope

	  ■非标准关联容器：hash_set,hash_multiset,hash_map,hash_multimap

	  ■vector<char>作为string的替代

	  ■vector作为标准关联容器的替代
	 
	  ■几种标准的非STL容器：数组，bitset,valarray,stack,queue,priority_queue
	 
	  意见：
	  1.是否需要在容器任意位置插入新元素？
	  答：如果需要，选择序列容器，关联容器不行。

	  2.是否关心容器中元素是否排序？
	  答：如果不关心排序，可以选择散列容器；如果要排序，就不可以选择散列容器。

	  3.需要哪种类型的迭代器？
	  答：如果是随机访问迭代器，可以选择vector，deque,string,rope。如果要双向
	      迭代器，则要避免使用slist(单向迭代器）

	  4.当元素插入或者删除操作时，避免移动原来元素位置是否很重要？
	  答：如果是，就要避免使用连续内存的容器。

	  5.容器中数据的布局是否要和C兼容？
	  答：如果是，就只能选择vector。

	  6.容器元素的查找速度是否为考虑的关键？
	  答：如果是，可以考虑散列容器，排序的vector和标准关联容器。

	  7.对于插入和删除操作，是否需要事务处理？
	  答：如果需要，可以选择list，只有list对多个元素的插入操作
	      提供事物语义。
	 */


	 //★2.不要试图编写独立于容器类型的代码（慢慢理解，现在不做总结）



	 //★3.确保容器中的对象副本正确而高效

	  /*
	    1.剥离现象：创建一个容器存在基类对象，结果放进去的是派生类的对象。
		            此时，派生类对象（通过基类的复制构造函数）被复制进容器，
					派生类所特有的部分消失。
		  
	   如何解决？
	   答：容器中存在1的不要是对象，应该存在对象的指针。智能指针更是一个不错的
	       选择。

	  */


	  //★4.调用empty而不是size()判断容器是否为空
	   
	  /*
	    1.为什么这么做？
		答：empty对所有的标准容器都是常数时间操作，
		    对于一些list实现（链接操作，splice)，size是线性时间。
	  
	    不管怎样，总是用empty来检查容器中元素个数是否为0.
	  
	  */

	  //★5.区间成员函数优于与之对应的单元素成员函数。

	  //★6.当心C++编译器烦人的分离机制
	//错误做法
	/*
	     ifstream testFile(R"(C:\Users\Administrator\Desktop\test.txt)");
	     list<int> test(istream_iterator<int>(testFile), istream_iterator<int>());
	     上面是一个函数声明:
		 list<int> 位函数返回值，test函数名，参数1：testFile(testFile两边括号可以省略）
		 类型为istream_iterator<int>；
		 注意： int test（int （temp））；和int test（int temp）是一样的。参数两边括号是多余的。
		        不过确实可以这样子写。
	*/
	//正确做法
	/*
	ifstream testFile(R"(C:\Users\Administrator\Desktop\test.txt)");
	istream_iterator<int> testBegin(testFile);
	istream_iterator<int> testEnd;
	list<int> test(testBegin, testEnd);
	for (auto i : test)
	{
		cout << i << " ";
	}
	cout << endl;
	*/

	cout << "没写完，改天有空再写！" << endl;
	return 0;
}
