fn main() {
    println!("Hello, slice 4_3!");
    let mut s = String::from("Hello, slice 4_3!");

    // 0 开始索引，切片起始位置索引值
    // 5 结束索引，切片终止位置索引后一个索引值
    let hello = &s[0..5];
    println!("hello: {}", hello);

    let idx = first_word(&s);
    // s.clear(); // 报错，已有不可变借用后，不能再进行可变借用。
    println!("{}", idx);
}

/*
 * 功能描述：根据输入字符串s，获取其中第一个空格的索引
 */
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (idx, &item) in bytes.iter().enumerate(){
        if item == b' ' {
            return &s[0..idx];
        }
    }
    &s[0..]
}
