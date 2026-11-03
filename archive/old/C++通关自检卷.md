# C++ 通关自检卷 · Qt 前置最低标准

> **这份卷子考什么**：能看懂、能写出 Qt 代码所需的 C++ **最小集合**。
> **这份卷子不考什么**：模板元编程、异常处理、多线程、智能指针、STL 高级容器、运算符重载的写法。
> 那些东西 Qt 里用到了再补——**你爸说的"需要深入时再学"就是这个意思**。
>
> 预估时长：**概念 + 读代码 + 找 bug 约 60 分钟，手写代码约 90 分钟**。建议分两次做。

---

## 考试规则（先读，别耍赖）

| 允许 | 不允许 |
|---|---|
| 查语法手册、搜"vector 怎么排序"这类**函数名/用法** | 翻阅 `cpp00`/`cpp01` 讲义 |
| 看视频教程、**一边看一边做** | 打开你自己写过的 `.c` / `.cpp` 文件 |
| 编译器报错后自己改 | 让我（AI）直接给答案 |
| 想不出来标"跳过"，但跳过 = 这题不会 | 跳过超过 2 题还说自己会了 |

> **为什么允许查语法**：记不住 `vector.resize()` 还是 `reserve()` 这种细节很正常，工作里也一样查。
> **真正的分界线是**：**你能不能不看旧代码，把逻辑从头写出来。**抄自己昨天写的东西不算会。

---

# 第一部分 · 概念口答（15 题）

**要求：不看任何资料，用自己的话说出来。说不出关键词的一半以上，就算错。**
（可以录音自测，或者讲给室友听——**能讲明白才是真懂**）

### A 组 · 内存与参数传递（Qt 天天用）

**1.** C++ 里符号 `&` 有几种含义？分别出现在什么语境？请举出至少两种并说明区别。
> 提示：想想 `int &r = a;` 和 `scanf("%d", &a);` 里的 `&` 是同一回事吗？

**2.** 引用（reference）和指针（pointer）相比，有哪三个关键区别？什么情况下必须用指针而不能用引用？
> 提示：从"能不能为空""能不能改指向""声明时是否必须初始化"三个角度想。

**3.** 值传递、地址传递、引用传递，三种方式里哪些能改掉函数外面的变量？为什么？
> 提示：复印件 vs 原件。

**4.** `new` 和 `malloc` 有什么区别？（至少说出 2 点）
> 提示：malloc 要不要写 sizeof？会不会调用构造函数？释放用什么？

**5.** 为什么 Qt 里创建控件经常写 `QPushButton *btn = new QPushButton(this);` 而不是直接定义局部变量？
> 提示：想想局部变量的生命周期——函数返回时会发生什么。

### B 组 · 类型与容器（替代你受过的罪）

**6.** `string` 相比 C 的 char 数组，解决了哪些痛点？（至少 3 条）

**7.** `vector` 相比普通数组，解决了什么痛点？至少说出 3 个常用操作（函数名）。

**8.** `int a[5];` 的合法下标范围是？写 `a[5] = 10;` 会发生什么？编译器会报错吗？

**9.** 范围 for 循环 `for (int x : a)` 和 `for (int &x : a)` 有什么区别？后者能干什么前者干不了的事？

**10.** 用 `sort(v.begin(), v.end())` 默认排成什么顺序？怎么让它降序？
> 提示：`greater<int>()` 或者自定义比较函数。

### C 组 · 类与对象（Qt 的地基）

**11.** `class` 里 `public:` 和 `private:` 的区别是什么？如果什么都不写，默认是哪个？

**12.** 构造函数什么时候被自动调用？析构函数呢？它们的作用分别是什么？

**13.** 为什么「先有 class，才能学 Qt」？——说说 `class MainWindow : public QMainWindow` 这行里，冒号 `:` 是什么意思。
> 提示：继承。

**14.** 下面这行代码里发生了几件事？请拆开描述：
```cpp
Student s("张三", 90);
```

**15.** `const` 写在成员函数后面（`void print() const;`）是什么意思？
> 提示：承诺不修改成员变量。

---

# 第二部分 · 读代码说输出（6 题）

**要求：不看编译器，先自己写出答案，再编译验证。任何时候说得出"为什么"，比答案对错更重要。**

**第 1 题**（考察：整数除法，你踩过 3 次的坑）
```cpp
#include <iostream>
using namespace std;
int main() {
    int sum = 87;
    cout << sum / 10 << endl;
    cout << (double)sum / 10 << endl;
    cout << sum / 10.0 << endl;
    return 0;
}
```
三行分别输出什么？

**第 2 题**（考察：未初始化变量，你踩过 3 次的坑）
```cpp
#include <iostream>
using namespace std;
int main() {
    int max;
    int a[3] = {-5, -3, -9};
    max = a[0];
    for (int x : a) {
        if (x > max) max = x;
    }
    cout << max << endl;
    return 0;
}
```
输出是多少？如果把 `int a[3] = {-5, -3, -9};` 换成 `-5, -3, -1`，输出又是多少？

**第 3 题**（考察：引用不是副本）
```cpp
#include <iostream>
using namespace std;
void change(int &x) {
    x = x * 2;
}
int main() {
    int a = 10;
    change(a);
    cout << a << endl;
    return 0;
}
```
输出？如果把 `int &x` 改成 `int x` 呢？

**第 4 题**（考察：字符串比较的两种世界）
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1 = "abc";
    string s2 = "abc";
    char c1[] = "abc";
    char c2[] = "abc";
    cout << (s1 == s2) << endl;
    cout << (c1 == c2) << endl;
    return 0;
}
```
两行分别输出什么？（注意：C++ 的 cout 打印 bool 类型时，true 显示 1，false 显示 0）

**第 5 题**（考察：vector 与越界）
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 0; i < 5; i++) v.push_back(i * 10);
    cout << v.size() << endl;
    cout << v[2] << endl;
    cout << v[5] << endl;
    return 0;
}
```
第 3 行会发生什么？（描述现象即可，不用写具体数字）

**第 6 题**（考察：局部变量生命周期，为 Qt 的 new 铺垫）
```cpp
#include <iostream>
using namespace std;
int* make() {
    int x = 100;
    return &x;
}
int main() {
    int *p = make();
    cout << *p << endl;
    return 0;
}
```
这题**有严重问题**。请说明：问题在哪？正确写法应该是什么？

---

# 第三部分 · 找 Bug（5 题）

**要求：每道题都要说出「错在哪」+「为什么」+「怎么改」。**
> 这一部分的 5 个 bug，有 3 个你**以前亲手在 C 里犯过**——它们换了个马甲又来了。认出来就算赢。

**第 1 题**（老朋友一号）
```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    int sum = 0;
    cout << "输入个数:";
    cin >> n;
    int scores[10];
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    cout << "平均:" << sum / n << endl;
    return 0;
}
```
> 提示：至少 3 个问题。想想 `n > 10` 会怎样、`sum / n` 的类型、`n` 为 0 会怎样。

**第 2 题**（老朋友二号）
```cpp
#include <iostream>
#include <vector>
using namespace std;
int findMax(vector<int> v) {
    int max = 0;
    for (int x : v) {
        if (x > max) max = x;
    }
    return max;
}
int main() {
    vector<int> t = {-20, -15, -30};
    cout << findMax(t) << endl;
    return 0;
}
```
> 输入全负数时输出什么？正确答案应该是多少？

**第 3 题**（值传递 vs 地址/引用传递）
```cpp
#include <iostream>
using namespace std;
void addOne(int x) {
    x = x + 1;
}
int main() {
    int a = 5;
    addOne(a);
    cout << a << endl;
    return 0;
}
```
> 输出是 5 还是 6？怎么改才能让它输出 6？（要求给出**两种**改法）

**第 4 题**（Class 基础）
```cpp
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int score;
public:
    void print() {
        cout << name << " " << score << endl;
    }
};
int main() {
    Student s;
    s.print();
    return 0;
}
```
> 问题在哪？`name` 和 `score` 会输出什么？怎么修？

**第 5 题**（循环变量重置，你踩过一次）
```cpp
#include <iostream>
using namespace std;
int main() {
    int a[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    int sum;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            sum += a[i][j];
        }
        cout << "第" << i << "行合计:" << sum << endl;
    }
    return 0;
}
```
> 输出的第 2 行会是正确结果吗？

---

# 第四部分 · 闭卷手写代码（5 题）★核心

**要求：从头写出来，能编译、能运行、边界情况正确。**
- 允许查语法细节（函数签名、头文件名）；
- **不许打开你以前写过的任何文件**；
- 每题都要自己设计测试用例，包括边界情况。

---

### 💻 第 1 题 · swap 双版本（`swap2.cpp`）

**题目**：写一个函数真正交换两个 int 变量的值，**分别用「指针版」和「引用版」实现**，并在 main 里各调用一次验证。

```cpp
void swapPtr(int *x, int *y);   // 指针版
void swapRef(int &x, int &y);   // 引用版
```

**通关标准**：两种都能真正交换；你能说出"函数调用时为什么一个要写 `&`、一个不要"。

---

### 💻 第 2 题 · 字符串统计（`strstat.cpp`）

**题目**：读入一行英文字符串（含空格），统计并输出：
- 字符串长度
- 其中字母 `a`（不分大小写）出现的次数
- 单词个数（按空格分隔）

**通关标准**：必须用 `string` + `getline`；不许用 char 数组 + `strlen`。
> 提示：`getline(cin, s)` 读整行；范围 for 遍历每个字符；判断单词数可以数"空格 + 1"（要注意连续空格和首尾空格——能处理最好，处理不了至少写写看）。

---

### 💻 第 3 题 · 成绩处理（`scores.cpp`）

**题目**：先读入一个整数 n（表示成绩个数），再读入 n 个成绩，存入 `vector`。然后输出：
- 去掉一个最高分、去掉一个最低分后的平均分（**保留 1 位小数**）
- 这 n 个成绩降序排列的结果

**通关标准**：
- 用 `vector` 不是数组；
- 平均分是小数不是整数（`(double)` 或 `sum * 1.0`）;
- 排序用 `sort`，**你要知道怎么让它降序**；
- **边界测试**：n = 1 时你的程序会崩吗？n = 2 呢？（能处理最好，不能就说出来问题在哪）

---

### 💻 第 4 题 · Student 类（★Qt 地基，必做题）（`cpp_student.cpp`）

**题目**：定义一个 `Student` 类并完成 main 逻辑：

```cpp
class Student {
private:
    string name;
    int score;
public:
    Student(string n, int s);        // 构造函数
    string getName();                // getter
    int getScore();
    void print();                    // 输出 "张三: 90分"
};
```

**main 里做这些事**：
1. 创建至少 4 个 Student 对象，放进 `vector<Student>`;
2. 按成绩**降序**排序并依次输出;
3. 输出平均分。

**通关标准**：
- 成员变量必须是 `private`（这是"封装"，Qt 的窗口类也是这个套路）;
- 构造函数正确初始化 name 和 score;
- **能说出** `sort(v.begin(), v.end(), cmp)` 里的 `cmp` 函数该怎么写、为什么参数是 `const Student &`;

> **这题就是 Qt 项目的雏形**：Qt 里 `class MainWindow : public QMainWindow { private: ... public: ... };` 和你写的是同一个套路。这题写不利索，Qt 就只能抄代码。

---

### 💻 第 5 题 · 结构体 + 指针（★数据结构入场券）（`node_link.cpp`）

**题目**：定义一个链表节点结构体，并手工串起 3 个节点再遍历输出。

```cpp
struct Node {
    int data;
    Node *next;      // 指向下一个节点的指针
};
```

**要求**：
1. 用 `new` 创建 3 个节点，data 分别为 10、20、30;
2. 手工把它们串成一条链（第一个的 next 指向第二个……最后一个的 next 指向 nullptr）;
3. 用一个指针从链头走到链尾，依次输出每个节点的 data;
4. **用完之后 delete 掉所有节点**。

**通关标准**：
- 你能说出**为什么 `next` 必须是指针而不是 `Node next;`**（想不出来就试试写成 `Node next;` 看编译器怎么说）;
- 遍历循环写出来且能跑（循环条件是 `p != nullptr`）;
- 知道忘记 `delete` 会造成什么后果（一句话即可）。

> 输出应该是：`10 20 30`

---

# 📊 评分标准

| 部分 | 题数 | 通过线 |
|---|---|---|
| 一 · 概念口答 | 15 | 至少答对 **12** 题（能说出核心意思，不要求逐字准确） |
| 二 · 读代码 | 6 | 至少 **5** 题（含说明原因） |
| 三 · 找 Bug | 5 | **全部 5 题** 都能说出错在哪 + 怎么改 |
| 四 · 手写代码 | 5 | **全部 5 题** 都能编译运行且结果正确 |

## 🎯 通关判定

```
第四部分 5 题全通 且 前三部分合计错题 ≤ 4
        ↓
   ✅ C++ 达到 Qt 前置标准，开始 Qt
```

```
第四部分过 3-4 题
        ↓
   ⚠️ 差一口气：把没过的那题对应的视频章节看完，重做该题即可（通常半天）
```

```
第四部分过 ≤ 2 题
        ↓
   ❌ 别急着看新内容：概念视频没吃透，回去看下面推荐的章节
```

> **重要**：第 4 题（Student 类）和第 5 题（链表节点）是**一票否决题**——这两题过不了，Qt 和数据结构都会卡住，不许跳。

---

# 📺 卡在哪题 → 看什么（视频对照表）

推荐看 **B 站「黑马程序员 C++ 核心编程」**（讲得慢、例子多，适合你的情况）。
不需要从头看——按下面跳：

| 卡住的题 | 看什么 | 大约位置 |
|---|---|---|
| 第一部分 A 组（1-5 题） | 「引用」「指针」「内存分区模型」「new/delete」 |  curso 前半部分，讲引用的那几节 |
| 第一部分 B 组（6-10 题） | 「string 容器」「vector 容器」「sort 算法」 | STL 章节的 string / vector 部分 |
| 第一部分 C 组（11-15 题） | 「类和对象」「封装」「构造函数和析构函数」「继承」 | 核心编程的类与对象部分 |
| 第二、三部分（坑题） | 直接看答案详解，然后**自己故意写一遍错的跑通** | — |
| 第四部分第 4 题 | 「类和对象」「对象数组」「友元/比较函数」 | 类和对象后半段 |
| 第四部分第 5 题 | 「结构体」「指针」「内存泄漏」 | 指针 + 结构体章节 |

**可以现在完全跳过的章节**（Qt 用不到）：模板（template）、异常（try/catch）、文件 IO 详解、多线程、STL 的 map/set/deque 详解、运算符重载的复杂写法。

> 等你做完 Qt 第一个项目，再回头看这些，会发现容易得多——**因为那时候你已经知道它们解决什么问题了**。

---

# ✅ 做完之后

1. 五个 `.cpp` 文件（`swap2.cpp`、`strstat.cpp`、`scores.cpp`、`cpp_student.cpp`、`node_link.cpp`）放进 `E:\zaxiang\study-log\`;
2. git 三连推上去（commit: `cpp-exam: C++通关自检卷`）;
3. 把你觉得最难的那题告诉我，我针对性补讲;
4. 通过后 → 我给你出 **`qt01_环境搭建与第一个窗口`**。

**别偷看答案**——答案在我这儿（`C++通关自检卷_答案与评分.md`），做完发我代码，我按卷子给你逐题判分，比你自己对答案准：我能看出你是"真懂"还是"碰巧跑通"。
