mod back_of_house;
// 餐厅前厅，用于吃饭
pub mod hosting {
    pub fn add_to_waitlist() {
        println!("add_to_waitlist begin");
    }

    pub fn seat_at_table() {
        println!("seat_at_table begin");
    }
}

pub mod serving {
    fn take_order() {}

    pub fn serve_order() {}

    fn take_payment() {}

    pub fn server_dishes() {
        crate::front_of_house::back_of_house::fix_incorrect_order();
        println!("server_dishes begin");
    }
}