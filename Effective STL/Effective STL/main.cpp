/**************************************************************
           function:��һ��"����"ʹ�ý���
           ��:ȫ����������"Effective STL"����
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


	//��1.����ѡ����������

	 /*
	  ����׼STL����������vector��string��deque,list

	  ����׼STL����������set��multiset��map��multimap

	  ���Ǳ�׼����������slist,rope

	  ���Ǳ�׼����������hash_set,hash_multiset,hash_map,hash_multimap

	  ��vector<char>��Ϊstring�����

	  ��vector��Ϊ��׼�������������
	 
	  �����ֱ�׼�ķ�STL���������飬bitset,valarray,stack,queue,priority_queue
	 
	  �����
	  1.�Ƿ���Ҫ����������λ�ò�����Ԫ�أ�
	  �������Ҫ��ѡ�����������������������С�

	  2.�Ƿ����������Ԫ���Ƿ�����
	  ��������������򣬿���ѡ��ɢ�����������Ҫ���򣬾Ͳ�����ѡ��ɢ��������

	  3.��Ҫ�������͵ĵ�������
	  �������������ʵ�����������ѡ��vector��deque,string,rope�����Ҫ˫��
	      ����������Ҫ����ʹ��slist(�����������

	  4.��Ԫ�ز������ɾ������ʱ�������ƶ�ԭ��Ԫ��λ���Ƿ����Ҫ��
	  ������ǣ���Ҫ����ʹ�������ڴ��������

	  5.���������ݵĲ����Ƿ�Ҫ��C���ݣ�
	  ������ǣ���ֻ��ѡ��vector��

	  6.����Ԫ�صĲ����ٶ��Ƿ�Ϊ���ǵĹؼ���
	  ������ǣ����Կ���ɢ�������������vector�ͱ�׼����������

	  7.���ڲ����ɾ���������Ƿ���Ҫ������
	  �������Ҫ������ѡ��list��ֻ��list�Զ��Ԫ�صĲ������
	      �ṩ�������塣
	 */


	 //��2.��Ҫ��ͼ��д�������������͵Ĵ��루������⣬���ڲ����ܽᣩ



	 //��3.ȷ�������еĶ��󸱱���ȷ����Ч

	  /*
	    1.�������󣺴���һ���������ڻ�����󣬽���Ž�ȥ����������Ķ���
		            ��ʱ�����������ͨ������ĸ��ƹ��캯���������ƽ�������
					�����������еĲ�����ʧ��
		  
	   ��ν����
	   �������д���1�Ĳ�Ҫ�Ƕ���Ӧ�ô��ڶ����ָ�롣����ָ�����һ�������
	       ѡ��

	  */


	  //��4.����empty������size()�ж������Ƿ�Ϊ��
	   
	  /*
	    1.Ϊʲô��ô����
		��empty�����еı�׼�������ǳ���ʱ�������
		    ����һЩlistʵ�֣����Ӳ�����splice)��size������ʱ�䡣
	  
	    ����������������empty�����������Ԫ�ظ����Ƿ�Ϊ0.
	  
	  */

	  //��5.�����Ա����������֮��Ӧ�ĵ�Ԫ�س�Ա������

	  //��6.����C++���������˵ķ������
	//��������
	/*
	      ifstream testFile(R"(C:\Users\Administrator\Desktop\test.txt)");
	     list<int> test(istream_iterator<int>(testFile), istream_iterator<int>());
	     ������һ����������:
		 list<int> λ��������ֵ��test������������1��testFile(testFile�������ſ���ʡ�ԣ�
		 ����Ϊistream_iterator<int>��
		 ע�⣺ int test��int ��temp��������int test��int temp����һ���ġ��������������Ƕ���ġ�
		        ����ȷʵ����������д��
	*/
	//��ȷ����
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

	cout << "ûд�꣬�����п���д��" << endl;
	return 0;
}