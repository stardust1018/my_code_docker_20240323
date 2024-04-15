fn main() {
    println!("result test!");
    let x: Result<u32, &str> = Err("emergency failure");
    
    // x.expect("Testing expect"); // panics with `Testing expect: emergency failure`
    // https://rust-coding-guidelines.github.io/rust-coding-guidelines-zh/safe-guides/coding_practice/error-handle/G.ERR.02.html 不要滥用expect，考虑使用unwrap_or_系列方法代替；
    // 我不打算处理 None 或 Err 这种可能性，因为我知道这种可能性永远不会发生，或者，它不应该发生。但是 类型系统并不知道它永远不会发生。
    // 所以，我需要向类型系统保证，如果它确实发生了，它可以认为是一种错误，并且程序应该崩溃，并带着可以用于跟踪和修复该错误的栈跟踪信息。

    // match匹配
    let ret = match x {
        Ok(num) => num.to_string(),
        Err(err) => err.to_string(),
    };
    println!("match Test -- ret: {}", ret);

    // unwrap()
    let x: Result<u32, &str> = Ok(2);
    assert_eq!(x.unwrap(), 2);
    // let x: Result<u32, &str> = Err("emergency failure");
    // x.unwrap(); // panics with `emergency failure`

    // unwrap_or(default) -- Err时用返回默认值，不触发panic
    let default = 2;
    let x: Result<u32, &str> = Ok(9);
    assert_eq!(x.unwrap_or(default), 9);
    let x: Result<u32, &str> = Err("emergency failure unwrap_or");
    println!("unwrap_or test: -- x:{}", x.unwrap_or(default));

    // unwrap_or_else(closure)
    fn count(x: &str) -> usize { x.len() }
    assert_eq!(Ok(2).unwrap_or_else(count), 2);
    assert_eq!(Err("foo").unwrap_or_else(count), 3);
    
}
