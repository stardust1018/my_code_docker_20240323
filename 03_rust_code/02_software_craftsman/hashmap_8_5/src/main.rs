use std::collections::HashMap;

fn main() {
    println!("Hello, hashMap!");

    {
        let mut map = HashMap::new();
        map.insert(String::from("Blue"), 10);
        map.insert(String::from("Red"), 30);
        map.insert(String::from("Green"), 50);

        for elem in &map {
            println!("{:?}", elem);
        }

        let val = map.get("Red");
        match val {
            Some(num) => println!("val: {}", num),
            None => println!("None"),
        }
    }

    {
        println!("\ncollect创建HashMap");
        let teams_list = vec![
            ("中国队".to_string(), 100),
            ("美国队".to_string(), 10),
            ("日本队".to_string(), 50),
        ];

        let mut team_map:HashMap<_, _> = teams_list.into_iter().collect();
        println!("{:?}", team_map);

        team_map.insert("日本队".to_string(), 30);
        println!("{:?}", team_map);

        team_map.entry("俄罗斯队".to_string()).or_insert(60);
        println!("{:?}", team_map);
    }
}
