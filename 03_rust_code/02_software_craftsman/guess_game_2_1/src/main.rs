use std::io; // prelude
use rand::Rng; // trait
use std::cmp::Ordering;

fn main() {
    println!("猜数!");
    let secret_num = rand::thread_rng().gen_range(1, 101);

    loop {
        println!("猜测一个数");
        let mut guess = String::from(""); // 声明一个可变字符串变量guess
        io::stdin().read_line(&mut guess)   // read_line读取输入的整行内容到guess，guess采用可变引用方式传入
        .expect("无法读取行"); // 
        println!("你猜测的数是:{}", guess);
        let guess:i32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    
        match guess.cmp(&secret_num) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too bigger!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
