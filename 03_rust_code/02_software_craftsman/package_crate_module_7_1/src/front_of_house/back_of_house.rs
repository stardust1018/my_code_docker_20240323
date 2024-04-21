// 厨房模块
pub fn fix_incorrect_order() {
    cook_order();
    super::serving::serve_order(); // super:从父模块back_of_house同级别模块开始引用
}

fn cook_order() {}