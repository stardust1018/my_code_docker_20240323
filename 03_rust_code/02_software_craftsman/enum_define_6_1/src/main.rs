
enum IpAddrKind {
    V4(u32, u32, u32, u32), // 为具体枚举类型嵌入类型
    V6(String),
}

// 为枚举定义方法
impl IpAddrKind {
    fn show_kind(self: &Self) {}
}

fn main() {
    println!("Hello, enum!");
    let v4 = IpAddrKind::V4(192, 168, 0, 1);
    route(&v4);
    v4.show_kind();
}

fn route(ip_kind: &IpAddrKind){}
