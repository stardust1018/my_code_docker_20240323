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
}
