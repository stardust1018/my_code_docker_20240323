[toc]

# 一、介绍
学习B站 rust视频
https://www.bilibili.com/video/BV1hp4y1k7SV/?p=3&spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=26a4267da0466e8f2a0cef3ed5efff90

- 每一节都看
- 每一节都思考
- 每一节都练习

# 二、猜数游戏
## 2.1 一次猜测
学习的知识点：
- let、match等方法
  - let 来声明变量，默认变量是不可变的；mut显式声明为可变的；
- Result枚举
  - https://course.rs/basic/result-error/panic.html rust圣经-pinic！资料
  - Result<T,E> 是rust中的一个枚举类型。没有错误时，返回Ok(T);有错误时返回Err(E);
  - 对Rusult结果的处理，最常用的是unwrap和expect方法。
    - expect -- 遇到Err时，携带指定的信息触发panic。
    - unwrap() -- 遇到Err时，出发panic。
    - unwrap_or(default) -- 遇到Err时，返回默认值
    - unwrap_or_else(closure) -- 遇到Err时，执行闭包
- 相关的函数
- 外部的crate
  - use 引用其他库

https://rust-coding-guidelines.github.io/rust-coding-guidelines-zh/safe-guides/coding_practice/error-handle/G.ERR.02.html
不要滥用expect，考虑使用unwrap_or_系列方法代替；

## 2.2 神秘数字
学习的知识点：
- 引入外部库 crate
  - cargo.toml 中需要指定 dependencies 库和版本
  - cargo.lock 中会自动生成 对应的依赖指纹信息，依次来保证源代码和依赖库的唯一性
- 引入随机数生成库
  - use rand::Rng; // trait
  - let secret_num = rand::thread_rng().gen_range(1, 101);

## 2.3 比较猜测数字和神秘数字
学习的知识点：
- 将字符串转化为数字
  - guess.trim() 删除字符串前后的空白字符
  - guess.trim().parse() 将字符串解析为指定数字类型，返回的是一个Result。
- 数字和字符串比较 cmp
  - use std::cmp::Ordering;
  - Ordering::less  Ordering::greater  Ordering::Equal

## 2.4 多次猜测
学习的知识点：
- 利用match 处理Result结果
- loop 循环
  - 一定要配合break使用

## 3.1 变量与可变性
- let声明变量，默认为不可变
  - mut 声明的变量，才是可变的
- 常量
  - const 声明，全大写字母，中间下划线分割；
  - 声明常量必须声明类型
- 变量shadowing
- rust中char 类型占用4个字节

## 3.3 复合类型
- tuple
  - 类型 (type1, type2, type3)
- 数组
  - 类型[i32; 5]
  - 二维数组[[i32;3];5]

## 4.3 切片
学到的知识点：
- 字符串切片
  - 类型 &str
- 数组切片
  - 类型 &[type]

## 5.1 struct
学到的知识：
- struct定义、初始化、访问
- struct更新语法
- tuple struct -- 类似tuple的struct，类型有名字，但内部元素没有名字

## 5.2 struct 例子
- 从离散的数据引出为什么要使用struct
- 对于struct的打印
  - std::fmt::Debug
  - #[derive(Debug)]
  - {:?} {:#?}

## 5.3 struct 方法
- impl 定义struct 方法
- Self、self、&self、&mut self
- 关联函数(静态方法)
  - 不把self作为第一个参数的函数，可以用structName:function 直接调用。类似于c++ 类的静态成员函数；

## 6.1 定义枚举
- rust中枚举的定义、初始化
- 在枚举的类型中嵌入具体数据类型
- 为枚举定义方法

## 6.2 option枚举
- Some
- None

## 6.3 match
- match匹配时，必须穷举所有的可能
- 通配符 _ 可以表示其余所有可能；

## 6.4 if let
- 只关心一种匹配，忽略其他的所有情况；
- 算是针对特殊场景的一种 语法糖；
- if let 放弃了穷举的可能；

## 7.1 package、crate、module
- module
  - rust代码组成单元。按照功能性、可读性和易用性进行重组
  - 可以进行可见性 区分；
  - mod名和文件名一样，所以拆分到同名rs文件后，mod 定义需要删除
- crate
  - crate root
  - 从crate root的绝对路径引用
- package
  - cargo add packageName 或者在toml文件手动写入依赖项
  - use 导入module

## 8.1 vector
- 创建vector
  - Vector::new
  - vec![]
- 常用方法
  - push
  - pop
  - len
  - iter
  - iter_mut
  - []
  - get
- 所有权和引用
  - vector在栈上是由一个指针、实际长度、容量大小确定的；
  - 当实际长度不够时，会在堆上重新配置一块更大的内存空间，并将原来的内容拷贝到新的区域。
- enum + vector 可以实现利用vector存储多种不同的数据类型

## 8.3 String
- 创建String
  - string::from()
  - string::new()
  - to_string
- push()
- push_str()
- +
- format!()
- len

## 8.5 HashMap
- HashMap::new()
- into_iter().collect()
- get()
- insert()
- entery().or_insert()