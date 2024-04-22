fn main() {
    println!("Hello, lifetime!");

    let res: &str;
    let s1 = String::from("melon");
    let s2 = "jiaojiao";
    {
        res = get_lengest_str(&s1, s2);
    }

    println!("lengest:{}", res);
}

// 表示函数只有'a这一种生命周期，而实际生效的是x和y中 生命周期短的那个
fn get_lengest_str<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}