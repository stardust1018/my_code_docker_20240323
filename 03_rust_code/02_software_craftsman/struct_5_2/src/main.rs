#[derive(Debug)] // // `derive` 属性会自动创建所需的实现，使这个 `struct` 能使用 `fmt::Debug` 打印
struct Rectangle {
    width: u32,
    length: u32,
}

// 定义Rectangle方法
impl Rectangle {
    fn area(self: &Self) -> u32 {
        self.width * self.length
    }

    // 关联函数
    fn square(size: u32) -> Rectangle {
        Rectangle { width: size, length: size }
    }
}

fn main() {
    println!("Hello, Rectangle!");

    let rect = Rectangle {
        width: 30,
        length: 50,
    };
    println!("{:?}", rect);
    println!("area: {}", rect.area());

    let square = Rectangle::square(10);
    println!("square:{:?}", square);
}