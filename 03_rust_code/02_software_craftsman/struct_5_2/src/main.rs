#[derive(Debug)] // // `derive` 属性会自动创建所需的实现，使这个 `struct` 能使用 `fmt::Debug` 打印
struct Rectangle {
    width: u32,
    length: u32,
}

fn main() {
    println!("Hello, Rectangle!");

    let rect = Rectangle {
        width: 30,
        length: 50,
    };
    println!("{:?}", rect);
    let rect_area = area(&rect);
    println!("area: {}", rect_area);
}

fn area(rect: &Rectangle) -> u32 {
    rect.width * rect.length
}
