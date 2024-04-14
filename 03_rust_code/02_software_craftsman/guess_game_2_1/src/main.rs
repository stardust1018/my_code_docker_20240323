use std::io; // prelude

fn main() {
    println!("猜数!");
    println!("猜测一个数");

    let mut guess = String::from(""); // 声明一个可变字符串变量guess
    io::stdin().read_line(&mut guess)   // read_line读取输入的整行内容到guess，guess采用可变引用方式传入
    .expect("无法读取行"); // 
    println!("你猜测的数是:{}", guess);
}
