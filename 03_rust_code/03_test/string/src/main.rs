fn main() {
    println!("Hello, string!");

    {
        println!("\nString的chars()方法");
        let str = String::from("melon");

        // chars() 返回一个迭代器
        for ch in str.chars() {
            print!("{} ", ch);
        }
        println!("");

        let chs = str.chars();
        for ch in chs {
            print!("{}", ch);
        }
        println!("");

        let str = String::from("melon");
        let mut chs = str.chars();
        if let Some(ch) = chs.next() {
            println!("ch:{}", ch);
        }
        if let Some(ch) = chs.next() {
            println!("ch:{}", ch);
        }

        // nth 针对迭代器，返回第n个元素
        if Some('l') == chs.nth(2) {
            println!("chs 2 idx is {}", "l");
        } else {
            println!("chs 2 idx is not {}", "l");
        }

    }
}
