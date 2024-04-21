mod front_of_house; // 引入front_of_house module
use rand::prelude::*; // toml引入外部依赖package后，use引入模块

fn main() {
    println!("Hello, package crate module\n");
    let people_num = rand::thread_rng().gen_range(0..100);
    println!("people_num: {}", people_num);

    eat_at_restaurant();
}

pub fn eat_at_restaurant() {
    // 绝对路径, front_of_house和eat_at_restaurant在同一个crate root下，所以不涉及私有化问题
    crate::front_of_house::hosting::add_to_waitlist();

    // 相对路径，front_of_house和eat_at_restaurant在同一个crate root下，所以不涉及私有化问题
    front_of_house::hosting::seat_at_table();

    front_of_house::serving::server_dishes();
}