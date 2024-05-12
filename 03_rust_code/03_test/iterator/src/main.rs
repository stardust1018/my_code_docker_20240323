fn main() {
    println!("Hello, iterator!");

    {
        println!("\n迭代器基本方法");
        let s = String::from("melon love jiaojiao");
        let itor = s.chars();

        println!("count:{}", itor.count()); // count方法，计算迭代器中的元素数量

        // let last_ch = itor.last(); // error，itor moved
    }

    {
        println!("\n迭代器next方法");
        let arr = [1, 2, 3];
        let mut itor = arr.iter();
        assert_eq!(Some(&1), itor.next());
        assert_eq!(Some(&2), itor.next());
        assert_eq!(Some(&3), itor.next());
        assert_eq!(None, itor.next()); // next 方法对迭代器的遍历是消费性的，每次消耗它一个元素，最终迭代器中将没有任何元素，只能返回 None。
    }

    {
        println!("\nsum方法");
        let arr = [1, 2, 3];
        let total:i32 = arr.iter().sum(); // 将迭代器中所有元素sum
        println!("total:{}", total);
    }

    {
        println!("\nnth方法");
        let arr = [1, 2, 3];
        let num = arr.iter().nth(1).unwrap(); // 获取迭代器中索引为1的元素
        println!("num:{}", num);
    }

    {
        println!("\nmap方法和collect方法");
        let v1: Vec<i32> = vec![1, 2, 3];
        let v2: Vec<_> = v1.iter().map(|x| x + 1).collect(); // 对迭代器所有元素加1，然后收集为一个新的集合
        println!("v2 {:?}", v2);
    }

    {
        println!("\nlast方法");
        let last_item = (1..10).into_iter().last(); // 获取迭代器中最后一个元素
        if let Some(num) = last_item {
            println!("last num {}", num);
        }
    }

    {
        println!("\nskip方法");
        let arr:Vec<_> = (1..10).into_iter().skip(3).collect(); // 跳过迭代器中前3个元素
        println!("arr {:?}", arr);
    }

    {
        println!("\nrev方法");
        let arr:Vec<_> = (1..10).into_iter().rev().collect(); // rev反转迭代器中的元素顺序
        println!("arr {:?}", arr);
    }
}
