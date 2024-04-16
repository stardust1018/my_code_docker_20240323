fn main() {
    println!("Hello, variable!");

    let a = 1;
    println!("a:{}", a);

    const NUM_MAX:i32 = 999; // const variable
    let a = 100 + NUM_MAX; // shadow a
    println!("a:{}", a);

    let _f1 = 2.0; // 浮点型默认类型是f64;
    let _a1 = 2; // 整数默认类型是i32;
    let _flag = true;
    let ch = '😂';
    println!("ch len:{}", ch.len_utf8());

    let ch = 'a';
    println!("ch len:{}", ch.len_utf8());
}
