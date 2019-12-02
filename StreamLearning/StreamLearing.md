
# 输入输出流学习

---

<h2 id="back"></h2>

## 目录
- [基本介绍](#baseintruduction)
- [get()系列](#get)
- [流错误处理](#fail)operate)

---

<h2 id="baseintruduction"></h2>

## 基本介绍

C++的标准模板库中提供了一组模板类来支持面向对象的数据输入输出功能

好比如有以下几种

#### 基本输入输出流
- istream 类
- ostream 类
- iostream 类

#### 文件输入输出流 
- ifstream 类
- ofstream 类
- fstream 类

#### 字符串输入输出流
- stringstream 类
- istringstream 类
- ostringstream 类

这些类都位于std的名字空间内，一般都是以stream作为后缀名，在处理数据流上有着非常强大的功能

---

C++中都是以流的形式传送的，比如标准输入输出流cin(一般只键盘)，cout(一般指显示屏)。其中，左移右移运算符被重写，也就是``>>,<<``运算符,重写后，我们能够用他们标明从一个流流到另一个流中。``cin>>i;``从键盘输入的东西流到``i``变量中。

通过对流的了解，我们可以明白一些其他的事情:
- <<、>>可以连续插入，连续赋值，对于cin来说，各个数值之间是通过空格来表示分界的
- 可以通过<<输入不同的数据类型,可以通过>>给不同的数据类型赋值

好比如下面的一个小程序

#### cpp1

```c++

#include<iostream>
using namespace std;

int main()
{
	int ans;
    char ch1;
    cin>>ans>>ch1;
    cout<<"ans= "<<ans<<endl<<" ch1= "<<ch1<<endl;
	return 0;
}

//endl为输出回车换行项

```

这个例子就很好地说明了``>>、<<``可以连续输入或者连续输出

[---->back_to_top<----](#back)

---

<h2 id="get"></h2>

## get系列函数

常用的get()系列的函数有以下三个

|函数|功能|
|-|-|
|int get();|读取一个输入流的字符，并且返回值是它的ASCII值|
|istream& get(unsigned char* pszBuf, int nBufLen,char delim='\n');|第一个参数是指向字符串缓冲区的指针，保存结果用；第二个是长度，最大不可超过缓冲区长度；第三个是结束的字符标志，读到什么的时候结束|
|istream& getline(unsigned char* pszBuf, int nBufLen, char delim='\n')|同上解释|

> ``get(unsigned char* ,int ,char)``对于``getline(unsigned char* ,int char)``的区别是：
> - get()不从输入流中提取界定符，也就是delim
> - getline()从输入流中提取界定字符，提取delim，并在原输入流中删除

[---->back_to_top<----](#back)

---

<h2 id="fail_operate"></h2>

## 流错误处理

输入一个流的时候，cin如果遇到不相匹配的类型，便会返回错误。在C++中，每次输入输出的操作都是记录了其状态的信息。获取这些信息的函数如下：

|函数|功能|
|-|-|
|int rdstate();|返回时状态信息的特征值|
|bool good();|返回true，说明正常，返回false，说明有错误|
|bool eof();|返回true，说明到达了流的末尾，返回false，没有到达流的末尾|
|bool fail();|返回true，说明I/O的操作失败了，原因主要是非法的数据类型匹配，但是流可以正常使用，没有发生致命的错误。|
|bool bad();|返回true，说明发生了致命性的错误，流不能使用了。|

#### cpp2

```c++

#include<iostream>
using namespace std;

int main()
{
	int ans;
	char Buffer[100];
	
	do
	{
		cout << "请输入数据" << endl;
		cin >> ans;

		cout << "输出其状态值" << cin.rdstate() << endl;
		if (cin.good())
		{
			cout << "输入数据类型正确，没有错误产生" << endl;
			return 0;
		}
		if (cin.fail())
		{
			cout << "发生非致命错误，清空缓冲区之后仍能使用" << endl;
			cin.clear();
			cin.getline(Buffer, 100);
		}
	} while (true);

	return 0;
}

```

[---->back_to_top<----](#back)

---

后续......





