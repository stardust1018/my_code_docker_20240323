fn main() {
    println!("result test!");
    let x: Result<u32, &str> = Err("emergency failure");
    x.expect("Testing expect"); // panics with `Testing expect: emergency failure`
    // https://rust-coding-guidelines.github.io/rust-coding-guidelines-zh/safe-guides/coding_practice/error-handle/G.ERR.02.html 不要滥用expect，考虑使用unwrap_or_系列方法代替；
    // 我不打算处理 None 或 Err 这种可能性，因为我知道这种可能性永远不会发生，或者，它不应该发生。但是 类型系统并不知道它永远不会发生。
    // 所以，我需要向类型系统保证，如果它确实发生了，它可以认为是一种错误，并且程序应该崩溃，并带着可以用于跟踪和修复该错误的栈跟踪信息。
}
