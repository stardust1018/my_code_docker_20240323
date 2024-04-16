fn main() {
    println!("Hello, compound type!");

    // tuple
    let tup = (100, 1.23, true); // tuple定义
    println!("{} - {} - {}", tup.0, tup.1, tup.2); // tuple元素访问
    let (x, y, z) = tup; // 解析tuple值到普通变量
    println!("{} - {} - {}", x, y, z);

    // 数组
    let arr = [100, 200, 300]; // 数组类型[i32; 3]
    println!("{} - {} - {}", arr[0], arr[1], arr[2]);
    let slice = &arr[0..2]; // 数组切片
    assert_eq!(slice, &[100, 200]);
    println!("slice len:{}", slice.len());

    let one             = [1, 2, 3];
    // 显式类型标注
    let two: [u8; 3]    = [1, 2, 3];
    let blank1          = [0; 3];
    let blank2: [u8; 3] = [0; 3];
    let arr2 = [one, two, blank1, blank2]; // 二维数组
    println!("arr2 len:{}", arr2.len());
}
