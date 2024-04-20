
struct User {
    name: String,
    email: String,
    sign_in_count: u32,
    active: bool,
}

// tuple struct
struct Color (i32, i32, i32);
struct Point (i32, i32, i32);

fn main() {
    println!("Hello, struct!");

    let user_1 = User {
        name : String::from("melon"),
        email: String::from("melon@email.com"),
        sign_in_count: 1,
        active: true,
    };
    show_user_info(&user_1);

    let user_2 = build_user("jiaojiao", "jiaojiao@jiao.com");
    show_user_info(&user_2);

    let user_3 = User {
        name : String::from("laoba"),
        email: String::from("laoba@email.com"),
        ..user_1 // struct update 
    };
    show_user_info(&user_3);
    
    let user_4 = update_user("mama", "mama@email.com", &user_3);
    show_user_info(&user_4);
    show_user_info(&user_3);

    println!("\ntuple struct:");
    let blank = Color(0, 0, 0);
    println!("color info {} - {} - {}", blank.0, blank.1, blank.2);
    let point = Point(0, 0, 0); // 注意point和color是不同的类型，虽然都是(i32, i32, i32)
    println!("point info {} - {} - {}", point.0, point.1, point.2);

}

fn build_user(name: &str, email: &str) -> User {
    User {
        name: name.to_string(), 
        email: email.to_string(),
        sign_in_count: 1,
        active: true
    }
}

fn update_user(name: &str, email: &str, user: &User) -> User{
    User {
        name: name.to_string(), 
        email: email.to_string(),
        ..*user // *user解引用，解引用后onwership 有没有转变？
    }
}

fn show_user_info(user: &User) {
    println!("user info: {} - {} - {} - {}", user.name, user.email, user.sign_in_count, user.active);
}