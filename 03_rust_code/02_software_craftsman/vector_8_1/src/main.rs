fn main() {
    println!("Hello, vector!");

    {
        let mut v:Vec<i32> = Vec::new();
        v.push(1);

        match v.get(0) {
            Some(num) => println!("{}", num),
            None => println!("None"),
        }
    }

    {
        let mut v = vec![1, 2, 3];
        v.push(4);
        v.push(5);

        println!("v len:{}", v.len());

        for item in &v { // 注意，这里需要用到引用，否则内部元素所有权会被转移到item上
            println!("{} ", item);
        }
        v.push(6);

        println!("\nlast elem is {:?}", v.pop()); // pop移除最后一个元素，并返回对应option

        for itr in v.iter_mut() {
            *itr = *itr * 10;
        }
        for itr in v.iter() {
            println!("{} ", itr);
        }
    }

    {
        // vector + enum
        println!("\nvector + enum");
        #[derive(Debug)]
        enum SpreadsheetCell {
            Int(i32),
            Float(f64),
            Text(String),
        }

        let v = vec![SpreadsheetCell::Int(9), SpreadsheetCell::Float(3.14), SpreadsheetCell::Text("melon".to_string())];
        for itr in v.iter() {
            println!("{:?}", itr);
        }
    }
}

