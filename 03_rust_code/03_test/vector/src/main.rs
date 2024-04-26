fn main() {
    println!("Hello, vector!");

    {
        println!("\nvector get()方法")
        let mut strs = vec!["flower".to_string(), "melon".to_string()];
        let ret = strs.get(0);
        let str_0 = match ret {
            Some(str) => str,
            None => "",
        };
        println!("str_0:{}", str_0);

        strs.clear();
        let ret = strs.get(0..2);
        let str_1 = match ret {
            Some(str) => str,
            None => &[],
        };
        println!("str_1:{:?}", str_1);

        
    }
}
