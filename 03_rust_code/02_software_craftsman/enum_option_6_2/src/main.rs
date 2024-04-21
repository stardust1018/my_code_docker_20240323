fn main() {
    println!("Hello, enum option!");

    let some_num = Some(5);
    let some_str = Some("a string");
    let none_val: Option<i32> = None;

    match some_num {
        Some(num) => println!("num: {}", num),
        None => println!("None"),
    }

    if let Some(5) = some_num {
        println!("aaa");
    }
}
