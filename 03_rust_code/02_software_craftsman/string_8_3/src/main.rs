fn main() {
    println!("Hello, string!");

    {
        let mut s1 = String::new();
        s1.push('m');
        println!("{}", s1);
    }

    {
        let mut s = String::from("melon");
        let s1 = "jiaojiao";
        s.push_str(s1);
        println!("{} -{}", s, s1);
    }

    {
        let s1 = "melon".to_string();
        let s2 = String::from(" love jiaojiao");
        let s3 = s1 + &s2; // + 类似于运算符重载，fn add(self, s: &str) -> String {}。所以第二个参数需要是&str

        // println!("{}", s1);
        println!("{}", s2);
        println!("{}", s3);
    }

    {
        println!("\nformat test");
        let s1 = "melon".to_string();
        let s2 = String::from("love jiaojiao");
        let s3 = format!("{} {}", s1, s2);
        println!("{}", s1);
        println!("{}", s2);
        println!("{}", s3);
    }

    {
        println!("\nString traversal");
        let s1 = "melon".to_string();

        // String 按照字节遍历
        for itr in s1.bytes() {
            println!("{}", itr);
        }

        // String按照字符遍历
        for itr in s1.chars() {
            println!("{}", itr);
        }
    }

    {
        println!("\n从String中取出单个字符");
        let s = String::from("EN中文");
        let idx = 3;
        let ch = s.chars().nth(idx).unwrap(); // nth 函数是从迭代器中取出某值的方法，请不要在遍历中这样使用！
        println!("{}", ch);
    }

    {
        println!("\n字符串分割");
        let s1 = "melon".to_string();
        let s2 = String::from("love jiaojiao");
        let s3 = format!("{} {}", s1, s2);

        let arr: Vec<&str> = s3.split(' ').collect();
        println!("{:?}", arr);

        let arr1: Vec<&str> = s3.split_whitespace().collect();
        println!("{:?}", arr1);

        let res = s3.split_once(' ').unwrap_or(("aaa", "bbb"));
        println!("{:?}", res);
    }

    {
        println!("\n字符串转化为数字");
        let str1 = String::from("123");
        let num1:u32 = str1.parse().unwrap_or(0);
        println!("num1:{}", num1);

        let str1_hex = format!("0x{:X}", num1);
        println!("str1_hex:{}", str1_hex);

        let str2 = String::from("3.14");
        let num2:f64 = str2.parse().unwrap_or(0.0);
        println!("num2:{}", num2);
    }

    {
        
    }
}
