/**************************************************************
		   function:第一章"容器"使用建议
		   ★:全部内容来自"Effective STL"该书
	   author:Demon
	   Time:2017/11/2 ,2017/11/3
**************************************************************/

#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<iterator>
#include<algorithm>
#include <functional>

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
	   答：容器中存在的不要是对象，应该存在对象的指针。智能指针更是一个不错的
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
		 list<int> 为函数返回值，test函数名，参数1：testFile(testFile两边括号可以省略）
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

	//★7.如果容器中存放了通过new操作创建的指针，记得在容器对象析构前把指针delete掉

	 /*
		 例子：
		 struct A{...}；
		 //错误做法
		 void test()
		 {
			vector<A*> v_a;
			v_a.push_back(new A);
			v_a.push_back(new A);
			.....                   //出了test,v_a作用域结束，v_a全部元素析构。但是没有释放new创建的对象。

		 }
		 //正确做法
		 void test()
		 {
		 vector<A*> v_a;
		 v_a.push_back(new A);
		 v_a.push_back(new A);
		 .....
		 //释放
		 for(auto i=v_a.begin();i!=v_a.end();++i)
		 {
			  delete *i;

		 }
		}
		//通过智能指针
		void test()
		{
		   using p=boost::shared_ptr<A>;
		   vector<p> v_a;
		   v_a.push_back(p(new A));
		   v_a.push_back(p(new A));
			......  //不用自己释放指针了，一切交给智能指针

		}

	 */


	 //★8.不要创建包含auto_ptr的容器（现在都不建议使用auto_ptr)


	 //★9.慎重选择删除元素的方法。
	   /*
	  问：如何删除容器中特定值的所有对象？
	  答：1.如果容器是vector，string，deque,使用erase_remove
		  2.如果容器是list，使用list::remove
		  3.如果容器是标准关联容器，使用其成员函数erase

		  1.●
		  vector<int> v{ 1,24,3,5,3,89,45,56,2,3 };
		  for (auto i : v)
		  {
		  cout << i << "  ";
		  }
		  cout << endl;
		  v.erase(remove(v.begin(), v.end(), 3), v.end());
		  for (auto i : v)
		  {
		  cout << i << "  ";
		  }
		  cout << endl;

		  2.●
		  list<int> L{ 12, 34, 13, 56, 34, 765, 34, 98, 17 };
		  for (auto i : L)
		  {
		  cout << i << "  ";
		  }
		  cout << endl;
		  L.remove(34);
		  for (auto i : L)
		  {
		  cout << i << "  ";
		  }
		  cout << endl;
          3.●
		  using t =map<int, int>;
		  map<int, int> m;
		  m.insert(t::value_type(1, 3));
		  m.insert(t::value_type(2, 35));
		  m.insert(t::value_type(3, 3));
		  for (auto i : m)
		  {
		  cout << i.second << "  ";
		  }
		  cout << endl;
		  for (auto i=m.begin();i!=m.end();)
		  {
		  if ((*i).second == 3)
		  {
		  i = m.erase(i);
		  }
		  else
		  {
		  ++i;
		  }
		  }
		  cout << endl;
		  for (auto i : m)
		  {
		  cout << i.second << "  ";
		  }
		  cout << endl;

	  问：如何删除容器中满足特定判别式（条件）的所有对象？
	  答：1.如果容器是vector，string，deque，使用erase_remove_if
		  2.如果容器是list，使用list::remove_if
		  3.如果容器是一个标准关联容器，使用remove_copy_if和swap。
			或者写个循环遍历容器元素，记得把迭代器传给erase时，要
			对它进行后缀递增。
			◆1.vector<int> v{ 1,24,3,5,3,89,45,56,2,345 };
              for (auto i : v)
              {
	             cout << i << "  ";
			  }
              cout << endl;
              v.erase(remove_if(v.begin(), v.end(), bind2nd(less<int>(), 5)),v.end());
              for (auto i : v)
              {
	           cout << i << "  ";
              }
              cout << endl;
            ◆2
			  list<int> L{ 12, 34, 13, 56, 34, 765, 34, 98, 17 };
              for (auto i : L)
              {
	           cout << i << "  ";
              }
              cout << endl;
              L.remove_if(bind2nd(less<int>(), 35));
              for (auto i : L)
             {
	           cout << i << "  ";
             }
             cout << endl;



			◆3.
			for(auto it=v.begin();it!=v.end();)
			{
			 if(*it==xxx)
			 {
			  it=v.erase(it);
			 }
			 else
			 {
			  ++it;
			 }
		   }

	  问：如何在循环内部做些操作（不是删除对象）？
	  答：1.如果容器是一个标准序列容器，写个循环遍历容器元素，特别
		  记住每次调用erase时。要用它的返回值更新迭代器。
		  2.如果容器是一个标准关联容器，则写一个循环来遍历容器中的
			元素，记得把迭代器传给erase时，要对迭代器做后缀递增。


	 */
      

	cout << "没写完，改天有空再写！" << endl;
	return 0;
}
