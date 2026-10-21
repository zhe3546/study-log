# Day 11 · C++ 入门与面向对象（10.21 周三）

> **学法**：全部内容按「**和 C 对照**」来学——C++ 不是新语言，它是"把你在 C 里受的罪逐个解决掉"的 C。
> 每遇到一个新东西，先问：**它替我解决的是 C 里的哪个痛点？**
>
> **环境**：`g++ 16.2.0` 已装好，零安装成本。C++ 源文件后缀 `.cpp`：
> ```
> g++ main.cpp -o main
> .\main
> ```

---

## 第 0 步 · 总印象：C++ 到底改了什么

| 你在 C 里受的罪 | C++ 的解法 | 第几节 |
|---|---|---|
| char 数组、`strcpy`/`strcmp`、还要留 `\0` | **`string`**：`=` 赋值、`==` 比较、`+` 拼接 | 4 |
| 数组长度写死，超了就崩 | **`vector`**：自动增长，`push_back` 随便加 | 5 |
| 没有真正的布尔类型 | **`bool`**：`true`/`false` | 2 |
| 改外面的变量要传指针、写 `*p` | **引用 `&`**：写法像普通变量，改的是原件 | 3 |
| 数据和操作数据的函数是分开的 | **`class`**：数据和方法打包成对象 | 6 |
| 排序要自己写冒泡 | **`sort()`**：一行搞定，还比冒泡快 | 5 |
| 遍历要写 `for(i=0;i<n;i++)` | **范围 for**：`for (int x : a)` | 2 |

**一句话**：C 让你自己管一切细节，C++ 把最常用的细节做成趁手工具。你先学 C 是对的——**见过地狱才懂天堂**。

---

## 第 1 节 · 第一个 C++ 程序（逐行和 C 对照）

```cpp
#include <iostream>          // ① 输入输出库
using namespace std;         // ② 命名空间

int main() {                 // ③ C++ 里空参数不用写 void
    int a;
    cin >> a;                               // ④ 输入,【不用 &】,【不用 %d】
    cout << "你输入了" << a << endl;         // ⑤ 输出,不用管类型
    return 0;
}
```

**① `#include <iostream>`**：C++ 标准库头文件**不带 `.h`**。C 的老头文件也能用，改写为 `<cstdio>`、`<cstring>`（加 c、去 .h）。新代码一律用新版。

**② `using namespace std;`（新概念·命名空间）**
C++ 标准库的所有东西（cout、cin、string、vector）都放在 `std` 这个"姓氏"下。写全名是 `std::cout`，加了这句就能简写成 `cout`。
> 类比：两个"张伟"要区分是哪个家族的。大项目里不同库容易撞名，命名空间就是防打架的。初学无脑加这一行。

**③ `int main()`**：C++ 允许空参数不写 void。

**④⑤ `cin >> a` / `cout << ... << endl`**
`>>` 是"提取运算符"、`<<` 是"插入运算符"，可以无限连写。**它们自动识别类型**，所以：

```c
printf("%s考了%d分,平均%.1f\n", name, score, avg);   // C:类型符写错就崩/出乱数
```
```cpp
cout << name << "考了" << score << "分,平均" << avg << endl;   // C++:不用写类型
```

> 你之前踩过 `%d` 写成 `%f` 的坑——C++ 从根上消灭了这类 bug。

---

## 第 2 节 · 第一批小解放

### `bool`
```cpp
bool flag = true;    // 或 false
if (flag) { ... }
```

### `auto` 自动类型推导
```cpp
auto x = 10;        // int
auto y = 3.14;      // double
```
类型名很长的场合（Qt 里常见）特别救命。

### 范围 for ★常用
```cpp
int a[5] = {1,2,3,4,5};

for (int i = 0; i < 5; i++) cout << a[i] << " ";   // C 写法
for (int x : a)      cout << x   << " ";           // C++:读作"对于 a 里的每个 x"
```
**好处**：没有下标、没有边界判断——**数组越界这个 C 的头号 bug 自动消失**。
想修改元素本身而不是复制品？写 `for (int &x : a)`（`&` 是引用，下一节讲）。

---

## 第 3 节 · 引用 `&`（今天最重要的新符号）

`&` 在 C 里是"取地址"，在 C++ 里**多了一个新含义：别名**。这是你今天唯一需要动脑记的概念。

### 对照你 Day 9 写的指针版 swap

```c
void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }   // C
swap(&a, &b);        // 调用要 &,函数里要写一堆 *
```
```cpp
void swap(int &x, int &y) { int t = x; x = y; y = t; }        // C++ 引用版
swap(a, b);          // 调用不用 &,函数里不用 *
```

### 讲透：引用 = 同一个房间的第二个名字

```cpp
int a = 10;
int &r = a;      // r 是 a 的别名,【是同一个房间】

r = 100;
cout << a;                    // 100 —— 改 r 就是改 a
cout << &a << " " << &r;      // 两个地址完全相同
```

**三个事实：**
1. 引用**必须在声明时就绑定**变量（`int &r;` 单独写非法）—— 这恰好干掉了 C 的"野指针"问题；
2. 绑定后**不能改指向**（指针可以）；
3. **用起来和普通变量一模一样**，不用写 `*`。

| 场景 | 用哪个 |
|---|---|
| 函数要改动外面传进来的变量 | **引用**（简洁安全） |
| 参数可能"没有值" | 指针（传 nullptr） |
| 动态申请内存 | 指针 |
| 传大对象、不想复制、不许改 | `const 引用` |

> **Qt 里天天见引用**：信号槽参数大量写成 `const QString &`（避免复制大字符串）。今天立住这个概念，后面 Qt 代码你才读得懂。

---

## 第 4 节 · `string`：彻底告别 char 数组 ★★

| 需求 | C（受罪） | C++（解放） |
|---|---|---|
| 定义 | `char name[20];` 惦记留 `\0` | `string name;` |
| 赋值 | `strcpy(name, "张三");` | `name = "张三";` |
| 比较 | `strcmp(a,b)==0` | `a == b` |
| 拼接 | `strcat(a,b);` 怕越界 | `a = a + b;` |
| 长度 | `strlen(a)` | `a.length()` |

```cpp
#include <iostream>
#include <string>              // string 要单独引
using namespace std;

int main() {
    string name;
    cout << "请输入姓名:";
    cin >> name;                        // 不用 &

    string hi = "你好," + name;          // 直接 + 拼接
    cout << hi << endl;

    if (name == "张三") { cout << "老熟人" << endl; }   // 直接 == 比较
    cout << "长度:" << name.length() << endl;
    return 0;
}
```

**讲透**：为什么 C++ 能直接 `==` 和 `+`？因为 `string` 是一个**类**，内部把比较/拼接写成函数，而 C++ 支持**运算符重载**——让 `==`、`+` 对自定义类型也能用。这就是 C++ 的核心哲学：**让自定义类型用起来和内置类型一样自然**。

⚠️ `cin >> name` 仍遇空格就停。读一整行用 `getline(cin, name);`

---

## 第 5 节 · `vector`：会自己长大的数组 ★★

```cpp
#include <vector>
using namespace std;

vector<int> v;            // 空容器,长度 0

v.push_back(90);          // 尾部加 → 长度 1
v.push_back(85);
v.push_back(78);

cout << v.size();         // 3 —— 当前元素个数
cout << v[0];             // 90 —— 和数组一样用下标
v[1] = 100;               // 改元素

for (int x : v) cout << x << " ";      // 范围 for 遍历
```

**核心优势**：不用预先知道有多少数据。这在真实程序里是刚需（你不知道用户会录入几个学生）。

### 排序：一行搞定，还比冒泡快

```cpp
#include <algorithm>       // sort 在这里

sort(v.begin(), v.end());              // 升序
sort(v.begin(), v.end(), greater<int>());   // 降序
```

> 你 Day 5 手写冒泡是**必须的经历**（理解了交换的本质），但从今往后工程里用 `sort`——它内部是快速排序，复杂度 O(nlogn)，比冒泡的 O(n²) 快得多。**面试时你会写冒泡，干活时用 sort**，这就是"学过"和"没学过"的区别。

---

## 第 6 节 · 类与对象（面向对象入门）★★★

### 为什么需要类

C 里，"一个学生的数据"和"操作这些数据的函数"是分开的：

```c
struct Student { int id; char name[20]; int score; };   // 数据在这
void printStu(struct Student s) { ... }                  // 函数在那
void setScore(struct Student *s, int v) { ... }
```
全靠你**记住**哪个函数配哪个结构体，项目一大就乱。

**类 = 数据 + 操作数据的函数，打包成一个东西。**

```cpp
class Student {
public:                          // ① public:外面能访问
    string name;
    int score;

    // ② 构造函数:创建对象时自动调用,用来初始化
    Student(string n, int s) {
        name = n;
        score = s;
    }

    // ③ 成员函数(方法):属于这个对象的函数
    void print() {
        cout << name << " 的成绩:" << score << endl;
    }

    string level() {                 // 根据成绩返回等级
        if (score >= 90) return "优";
        if (score >= 60) return "及格";
        return "不及格";
    }
};
```

### 逐条讲透

**① `public:` 访问修饰符（封装）**
- `public`：外面能访问（接口）；
- `private`：只有类内部的函数能访问（隐藏实现细节）。

**这就是"封装"**：把不该让人直接碰的数据藏起来，只留安全的操作口子。比如成绩如果设成 private，你只能通过 `setScore()` 改，而 `setScore` 里可以拒绝 -5 分这种非法输入——**数据不会被随便弄脏**。

**② 构造函数（重点）**
- 名字必须和类名**完全相同**，没有返回类型；
- **创建对象时自动调用一次**：`Student s("张三", 90);`
- 作用：保证对象一出生就是合法状态，不会出现"未初始化的垃圾值"——**你那个反复踩的"未初始化变量"bug，在有构造函数的世界里几乎不会发生**。

**③ 成员函数**
用点号调用：`s.print();`。函数里能直接用 `name`、`score` 这些成员，不用传参——因为它们本来就是这个对象的一部分。

### 使用

```cpp
int main() {
    Student s("张三", 90);
    s.print();                  // 张三 的成绩:90
    cout << s.level() << endl;  // 优

    vector<Student> stu;                 // 装对象的容器!
    stu.push_back(Student("李四", 75));
    stu.push_back(Student("王五", 88));
    cout << stu.size();
    return 0;
}
```

> 注意 `vector<Student>`：容器里可以装任何类型，包括你自己写的类。这比 C 的 `struct Student stu[100]` 强太多——不用定长度，还能直接排序。

---

## 第 7 节 · 继承与多态（了解即可，Qt 天天见）

**你爸说"了解面向对象概念，差不多就行"——这两条就是"了解"的边界，懂是什么、能看懂代码即可，不用深入。**

### 继承：新类复用旧类的一切

```cpp
class Person {
public:
    string name;
    void speak() { cout << "我是" << name << endl; }
};

class Student : public Person {      // Student 继承 Person
public:
    int score;                       // 新增自己的成员
    void study() { cout << name << "在学习" << endl; }
};
```
`Student` 自动拥有 `name` 和 `speak()`，不用重写。读作"学生**是一个**人"。

### 多态：同一个调用，不同对象有不同反应

```cpp
class Shape {
public:
    virtual void draw() { cout << "画图形" << endl; }   // virtual:可被覆盖
};
class Circle : public Shape {
public:
    void draw() override { cout << "画圆形" << endl; }  // override:我覆盖了父类的
};

Shape *p = new Circle();
p->draw();        // 打印"画圆形" —— 而不是"画图形"
```
**一句话**：`virtual` + `override` 让程序在**运行时**才决定调哪个版本。

> **为什么你必须懂这个？** 因为 Qt 的核心机制——**信号与槽、事件处理**——全靠它。你在 Qt 里写的窗口类是这样诞生的：
> ```cpp
> class MainWindow : public QMainWindow {   // 继承 Qt 的窗口类
>     void closeEvent(QCloseEvent *e) override;   // 覆盖 Qt 的关闭事件
> };
> ```
> 换句话说：**Qt 编程的本质，就是不断继承 Qt 提供的类、然后覆盖它的方法。** 所以这两条必须是"懂"，不能是"没听过"。

---

## 第 8 节 · 文件读写（C++ 版，为项目存档准备）

```cpp
#include <fstream>

// 写文件
ofstream out("data.txt");
out << "张三 90" << endl;
out.close();

// 读文件
ifstream in("data.txt");
string name; int score;
while (in >> name >> score) {        // 读到文件尾自动停
    cout << name << " " << score << endl;
}
in.close();
```
比 C 的 `fopen/fprintf/fscanf` 干净得多，**而且不用管格式符**。Qt 项目里你就用这套做"退出保存、启动读取"。

---

## 今天的练习（按顺序做）

| # | 练习 | 文件名 | 练的是什么 |
|---|---|---|---|
| 1 | C++ 版 hello：输入两个数，输出和/差/积/商（商要保留小数） | `cpp_hello.cpp` | cin/cout、环境跑通 |
| 2 | 引用版 swap：交换两个 int，打印前后 | `cpp_swap.cpp` | 引用 |
| 3 | 录入 5 个成绩存进 vector，用 `sort` 降序输出 + 求平均 | `cpp_sort.cpp` | vector + sort + 范围 for |
| 4 | **Student 类**：含 name/score + 构造 + `level()`；录入 3 个学生存进 `vector<Student>`，按成绩降序输出 | `cpp_student.cpp` | 类 + 容器 ★必做 |
| 5 | 把练习 4 的数据写入 `stu.txt`，再读回来打印 | `cpp_file.cpp` | fstream（为 Qt 项目铺路） |

**练习 4 的排序提示**（自定义类型排序要给规则）：
```cpp
sort(stu.begin(), stu.end(), [](Student a, Student b) {
    return a.score > b.score;      // 按成绩降序
});
```
这个 `[](...){...}` 叫 **lambda 表达式**（匿名函数）——Qt 里写槽函数时到处都是，今天先照抄会用，明天我讲透。

---

## 验收清单（明天我问）

1. `cin >> a` 为什么不用 `&`，`printf` 的 `%d` 在 C++ 里为什么不需要了？
2. 引用 `&` 和指针 `*` 的区别？什么时候用引用？
3. `string` 解决了 C 里 char 数组的哪几个痛点？
4. `vector` 相比数组最大的好处是什么？
5. 构造函数什么时候被调用？它消灭了你哪个老 bug？
6. `public` 和 `private` 的区别，为什么要封装？
7. Qt 里 `class MainWindow : public QMainWindow` 这行是什么意思？

---

## 明天预告

**面向对象收尾 + Qt 环境搭建**：构造函数重载、析构、继承/多态再把练习过一遍；然后开始装 Qt（体积大，今晚可以先挂着下）。
