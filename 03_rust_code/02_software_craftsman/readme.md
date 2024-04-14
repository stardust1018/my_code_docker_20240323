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
  - Result<T,E> 是rust中的一个美剧类型。没有错误时，返回Ok(T);有错误时返回Err(E);
  - 对Rusult结果的处理，最常用的是unwrap和expect方法。
    - expect -- 遇到Err时，携带指定的信息触发panic。
- 相关的函数
- 外部的crate
  - use 引用其他库

https://rust-coding-guidelines.github.io/rust-coding-guidelines-zh/safe-guides/coding_practice/error-handle/G.ERR.02.html
不要滥用expect，考虑使用unwrap_or_系列方法代替；
